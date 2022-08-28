#!/usr/bin/env python3

# define necessary libraries
import matplotlib.pyplot as plt
import numpy as np
#from scipy import interpolate
from scipy.interpolate import interp1d

#data = pd.read_csv("/home/userx/GIT/ndnSIM-PIT/ns-3/plotting/py-loss-packet.csv", sep=",")
#x  = np.array(data['consumer'])
#y1 = np.array(data['sdn'])
#y2 = np.array(data['ndn'])


#x  = [10,20,30,40,50,60,70,80,90,100,200,300,400,500]
#y1 = [1990,3977,5965,7955,9944,11940,13937,15730,17723,19717,38106,56815,75970,83544]
#y2 = [1389,2386,3470,4658,5759,6853,8133,8932,10335,11374,15850,35778,59202,43614]


x  = [10,100,200,300,400,500]
y2 = [0.38,0.53,0.56,0.56,0.55,0.56]
y1 = [0.005,0.014,0.047,0.053,0.050,0.165]




# define interpolation
f1 = interp1d(x, y1, kind='cubic')
f2 = interp1d(x, y2, kind='cubic')

xnew = np.linspace(10, 500, num=50, endpoint=True)



# interpolated plot {modified 31-01-2020}
plt.plot(xnew,f1(xnew), label='Our Implementation')
plt.plot(xnew,f2(xnew), label='Traditional NDN')


#plt.plot(xnew,f2(xnew), label='Traditional NDN')
#plt.plot(xnew,f3(xnew), label='SDN-Python')
#plt.plot(xnew,f4(xnew), label='NDN-Python')


# define X-Y label
plt.xlabel('No. of Consumers')
plt.ylabel('Packet Loss (%)')

# define Title of the Figure

#plt.title('Performance Evaluation (Throughput)')

plt.legend()
#plt.grid(True)
plt.show()
