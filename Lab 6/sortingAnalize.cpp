#include <iostream> 
#include <time.h> 
#include <span>
#include <array>
#include <chrono>

#include "searching/searchAlgorithms.h"
#include "sorting/sortAlgorithms.h"

using std::span;
using std::cout;
using std::endl;

//buff create
span<int> createBuff(size_t size,int* buf)
{

    buf = new int[size];


    return { buf,size};
}

//buff fullfill
void randomFill(span<int> buff)
{
    srand(time(0));

    for (int i = 0; i < buff.size(); i++)
    {
        buff[i]=rand();
    }
}

void ascendingFill(span<int> buff)
{
    randomFill(buff);
    callMergeSort(buff);
}

void descendingFill(span<int> buff)
{
    randomFill(buff);
    bubbleSortDescending(buff); 
}

//count duration of the sorting algorithm
std::chrono::microseconds cntDurOfSortAlg(void(*op)(span<int>),span<int> buff)
{
    auto startTime = std::chrono::high_resolution_clock::now();

    // Вызов функции, время выполнения которой вы хотите измерить
    op(buff);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    return duration;
}
//count duration of the searching algorithm
std::chrono::microseconds cntDurOfSearchAlg(void(*op)(span<int>,int),span<int> buff,int elementToFind)
{
    auto startTime = std::chrono::high_resolution_clock::now();

    // Вызов функции, время выполнения которой вы хотите измерить
    op(buff,elementToFind);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    return duration;
}
//print time in human readable form
void printTimeFormatted(std::chrono::microseconds timeInMicrosec)
{
    // Перевод времени в секунды
    auto timeInSeconds = std::chrono::duration_cast<std::chrono::seconds>(timeInMicrosec);
    cout << "seconds: " << timeInSeconds.count() << " sec." << std::endl;

    // Перевод времени в миллисекунды
    auto timeInMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(timeInMicrosec);
    cout << "milliseconds: " << timeInMilliseconds.count() << " millisec." << std::endl;

    // Вывод времени в микросекундах
    cout << "microseconds: " << timeInMicrosec.count() << " microsec." << std::endl;
}
//call necessary functions to analize algorithms
void AnalizeSortingFunctions(span<int> buff)
{
    //SelectionSort
    cout<<"\nselectionSort random fill:"<<endl;
    randomFill(buff);
    printTimeFormatted(cntDurOfSortAlg(selectionSort,buff));

    cout<<"\nselectionSort ascending fill:"<<endl;
    ascendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(selectionSort,buff));

    cout<<"\nselectionSort descending fill:"<<endl;
    descendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(selectionSort,buff));

    //bubbleSort
    cout<<"\n bubbleSort random fill:"<<endl;
    randomFill(buff);
    printTimeFormatted(cntDurOfSortAlg(bubbleSort,buff));

    cout<<"\n bubbleSort ascending fill:"<<endl;
    ascendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(bubbleSort,buff));

    cout<<"\n bubbleSort descending fill:"<<endl;
    descendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(bubbleSort,buff));


    //bubbleSort recursive
    cout<<"\n bubbleSort recursive random fill:"<<endl;
    randomFill(buff);
    printTimeFormatted(cntDurOfSortAlg(bubbleSortRecursive,buff));

    cout<<"\n bubbleSort recursive ascending fill:"<<endl;
    ascendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(bubbleSortRecursive,buff));

    cout<<"\n bubbleSort recursive descending fill:"<<endl;
    descendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(bubbleSortRecursive,buff));

    //quickSort 
    cout<<"\n quickSort random fill:"<<endl;
    randomFill(buff);
    printTimeFormatted(cntDurOfSortAlg(quickSort,buff));

    cout<<"\n quickSort ascending fill:"<<endl;
    ascendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(quickSort,buff));

    cout<<"\n quickSort descending fill:"<<endl;
    descendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(quickSort,buff));

    //MergeSort 
    cout<<"\n MergeSort random fill:"<<endl;
    randomFill(buff);
    printTimeFormatted(cntDurOfSortAlg(callMergeSort,buff));

    cout<<"\n MergeSort ascending fill:"<<endl;
    ascendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(callMergeSort,buff));

    cout<<"\n MergeSort descending fill:"<<endl;
    descendingFill(buff);
    printTimeFormatted(cntDurOfSortAlg(callMergeSort,buff));
}

int main()
{
    size_t size;
    int* buf;
    span<int> buff;




// ANALIZE SORTING ALGORITHMS
    cout<<"enter size of array: ";
    std::cin>>size;
    cout<<"\n\n\nSize of array: "<<size<<"\n\n\n"<<endl;
    buff = createBuff(size,buf);

    for (int i = 0; i < 5; i++)
    {
        cout<<"\n\n\n-----------------------"<<i<<"------------------------\n\n\n"<<endl;
        AnalizeSortingFunctions(buff);
    }

    system("pause");


}
