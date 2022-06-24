//Filename: Ringbuffer.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 10.05.2022
#include "Ringbuffer.h"
#include <cassert>

MyDataStructures::Ringbuffer::Ringbuffer()
{
#ifdef _DEBUG
	std::cout << "--Ringbuffer Constructor called--" << std::endl;
#endif // _DEBUG
}

MyDataStructures::Ringbuffer::Ringbuffer(uint32_t u32SizeOfBuffer_) noexcept
{
	u32ReadPos_ = 0;
	u32WritePos_ = 0;
	u32NumberElements_ = 0;
	this->u32SizeOfBuffer_ = u32SizeOfBuffer_;

	ps32Buffer_ = new int32_t[u32SizeOfBuffer_]; // without zeroing � How to zeroing? 
	if (ps32Buffer_ != nullptr)
	{
		for (uint8_t i8i = 0; i8i < u32SizeOfBuffer_; i8i++)
		{
			ps32Buffer_[i8i] = 0;
		}
	}
	

	/*for (uint8_t i = 0; i < RINGBUFFER_MAXELEMENTS; i++)
	{
		as32E[i] = 0;
	}*/
#ifdef _DEBUG
	std::cout << "--Constructor of Ringbuffer called--" << std::endl;
#endif // _DEBUG

	
}

MyDataStructures::Ringbuffer::~Ringbuffer() noexcept
{
	if (ps32Buffer_ != nullptr)
	{
		delete[] ps32Buffer_;					// Deletes arrays of objects 

		
	}
#ifdef _DEBUG
	std::cout << "--Destructor of Ringbuffer called--" << std::endl;
#endif // _DEBUG

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

int32_t MyDataStructures::Ringbuffer::s32ReadElement(int32_t& rs32Element)
{
#ifdef _DEBUG
	std::cout << "--Constroctor s32ReadElement called--" << std::endl;
#endif // _DEBUG

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

int32_t MyDataStructures::Ringbuffer::s32WriteElement(const int32_t& rs32Element)
{
#ifdef _DEBUG
	std::cout << "--Constroctor s32WriteElement called--" << std::endl;
#endif // _DEBUG
	int32_t i32State = RINGBUFFER_FULL;
	if (ps32Buffer_ != 0)
	{
		if (u32NumberElements_ < u32SizeOfBuffer_)
		{
			ps32Buffer_[u32WritePos_] = rs32Element;
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

//MyDataStructures::IOChannel::IOChannel() : Channels{ 10U,10U,10U }		//Function for Constracor IOChannel
//{
//#ifdef _DEBUG
//	std::cout << "\n--IOChannelconstruktor called--\n" << std::endl;
//#endif
//}
//
//MyDataStructures::IOChannel::~IOChannel() noexcept						//Function for Deconstracor IOChannel
//{
//#ifdef _DEBUG
//	std::cout << "\n--IOChanneldeconstruktor called--\n" << std::endl;
//#endif
//}
//int32_t MyDataStructures::IOChannel::s32WriteElementToChannel(uint32_t u32Channel, const int32_t& rs32Element)	//Function for Channel Write 
//{
//	assert(u32Channel < 3U);
//	return Channels[u32Channel].s32WriteElement(rs32Element);
//}
//int32_t MyDataStructures::IOChannel::s32ReadElementFromChannel(uint32_t u32Channel, int32_t& rs32Element)		//Function for Channel Read
//{
//	assert(u32Channel < 3U);
//	return Channels[u32Channel].s32ReadElement(rs32Element);
//}
//
//void MyDataStructures::IOChannel::vPrint(uint32_t u32Channel)	//Function for Printing Channel
//{
//	assert(u32Channel < 3U);
//	std::cout << "--Print Channel: " << u32Channel << "--" << std::endl;
//	Channels[u32Channel].vPrintRingBuffer();
//}




MyDataStructures::Queue::Queue()
{
#ifdef _DEBUG
	std::cout << "--Queue Constructor called--" << std::endl;
#endif // _DEBUG

	
}
MyDataStructures::Queue::~Queue()
{
#ifdef _DEBUG
	std::cout << "--Queue Deconstructor called--" << std::endl;
#endif // _DEBUG
}
int32_t MyDataStructures::Queue::s32WriteElementFront(const int32_t& rs32Element)
{
#ifdef _DEBUG
	std::cout << "--s32WriteElementFront Constructor called--" << std::endl;
#endif // _DEBUG
	uint32_t u32ReadDummy = MyDataStructures::Ringbuffer::u32ReadPos_;
	int32_t s32Return = RINGBUFFER_OKAY;
	if (u32ReadDummy > 0)
	{
		u32ReadDummy--;
	}
	else
	{
		u32ReadDummy = u32SizeOfBuffer_;
	}

	if (ps32Buffer_ != nullptr)
	{
		if (u32ReadDummy > 0)
		{
			ps32Buffer_[u32ReadDummy - 1] = rs32Element;
		}		
	}
	else
	{
		s32Return = RINGBUFFER_NULLPTR;
	}
	return s32Return; //if sanity check fails
}
//Copy
MyDataStructures::Queue::Queue(const Queue& rq) noexcept(true) : Ringbuffer(rq)
{
#ifdef _DEBUG
	std::cout << "\n--Copyconstruktor Queue called--\n" << std::endl;
#endif // _DEBUG

}
//Move
MyDataStructures::Queue::Queue(Queue&& rq) noexcept(true) : Ringbuffer(std::move(rq))
{
#ifdef _DEBUG
	std::cout << "\n--Moveconstruktor Queue called--\n" << std::endl;
#endif // _DEBUG
}
MyDataStructures::Queue::Queue(uint32_t u32Size) noexcept(true) : Ringbuffer(u32Size)
{
#ifdef _DEBUG
	std::cout << "\n--Constructor Queue(uint32_t u32Size) noexcept(true) : Ringbuffer(u32Size) called--\n" << std::endl;
#endif // _DEBUG
}



void MyDataStructures::RingbufferPrint::vPrint(const Ringbuffer& crRingbuffer)
	{
#ifdef _DEBUG
	std::cout << "--vPrint Constructor called--" << std::endl;
#endif // _DEBUG
	//Print all Status Parameter
	std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Number of Elements: " << crRingbuffer.u32NumberElements_ << std::endl;
	std::cout << "Write Position: " << crRingbuffer.u32WritePos_ << std::endl;
	std::cout << "Read Position: " << crRingbuffer.u32ReadPos_ << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	for (uint32_t i8i = 0; i8i < crRingbuffer.u32SizeOfBuffer_; i8i++)
	{

		std::cout << "Wert an Pos:  "<< i8i << " mit dem Inhalt: " << crRingbuffer.ps32Buffer_[i8i] << std::endl;
	}
}

void MyDataStructures::RingbufferPrint::vPrintMembersValueAndAddress(const Ringbuffer& crRingbuffer)
{
#ifdef _DEBUG
	std::cout << "--vPrintMembersValueAndAddress Constructor called--" << std::endl;
#endif // _DEBUG
	std::cout << std::hex;
	std::cout << "--RingBufferMembers--" << std::endl;
	std::cout << "WritePos: \t\t" << crRingbuffer.u32WritePos_ << "\t" << &crRingbuffer.u32WritePos_ << std::endl;
	std::cout << "ReadPos: \t\t" << crRingbuffer.u32ReadPos_ << "\t" << &crRingbuffer.u32ReadPos_ << std::endl;
	std::cout << "NumberofElements: \t" << crRingbuffer.u32NumberElements_ << "\t" << &crRingbuffer.u32NumberElements_ << std::endl;
	//std::cout << "ps32Buffer_[0]: \t\t" << crRingbuffer.ps32Buffer_[0] << "\t" << &crRingbuffer.ps32Buffer_[0] << std::endl;
	std::cout << std::dec;
}