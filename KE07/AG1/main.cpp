// KE07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Car.h"
//Warum gibt es in Bubblesort einen Fehler ?
//Weil so die ganze Klasse so nicht verglichen werden kann. Deswegen muss der Operator überladen werden.

int main()
{
	Vehicle::Car CarDummy = {0,0};

	Vehicle::Car Cars[5] = { {3000, 200} , {3050, 190}, {4095,400}, {3800,480}, {5060,900} };
	
	for (uint32_t u32i = 0; u32i < 5; u32i++)
	{
		Cars[u32i].vPrintIt();

	}
	
	for (uint32_t i32i = 0; i32i < (5); i32i++)
	{
		for (uint32_t j32i = 0; j32i < ((5 - 1) - i32i); j32i++)
		{
			if (Cars[j32i] > Cars[j32i+1])
			{
				CarDummy = Cars[j32i + 1];
					Cars[j32i + 1] = Cars[j32i];
					Cars[j32i] = CarDummy;
			}
		}
	}
}
