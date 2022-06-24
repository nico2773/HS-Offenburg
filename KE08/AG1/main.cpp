// KE08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TemplateArray.h"
#include "Complex.h"
void TestCreateObjects();

int main()
{
    try
    {
        TestCreateObjects();
    }
    catch (std::exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void TestCreateObjects()
{
    //Aufgabe 1.2
    MyTemplates::MyArray<int32_t, 5> MyIntArray;
    for (uint32_t i32i = 0; i32i < 5U; i32i++)
    {
        MyIntArray.operator[](i32i) = 10 + i32i;
    }

    std::cout << MyIntArray << std::endl;   // Print old Array
    MyIntArray.vResize(7U);                 // Resize new Array
    std::cout << MyIntArray << std::endl;   // check for the new Array
    MyIntArray.operator[](5) = 15;          // Fill items           
    MyIntArray.operator[](6) = 16;          // Fill items
    std::cout << MyIntArray << std::endl;   // check for the new items
    MyIntArray.vResize(3);                  // 
    std::cout << MyIntArray << std::endl;   // Print

//AAufgabe 1.3
    MyTemplates::MyArray<MyMath::Complex, 5> MyComplexArray;
    for (uint32_t i32i = 0; i32i < 5U; i32i++)
    {
        MyComplexArray.operator[](i32i) = MyMath::Complex(5 + i32i, 10 + i32i);
    }

    std::cout << MyComplexArray << std::endl;   // Print old Array
    MyComplexArray.vResize(7U);                 // Resize new Array
    std::cout << MyComplexArray << std::endl;   // check for the new Array
    MyComplexArray.operator[](5) = MyMath::Complex(34, 21);          // Fill items           
    MyComplexArray.operator[](6) = MyMath::Complex(43, 12);          // Fill items
    std::cout << MyComplexArray << std::endl;   // check for the new items
    MyComplexArray.vResize(3);                  // 
    std::cout << MyComplexArray << std::endl;   // Print
}
