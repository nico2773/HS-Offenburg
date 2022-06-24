#pragma once


#include <iostream>
#include <stdint.h>
#include <ostream>
#define _USE_MATH_DEFINES
#include <cmath>

typedef double f64_t;
typedef float f32_t;

namespace MyMath
{
	class Complex
	{
	public:
		Complex(f64_t f64Real, f64_t f64Img);
		~Complex();
		f64_t f64Getf64Real(void);
		void vSetf64Real(f64_t f64Realnew);
		f64_t f64Getf64Img(void);
		void vSetf64Img(f64_t f64Imgnew);

		f64_t f64GetAbs(void);
		f64_t f64GetArg(void);

		void vPrintComplexNumber(void);

	protected:
	private:
		f64_t f64Real_;
		f64_t f64Img_;
	};
}