#include <iostream> 
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h> 
#include "Temperature.h" 
#include "Humidity.h" 
#include "Display.h" 
#include "FileLogger.h" 

static void vClientCode(void);

int main(void)
{
	vClientCode();
	_CrtDumpMemoryLeaks();
	return 0;
}
static void vClientCode(void)
{
	// Three Subjects 
	std::shared_ptr<MyDesignPattern::Temperature> pTemp1 = std::make_shared<MyDesignPattern::Temperature>("Temp1");
	std::shared_ptr<MyDesignPattern::Temperature> pTemp2 = std::make_shared<MyDesignPattern::Temperature>("Temp2");
	std::shared_ptr<MyDesignPattern::Humidity> pHumidity = std::make_shared<MyDesignPattern::Humidity>("Humidity bath");
	// Four Observers 
	std::shared_ptr<MyDesignPattern::Display> pDisplay1 = std::make_shared<MyDesignPattern::Display>("Display1");
	std::shared_ptr<MyDesignPattern::Display> pDisplay2 = std::make_shared<MyDesignPattern::Display>("Display2");
	std::shared_ptr<MyDesignPattern::FileLogger> pLoggerHum = std::make_shared<MyDesignPattern::FileLogger>("Humidity.txt");
	std::shared_ptr<MyDesignPattern::FileLogger> pLoggerTemp = std::make_shared<MyDesignPattern::FileLogger>("Temp1.txt");

	pTemp1->vAttach(pLoggerTemp);
	pTemp1->vAttach(pDisplay1);
	pTemp1->vAttach(pDisplay2);
	pTemp2->vAttach(pDisplay1);
	pHumidity->vAttach(pDisplay1);
	pHumidity->vAttach(pLoggerHum);
	pTemp1->vSetTemperature(29.5F);
	pTemp2->vSetTemperature(10.42F);
	pHumidity->vSetHumidity(80.0);
}