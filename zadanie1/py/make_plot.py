import matplotlib.pyplot as plt
#import matplotlib

import numpy as np
from sys import argv

my_data = np.genfromtxt("../results/tab_test_1000el.txt", delimiter=',')
print(my_data)

plt.plot(my_data[:,0], my_data[:,1])
plt.ylabel('czas [s]')
plt.xlabel('liczba elementów w tablicy')
plt.title('Czas dodania 1000 elementów')
plt.savefig("../results/tab_test_1000el.png")



