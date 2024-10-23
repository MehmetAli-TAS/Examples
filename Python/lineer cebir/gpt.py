import math

def approximate_circle_area(radius, num_triangles):
    # Her bir üçgen diliminin tabanı çemberin çevresindeki küçük bir yay parçası olacak
    circumference = 2 * math.pi * radius
    triangle_base = circumference / num_triangles

    # Üçgenin yüksekliği çemberin yarıçapı kadar olacak
    triangle_height = radius

    # Her bir üçgenin alanı (base * height) / 2 ile hesaplanır
    triangle_area = (triangle_base * triangle_height) / 2

    # Toplam alan N üçgenin alanına eşittir
    total_area = num_triangles * triangle_area

    return total_area

# Kullanıcıdan çemberin yarıçapını ve üçgen sayısını alalım
radius = float(input("Çemberin yarıçapını girin: "))
real_area = math.pi * radius * radius
# Alanı hesapla
i = 1
while True:
    approx_area = approximate_circle_area(radius,i)
    print(approx_area)
    i += 1

