import matplotlib.pyplot as plt

import numpy as np
from sys import argv

my_data = np.genfromtxt("heap_add_rand_100,000_el.txt", delimiter=',')

x= my_data[:, 0].astype(int)

plt.plot( my_data[:,0], my_data[:,1])

#plt.xticks( range(0, 101, 20) , x[ 0:101:20])

plt.ylabel("czas [s]")
plt.xlabel('liczba elementów w kopcu')

plt.title('Czas dodawania po 100,000 losowych elementów do kopca')
plt.savefig("heap_add_rand_100,000_el.png" , pad_inches = 5)
plt.show()



