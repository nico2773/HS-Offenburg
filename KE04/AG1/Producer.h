#pragma once
#include "Ringbuffer.h"
namespace Client
{
	class Producer
	{
	public:
		Producer(MyDataStructures::Ringbuffer* pRingbuffer);
		//~Producer() noexcept;

		int32_t s32WriteToRingbuffer(const int32_t& s32Value1);
	protected:
	private:
		MyDataStructures::Ringbuffer* pMyRingBuffer;
	};
}