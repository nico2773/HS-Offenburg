#include "Ringbuffer.h"


int main()
{
	MyDataStructures::Ringbuffer Ring1;
	Ring1.vPrintRingBuffer();

	std::cout << "Schreiben:" << std::endl;
	for (int32_t i = 10; i < 15; i++)
	{
		std::cout << "WriteElement with Val: " << i << ", with return value " << Ring1.s32WriteElement(i) << std::endl;
	}

	std::cout << "Lesen: " << std::endl;
	for (int32_t i = 10; i < 12; i++)
	{
		std::cout << "ReadElement with Val: " << i << ", with return value " << Ring1.s32ReadElement(i) << std::endl;
	}
	Ring1.vPrintRingBuffer();













}