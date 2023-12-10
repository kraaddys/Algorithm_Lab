#include <span>
#include <iostream>

int interpolationSearch(std::span<int> arr,int numToFind)
{
    int low=0;
    int high = arr.size();
    int mid;

    while (low<=high)
    {
        mid = low + (((numToFind - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        
        if (arr[mid] == numToFind)
            return mid;            
        if (numToFind > arr[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int numToFind;
    int arr[]={1,3,4,5,6,8,9,11,14,15,16,18,19,22,24,25,26,28,29,30,33,34,35,36,37};
    numToFind = 25;
    int index = interpolationSearch(arr,numToFind);
    std::cout<<"index to find- "<<index<<" number- "<<arr[index]<<std::endl;

}