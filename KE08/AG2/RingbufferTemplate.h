#pragma once
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
	/*class RingbufferPrint;*/
	template<class T, uint32_t u32S>
	class Ringbuffer
	{
	public:
		Ringbuffer() {
#ifdef _DEBUG
			std::cout << "--Ringbuffer Constructor called--" << std::endl;
#endif // _DEBUG
			
			u32ReadPos_ = 0;
			u32WritePos_ = 0;
			u32NumberElements_ = 0;
			u32SizeOfBuffer_ = u32S;
			ps32Buffer_ = new T[u32SizeOfBuffer_];

			for (uint32_t X = 0; X < u32SizeOfBuffer_; X++)
			{
				ps32Buffer_[X] = T();
			}

		};
		Ringbuffer(uint32_t u32SizeOfBuffer_) noexcept
		{
			u32ReadPos_ = 0;
			u32WritePos_ = 0;
			u32NumberElements_ = 0;
			this->u32SizeOfBuffer_ = u32SizeOfBuffer_;

			ps32Buffer_ = new int32_t[u32SizeOfBuffer_]; // without zeroing – How to zeroing? 
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


		};
		~Ringbuffer() noexcept 
		{
			if (ps32Buffer_ != nullptr)
			{
				delete[] ps32Buffer_;					// Deletes arrays of objects 
			}
#ifdef _DEBUG
			std::cout << "--Destructor of Ringbuffer called--" << std::endl;
#endif // _DEBUG

		};
		int32_t s32ReadElement(T& rs32Element)
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
		};
		int32_t s32WriteElement(const T& rs32Element)
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
		};
		void vPrint()
		{
#ifdef _DEBUG
			std::cout << "--vPrint Constructor called--" << std::endl;
#endif // _DEBUG
			//Print all Status Parameter
			std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "Number of Elements: " << u32NumberElements_ << std::endl;
			std::cout << "Write Position: " << u32WritePos_ << std::endl;
			std::cout << "Read Position: " << u32ReadPos_ << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;

			for (uint32_t i8i = 0; i8i < u32SizeOfBuffer_; i8i++)
			{

				std::cout << "Wert an Pos:  " << i8i << " mit dem Inhalt: " << ps32Buffer_[i8i] << std::endl;
			}
		}
		Ringbuffer(const Ringbuffer& rotherRingbuffer)
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

		};		//C0py
		Ringbuffer(Ringbuffer&& rotherRingbuffer) noexcept
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
		};	//M0ve

	protected:
		int32_t as32E[RINGBUFFER_MAXELEMENTS];
		uint32_t u32ReadPos_;
		uint32_t u32WritePos_;
		uint32_t u32NumberElements_;
		uint32_t u32SizeOfBuffer_;
		T* ps32Buffer_;
	};
//	class RingbufferPrint
//	{
//	public:
//		static void vPrint(const Ringbuffer& crRingbuffer)
//		{
//#ifdef _DEBUG
//			std::cout << "--vPrint Constructor called--" << std::endl;
//#endif // _DEBUG
//			//Print all Status Parameter
//			std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
//			std::cout << "Number of Elements: " << crRingbuffer.u32NumberElements_ << std::endl;
//			std::cout << "Write Position: " << crRingbuffer.u32WritePos_ << std::endl;
//			std::cout << "Read Position: " << crRingbuffer.u32ReadPos_ << std::endl;
//			std::cout << std::endl;
//			std::cout << std::endl;
//
//			for (uint32_t i8i = 0; i8i < crRingbuffer.u32SizeOfBuffer_; i8i++)
//			{
//
//				std::cout << "Wert an Pos:  " << i8i << " mit dem Inhalt: " << crRingbuffer.ps32Buffer_[i8i] << std::endl;
//			}
//		};
//		static void vPrintMembersValueAndAddress(const Ringbuffer& crRingbuffer)
//		{
//#ifdef _DEBUG
//			std::cout << "--vPrintMembersValueAndAddress Constructor called--" << std::endl;
//#endif // _DEBUG
//			std::cout << std::hex;
//			std::cout << "--RingBufferMembers--" << std::endl;
//			std::cout << "WritePos: \t\t" << crRingbuffer.u32WritePos_ << "\t" << &crRingbuffer.u32WritePos_ << std::endl;
//			std::cout << "ReadPos: \t\t" << crRingbuffer.u32ReadPos_ << "\t" << &crRingbuffer.u32ReadPos_ << std::endl;
//			std::cout << "NumberofElements: \t" << crRingbuffer.u32NumberElements_ << "\t" << &crRingbuffer.u32NumberElements_ << std::endl;
//			//std::cout << "ps32Buffer_[0]: \t\t" << crRingbuffer.ps32Buffer_[0] << "\t" << &crRingbuffer.ps32Buffer_[0] << std::endl;
//			std::cout << std::dec;
//		};
//	protected:
//	private:
//	};
	/*class IOChannel
	{
	public:
		IOChannel();
		~IOChannel() noexcept;
		int32_t s32WriteElementToChannel(uint32_t u32Channel, const int32_t& rs32Element);
		int32_t s32ReadElementFromChannel(uint32_t u32Channel, int32_t& rs32Element);
		void vPrint(uint32_t u32Channel);

	private:
		Ringbuffer Channels[3];
	};*/
//
//	class Queue : public Ringbuffer
//	{
//	public:
//		Queue()
//		{
//#ifdef _DEBUG
//			std::cout << "--Queue Constructor called--" << std::endl;
//#endif // _DEBUG
//		};
//		~Queue()
//		{
//#ifdef _DEBUG
//			std::cout << "--Queue Deconstructor called--" << std::endl;
//#endif // _DEBUG
//		};
//		int32_t s32WriteElementFront(const int32_t& rs32Element)
//		{
//#ifdef _DEBUG
//			std::cout << "--s32WriteElementFront Constructor called--" << std::endl;
//#endif // _DEBUG
//			uint32_t u32ReadDummy = MyDataStructures::Ringbuffer::u32ReadPos_;
//			int32_t s32Return = RINGBUFFER_OKAY;
//			if (u32ReadDummy > 0)
//			{
//				u32ReadDummy--;
//			}
//			else
//			{
//				u32ReadDummy = u32SizeOfBuffer_;
//			}
//
//			if (ps32Buffer_ != nullptr)
//			{
//				if (u32ReadDummy > 0)
//				{
//					ps32Buffer_[u32ReadDummy - 1] = rs32Element;
//				}
//			}
//			else
//			{
//				s32Return = RINGBUFFER_NULLPTR;
//			}
//			return s32Return; //if sanity check fails
//		};
//		Queue(uint32_t u32Size) noexcept(true)
//		{
//#ifdef _DEBUG
//			std::cout << "\n--Constructor Queue(uint32_t u32Size) noexcept(true) : Ringbuffer(u32Size) called--\n" << std::endl;
//#endif // _DEBUG
//		};
//		Queue(const Queue& otherQueue) noexcept(true)
//		{
//#ifdef _DEBUG
//			std::cout << "\n--Copyconstruktor Queue called--\n" << std::endl;
//#endif // _DEBUG
//
//		};
//		Queue(Queue&& otherQueue) noexcept(true)
//		{
//#ifdef _DEBUG
//			std::cout << "\n--Moveconstruktor Queue called--\n" << std::endl;
//#endif // _DEBUG
//		};
//	protected:
//	private:
//	};


}