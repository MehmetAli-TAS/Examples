import matplotlib.pyplot as plt
import random

def rand():
    return random.randint(-10, 10)
# Daire çizmek için bir fonksiyon
def ciz_daire(merkez, yaricap, kenar_rengi, ic_dolgu=None):
    daire = plt.Circle(merkez, yaricap, edgecolor=kenar_rengi, facecolor=ic_dolgu, fill=ic_dolgu is not None, linewidth=2)
    plt.gca().add_patch(daire)

# Grafik ayarları
fig, ax = plt.subplots()
ax.set_aspect('equal')

# Dış kırmızı boş çember
ciz_daire((0, 0), 10, 'red')  # Dış çemberin yarıçapı 10 (çapı 20)
ciz_daire((0, 0), 3, 'black')  # Dış çemberin yarıçapı 10 (çapı 20)


for i in range(10):
    x = rand()
    y = rand()
    plt.plot(x, y, marker='o', markersize=5, color='blue')
    hipotenus = (x**2 + y**2) ** 1/2
    
    if(hipotenus > 3):
        print("nokta çember dışında")
    else:
        print("nokta çember içinde")

plt.xlim(-11, 11)
plt.ylim(-11, 11)
plt.gca().set_facecolor('white')   # Arka plan rengi beyaz
plt.axis('on')                    # Eksenleri gizle


plt.show()
