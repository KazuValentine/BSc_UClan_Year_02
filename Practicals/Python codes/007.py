def GDC(num1, num2):
    R = num1 % num2
    if R == 0:
        return num2
    return GDC(num2, R)
print(GDC(33, 12))