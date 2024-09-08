import matplotlib.pyplot as plt
import random

def rand():
    return random.randint(-10, 10)


def ciz_daire(merkez, yaricap, kenar_rengi, ic_dolgu=None):
    daire = plt.Circle(merkez, yaricap, edgecolor=kenar_rengi, facecolor=ic_dolgu, fill=ic_dolgu is not None, linewidth=2)
    plt.gca().add_patch(daire)



fig, ax = plt.subplots()
ax.set_aspect('equal')

ciz_daire((0, 0), 10, 'red') 
ciz_daire((0, 0), 3, 'black') 

tahmini_cap = rand()
h = 100
h2 = 0
for i in range(10000):
    x = rand()
    y = rand()
    plt.plot(x, y, marker='o', markersize=5, color='blue')
    hipotenus = (x**2 + y**2) ** 1/2
    
    if hipotenus > 3:
        if hipotenus < h:
            h = hipotenus
    else:
        if hipotenus > h2:
            h2 = hipotenus
    
    
    
print(h, h2)      
print((h+h2)/2)




plt.xlim(-11, 11)
plt.ylim(-11, 11)
plt.gca().set_facecolor('white')  
plt.axis('on')                   


plt.show()
