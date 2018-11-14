import numpy as np
import matplotlib.pyplot as plt
import sys
import glob

path='../DavidPabon_Ejercicio27/sample_*.dat';

files = glob.glob(path)   


mu=float(sys.argv[2])
sigma=float(sys.argv[3])

from scipy.stats import norm

data_=[]
for file in files:     
	archivo=list(np.genfromtxt(file))
	data_.append(archivo)

data_=np.array(data_)
data=[]
for i in data_:
	data.append(i)	

data=np.array(data).reshape(-1,1)
x_axis = np.arange(-1, 1, 0.001)
plt.plot(x_axis, norm.pdf(x_axis,mu,sigma))
plt.hist(data,density=True)
plt.title('PDF real vs datos de sample.dat')
plt.savefig('sample.pdf')
plt.close()

