// Linked_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include "List.h"

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
}
