#pragma once
#include "Ringbuffer.h"
namespace Client
{
	class Consumer
	{
	public:
		Consumer(MyDataStructures::Ringbuffer* pRingbuffer);
		//~Consumer() noexcept;

		int32_t s32ReadFromRingbuffer(int32_t& s32Value1);
	protected:
	private:
		MyDataStructures::Ringbuffer* pMyRingBuffer;

	};
}