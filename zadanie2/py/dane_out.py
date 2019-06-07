#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt

N = (200, 400, 600, 800, 1000);
dens = (25, 50, 75, 99);

print("hello")
o_file = open("mst75.csv", 'w')

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
    
o_file.write('Liczba wierzchołków')
o_file.write(',')
for x in N  :
    o_file.write( str(x) )
    o_file.write(',')
o_file.write('\n')
    
o_file.write('Prim - macierz')
o_file.write(',')
for x in raw_pm  :
    o_file.write( "{:9.9f}".format(x) )
    o_file.write(',')
o_file.write('\n')

o_file.write('Prim - lista')
o_file.write(',')
for x in raw_pl  :
    o_file.write( "{:9.9f}".format(x) )
    o_file.write(',')
o_file.write('\n')

o_file.write('Kruskal - macierz')
o_file.write(',')
for x in raw_km  :
    o_file.write( "{:9.9f}".format(x) )
    o_file.write(',')
o_file.write('\n')

o_file.write('Kruskal - macierz')
o_file.write(',')
for x in raw_kl :
    o_file.write( "{:9.9f}".format(x) )
    o_file.write(',')
o_file.write('\n')

o_file.close()

#print(raw_pm)
#print(my_data)
#print(prim_m)
#print(prim_l)

