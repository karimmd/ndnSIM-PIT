#!/usr/bin/env python3

# define necessary libraries
import matplotlib.pyplot as plt
import numpy as np
from scipy import interpolate
from scipy.interpolate import interp1d

# We will these arrays to plot 10 to 500 consumers
x  = [10,20,30,40,50,60,70,80,90,100,200,300,400,500]
y1 = [4607,9234,13897,18533,23224,27818,32050,36115,40368,44895,84543,126000,165228,186883]
y2 = [4597,9203,13813,18408,23022,27607,32201,36241,40480,44889,78534,107440,133871,147328]



# We will these arrays to plot 10,100,200,300,400,500 consumers
#x  = [10,100,200,300,400,500]
#y1 = [4607,44895,84543,126000,165228,186883]
#y2 = [4597,44889,78534,107440,133871,147328]

# we use this to convert in Kbps 
z  = 0.001

# we multiply 1028 with 8 to convert into bytes
y1new  = np.multiply(y1,8224)
y2new  = np.multiply(y2,8224)

y1new1 = np.divide(y1new,1024)
y2new1 = np.divide(y2new,1024)

z1new1 = np.multiply(y1new1,z)
z2new1 = np.multiply(y2new1,z)

# define interpolation
f1 = interp1d(x, z1new1, kind='cubic')
f2 = interp1d(x, z2new1, kind='cubic')

xnew = np.linspace(10, 500, num=50, endpoint=True)

# interpolated plot {modified 31-01-2020}
plt.plot(xnew,f1(xnew), label='with Caching')
plt.plot(xnew,f2(xnew), label='without Caching')

# general plot-1
#plt.plot(x,y1new1,label='with caching')
#plt.plot(x,y2,label='without caching')



# general plot with dots
#plt.plot(x,y1,'bo')
#plt.plot(x,y2,'o')
#plt.plot(x,y3,'go')
#plt.plot(x,y4,'ro')


# define X-Y label
plt.xlabel('No. of Consumers')
plt.ylabel('Data Rate (Kbps)')

# define Title of the Figure
#plt.title('Performance Evaluation (Flow Installation Time)')




plt.legend()
#plt.grid(True)
plt.show() 
