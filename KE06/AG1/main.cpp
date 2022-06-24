//Filename: main.cpp
//Description: This file is for the main Programm
//Author: Nicolas Wajs
//Date: 10.05.2022

#include <iostream>
#include "CAD_Drawing.h"


#define _CRTDBG_MAP_ALLOC


void vTest_CAD_Drawing(void);

int main()
{
    vTest_CAD_Drawing();
    _CrtDumpMemoryLeaks();

    return 0;
}


void vTest_CAD_Drawing(void)
{
    std::cout << "--statisches Object Rectangle--" << std::endl;
    CAD::Rectangle Rectangle;
    Rectangle.vDraw();
    std::cout << "\n\n" << Rectangle.u32GetNumberofInstances() << std::endl;

    CAD::Rectangle Rectangle2;
    Rectangle2.vDraw();
    std::cout << "\n\n" << Rectangle2.u32GetNumberofInstances() << std::endl;

    CAD::Circle Circle;
    Circle.vDraw();
    std::cout << "\n\n" << Circle.u32GetNumberofInstances() << std::endl;
   

    std::cout << "--Dynamisch Object Rectangle--" << std::endl;
    CAD::Rectangle* RectangleDyn = new CAD::Rectangle;
    //CAD::CAD_Drawing Drawing;
    RectangleDyn->vDraw();
 /*   Drawing.vAddShape(&Circle);*/
    std::cout << RectangleDyn->u32GetNumberofInstances() << std::endl;
    CAD::CAD_Drawing Draw;

    Draw.vAddShape(RectangleDyn);

    delete (RectangleDyn);
}