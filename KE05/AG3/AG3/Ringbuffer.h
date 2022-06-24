//Filename: Ringbuffer.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 10.05.2022
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
	class RingbufferPrint;

	class Ringbuffer
	{
	public:
		Ringbuffer();
		Ringbuffer(uint32_t u32SizeOfBuffer_) noexcept;
		~Ringbuffer() noexcept;
		int32_t s32ReadElement(int32_t& rs32Element);
		int32_t s32WriteElement(const int32_t& rs32Element);

		Ringbuffer(const Ringbuffer& rotherRingbuffer);		//C0py
		Ringbuffer(Ringbuffer&& rotherRingbuffer) noexcept;	//M0ve

	protected:
		int32_t as32E[RINGBUFFER_MAXELEMENTS];
		uint32_t u32ReadPos_;
		uint32_t u32WritePos_;
		uint32_t u32NumberElements_;
		uint32_t u32SizeOfBuffer_;
		int32_t* ps32Buffer_;
		friend RingbufferPrint;
	};
	class RingbufferPrint
	{
	public:
		static void vPrint(const Ringbuffer& crRingbuffer);
		static void vPrintMembersValueAndAddress(const Ringbuffer& crRingbuffer);
	protected:
	private:
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
			Queue(uint32_t u32Size) noexcept(true);
			Queue(const Queue& otherQueue) noexcept(true);
			Queue(Queue&& otherQueue) noexcept(true);
		protected:
		private:
	};
	
	
}