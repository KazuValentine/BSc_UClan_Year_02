def SelectionSort(array):

    temp = 0
    tempIndex = 0

    for i in range(len(array) - 1):

        temp = array[i]
        tempIndex = i

        for j in range(i + 1, len(array)):

            if temp > array[j]:

                temp = array[j]
                tempIndex = j

        temp = array[i]
        array[i] = array[tempIndex]
        array[tempIndex] = temp

def PrintArray(array):
    for i in range(len(array)):
        print(array[i], end='')
        if i != len(array) - 1:
            print(', ', end='')

array = [4, 4, 3, 3, 1, 1, 4, 3, 1]
SelectionSort(array)
PrintArray(array)