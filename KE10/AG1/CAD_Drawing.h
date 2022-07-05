//Filename: CAD_Drawing.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 10.05.2022

#pragma once
#include <set> 
#include "Shape.h" 
#include "Triangle.h" 
#include "Circle.h" 
#include "Rectangle.h"
#include <iostream>
namespace CAD
{
	class CAD_Drawing
	{
	private:
		std::set<std::shared_ptr<Shape>> setShapes_;
	public:
		CAD_Drawing(void);
		~CAD_Drawing(void);
		void vAddShape(std::shared_ptr<Shape>);
		void vRemoveShape(std::shared_ptr<Shape>);
		void vDrawIt(void);
	};
}