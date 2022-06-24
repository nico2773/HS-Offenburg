#include <iostream> 
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h> 
#include "Decorator.h" 
#include "Sales.h" 

static void vClientCode(void);
int main(void)
{
	vClientCode();
	_CrtDumpMemoryLeaks();
	return 0;
}
static void vClientCode(void)
{
	MyDesignPattern::Sales MySales;
	MyDesignPattern::Beverage* pb1 = new MyDesignPattern::Espresso();
	MyDesignPattern::Beverage* pc1 = new MyDesignPattern::Whip(pb1);
	MyDesignPattern::Beverage* pc2 = new MyDesignPattern::Soy(pc1);
	MySales.AddBeverage(pc2);
	MyDesignPattern::Beverage* pb2 = new MyDesignPattern::HouseBlend();
	MyDesignPattern::Beverage* pc3 = new MyDesignPattern::Milk(pb2);
	MySales.AddBeverage(pc3);
	MyDesignPattern::Beverage* pb3 = new MyDesignPattern::DarkRoast();
	MySales.AddBeverage(pb3);

	MySales.vPrintAllBeverages();
	std::cout << "Total Sales: " << MySales.f64GetTotalSales() << std::endl;
	
}