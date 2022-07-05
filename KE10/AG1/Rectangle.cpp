//Filename: Rectangle.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "Rectangle.h"

CAD::Rectangle::Rectangle() 
{
#ifdef _DEBUG
	std::cout << "Rectangle called" << std::endl;
#endif // _DEBUG
	u32NumberofInstances_c++;
}
CAD::Rectangle::~Rectangle() 
{
#ifdef _DEBUG
	std::cout << "~Rectangle called" << std::endl;
#endif // _DEBUG
	u32NumberofInstances_c--;
}

void CAD::Rectangle::vDraw() 
{
#ifdef _DEBUG
	std::cout << "vDraw called" << std::endl;
#endif // _DEBUG
	printf("Draw Rectangle");
}