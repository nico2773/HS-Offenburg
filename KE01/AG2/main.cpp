//Filename: main.cpp
//Description: This file is for the main Programm
//Author: Nicolas Wajs
//Date: 07.04.2022

#include <iostream>
#include <string>

#define _CRT_UNUSED

typedef float f32_t;


enum class FileAccessMode
{
    Read = 0,
    Write,
    ReadWrite
};

void vOpenFile(const uint8_t* cpu8File, FileAccessMode eFileAccessMode = FileAccessMode::ReadWrite);
f32_t f32Add(f32_t f32Val1, f32_t f32Val2, f32_t f32Val3 = 69);

int main()
{
    const uint8_t* pf = nullptr;
    FileAccessMode eFileAccessMode1 = FileAccessMode::Read;
    f32_t f32Val1 = 3.5;
    f32_t f32Val2 = 43.2;
    f32_t f32Val3 = 98.8;
    f32_t f32Return;
    std::string String1 = "Hallo C++";
    std::string String2;

    // Aufgabe 1
    vOpenFile(pf, eFileAccessMode1);

    //Aufgabe 2
    std::cout << "Add mit 2: " << f32Add(f32Val1, f32Val2) << std::endl;
    std::cout << "Add mit 3: " << f32Add(f32Val1, f32Val2, f32Val3) << std::endl;

    //Aufgabe 3
    std::cout << String1 << "\nLaenge: " <<String1.length() << std::endl;
    std::cin >> String2;
    std::cout << String2 << std::endl;
    std::cout << String1 + String2 << std::endl;

}

void vOpenFile(const uint8_t* cpu8File, FileAccessMode eFileAccessMode){}

f32_t f32Add(f32_t f32Val1, f32_t f32Val2, f32_t f32Val3) 
{
    return f32Val1 + f32Val2 + f32Val3;
}
