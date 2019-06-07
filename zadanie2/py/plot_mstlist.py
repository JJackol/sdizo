#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt

N = (200, 400, 600, 800, 1000);
dens = (25, 50, 75, 99);

print("hello")
#o_file = open("prim.txt")

raw_pm = np.empty((5,4))
raw_pl = np.empty((5,4))
raw_km = np.empty((5,4))
raw_kl = np.empty((5,4))
raw_dm = np.empty((5,4))
raw_dl = np.empty((5,4))
raw_bm = np.empty((5,4))
raw_bl = np.empty((5,4))

my_data = np.genfromtxt("../results/res1.csv", delimiter=',', dtype=None, encoding=None)
prim_m = np.array([])
prim_l = np.array([])
matrix = np.array(list(filter(lambda row:row[2]=='m', my_data)))

prim_m_r = np.array(list(filter(lambda row:row[3]=='p', matrix)))
kruskal_m_r = np.array(list(filter(lambda row:row[3]=='k', matrix)))

list_r = np.array(list(filter(lambda row:row[2]=='l', my_data)))

prim_l = np.array(list(filter(lambda row:row[3]=='p', list_r)))
kruskal_l = np.array(list(filter(lambda row:row[3]=='k', list_r)))


for i, d in enumerate(dens): 
    for j, size in enumerate(N):
        pre_avg = np.array([])
        for row in prim_l:            
            if row[0] == size and row[1]==d :                    
                pre_avg = np.append(pre_avg, row[4])
        
        raw_pm[j,i] = np.average(pre_avg)      
        
for i, d in enumerate(dens): 
    for j, size in enumerate(N):
        pre_avg = np.array([])
        for row in kruskal_l:            
            if row[0] == size and row[1]==d :                    
                pre_avg = np.append(pre_avg, row[4])
        
        raw_km[j,i] = np.average(pre_avg)      
                
plt.plot(N,raw_pm[:,0], label='Prim d=25%')
plt.plot(N,raw_pm[:,1], label='Prim d=50%')
plt.plot(N,raw_pm[:,2], label='Prim d=75%')
plt.plot(N,raw_pm[:,3], label='Prim d=99%')

plt.plot(N,raw_km[:,0], label='Kruskal d=25%', linestyle='--')
plt.plot(N,raw_km[:,1], label='Kruskal d=50%', linestyle='--')
plt.plot(N,raw_km[:,2], label='Kruskal d=75%', linestyle='--')
plt.plot(N,raw_km[:,3], label='Kruskal d=99%', linestyle='--')

colour_blind_cycle = ['#377eb8', '#ff7f00', '#4daf4a',
                  '#f781bf', '#a65628', '#984ea3',
                  '#999999', '#e41a1c', '#dede00']

plt.gca().set_prop_cycle(color=colour_blind_cycle)

plt.legend(loc='upper left')
plt.title("MST - reprezentacja listowa")
plt.ylabel("czas [s]")
plt.xlabel("liczba wierzchołków")

#print(raw_pm)
#print(my_data)
#print(prim_m)
#print(prim_l)
plt.show()
