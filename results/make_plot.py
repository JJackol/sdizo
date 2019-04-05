import matplotlib.pyplot as plt
#import matplotlib

import numpy as np
from sys import argv

my_data = np.genfromtxt("list_test_1000000x100_el.csv", delimiter=',')


plt.plot( my_data[:,0], my_data[:,1])
#plt.xticks(my_data[0::1000,0])
plt.ylabel('czas [s]')

plt.xlabel('liczba elementów na liscie')
plt.title('Czas dodania po 1.000.000 elementów')
plt.savefig("./list/list_1000,000.png")



