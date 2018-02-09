#initialize some empty lists to fill...
missing_dsids=( )
found_dsids=( )
all_dsids=( )
dataset_matches=( )

datasets=( "345728"
"345729"
"345730"
"345731"
"345732"
"345733"
"345734"
"345735"
"345736"
"345737"
"345738"
"345739"
"345740"
"345741"
"345742"
"345743"
"345744"
"345745" )


for ds in ${datasets[@]}
do
    #either use just the number or a dataset name
    #dsid=$(echo $ds | awk -F"." '{print $1}')
    dsid=$ds
   
    #count the number of lines in the rucio printout. 4 means no match found 
    num_lines=$( rucio list-dids mc15_13TeV:*$dsid*merge.AOD*e*s*r*r* | wc -l )
    all_dsids+=($dsid)
    if [ "$num_lines" -eq "4" ]; then
        echo "No MC16 dataset found for $dsid"
        missing_dsids+=($dsid)
        continue
    else
        echo "Found MC16 dataset for $dsid"
        found_dsids+=($dsid)
    fi
    
    #now to determine the most recent dataset...
    rucio_output=$( rucio list-dids mc15_13TeV:*$dsid*merge.AOD*e*s*r*r* )
    
    egen_tags=( )
    simu_tags=( )
    reco_tags=( )
    merg_tags=( )
    possible_datasets=( )
    for line in ${rucio_output[@]}
    do
        REGEX="^mc15_13TeV.*e[0-9]{4}\_s[0-9]{4}\_r[0-9]{4}\_r[0-9]{4}$"
        if [[ $line =~ $REGEX ]]; then
            possible_datasets+=($line)
            ami_info=$( echo $line | awk -F"." '{print $6}' )
            egen_tag=$( echo $ami_info | awk -F"e" '{print $2}' | awk -F"_" '{print $1}' )
            simu_tag=$( echo $ami_info | awk -F"s" '{print $2}' | awk -F"_" '{print $1}' )
            reco_tag=$( echo $ami_info | awk -F"r" '{print $2}' | awk -F"_" '{print $1}' )
            merg_tag=$( echo $ami_info | awk -F"r" '{print $3}' | awk -F"_" '{print $1}' )
            egen_tags+=($egen_tag)
            simu_tags+=($simu_tag)
            reco_tags+=($reco_tag)
            merg_tags+=($merg_tag)
        fi
    done

    #now to find largest values...
    egen_max=0
    simu_max=0
    reco_max=0
    merg_max=0
    for e in ${egen_tags[@]}; do
        if (( $e > $egen_max )); then egen_max=$e; fi;
    done
    for s in ${simu_tags[@]}; do
        if (( $s > $simu_max )); then simu_max=$s; fi;
    done
    for r in ${reco_tags[@]}; do
        if (( $r > $reco_max )); then reco_max=$r; fi;
    done
    for m in ${merg_tags[@]}; do
        if (( $m > $merg_max )); then merg_max=$m; fi;
    done

    #now to find the "best match" recursively
    match_str="e${egen_max}_s${simu_max}_r${reco_max}_r${merg_max}"
    match_dataset="Could not find best dataset. Please check manually."
    while [ ${#match_str} -gt 0 ]
    do
        num_match=$(echo "${possible_datasets[@]}" | grep "${match_str}" -o | wc -l )   
        if [ $num_match -eq 1 ]; then
            match_dataset=$( echo "${possible_datasets[@]}" | grep "\S*${match_str}\S*" -o )
            break
        fi
        if [ ${#match_str} -gt 5 ]; then match_str=${match_str%??????}; fi;
        if [ ${#match_str} -le 5 ]; then 
            break 
        fi
    done 
    dataset_matches+=($match_dataset)
done

echo "missing: ${missing_dsids[@]}"
echo "found: ${found_dsids[@]}"

for ds in ${all_dsids[@]}
do
    found=0
    for found_ds in ${found_dsids[@]}
    do
        if [ "$found_ds" -eq "$ds" ]; then
            #if the dataset is found, print its match from the list of "best" matches
            if echo "${dataset_matches[@]}" | grep -q "\S*${ds}\S*"; then
                echo "${dataset_matches[@]}" | grep "\S*${ds}\S*" -o
            else
                echo "Could not find best dataset for $ds. Please check manually."
            fi
            found=1
        fi
    done
    if [ "$found" -eq "0" ]; then
        echo "Not available"
    fi
done
