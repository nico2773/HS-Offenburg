//Filename: Ringbuffer.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 25.04.2022
#pragma once
#include <iostream>
#include <cstdint>

#define RINGBUFFER_OKAY 0				//State
#define RINGBUFFER_FULL -1				//State
#define RINGBUFFER_EMPTY -2				//State
#define RINGBUFFER_NULLPTR -3			//State
#define RINGBUFFER_MAXELEMENTS 8		//Size 


namespace MyDataStructures
{
	class Ringbuffer
	{
	public:
		Ringbuffer();
		Ringbuffer(uint32_t u32SizeOfBuffer_) noexcept;
		~Ringbuffer() noexcept;
		int32_t s32ReadElement(int32_t& rs32Element);
		int32_t s32WriteElement(const int32_t& rs32Element);
		void vPrintRingBuffer(void);

		void vPrintRingbufferMembersValueAndAddress(void) const noexcept;

		Ringbuffer(const Ringbuffer& rotherRingbuffer);		//C0py
		Ringbuffer(Ringbuffer&& rotherRingbuffer) noexcept;	//M0ve

	protected:
		int32_t as32E[RINGBUFFER_MAXELEMENTS];
		uint32_t u32ReadPos_;
		uint32_t u32WritePos_;
		uint32_t u32NumberElements_;
		uint32_t u32SizeOfBuffer_;
		int32_t* ps32Buffer_ = nullptr;
	};

	class IOChannel
	{
	public:
		IOChannel();
		~IOChannel() noexcept;
		int32_t s32WriteElementToChannel(uint32_t u32Channel, const int32_t& rs32Element);
		int32_t s32ReadElementFromChannel(uint32_t u32Channel, int32_t& rs32Element);
		void vPrint(uint32_t u32Channel);

	private:
		Ringbuffer Channels[3];
	};

	class Queue : public Ringbuffer 
	{
		public:
			Queue();
			~Queue();
			int32_t s32WriteElementFront(const int32_t& rs32Element); 
			Queue(uint32_t u32Size) noexcept(true) : Ringbuffer(u32Size)
			{ 
#ifdef _DEBUG
				std::cout << "\n--Constructor Queue(uint32_t u32Size) noexcept(true) : Ringbuffer(u32Size) called--\n" << std::endl;
#endif // _DEBUG
			}
			Queue(const Queue& otherQueue) noexcept(true);
			Queue(Queue&& otherQueue) noexcept(true);
		protected:
		private:
	};
}