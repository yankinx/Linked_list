// Linked_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include "List.h"

using namespace std;
int main()
{
    List<int>* test = new List<int>();
    test->push_back(1);
    cout << !(test) << endl;
    
    List<int>* a;
   // a = test;

   // a->list_out();
   
}
