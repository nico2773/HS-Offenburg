//Filename: CAD_Drawing.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 10.05.2022
#include "CAD_Drawing.h"

void CAD::CAD_Drawing::vDrawIt(void) {
#ifdef _DEBUG
	std::cout << "vDraw called" << std::endl;
#endif // _DEBUG

	for (auto it: setShapes_)
	{
		it->vDraw();
	}
}

void CAD::CAD_Drawing::vAddShape(Shape* pshape) {
	setShapes_.insert(pshape);
#ifdef _DEBUG
	std::cout << "vAddShape called" << std::endl;
#endif // _DEBUG
}

void CAD::CAD_Drawing::vRemoveShape(Shape* pshape) {
	setShapes_.erase(pshape);
#ifdef _DEBUG
	std::cout << "vRemoveShape called" << std::endl;
#endif // _DEBUG
}

CAD::CAD_Drawing::CAD_Drawing() {
#ifdef _DEBUG
	std::cout << "CAD_Drawing called" << std::endl;
#endif // _DEBUG
}
CAD::CAD_Drawing::~CAD_Drawing() {
#ifdef _DEBUG
	std::cout << "~CAD_Drawing called" << std::endl;
#endif // _DEBUG
}