import urllib

link = "http://adc-mon.cern.ch/DAODProduction//DAILYCHECK_MC"
f = urllib.urlopen(link)
myfile = f.read()
print myfile
