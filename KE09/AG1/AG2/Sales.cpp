#include "Sales.h"
#include "Decorator.h"
#include <ostream>
#include<stdio.h>



void MyDesignPattern::Sales::AddBeverage(MyDesignPattern::Beverage* BeverageAdd)
{
	VectorBeverages_.push_back(BeverageAdd);
}

f64_t MyDesignPattern::Sales::f64GetTotalSales()
{
	f64_t f64Return = 0;
	for (auto ait : VectorBeverages_)
	{
		f64Return = f64Return + ait->f64Cost();
	}
	return f64Return;
}

void MyDesignPattern::Sales::vPrintAllBeverages()
{
	for (auto ait : VectorBeverages_)
	{
		std::cout << ait->strGetDescription() << "kostet Gesamt: " << ait->f64Cost() << std::endl;
	}
}

MyDesignPattern::Sales::~Sales() 
{
#ifdef _DEBUG
	std::cout << "Deconstructor Sales" << std::endl;
#endif
	for (auto ait : VectorBeverages_)
	{
		vDeleteBeveragesRecursive(ait);
	}
	
}

void MyDesignPattern::Sales::vDeleteBeveragesRecursive(MyDesignPattern::Beverage* ait)
{
		if (dynamic_cast<MyDesignPattern::CondimentDecorator*>(ait) == nullptr)
		{
			delete ait;
		}
		else
		{
			vDeleteBeveragesRecursive(dynamic_cast<MyDesignPattern::CondimentDecorator*>(ait)->getCondimentDecorator());
			delete ait;
		}
}