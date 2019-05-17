import matplotlib.pyplot as plt

import numpy as np
from sys import argv

my_data = np.genfromtxt("list_add_r_1000_el.csv", delimiter=',')

x= my_data[:, 0].astype(int)

plt.plot( my_data[:,0], my_data[:,1])

#plt.xticks( range(0, 101, 20) , x[ 0:101:20])

plt.ylabel("czas [s]")
plt.xlabel('liczba elementów na liście')

plt.title('Czas dodawania po 1000 losowych elementów do listy')
plt.savefig("list_add_r_1000_el2.png" , pad_inches = 2)
plt.show()



