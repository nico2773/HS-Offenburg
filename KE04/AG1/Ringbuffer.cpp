#pragma once

#include "Ringbuffer.h"

MyDataStructures::Ringbuffer::Ringbuffer(uint32_t u32SizeOfBuffer_) noexcept
{
	u32ReadPos_ = 0;
	u32WritePos_ = 0;
	u32NumberofElements_ = 0;

	ps32Buffer_ = new int32_t[u32SizeOfBuffer_];
	for (int32_t i = 0; i < u32SizeOfBuffer_; i++)
	{
		ps32Buffer_[i] = 0;
	}
}

MyDataStructures::Ringbuffer::~Ringbuffer()
{
	std::cout << "Deconstruktor" << std::endl;
	if (ps32Buffer_ == nullptr)
	{
		delete[] ps32Buffer_;
	}
}

void MyDataStructures::Ringbuffer::vPrintRingBuffer(void) const
{
	std::cout << "u32NumberElements_: " << u32NumberofElements_ << std::endl;
	std::cout << "uiWritePos_" << std::endl;
	for (uint32_t i = 0; i < u32WritePos_; i++)
	{
		std::cout << "\t";
	}
	std::cout << "|" << std::endl;

	for (uint32_t i = 0; i < RINGBUFFER_MAXELEMENTS; i++)
	{
		std::cout << ps32Buffer_[i] << "\t";
	}
	std::cout << std::endl;

	for (uint32_t i = 0; i < u32ReadPos_; i++)
	{
		std::cout << "\t";
	}
	std::cout << "|" << std::endl;
	std::cout << "u32ReadPos_" << std::endl;
}


int32_t MyDataStructures::Ringbuffer::s32WriteElement(const int32_t& rs32Element)
{
	
	int32_t i32State = RINGBUFFER_FULL;
	if (ps32Buffer_ != nullptr)
	{

		if (u32NumberofElements_ < RINGBUFFER_MAXELEMENTS)
		{
			ps32Buffer_[u32WritePos_] = rs32Element;
			u32NumberofElements_++;
			u32WritePos_++;
			i32State = RINGBUFFER_OKAY;
		}
		else
		{
			u32WritePos_ = 0;
		}
	}
	else
	{
		i32State = RINGBUFFER_NULLPTR;
	}
	return i32State;
}

int32_t MyDataStructures::Ringbuffer::s32ReadElement(int32_t& rs32Element) 
{
	int32_t i32State = RINGBUFFER_EMPTY;
	if (ps32Buffer_ != nullptr)
	{

		if ((u32NumberofElements_ > 0) && (u32NumberofElements_ < RINGBUFFER_MAXELEMENTS) && (u32ReadPos_ <= u32WritePos_))
		{
			i32State = RINGBUFFER_OKAY;
			u32NumberofElements_--;
			u32ReadPos_++;
			ps32Buffer_[u32ReadPos_] = rs32Element;
		}
		else
		{
			u32ReadPos_ = 0;
		}
	}
	else
	{
		i32State = RINGBUFFER_NULLPTR;
	}
	return i32State;

}

void MyDataStructures::Ringbuffer::vPrintRingbufferMembersValueAndAddress(void) const noexcept
{
	std::cout << std::hex;
	std::cout << "-----------------RingbufferMembers-----------------" << std::endl;
	std::cout << "u32ReadPos_:" << "\t\t\t" << u32ReadPos_ << "\t\t" << &u32ReadPos_ << std::endl;
	std::cout << "u32WritePos_:" << "\t\t\t" << u32WritePos_ << "\t\t" << &u32WritePos_ << std::endl;
	std::cout << "u32NumberofElements_:" << "\t\t" << u32NumberofElements_ << "\t\t" << &u32NumberofElements_ << std::endl;
	std::cout << "as32Elements_[0]:" << "\t\t" << ps32Buffer_[0] << "\t\t" << &ps32Buffer_[0] << std::endl;
	std::cout << "-----------------END-----------------" << std::endl;
	std::cout << std::dec;
}

MyDataStructures::Ringbuffer::Ringbuffer(const Ringbuffer& rotherRingbuffer)
{
	
}

MyDataStructures::Ringbuffer::Ringbuffer(const Ringbuffer&& rotherRingbuffer) noexcept
{
	
}

