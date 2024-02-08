#include <iostream>

using namespace std;

void MergeSort(int* pArray, const int& start, const int& end);
void Divide(int* pArray, const int& start, const int& end);
void Conquer(int* pArray, int* pLeftArr, int* pRightArr, const int& start, const int& mid, const int& end);
void PrintArray(int* pArray, const int& size);

int main()
{

    int sizeOfArray = 10;
    int* array = new int[sizeOfArray];

    array[0] = 2;
    array[1] = 1;
    array[2] = 2;
    array[3] = 1;
    array[4] = 2;
    array[5] = 1;
    array[6] = 2;
    array[7] = 1;
    array[8] = 2;
    array[9] = 1;

    cout << "Unsorted array: ";
    PrintArray(array, sizeOfArray);
    cout << endl;

    MergeSort(array, 0, sizeOfArray - 1);

    cout << "Sorted array: ";
    PrintArray(array, sizeOfArray);
    cout << endl;

    delete[] array;
    array = nullptr;

    return 0;

}

void MergeSort(int* pArray, const int& start, const int& end)
{
    Divide(pArray, start, end);
}

void Divide(int* pArray, const int& start, const int& end)
{
    int* pLeftArr = nullptr;
    int* pRightArr = nullptr;
    int mid = (start + end) / 2;

    if(end - start > 0)
    {
        Divide(pArray, start, mid);
        Divide(pArray, mid + 1, end);
    }

    pLeftArr = new int[mid - start + 1];
    pRightArr = new int[end - mid];

    for(int i = 0, j = start; j <= mid; i++, j++)
    {
        pLeftArr[i] = pArray[j];
    }
    for(int i = 0, j = mid + 1; j <= end; i++, j++)
    {
        pRightArr[i] = pArray[j];
    }

    Conquer(pArray, pLeftArr, pRightArr, start, mid, end);

    delete[] pLeftArr;
    pLeftArr = nullptr;
    delete[] pRightArr;
    pRightArr = nullptr;
}

void Conquer(int* pArray, int* pLeftArr, int* pRightArr, const int& start, const int& mid, const int& end)
{
    int i = start;
    int j = 0;
    int k = 0;

    while(j <= mid - start || k < end - mid)
    {
        if(j <= mid - start && k < end - mid)
        {
            if(pLeftArr[j] <= pRightArr[k])
            {
                pArray[i] = pLeftArr[j];
                j++;
            }
            else
            {
                pArray[i] = pRightArr[k];
                k++;
            }
        }
        else if(j <= mid - start)
        {
            pArray[i] = pLeftArr[j];
            j++;
        }
        else
        {
            pArray[i] = pRightArr[k];
            k++;
        }
        i++;
    }
}

void PrintArray(int* pArray, const int& size)
{
    for(int i = 0; i < size; i++)
    {
        cout << pArray[i];
        if(i == size - 1)
        {
            break;
        }
        cout << ", ";
    }
}