def yahallo(n):
    if n == 1 or n == 2:
        return 1
    return yahallo(n - 1) + yahallo(n - 2)
    
number = int(input("Number: "))
answer = yahallo(number)
print(answer)