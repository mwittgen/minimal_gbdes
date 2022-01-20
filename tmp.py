#import wcsfit

#import numpy as np
#import matplotlib.pyplot as plt
#from glob import glob
#from astropy.io import fits

import sys
#import wcsfit

from lsst.daf.butler import Butler
import example
#from lsst.daf.butler import Butler
print('imports done')

#butler = Butler('/repo/main', collections="HSC/runs/RC2/w_2021_34/DM-31524")
#butler.get("skyMap")
#print('got skymap')
x = example.add(1,2)
print(x)
sys.exit()
print("spaceRep 2:")
wcsfit.spaceReplace2("test")

print("orig:")
fh = wcsfit.Fields(['9813'], [1.0], [2.0], [3.0])

fields = [9813]
ras = [150.2]
decs = [2.5]
epochs = [2015.5]
fieldNames = []
fieldNames.append(str(fields[0]))
fh2 = wcsfit.Fields(fieldNames, ras, decs, epochs)
print('done')
