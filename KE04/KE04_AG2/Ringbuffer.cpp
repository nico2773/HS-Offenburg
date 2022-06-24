//Filename: Ringbuffer.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 25.04.2022
#include "Ringbuffer.h"
#include <cassert>

MyDataStructures::Ringbuffer::Ringbuffer(uint32_t u32SizeOfBuffer_) noexcept
{
	u32ReadPos_ = 0;
	u32WritePos_ = 0;
	u32NumberElements_ = 0;

	
	ps32Buffer_ = new int32_t[u32SizeOfBuffer_]; // without zeroing � How to zeroing? 


	for (uint8_t i = 0; i < RINGBUFFER_MAXELEMENTS; i++)
	{
		as32E[i] = 0;
	}
	std::cout << "--Constructor of Ringbuffer called--" << std::endl;
}

MyDataStructures::Ringbuffer::~Ringbuffer() noexcept
{
	if (ps32Buffer_ != nullptr)
	{
		delete[] ps32Buffer_;					// Deletes arrays of objects 

		std::cout << "--Destructor of Ringbuffer called--" << std::endl;
	}
}

MyDataStructures::Ringbuffer::Ringbuffer(const Ringbuffer& rotherRingbuffer)		//Copy 
{
#ifdef _DEBUG
	std::cout << "\n--Copyconstruktor called--\n" << std::endl;
#endif
	u32ReadPos_ = rotherRingbuffer.u32ReadPos_;
	u32WritePos_ = rotherRingbuffer.u32WritePos_;
	u32NumberElements_ = rotherRingbuffer.u32NumberElements_;
	u32SizeOfBuffer_ = rotherRingbuffer.u32SizeOfBuffer_;

	ps32Buffer_ = new int32_t[u32SizeOfBuffer_];
	memcpy(ps32Buffer_, rotherRingbuffer.ps32Buffer_, u32SizeOfBuffer_ * sizeof(int32_t));

}

MyDataStructures::Ringbuffer::Ringbuffer(Ringbuffer&& rotherRingbuffer) noexcept		//Move
{
#ifdef _DEBUG
	std::cout << "\n--Moveconstruktor called--\n" << std::endl;
#endif

	u32ReadPos_ = rotherRingbuffer.u32ReadPos_;
	rotherRingbuffer.u32ReadPos_ = 0;

	u32WritePos_ = rotherRingbuffer.u32WritePos_;
	rotherRingbuffer.u32WritePos_ = 0;

	u32NumberElements_ = rotherRingbuffer.u32NumberElements_;
	rotherRingbuffer.u32NumberElements_ = 0;

	u32SizeOfBuffer_ = rotherRingbuffer.u32SizeOfBuffer_;
	rotherRingbuffer.u32SizeOfBuffer_ = 0;

	ps32Buffer_ = rotherRingbuffer.ps32Buffer_;
	rotherRingbuffer.ps32Buffer_ = nullptr;
}

void MyDataStructures::Ringbuffer::vPrintRingbufferMembersValueAndAddress(void) const noexcept 
{
	std::cout << std::hex;
	std::cout << "--RingBufferMembers--" << std::endl;
	std::cout << "WritePos: \t\t" << u32WritePos_ << "\t" << &u32WritePos_ << std::endl;
	std::cout << "ReadPos: \t\t" << u32ReadPos_ << "\t" << &u32ReadPos_ << std::endl;
	std::cout << "NumberofElements: \t" <<u32NumberElements_ << "\t" << & u32NumberElements_ << std::endl;
	std::cout << "as32E[0]: \t\t" << as32E[0] << "\t" << &as32E[0] << std::endl;
	std::cout << std::dec;
}

void MyDataStructures::Ringbuffer::vPrintRingBuffer()
{
	//Print all Status Parameter
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Number of Elements: " << u32NumberElements_ << std::endl;
	std::cout << "Write Position: " << u32WritePos_ << std::endl;
	std::cout << "Read Position: " << u32ReadPos_ << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "\t\t3: " << as32E[3] << "\t4: " << as32E[4] << std::endl;
	std::cout << "\n\n" << std::endl;
	std::cout << "\t2: " << as32E[2] << "\t\t\t5: " << as32E[5] << std::endl;
	std::cout << "\n\n" << std::endl;
	std::cout << "\t1: " << as32E[1] << "\t\t\t6: " << as32E[6] << std::endl;
	std::cout << "\n\n" << std::endl;
	std::cout << "\t\t0: " << as32E[0] << "\t7: " << as32E[7] << std::endl;

}
 
int32_t MyDataStructures::Ringbuffer::s32ReadElement(int32_t &rs32Element)
{

	int32_t i32State = RINGBUFFER_EMPTY;
	(void)&rs32Element;
	if (ps32Buffer_ != nullptr) {

		if (u32NumberElements_ > 0)
		{
			i32State = RINGBUFFER_OKAY;
			u32ReadPos_++;
			u32NumberElements_--;
		}
		else
		{
			u32ReadPos_ = 0;
		}
		return i32State;
	}
	else
	{
		return RINGBUFFER_NULLPTR; //if sanity check fails
	}
}

int32_t MyDataStructures::Ringbuffer::s32WriteElement(const int32_t &rs32Element)
{
	int32_t i32State = RINGBUFFER_FULL;
	if (ps32Buffer_ != 0)
	{
		if (u32NumberElements_ < RINGBUFFER_MAXELEMENTS)
		{
			as32E[u32WritePos_] = rs32Element;
			i32State = RINGBUFFER_OKAY;
			u32NumberElements_++;
			u32WritePos_++;
		}
		else
		{
			u32WritePos_ = 0;
		}
		return i32State;
	}
	else
	{
	return RINGBUFFER_NULLPTR; //if sanity check fails
	}
}

MyDataStructures::IOChannel::IOChannel() : Channels{10U,10U,10U}		//Function for Constracor IOChannel
{
#ifdef _DEBUG
	std::cout << "\n--IOChannelconstruktor called--\n"  << std::endl;
#endif
}

MyDataStructures::IOChannel::~IOChannel() noexcept						//Function for Deconstracor IOChannel
{
#ifdef _DEBUG
	std::cout << "\n--IOChanneldeconstruktor called--\n" << std::endl;
#endif
}
int32_t MyDataStructures::IOChannel::s32WriteElementToChannel(uint32_t u32Channel, const int32_t& rs32Element)	//Function for Channel Write 
{
	assert(u32Channel < 3U);
	return Channels[u32Channel].s32WriteElement(rs32Element);
}
int32_t MyDataStructures::IOChannel::s32ReadElementFromChannel(uint32_t u32Channel, int32_t& rs32Element)		//Function for Channel Read
{
	assert(u32Channel < 3U);
	return Channels[u32Channel].s32ReadElement(rs32Element);
}

void MyDataStructures::IOChannel::vPrint(uint32_t u32Channel)	//Function for Printing Channel
{
	assert(u32Channel < 3U);
	std::cout << "--Print Channel: " << u32Channel << "--" << std::endl;
	Channels[u32Channel].vPrintRingBuffer();
}