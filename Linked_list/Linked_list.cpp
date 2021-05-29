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
    
    for (int i = 0; i < 10000000; i++)
    {
        a->push_back(rand());
    }
    t = clock();

    a->Merge_Sort();

    t = clock() - t;
    cout << " Time: " << ((double)t) / CLOCKS_PER_SEC << "seconds" << endl;
    
    delete a;


    //=======================================================

   // List<int>* a = new List<int>();
   // a->push_back(1);
   ////a->push_back(5);
   // a->push_back(3);
   // a->push_back(4);
   // a->push_back(2);
   // a->push_back(6);
   // a->push_back(7);

   ///* List<int>* b = new List<int>();
   // b->push_back(6);
   // b->push_back(7);
   // b->push_back(8);

   // (*a) = (*b);*/
   // ++(*a);
   // ++(*a);
   // ++(*a);
   // a->sort_current_value();
   // a->list_out();

    //=======================================================


    /*TBList<int>* blist = new TBList<int>();
    clock_t bt;
    int b;
    for (int i = 0; i < 10000000; i++)
    {
        b = rand();
        blist->AddAfterTail(b);
    }
    bt = clock();

    blist->SortListBiDir();

    bt = clock() - bt;
    cout << " Time: " << ((double)bt) / CLOCKS_PER_SEC << "seconds" << endl;
    delete blist;*/
}
