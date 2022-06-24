#pragma once

#include <ostream>
#include <iostream>
#include <stdio.h>
#include <stdint.h>

#define RINGBUFFER_OKAY 0 
#define RINGBUFFER_FULL -1 
#define RINGBUFFER_EMPTY -2
#define RINGBUFFER_NULLPTR -3
#define RINGBUFFER_MAXELEMENTS 8 

namespace MyDataStructures
{

	class Ringbuffer
	{
	public:
		Ringbuffer(uint32_t u32SizeOfBuffer_) noexcept;
		//Ringbuffer(void);
		//Ringbuffer() noexcept;
		~Ringbuffer() noexcept;
		Ringbuffer(const Ringbuffer& rotherRingbuffer);//Copy
		Ringbuffer(const Ringbuffer&& rotherRingbuffer) noexcept;//Move
		int32_t s32ReadElement(int32_t& rs32Element);
		int32_t s32WriteElement(const int32_t& rs32Element);
		void vPrintRingBuffer(void) const;

		void vPrintRingbufferMembersValueAndAddress(void) const noexcept;

		

	protected:
	private:
		uint32_t u32ReadPos_;
		uint32_t u32WritePos_;
		uint32_t u32NumberofElements_;
		int32_t* ps32Buffer_;
		uint32_t u32SizeOfBuffer_ = 6;
		//int32_t as32E_[RINGBUFFER_MAXELEMENTS];
	};
}