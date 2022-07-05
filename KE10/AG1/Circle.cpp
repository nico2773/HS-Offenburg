//Filename: Circle.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "Circle.h"

CAD::Circle::Circle() 
{
#ifdef _DEBUG
	std::cout << "Circle called" << std::endl;
#endif // _DEBUG
	u32NumberofInstances_c++;
}
CAD::Circle::~Circle() 
{
#ifdef _DEBUG
	std::cout << "~Circle called" << std::endl;
#endif // _DEBUG
	u32NumberofInstances_c--;
}

void CAD::Circle::vDraw() 
{
#ifdef _DEBUG
	std::cout << "vDraw called" << std::endl;
#endif // _DEBUG
	printf("Draw Circle");
}