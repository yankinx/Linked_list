// Linked_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include "List.h"
#include "blist.h"

using namespace std;
int main()
{
    List<int>* a = new List<int>();
    clock_t t;
    
    /*for (int i = 0; i < 10000000; i++)
    {
        a->push_back(rand());
    }
    t = clock();

    a->Merge_Sort();

    t = clock() - t;
    cout << " Time: " << ((double)t) / CLOCKS_PER_SEC << "seconds" << endl;*/
    
    
    TBList<int>* blist = new TBList<int>();
    clock_t bt;
    int b;
    for (int i = 0; i < 10000000; i++)
    {
        b = rand();
        blist->AddAfterTail(b);
    }
    bt = clock();

    blist->SortList();

    bt = clock() - bt;
    cout << " Time: " << ((double)bt) / CLOCKS_PER_SEC << "seconds" << endl;
    delete blist;
}
