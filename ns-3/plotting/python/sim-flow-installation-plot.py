#!/usr/bin/env python3

# define necessary libraries
import matplotlib.pyplot as plt
import numpy as np
from scipy import interpolate
from scipy.interpolate import interp1d

x  = [10,20,30,40,50,60,70,80,90,100,200,300,400,500]

y1 = [37.24,35.94,32.76,26.69,22.44,19.22,16.5771,14.775,13.1733,11.972,12.136,12.1027,12.109,12.1456]
y2 = [26.49,22.11,20.8267,19.7175,18.26,16.7183,14.8929,13.1337,11.8911,10.811,10.9615,10.968,11.0282,10.9718]
y3 = [21.909,16.5645,15.6001,14.4782,13.9803,13.8159,13.0675,12.3048,11.5878,10.4621,10.7469,10.6,10.6216,10.7001]



x  = [10,100,200,300,400,500]

y1 = [37.24,11.972,12.136,12.1027,12.109,12.1456]
y2 = [26.49,10.811,10.9615,10.968,11.0282,10.9718]
y3 = [21.909,10.4621,10.7469,10.6,10.6216,10.7001]


# we call this to get results from ms to seconds
#z = 0.001

#y5 = np.multiply(y1,z)         
#y6 = np.multiply(y2,z)
#y7 = np.multiply(y3,z)
#y8 = np.multiply(y4,z)

# define interpolation
f1 = interp1d(x, y1, kind='cubic')
f2 = interp1d(x, y2, kind='cubic')
f3 = interp1d(x, y3, kind='cubic')
#f4 = interp1d(x, y4, kind='cubic')

xnew = np.linspace(10, 500, num=100, endpoint=True)

# interpolated plot {modified 31-01-2020}
plt.plot(xnew,f1(xnew), label='100 contents per consumer')
plt.plot(xnew,f2(xnew), label='200 contents per consumer')
plt.plot(xnew,f3(xnew), label='300 contents per consumer')
#plt.plot(xnew,f4(xnew), label='400 contents per consumer')



# define X-Y label
plt.xlabel('No. of Consumers')
plt.ylabel('Flow Install Time (MS)')

# define Title of the Figure
#plt.title('Performance Evaluation (Flow Installation Time)')

plt.legend()
#plt.grid(True)
plt.show()
