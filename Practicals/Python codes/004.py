def CalculateArea(x, y):
    return x * y

def TakeInput():
    return float(input("X: ")), float(input("Y: "))

x, y = TakeInput()

print("Area: ", CalculateArea(x, y))