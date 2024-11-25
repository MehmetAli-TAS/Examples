import numpy as np # kütüphane
import random
#MATRİSLER
a = np.zeros((4, 4), dtype=int)
b = np.zeros((4, 4), dtype=int)
c = np.zeros((4, 3), dtype=int)

#a ve b matrislerine random deger ekleme
a = np.random.randint(0, 4, size=(4, 4))
b = np.random.randint(0, 4, size=(4, 4))
z = random.randint(1, 5)
print(z)
#degiskenleri tanımlama
toplam = 0
toplam2 = 0
print(a)
print(b)
#for icinde matrislerden teker teker degerleri cekme
for i in range(0, 4):
    for j in range(0, 4):
        toplam  =toplam  + a[i,j]+b[i,j] #degerleri degiskene atama
        toplam2 =toplam2 + a[j,i]+b[j,i]
        
    c[i, :] = [toplam, toplam2, 0] #degisken degerlerini matrise ekleme 
    toplam = 0 #degiskenleri sıfırlama
    toplam2 = 0
        
        
print(c) #sonuc matrisini yazdırma