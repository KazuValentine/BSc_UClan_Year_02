def PrintArray(array):
    for i in range(len(array)):
        print(array[i], end='')
        if i != len(array) - 1:
            print(', ', end='')