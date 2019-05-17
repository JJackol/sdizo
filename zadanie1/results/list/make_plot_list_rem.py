import matplotlib.pyplot as plt

import numpy as np
from sys import argv

my_data = np.genfromtxt("list_rem_r_1000_el.csv", delimiter=',')

x= my_data[:, 0].astype(int)

plt.plot( my_data[:,1])

plt.xticks( range(0, 1000, 200) , x[ 0:1001:200])
plt.ylabel('czas [s]')

plt.xlabel('liczba elementów na liście')
plt.title('Czas usuwania po 1000 elementów z listy')
plt.savefig("list_rem_r_1000_el2.png" )
plt.show()



