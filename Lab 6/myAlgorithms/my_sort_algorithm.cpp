#include <span>
#include <iostream>


void insertionSort(std::span<int> arr)
{
    int currentElement;
    int j;
    for (int i = 1; i < arr.size(); i++)
    {
        currentElement = arr[i];
        j = i-1;

        while (j>=0 && arr[j]>currentElement)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j + 1]= currentElement;
    }

    
}



int main()
{
    int arr[]={43, 18, 29, 7, 36, 14, 50, 22, 9, 31,4, 25, 47, 12, 39, 6, 20, 46, 11, 35,17, 28, 45, 3, 30, 48, 8, 19, 41, 13,26, 49, 5, 32, 16, 37, 23, 2, 40, 10,33, 21, 44, 1, 38, 24, 42, 15, 34, 27};
    insertionSort(arr);
    for (int i = 0; i < 50; i++)
    {
        std::cout<<arr[i]<<std::endl;
    }
    
}