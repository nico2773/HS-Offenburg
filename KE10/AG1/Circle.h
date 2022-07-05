//Filename: Circle.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "Shape.h"
namespace CAD {
	class Circle: public Shape{
	public:
		Circle();
		~Circle();
		void vDraw();
	protected:
	private:
	};
}