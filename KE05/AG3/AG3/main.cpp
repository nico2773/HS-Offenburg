//Filename: main.cpp
//Description: This file is for the main Programm
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "Ringbuffer.h"

void vTestCreateObjects();

int main()
{
	vTestCreateObjects();

	_CrtDumpMemoryLeaks(); //check for memory leaks
	
	return 0;
}


void vTestCreateObjects(void)
{
	MyDataStructures::Ringbuffer Ring1;
	MyDataStructures::Queue Queue1;
	int32_t s32ReadDummy = 0;

	Ring1.s32WriteElement(22);
	Ring1.s32WriteElement(25);
	Ring1.s32WriteElement(23);
	Ring1.s32ReadElement(s32ReadDummy);

	Queue1.s32WriteElement(12);
	Queue1.s32WriteElement(18);
	Queue1.s32ReadElement(s32ReadDummy);
	Queue1.s32WriteElementFront(30);

	MyDataStructures::RingbufferPrint::vPrint(Ring1);
	MyDataStructures::RingbufferPrint::vPrintMembersValueAndAddress(Ring1);

	MyDataStructures::RingbufferPrint::vPrint(Queue1);
	MyDataStructures::RingbufferPrint::vPrintMembersValueAndAddress(Queue1);
}

