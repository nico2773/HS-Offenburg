//Filename: Shape.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "Shape.h"

uint32_t CAD::Shape::u32NumberofInstances_c = 0;


CAD::Shape::Shape() 
{
#ifdef _DEBUG
	std::cout << "~Shape called" << std::endl;
#endif // _DEBUG
	/*CAD::Shape::u32NumberofInstances_c = 0;*/
}

CAD::Shape::~Shape() 
{
#ifdef _DEBUG
	std::cout << "~Shape called" << std::endl;
#endif // _DEBUG
}

uint32_t CAD::Shape::u32GetNumberofInstances() 
{
#ifdef _DEBUG
	std::cout << "u32GetNumberofInstances called" << std::endl;
#endif // _DEBUG
	return u32NumberofInstances_c;
}

