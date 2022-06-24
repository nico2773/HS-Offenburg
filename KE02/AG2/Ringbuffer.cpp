#pragma once

#include "Ringbuffer.h"

MyDataStructures::Ringbuffer::Ringbuffer()
{
	u32ReadPos_ = 0;
	u32WritePos_ = 0;
	u32NumberofElements_ = 0;
	for (int32_t i = 0; i < RINGBUFFER_MAXELEMENTS; i++)
	{
		as32E_[i] = 0;
	}
}

MyDataStructures::Ringbuffer::~Ringbuffer()
{
	std::cout << "Deconstruktor" << std::endl;
}

void MyDataStructures::Ringbuffer::vPrintRingBuffer(void)
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
		std::cout << as32E_[i] << "\t";
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
	if (u32NumberofElements_ < RINGBUFFER_MAXELEMENTS)
	{
		as32E_[u32WritePos_] = rs32Element;
		u32NumberofElements_++;
		u32WritePos_++;
		i32State = RINGBUFFER_OKAY;
	}
	else
	{
		u32WritePos_ = 0;
	}
	return i32State;
}

int32_t MyDataStructures::Ringbuffer::s32ReadElement(int32_t& rs32Element) 
{
	int32_t i32State = RINGBUFFER_EMPTY;
	if ((u32NumberofElements_ > 0) && (u32NumberofElements_ < RINGBUFFER_MAXELEMENTS) && (u32ReadPos_ <= u32WritePos_))
	{
		i32State = RINGBUFFER_OKAY;
		u32NumberofElements_--;
		u32ReadPos_++;
		as32E_[u32ReadPos_] = rs32Element;
	}
	else
	{
		u32ReadPos_ = 0;
	}
	return i32State;

}