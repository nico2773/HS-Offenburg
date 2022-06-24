// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

typedef float f32_t;
typedef double f64_t;

struct Point
{
    int32_t s32X;
    int32_t s32Y;
    uint8_t au8VeryLongUnusedDescription[100];
};

// Aufgabe 1.1
void vPrint(int32_t i32Val);
void vPrint(double f64Val);
void vPrint(const int8_t* cpi8Val);
void vPrint(int8_t* pi8Val);
void vPrint(Point pVal);

// Aufgabe 1.2
int32_t Add(int32_t i32Val, int32_t i32Val2);
int32_t Add(int32_t* pi32Val, int32_t* pi32Val2);
float Add(float f32Val, float f32Val2);
Point Add(Point pVal, Point pVal2);

int main(void)
{
    std::cout << "Hello World!\n";
    int32_t i32Var = 7;
    double f64Var = 7.77;
    float f32Var = 7.7;
    const int8_t cpiVar = 69;
    int8_t i8Var = 20;
    Point pVar = { 512, 643, "That are random numbers"};

    //Aufgabe 1.1
    vPrint(i32Var);
    vPrint(f64Var);
    vPrint(cpiVar);
    vPrint(i8Var);
    vPrint(pVar);

    //Aufgabe 1.2
    std::cout << Add(i32Var, i32Var) << std::endl;
    std::cout << Add(&i32Var, &i32Var) << std::endl;
    std::cout << Add(f32Var, f32Var) << std::endl;
    Point pSum = Add(pVar, pVar);
    std::cout << pSum.s32X << " und " << pSum.s32Y << std::endl;
}

// Aufgabe 1.1
void vPrint(int32_t i32Val)
{
    std::cout << i32Val << std::endl;
}
void vPrint(double f64Val)
{
    std::cout << f64Val << std::endl;
}
void vPrint(const int8_t* cpi8Val)
{
    std::cout <<  "int " << cpi8Val << std::endl;
}
void vPrint(int8_t* pi8Val)
{
   std::cout << &pi8Val << std::endl;

}
void vPrint(Point pVal)
{
    std::cout << pVal.s32Y << " sowie " << pVal.s32X << " " << pVal.au8VeryLongUnusedDescription << std::endl;
}

// Aufgabe 1.2
int32_t Add(int32_t i32Val, int32_t i32Val2)
{
    
        int32_t i32Sum = i32Val + i32Val2;
        return i32Sum;
    
}
int32_t Add(int32_t* pi32Val, int32_t* pi32Val2)
{
    int32_t i32_Sum = 0; 

    if (pi32Val != nullptr && pi32Val2 != nullptr) {
        i32_Sum = (* pi32Val + *pi32Val2);
    }
    return i32_Sum;
}
float Add(float f32Val, float f32Val2)
{
    float f32Sum = f32Val + f32Val2;
    return f32Sum;


}
Point Add(Point pVal, Point pVal2)
{
    Point pSum = { 0, 0, 0 };
        
    pSum.s32X = pVal.s32X + pVal2.s32X;
    pSum.s32Y = pVal.s32Y + pVal2.s32Y;
    return pSum;
}

// Aufgabe 1.3
