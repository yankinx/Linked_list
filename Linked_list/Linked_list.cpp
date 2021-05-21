// Linked_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include "List.h"

using namespace std;
int main()
{
    List<int>* a = new List<int>();
    a->push_back(2);
    a->push_back(7);
    /*a->push_back(3);
    a->push_back(5);
    a->push_back(6);
    ++(*a);
    a->sort_current_value();
    a->list_out();*/
    List<int>* b = new List<int>();
    b->push_back(1);
    b->push_back(2);
    (*a) = (*b);
    a->list_out();
    cout << endl << endl;
    b->list_out();

}
