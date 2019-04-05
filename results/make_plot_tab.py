import matplotlib.pyplot as plt

import numpy as np
from sys import argv

my_data = np.genfromtxt("./tab/tab_add_r_1000_el.csv", delimiter=',')

x= my_data[:, 0].astype(int)

plt.plot( my_data[:,0], my_data[:,1])

#plt.xticks( range(0, 101, 20) , x[ 0:101:20])
plt.ylabel('czas [s]')

plt.xlabel('liczba elementów w tablicy')
plt.title('Czas dodawania  1000 losowych elementów do tablicy')
plt.savefig("./tab/tab_add_r_1000_el.png" )



