#import wcsfit

#import numpy as np
#import matplotlib.pyplot as plt
#from glob import glob
#from astropy.io import fits

import sys
#import wcsfit

mode = int(sys.argv[1])

if mode == 1:
    print('importing butler first')
    from lsst.daf.butler import Butler
    import example

if mode == 2:
    print('importing pybind11 package first')
    import example
    from lsst.daf.butler import Butler

try:
    butler = Butler('/repo/main', collections="HSC/runs/RC2/w_2021_34/DM-31524")
    butler.get("skyMap")
    print('got skymap')
except:
    print('butler.get failed')

try:
    x = example.add(1,2)
    print('pybind11 package worked')
except:
    print('pybind11 package failed')

