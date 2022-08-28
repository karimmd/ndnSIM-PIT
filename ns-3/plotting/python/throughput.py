#!/usr/bin/env python3

# define necessary libraries
import matplotlib.pyplot as plt
import numpy as np
#from scipy import interpolate
from scipy.interpolate import interp1d



# data from simulator and calculated [initial-bps]
x=[10,20,30,40,50,60,70,80,90,100,200,300,400,500]
y=[466260.969,911054.282,1351409.37,1802256.75,2252877.58,2705084.3,3157517.58,3563733.33,4015260.39,4467014,8633160.99,12850565.5,17211495.3,18927434]
y2=[394074.754,540563.747,786150.964,1055300.06,1304738.73,1552591.52,1842582.8,2023602.42,2341461.16,2576853.33,3590920.11,8105737.52,13412596.4,9881034]
z=1024

#x=[10,20,30,40,50,60,70,80,90,100,200,300,400,500]
#y=[466.260969,911.054282,1351409.37,1802256.75,2252877.58,2705084.3,3157517.58,3563733.33,4015260.39,4467014,8633160.99,12850565.5,17211495.3,18927434]
#y2=[394074.754,540563.747,786150.964,1055300.06,1304738.73,1552591.52,1842582.8,2023602.42,2341461.16,2576853.33,3590920.11,8105737.52,13412596.4,9881034]
#z=1000


# data from simulator and calculated [modified-bps]
#x=[10,20,30,40,50,60,70,80,90,100]
#y=[46626.0969,45552.7141,45046.979,45056.41875,45057.5516,45084.73833,45107.394,44546.666625,44614.00433,44670.14]
#y2=[32544.547,27329.337,26205.0321,26382.5,26094.7746,25876.52533,26322.62571,25295.03025,26016.23511,25768.5333]

# data from simulator and calculated [modified-kbps]
#x=[0,10,20,30,40,50,60,70,80,90,100]
#y=[0,45.5332978,44.4850724,43.9911904,44.0004089,44.0015152,44.0281087,44.051895,43.5026041,43.5683636,43.623183]
#y2=[0,31.7817842,26.6888057,25.5908517,25.76416,25.4831783,25.2700443,25.7056892,24.6670217,25.4064796,25.1645833]

y3 = np.divide(y,z)
y4 = np.divide(y2,z)

# define interpolation
f1 = interp1d(x, y3, kind='cubic')
f2 = interp1d(x, y4, kind='cubic')

xnew = np.linspace(10, 500, num=50, endpoint=True)

#xnew1 = xnew * 100


# interpolated plot {modified 31-01-2020}
plt.plot(xnew,f1(xnew), label='SDN-interpolate')
plt.plot(xnew,f2(xnew), label='NDN-interpolate')


# generated plot-1
#plt.plot(x,y,label='SDN')
#plt.plot(x,y2,label='NDN')
# generated plot with dots
#plt.plot(x,y,'ko')
#plt.plot(x,y2,'bo')


# define X-Y label
plt.xlabel('No. of Consumers')
plt.ylabel('KiloBits Per Second (Kbps)')



# define Title of the Figure

plt.title('Performance Evaluation (Throughput)')

plt.legend()
#plt.grid(True)
plt.show()
