def QuickSort(array, start, end):

    pivot = array[start];
    temp = 0;
    i = start + 1;
    j = end;

    while True:
    
        while i < end:
            if(pivot < array[i]):
                break

            i += 1

        while j > start:

            if pivot > array[j]:
                break

            j -= 1

        if i >= j:
           
           array[start] = array[j]
           array[j] = pivot
           pivot = array[start]

           if j - start > 0:
                QuickSort(array, start, j - 1)

           if end - j > 0:
                QuickSort(array, j + 1, end)

           break

        else:

            temp = array[i]
            array[i] = array[j]
            array[j] = temp

def PrintArray(array):
    for i in range(len(array)):
        print(array[i], end='')
        if i != len(array) - 1:
            print(', ', end='')

array = [78, 56, 45, 78, 56, 12, 98, 87, 32, 12]
QuickSort(array, 0, len(array) - 1)
PrintArray(array)