// AG2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "RingbufferTemplate.h"
#include "Complex.h"

int main()
{
    //Aufgabe 2.2
    int32_t i32Read;
    int32_t& pi32Read = i32Read;
    MyDataStructures::Ringbuffer<int32_t, 5> MyfirstRing;
    MyfirstRing.s32WriteElement(12);
    MyfirstRing.s32WriteElement(24);

    std::cout << MyfirstRing.s32ReadElement(pi32Read) << std::endl;
    MyfirstRing.vPrint();

    //Aufgabe 2.3
    MyMath::Complex Comp1(0, 0);
    MyDataStructures::Ringbuffer<MyMath::Complex, 2> MysecRing;
    MysecRing.s32WriteElement(MyMath::Complex(12, 34));
    MysecRing.s32WriteElement(MyMath::Complex(21, 43));
    MysecRing.s32ReadElement(Comp1);
    std::cout << Comp1 << std::endl;
    MysecRing.vPrint();
}