#include "Decorator.h"

//-----------Getränke-----------
//Espresso
f64_t MyDesignPattern::Espresso::f64Cost() const
{
	return 1.5;
}
std::string MyDesignPattern::Espresso::strGetDescription()const
{
	return "Esspresso ";
}

//Decaf
f64_t MyDesignPattern::Decaf::f64Cost()const
{
	return 1.6;
}
std::string MyDesignPattern::Decaf::strGetDescription()const
{
	return "Decaf ";
}

//HouseBlend
f64_t MyDesignPattern::HouseBlend::f64Cost()const
{
	return 1.2;
}
std::string MyDesignPattern::HouseBlend::strGetDescription()const
{
	return "HouseBlend ";
}

//DarkRoast
f64_t MyDesignPattern::DarkRoast::f64Cost()const
{
	return 2.0;
}
std::string MyDesignPattern::DarkRoast::strGetDescription()const
{
	return "DarkRoast ";
}

//Cocoa
f64_t MyDesignPattern::Cocoa::f64Cost()const
{
	return 3.0;
}
std::string MyDesignPattern::Cocoa::strGetDescription()const
{
	return "Cocoa ";
}

//-----------Zutaten-----------
//Milk
f64_t MyDesignPattern::Milk::f64Cost()const
{
	return 0.25 + beverage_->f64Cost();
}
std::string MyDesignPattern::Milk::strGetDescription()const
{
	return "Milk " + beverage_->strGetDescription();
}
MyDesignPattern::Milk::Milk(Beverage* beverage)
{
	this->beverage_ = beverage;
}

//Mocha
f64_t MyDesignPattern::Mocha::f64Cost() const
	{
		return 0.30 + beverage_->f64Cost();
	}
std::string MyDesignPattern::Mocha::strGetDescription()const 
{
	return "Mocha " + beverage_->strGetDescription();
}
MyDesignPattern::Mocha::Mocha(Beverage* beverage)
{
	this->beverage_ = beverage;
}

//Soy
f64_t MyDesignPattern::Soy::f64Cost() const
{
	return 0.20 + beverage_->f64Cost();
}
std::string MyDesignPattern::Soy::strGetDescription() const 
{
	return "Mocha " + beverage_->strGetDescription();
}
MyDesignPattern::Soy::Soy(Beverage* beverage)
{
	this->beverage_ = beverage;
}

//Whip
MyDesignPattern::Whip::Whip(Beverage* beverage) 
{
	this->beverage_ = beverage;
}
f64_t MyDesignPattern::Whip::f64Cost() const
{
	return 0.35 + beverage_->f64Cost();
}
std::string MyDesignPattern::Whip::strGetDescription() const
	{
		return "Whip " + beverage_->strGetDescription();
	}

//Cocoa
MyDesignPattern::Sugar::Sugar(Beverage* beverage)
{
	this->beverage_ = beverage;
}
f64_t MyDesignPattern::Sugar::f64Cost() const
{
	return 0.35 + beverage_->f64Cost();
}
std::string MyDesignPattern::Sugar::strGetDescription() const
{
	return "Sugar " + beverage_->strGetDescription();
}