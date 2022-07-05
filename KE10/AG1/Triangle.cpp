//Filename: Triangle.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "Triangle.h"

CAD::Triangle::Triangle() 
{
#ifdef _DEBUG
	std::cout << "Triangle called" << std::endl;
#endif // _DEBUG
	u32NumberofInstances_c += 1;
}
CAD::Triangle::~Triangle() 
{
#ifdef _DEBUG
	std::cout << "~Triangle called" << std::endl;
#endif // _DEBUG
	u32NumberofInstances_c -= 1;
}

void CAD::Triangle::vDraw() 
{
#ifdef _DEBUG
	std::cout << "vDraw called" << std::endl;
#endif // _DEBUG
	printf("Draw Triangle");
}