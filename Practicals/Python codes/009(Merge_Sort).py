def PrintArray(array):
    for i in range(len(array)):
        print(array[i], end='')
        if i != len(array) - 1:
            print(', ', end='')

def MergeSort(array):
    start = 0
    Divide(array, start, len(array) - 1)

def Divide(array, start, end):

    mid = int((start + end ) / 2)

    if(end - start > 0):
    
        Divide(array, start, mid)
        Divide(array, mid + 1, end)
    
    leftArr = [0] * (mid - start + 1)
    rightArr = [0] * (end - mid)

    i = 0

    for j in range(start, mid + 1):
        leftArr[i] = array[j]
        i += 1

    i = 0

    for j in range(mid + 1, end + 1):
        rightArr[i] = array[j]
        i += 1
    
    Conquer(array, leftArr, rightArr, start, mid, end)

def Conquer(array, leftArray, rightArray, start, mid, end):

    i = start;
    j = 0;
    k = 0;

    while j <= mid - start or k < end - mid:
    
        if j <= mid - start and k < end - mid:
        
            if leftArray[j] <= rightArray[k]:

                array[i] = leftArray[j]
                j += 1

            else:

                array[i] = rightArray[k]
                k += 1

        elif j <= mid - start:
        
            array[i] = leftArray[j]
            j += 1

        else:
    
            array[i] = rightArray[k]
            k += 1
        
        i += 1

array = [98, 89, 78, 87, 98, 12, 21, 0, 89, 87]
MergeSort(array)
PrintArray(array)