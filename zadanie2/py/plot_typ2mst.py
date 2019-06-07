#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt

N = (200, 400, 600, 800, 1000);
dens = (25, 50, 75, 99);

print("hello")
#o_file = open("prim.txt")

raw_pm = np.empty((5))
raw_pl = np.empty((5))
raw_km = np.empty((5))
raw_kl = np.empty((5))
raw_dm = np.empty((5))
raw_dl = np.empty((5))
raw_bm = np.empty((5))
raw_bl = np.empty((5))

my_data = np.genfromtxt("../results/res1.csv", delimiter=',', dtype=None, encoding=None)
prim_m = np.array([])
prim_l = np.array([])
matrix = np.array(list(filter(lambda row:row[2]=='m', my_data)))

prim_m_r = np.array(list(filter(lambda row:row[3]=='p', matrix)))
kruskal_m_r = np.array(list(filter(lambda row:row[3]=='k', matrix)))

list_r = np.array(list(filter(lambda row:row[2]=='l', my_data)))

prim_l = np.array(list(filter(lambda row:row[3]=='p', list_r)))
kruskal_l = np.array(list(filter(lambda row:row[3]=='k', list_r)))

d = 75

for i, size in enumerate(N):
    pre_avg = np.array([])
    for row in prim_m_r:            
        if row[0] == size and row[1]==d:                    
            pre_avg = np.append(pre_avg, row[4])    
    raw_pm[i] = np.average(pre_avg)      
    

for i, size in enumerate(N):
    pre_avg = np.array([])
    for row in kruskal_m_r:            
        if row[0] == size and row[1]==d:                    
            pre_avg = np.append(pre_avg, row[4])    
    raw_km[i] = np.average(pre_avg)  
    
    
for i, size in enumerate(N):
    pre_avg = np.array([])
    for row in prim_l:            
        if row[0] == size and row[1]==d:                    
            pre_avg = np.append(pre_avg, row[4])    
    raw_pl[i] = np.average(pre_avg)      
    

for i, size in enumerate(N):
    pre_avg = np.array([])
    for row in kruskal_l:            
        if row[0] == size and row[1]==d:                    
            pre_avg = np.append(pre_avg, row[4])    
    raw_kl[i] = np.average(pre_avg)      
                
plt.plot(N,raw_pm, label='Prim - macierz')
plt.plot(N,raw_km, label='Kruskal macierz')
plt.plot(N,raw_pl, label='Prim - lista')
plt.plot(N,raw_kl, label='Kruskal - lista')



colour_blind_cycle = ['#377eb8', '#ff7f00', '#4daf4a',
                  '#f781bf', '#a65628', '#984ea3',
                  '#999999', '#e41a1c', '#dede00']

plt.gca().set_prop_cycle(color=colour_blind_cycle)

plt.legend(loc='upper left')
plt.title("MST - gęstość "+str(d)+'%')
plt.ylabel("czas [s]")
plt.xlabel("liczba wierzchołków")

#print(raw_pm)
#print(my_data)
#print(prim_m)
#print(prim_l)
plt.show()
