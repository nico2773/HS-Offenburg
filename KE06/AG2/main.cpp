//Filename: main.cpp
//Description: This file is for the main Programm
//Author: Nicolas Wajs
//Date: 10.05.2022

#include <iostream>
#include"INumberSelection.h"
static void vPrintLotteryNumbers(Lotto::LotteryNumbers ln);

int main()
{
    //Local LotteryNumber-Structur
    Lotto::LotteryNumbers Number;

    //Three static Selections
    Lotto::ManualSelection Manu;
    Lotto::RandomSelection Rando;
    Lotto::LinearSelection Lino;

    //Random
    std::cout << "              --RANDOM--\n" << std::endl;
    Rando.vSelectNumbers(Number);   //create Numbers
    vPrintLotteryNumbers(Number);   //display the Numbers
    //Manual 
    std::cout << "\n              --MANUAL--\n" << std::endl;
    Manu.vSelectNumbers(Number);    //create Numbers
    vPrintLotteryNumbers(Number);   //display the Numbers
    //Linear
    std::cout << "\n              --LINEAR--\n" << std::endl;
    for (uint8_t i32i = 0; i32i < 12; i32i++)
    {
        Lino.vSelectNumbers(Number);    //create Numbers
        vPrintLotteryNumbers(Number);   //display the Numbers
    }
    
   
}
static void vPrintLotteryNumbers(Lotto::LotteryNumbers ln) {
    for (uint32_t i32i = 0; i32i < 6; i32i++)
    {
        std::cout << "Die Zahl " << i32i + 1 << ": lautet: " << ln.au32Numbers_[i32i] << std::endl;
    }
}
