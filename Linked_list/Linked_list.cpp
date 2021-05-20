// Linked_list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include "List.h"

using namespace std;
int main()
{
    List<int>* a = new List<int>();
    a->push_back(1);
    a->push_back(2);
    a->push_back(3);
    a->push_back(5);
    a->list_out();

}
