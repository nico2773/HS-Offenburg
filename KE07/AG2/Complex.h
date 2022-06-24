//Filename: Complex.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 07.04.2022
#pragma once
#include <cstdlib>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
#include <exception>

typedef double f64_t;
typedef float f32_t;

namespace MyMath        //declare namespace
{
    class Complex;
    std::ostream& operator<<(std::ostream& lostream, const Complex& CValue);

    class Complex       //declare class
    {
    public:
        //Functions
        Complex(f64_t f64Real, f64_t f64Img);

        f64_t f64Getf64Real(void);
        void vSetf64Real(f64_t f64Realnew);
        f64_t f64Getf64Img(void);
        void vSetf64Img(f64_t f64Imgnew);

        f64_t f64GetAbs(void);
        f64_t f64GetArg(void);

        //void vPrintComplexNumber(void);

        Complex operator+(const Complex& rValue);
        Complex operator-(const Complex& rValue);
        Complex operator*(const Complex& rValue);
        Complex operator/(const Complex& rValue);
        Complex operator~();
        friend std::ostream& operator<<(std::ostream& lostream, const Complex& CValue);

    protected:
    private:
        //Variable
        f64_t f64Real_;
        f64_t f64Img_;
    };
}