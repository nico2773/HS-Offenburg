//Filename: main.cpp
//Description: This file is for the main function
//Author: Nicolas Wajs
//Date: 25.04.2022
#include "Ringbuffer.h"

//Channels
#define CHANNEL_0 0
#define CHANNEL_1 1
#define CHANNEL_2 2

#define _CRTDBG_MAP_ALLOC 
#include <cstdlib>
#include <crtdbg.h>

void vTestCreateObject(void);

int main()
{
	vTestCreateObject();

	_CrtDumpMemoryLeaks(); //Memory Leaks
	return 0;
}

void vTestCreateObject(void)
{
	std::cout << "--statisches Object--" << std::endl;
	MyDataStructures::IOChannel IOChannel1;

	std::cout << "--dynamisches Object--" << std::endl;
	MyDataStructures::IOChannel* pIOChannel2 = new MyDataStructures::IOChannel;

	int32_t s32Read = 0;
	int32_t s32Var = 31;
	int32_t s32Var1 = 27;

	//Test with static allocation
	IOChannel1.s32WriteElementToChannel(CHANNEL_0, s32Var1);

	IOChannel1.s32ReadElementFromChannel(CHANNEL_0, s32Read);

	IOChannel1.s32WriteElementToChannel(CHANNEL_1, s32Var);

	IOChannel1.s32ReadElementFromChannel(CHANNEL_1, s32Var);

	IOChannel1.vPrint(CHANNEL_0);		//Print Channel 0
	IOChannel1.vPrint(CHANNEL_1);		//Print Channel 1
	IOChannel1.vPrint(CHANNEL_0);		//Print Channel 0

	
	//Test with Dynamic allocation
	pIOChannel2->s32WriteElementToChannel(CHANNEL_0, s32Var1);

	pIOChannel2->s32ReadElementFromChannel(CHANNEL_0, s32Read);

	pIOChannel2->s32WriteElementToChannel(CHANNEL_1, s32Var);

	pIOChannel2->s32ReadElementFromChannel(CHANNEL_1, s32Var);

	pIOChannel2->vPrint(CHANNEL_0);		//Print Channel 0
	pIOChannel2->vPrint(CHANNEL_1);		//Print Channel 1
	pIOChannel2->vPrint(CHANNEL_0);		//Print Channel 0

	std::cout << "--Delete for--" << std::endl;
	delete (pIOChannel2);					//Deleting Dynamic Memory
	std::cout << "--Delete after--" << std::endl;
}