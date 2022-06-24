// AG2.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Ringbuffer.h"

// Aufgabe2.1 So the Class Queue can access the variables

int main()
{
	//MyDataStructures::Ringbuffer* pRB1 = new MyDataStructures::Ringbuffer(10U);		//Create Ringbuffer with 10 Elements
	MyDataStructures::Queue* pQueue1 = new MyDataStructures::Queue(5U);
	int32_t s32readdummy;
	pQueue1->vPrintRingBuffer();
	for (uint32_t i8i = 0; i8i < 5; i8i++)
	{

		pQueue1->s32WriteElement(i8i);
		pQueue1->s32WriteElementFront(3);
		pQueue1->s32ReadElement(s32readdummy);

	}
	
	// Copy Constructor is called 
	MyDataStructures::Queue* pQueue2 = new MyDataStructures::Queue(*pQueue1);
	// Move Constructor is called 
	MyDataStructures::Queue* pQueue3 = new MyDataStructures::Queue(std::move(*pQueue1));
	std::cout << "Print 1" << std::endl;
	pQueue1->vPrintRingBuffer();

	std::cout << "Print 2" << std::endl;
	pQueue2->vPrintRingBuffer();
	std::cout << "Print 3" << std::endl;
	pQueue3->vPrintRingBuffer();

	delete pQueue1;
	delete pQueue2;
	delete pQueue3;
}
