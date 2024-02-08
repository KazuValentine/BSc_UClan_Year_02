#include <iostream>

using namespace std;

void QuickSort(int* array, const int& start, const int& end);

int main()
{

    int size = 10;
    int* array = new int[size];
    /*for(int i = 0; i < size; i++)
    {
        array[i] = size - i;
    }*/
    for(int i = 0; i < size; i++)
    {
        cout << "Array[" << i + 1 << "]: ";
        cin >> array[i];
    }

    QuickSort(array, 0, size - 1);

    for(int i = 0; i < size; i++)
    {
        cout << array[i];
        if(i == size - 1)
        {
            break;
        }
        cout << ", ";
    }

    delete [] array;
    array = nullptr;

    return 0;

}

void QuickSort(int* array, const int& start, const int& end)
{
    int pivot = array[start];
    int temp = 0;
    int i = start + 1;
    int j = end;
    while(true)
    {
        for(; i < end; i++)
        {
            if(pivot < array[i])
            {
                break;
            }
        }
        for(; j > start; j--)
        {
            if(pivot > array[j])
            {
                break;
            }
        }
        if(i >= j)
        {
           array[start] = array[j];
           array[j] = pivot;
           pivot = array[start];
           if(j - start > 0)
           {
                QuickSort(array, start, j - 1);
           }
           if(end - j > 0)
           {
                QuickSort(array, j + 1, end);
           }
           break;
        }
        else
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
}