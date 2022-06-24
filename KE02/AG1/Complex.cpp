#include "Complex.h"

//Construktor
MyMath::Complex::Complex(f64_t f64Real, f64_t f64Img)
{
	f64Real_ = f64Real;
	f64Img_ = f64Img;
}

MyMath::Complex::~Complex()
{
	std::cout << "De constructor aufgerufen" << std::endl;
}

//Getter
f64_t MyMath::Complex::f64Getf64Img()
{
	return f64Img_;
}
f64_t MyMath::Complex::f64Getf64Real()
{
	return f64Real_;
}
//Setter
void MyMath::Complex::vSetf64Real(f64_t f64Realnew)
{
	f64Real_ = f64Realnew;
}
void MyMath::Complex::vSetf64Img(f64_t f64Imgnew)
{
	f64Img_ = f64Imgnew;
}

f64_t MyMath::Complex::f64GetAbs(void)
{
	f64_t f64Return = sqrt((f64Real_ * f64Real_) + (f64Img_ * f64Img_));
	return f64Return;
}
f64_t MyMath::Complex::f64GetArg(void)
{
	f64_t f64Return = atan(f64Img_/f64Real_)*180/3.14159;
	return f64Return;
}

void MyMath::Complex::vPrintComplexNumber(void)
{
	std::cout << "Cartesian Coordinates: " << f64Real_ << " + j(" << f64Img_ << ")" << std::endl;
	std::cout << "PolarCoordinates: " << f64GetAbs() << " * e^(j" << f64GetArg() << ")" << std::endl;
}