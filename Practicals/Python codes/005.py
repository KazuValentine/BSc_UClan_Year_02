def TakeInput():
    return str(input("Name: ")), int(input("Number of bycicles needed: ")), float(input("Time in hours: "))

def CalculateTime(time):
    Time = int(time)
    if time % 1 != 0:
        Time += 1
    return Time

def CalculatePrice(Time, noOfBicycles):
    return 10 + 4.5 * Time * noOfBicycles

def PrintPrice(name, noOfBicycles, time, value):
    print('"', name.upper(), '", the cost of', noOfBicycles, "bycicles for", time, "hours is a TOTAL $", value, ".")

name, noOfBicycles, time = TakeInput()
Time = CalculateTime(time)
value = CalculatePrice(Time, noOfBicycles)
PrintPrice(name, noOfBicycles, time, value)