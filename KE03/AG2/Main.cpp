#include "Ringbuffer.h"
#include <ostream>
#define _CRTDBG_MAP_ALLOC
//MyDataStructures::Ringbuffer RingGlobal1();
MyDataStructures::Ringbuffer RingGlobal2;


void vTestCreateObjectsRingbuffer(void);

//Globale Variablen sind im Data Segment
//Lokale Variablen sind im Stack Segment
//Dynamische Variablen sind im Heap Segment

//Aufgabe 1.6
//•	 The copy assignment operator
//•	 The move assignment operator

int main()
{
	vTestCreateObjectsRingbuffer();
	_CrtDumpMemoryLeaks();
	return 0;
}

void vTestCreateObjectsRingbuffer(void)
{
	//MyDataStructures::Ringbuffer RingLokal1(); Glaubt functions
	MyDataStructures::Ringbuffer RingLokal1;
	MyDataStructures::Ringbuffer* RingDyn1 = new MyDataStructures::Ringbuffer();
	MyDataStructures::Ringbuffer* RingDyn2 = new MyDataStructures::Ringbuffer;

	std::cout << "Global: " << std::endl;
	RingGlobal2.vPrintRingbufferMembersValueAndAddress();
	std::cout << sizeof(RingGlobal2) << std::endl;

	std::cout << "Lokal Statisch: " << std::endl;
	RingLokal1.vPrintRingbufferMembersValueAndAddress();
	std::cout << sizeof(RingLokal1) << std::endl;

	std::cout << "Lokal Dynamisch1: " << std::endl;
	RingDyn1->vPrintRingbufferMembersValueAndAddress();
	std::cout << sizeof(RingDyn1) << std::endl;

	std::cout << "Lokal Dynamisch2: " << std::endl;
	RingDyn2->vPrintRingbufferMembersValueAndAddress();
	std::cout << sizeof(RingDyn2) << std::endl;


	delete RingDyn1;
	delete RingDyn2;
}