username = "kasun"
password = "bruh1234"
count = 0
while True:
    if count > 2:
        print("Blocked")
        break
    input1 = str(input("Username: "))
    input2 = str(input("Password: "))
    if input1 != username and input2 != password:
        print("Username & Password wrong")
    elif input1 != username:
        print("Username wrong")
    elif input2 != password:
        print("Password wrong")
    else:
        print("Vault unlocked")
        break
    count += 1
    
