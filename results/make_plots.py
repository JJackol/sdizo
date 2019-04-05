import matplotlib.pyplot as plt
#import matplotlib
import numpy as np
from sys import argv

my_data = np.genfromtxt( argv[1] , delimiter=',')
print(my_data)

plt.plot(my_data[:,0], my_data[:,1])
plt.ylabel('czas [s]')
plt.xlabel('liczba elementów w strukturze')
plt.title(argv[1])
plt.savefig(argv[1]+'.png')



