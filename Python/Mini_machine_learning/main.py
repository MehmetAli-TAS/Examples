#-- Mini machine learning example --#

import matplotlib.pyplot as plt
import random

def rand():
    return random.uniform(-10, 10)

def Draw_circle(center, radius, edge_color, inner_filling=None):
    edge = plt.Circle(center, radius, edgecolor=edge_color, facecolor=inner_filling, fill=inner_filling is not None, linewidth=2)
    plt.gca().add_patch(edge)

fig, ax = plt.subplots()
ax.set_aspect('equal')

Draw_circle((0, 0), 10, 'red')

Draw_circle((0, 0), 3, 'black') #The radius of the circle to be found can be assigned any value(3)

#Finding values close to the actual circle radius based on random values and calculating the average.


epoch = 100
h = 100
h2 = 0
for i in range(epoch):
    x = rand()
    y = rand()
    plt.plot(x, y, marker='o', markersize=5, color='blue') 
    hypotenuse = (x**2 + y**2) ** 0.5  

    if hypotenuse > 3:
        if hypotenuse < h:
            h = hypotenuse
    else:
        if hypotenuse > h2:
            h2 = hypotenuse

print(f"epoch: {epoch}")
print(f"The nearest distance from outside the circle: {h:.5f}")
print(f"The nearest distance from inside the circle: {h2:.5f}")
print(f"Output value: {(h+h2)/2:.5f}")


plt.xlim(-11, 11)
plt.ylim(-11, 11)
plt.gca().set_facecolor('white')
plt.axis('on')

plt.show()
