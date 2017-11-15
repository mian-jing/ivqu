#include <iostream>
#include <vector>

void vectorTest()
{
    std::vector<int> myvector(10);   // 10 zero-initialized elements

    std::vector<int>::size_type sz = 10;

    // assign some values:
    for (unsigned i=0; i<sz; i++)
    {
        myvector[i]=i;
    }

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
    {
        std::cout << ' ' << myvector[i];
    }
    std::cout << std::endl;
}

extern void emplacetest();
extern void mergeSortTest();
extern void heapSortTest();
extern void quickSortTest();
extern bool solveNQ();
extern int balancedP();

int main(int argc, char** argv)
{
    //emplacetest();
    //mergeSortTest();
    //heapSortTest();
    //quickSortTest();
    //solveNQ();
    balancedP();
    return 0;
}