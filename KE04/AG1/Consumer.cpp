#include "Consumer.h"

int32_t Client::Consumer::s32ReadFromRingbuffer(int32_t& s32Value1)
{
	return pMyRingBuffer->s32ReadElement(s32Value1);
}

Client::Consumer::Consumer(MyDataStructures::Ringbuffer* pRingbuffer)
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
