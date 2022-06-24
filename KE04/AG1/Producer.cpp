#include "Producer.h"

int32_t Client::Producer::s32WriteToRingbuffer(const int32_t& s32Value1)
{
	return pMyRingBuffer->s32WriteElement(s32Value1);
}

Client::Producer::Producer(MyDataStructures::Ringbuffer* pRingbuffer)
{
	if (pRingbuffer != nullptr)
	{
		pMyRingBuffer = pRingbuffer;
	}
	else
	{
		std::cout << "\n--Sanity Check failed--\n" << std::endl;
	}
}

