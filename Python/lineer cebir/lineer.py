import math

r = 1

def length(y, z, x_aci):
    aci_radyan = float(math.radians(x_aci))
    x2 = ((y**2) + (z**2)) - (2*y*z*math.cos(aci_radyan))
    x = math.sqrt(x2)
    return x


def kare_alan(x, y):
    return x*y

kenar = length(3, 4, 90)
i = 2

while True:
    aci = 360/i
    kenar = length(1, 1, aci)
    kenar = kenar*(i-1)
    alan2 = kare_alan(kenar, 1)
    i += 2
    if alan2 > 3.14:
        break
    
print(alan2)
print(i)