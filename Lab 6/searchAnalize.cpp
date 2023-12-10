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

//count duration of the searching algorithm
std::chrono::nanoseconds cntDurOfSearchAlg(void(*op)(span<int>,int),span<int> buff,int elementToFind)
{
    auto startTime = std::chrono::high_resolution_clock::now();

    // Вызов функции, время выполнения которой вы хотите измерить
    op(buff,elementToFind);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    return duration;
}
//print time in human readable form
void printTimeFormatted(std::chrono::nanoseconds timeInNanosec)
{
    // Перевод времени в микросекунды
    auto timeInMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(timeInNanosec);
    cout << "microseconds: " << timeInMicroseconds.count() << " microsec." << std::endl;

    // Вывод времени в микросекундах
    cout << "nanosec: " << timeInNanosec.count() << " nanosec." << std::endl;
}
//call necessary functions to analize algorithms
void AnalizeSortingFunctions(span<int> buff)
{


    int numberToFind = buff[rand()%(buff.size()-1)];

    cout<<"\nlinearSearch random fill:"<<endl;
    printTimeFormatted(cntDurOfSearchAlg(callLinearSearch,buff,numberToFind));

    cout<<"\nBinarySearch ascending fill:"<<endl;
    printTimeFormatted(cntDurOfSearchAlg(callBinarySearch,buff,numberToFind));

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
    //They will look for the same number in a sorted array
    ascendingFill(buff);

    for (int i = 0; i < 5; i++)
    {
        cout<<"\n\n\n-----------------------"<<i<<"------------------------\n\n\n"<<endl;
        AnalizeSortingFunctions(buff);
    }

    system("pause");


}
