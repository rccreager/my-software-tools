import urllib
import re
import smtplib

ftags = ("FTAG1", "FTAG2", "FTAG3", "FTAG4" )

for ftag in ftags:
    link = "http://adc-mon.cern.ch/DAODProduction/DAILYCHECK_MC/derivs/obs_tbl_DAOD_"+ftag+".html"
    f = urllib.urlopen(link)
    lines = f.readlines()
    
    if len(lines) == 4:
        print "Nothing to be deleted for " + ftag
    else:
        print "Deletion list for " + ftag
        for line in lines:
            if re.match("(.*mc.*)|(.*data.*)",line):
                if not re.match("Sort by.*",line):
                    print line.replace("<td>","").replace("</td>","").replace("\n","")
            #if (line != "<tr>\n") and (line != "</tr>\n") and (line != "</table><br>\n"):
            #    print line    

    #for i,v in enumerate(lines):
    #    if re.match(".*FTAG.*",lines[i]):
    #        print lines[i]
    #        print lines[i+1]
    #        print lines[i+2]

