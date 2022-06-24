// AG2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Complex.h"
#include <iomanip>

int main()
{
    //Schaltung 1
    MyMath::Complex Z1(0., 100.);
    MyMath::Complex Z2(0., -100.);
    MyMath::Complex Z3(100., 0.);
    MyMath::Complex Z4(0., -50.);

    MyMath::Complex SCH1 = Z1 + ~(~Z2 + ~Z3) + Z4;
    std::cout << "Schaltung 1: " << SCH1 << std::endl;

    //Schaltung 2
    MyMath::Complex Z5(0., 100.);
    MyMath::Complex Z6(50., 0.);

    MyMath::Complex SCH2 = ~(~(Z1 + ~(~Z3 + ~Z2) + Z4) + ~(Z5 + Z6));
    std::cout << "Schaltung 2: " << SCH2 << std::endl;

    //There is a wrong value. I double checked everything. I dont know why its only in Schaltung 2. In the
    //Other Schaltung it is working fine.

    //Schaltung 3
    MyMath::Complex Z7(0., 75.);
    MyMath::Complex Z8(50., 0.);
    MyMath::Complex Z9(0., -75.);
    MyMath::Complex Z10(25., 0.);
    MyMath::Complex Z11(0., -75.);
    MyMath::Complex Z12(50., 0.);
    MyMath::Complex Z13(0., 75.);
    MyMath::Complex Z14(0., 50.);
    MyMath::Complex Z15(150., 0.);

    MyMath::Complex SCH3 = ~(~(Z7 + Z8) + ~(Z9 + Z10)) + ~(~(Z11 + Z12 + Z13) + ~(Z14 + Z15));
    std::cout << "Schaltung 3: " << SCH3 << std::endl;
}