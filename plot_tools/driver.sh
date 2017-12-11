#WPs=("MV2c10at60tagged")
WPs=("MV2c10at60tagged" "MV2c10at70tagged" "MV2c10at77tagged" "MV2c10at85tagged")
tags=("tag")
#tags=("tag" "untag" )
datasets=("01758BT_with_HF_corr_normalization_fix" )
#datasets=("ingo_fitter" "ingo_templates_no_overflow" "ingo_templates_with_overflow" "old_tuples_old_BT" "new_tuples_old_BT" "new_tuples_new_BT"  )
#WPs=("MV2c10at85tagged")
#tags=("tag")
#datasets=("old_tuples_old_BT")
functionName="print_all_bins_integral"
#functionName="print_summary"
#hists=("bFrac_untagStart" )
#hists=("NTagB" "NUntagB")
hists=("pTrel_data_tag" "pTrel_data_untag")
#hists=("measuredBEfficiencies" "trueBEfficiencies")
#hists=( "b-Fraction_tag" "b-Fraction_untag" )

for hist in ${hists[@]}
do
    for dataset in ${datasets[@]}
    do
        for tag in ${tags[@]}
        do
            for WP in ${WPs[@]}
            do
                #newMacroName=${functionName}_${hist}_${WP}_${tag}_${dataset}.C
                newMacroName=${functionName}_${WP}_${tag}_${dataset}.C
                cp ${functionName}.C $newMacroName
                sed -i .backup "s#WP#$WP#g" $newMacroName
                sed -i .backup "s#TAG#$tag#g" $newMacroName
                sed -i .backup "s#DATASET#$dataset#g" $newMacroName
                sed -i .backup "s#HIST#$hist#g" $newMacroName
                root -l -q $newMacroName
                rm $newMacroName.backup
            done
        done
    done
done
