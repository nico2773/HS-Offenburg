#include "Complex.h"

int main()
{
	MyMath::Complex Z1(3., 4.);
	MyMath::Complex Z2(-1., -1.);
	MyMath::Complex Z3(2., -2.);
	MyMath::Complex Z4(0., -2.);
	MyMath::Complex Z5(0., 0.);
	Z1.vPrintComplexNumber();
	Z2.vPrintComplexNumber();
	Z3.vPrintComplexNumber();
	Z4.vPrintComplexNumber();
	Z5.vPrintComplexNumber();
}