//Filename: Complex.cpp
//Description: This file is for the defines
//Author: Nicolas Wajs
//Date: 07.04.2022

#include "Complex.h"

//set the constructer
MyMath::Complex::Complex(f64_t f64Real, f64_t f64Img)
{
    f64Real_ = f64Real;
    f64Img_ = f64Img;
    std::cout << "Comlpex Constructer called!" << std::endl;
}

f64_t MyMath::Complex::f64Getf64Real()
{
    return f64Real_;
}

void MyMath::Complex::vSetf64Real(f64_t f64Realnew)
{
    f64Real_ = f64Realnew;
}

f64_t MyMath::Complex::f64Getf64Img()
{
    return f64Img_;
}

void MyMath::Complex::vSetf64Img(f64_t f64Imgnew)
{
    f64Img_ = f64Imgnew;
}

//calculate the absolut 
f64_t MyMath::Complex::f64GetAbs()
{
    f64_t f64Res;
    f64Res = pow((f64Getf64Real()*f64Getf64Real()) + (f64Getf64Img()*f64Getf64Img()), 0.5);
    return f64Res;
}

//calculate the argument
f64_t MyMath::Complex::f64GetArg()
{
    f64_t f64Res;
    f64Res = atan(f64Img_ / f64Real_);
    return f64Res;

}

////Print the results in two forms
//void MyMath::Complex::vPrintComplexNumber(void)
//{
//    std::cout << "Cartesian: " << f64Getf64Real() << " + " << f64Getf64Img() << "j" << std::endl;
//
//    std::cout << "Polarform: " << f64GetAbs() << " * exp(j(" << f64GetArg() << "))" << std::endl;
//}

/*
------------------KE07------------------
this is Z1

rValue is Z2
*/


MyMath::Complex MyMath::Complex::operator+(const Complex& rValue)
{
   Complex CDummy = { 0,0 };
   CDummy.f64Img_ = this->f64Img_ + rValue.f64Img_;
   CDummy.f64Real_ = this->f64Real_ + rValue.f64Real_;
   return CDummy;
}
MyMath::Complex MyMath::Complex::operator-(const Complex& rValue)
{
   Complex CDummy = { 0,0 };
   CDummy.f64Img_ = this->f64Img_ - rValue.f64Img_;
   CDummy.f64Real_ = this->f64Real_ - rValue.f64Real_;
   return CDummy;
}
MyMath::Complex MyMath::Complex::operator*(const Complex& rValue)
{
   Complex CDummy = { 0,0 };
   CDummy.f64Img_ = (this->f64Real_ * rValue.f64Real_) - (this->f64Img_ * rValue.f64Img_);
   CDummy.f64Real_ = (this->f64Real_ * rValue.f64Img_) + (this->f64Img_ * rValue.f64Real_);
   return CDummy;
}
MyMath::Complex MyMath::Complex::operator/(const Complex& rValue)
{
    f64_t f64RealDummy = 0;
    f64_t f64ImgDummy = 0;
    f64_t f64Nenner = 0;
    Complex CReturn = { 0,0 };

    f64Nenner = (rValue.f64Real_ * rValue.f64Real_ + rValue.f64Img_  * rValue.f64Img_);
    try {
        if (f64Nenner != 0)
        {
            f64RealDummy = (this->f64Real_ * rValue.f64Real_ + this->f64Img_ * rValue.f64Img_) / f64Nenner;
            f64ImgDummy = (this->f64Img_ * rValue.f64Real_ - this->f64Real_ * rValue.f64Img_) / f64Nenner;
            CReturn.f64Real_ = f64RealDummy;
            CReturn.f64Img_ = f64ImgDummy;
        }

        else
        {

            std::cout << "Game... Over!" << std::endl;
            throw std::runtime_error(std::string("Division by a complex number which is zero\n"));
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what();

    }
    
    return CReturn;
    
}
MyMath::Complex MyMath::Complex::operator~() 
{
    f64_t f64RealDummy;
    f64_t f64ImgDummy;
    f64_t f64Nenner;
    Complex CReturn = { 0,0 };

    f64Nenner = (this->f64Img_ * this->f64Img_ + this->f64Real_ * this->f64Real_);

    if (f64Nenner != 0)
    { 
        f64ImgDummy = -this->f64Img_ / f64Nenner;
        f64RealDummy = this->f64Real_ / f64Nenner;
        this->f64Img_ = f64ImgDummy;
        this->f64Real_ = f64RealDummy;
    }
    else
    {
        std::cout << "Game... Over!" << std::endl;
        throw std::runtime_error("Division by a complex number which is zero\n");
    }

    CReturn.f64Real_ = this->f64Real_;
    CReturn.f64Img_ = this->f64Img_;
    return CReturn;
}


std::ostream& MyMath::operator<<(std::ostream& lostream, const Complex& CValue)
{
    std::string stringvorzei = "";

    if (CValue.f64Img_ >= 0)
    {
        stringvorzei = " + ";
    }
    lostream << CValue.f64Real_ << stringvorzei << CValue.f64Img_ << std::endl;
    return lostream;
}