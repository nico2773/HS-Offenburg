//Filename: A.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 10.05.2022
#pragma once
#include <iostream>
//#define DEBUG

namespace Hoo 
{
	class Foo
	{
		public:
			Foo()
			{
#ifdef _DEBUG
				std::cout << "\n--Constructor Foo called--\n" << std::endl;
#endif // DEBUG
					
			};
			~Foo() noexcept
			{
#ifdef _DEBUG
				std::cout << "\n--Deconstructor Foo called--\n" << std::endl;
#endif // DEBUG
			};
		protected:
		private:
	};

	class A
	{
		public:
			A() {
#ifdef _DEBUG
				std::cout << "\n--Constructor A called--\n" << std::endl;
				s32Priv_ = 23;
				s32Prot_ = 46;
				s32Pub_ = 92;
#endif // _DEBUG
			};
			~A() noexcept
			{
#ifdef _DEBUG
				std::cout << "\n--Deconstructor A called--\n" << std::endl;
#endif // _DEBUG
			};
			void ReadA();
			void ReadA(A a) {
				//a.s32Priv_;
			};
			int32_t s32Pub_;
		protected:
			int32_t s32Prot_;
		private:
			int32_t s32Priv_;
			Foo Foo;
	};

	class B : public A
	{
		public:
			B() {			//Constructor
#ifdef _DEBUG
				std::cout << "\n--Deconstructor B called--\n" << std::endl;
#endif // _DEBUG
				s32Prot_ = 13;
				s32Pub_ = 26;
			};
			~B()			//Deconstructor;
			{
#ifdef _DEBUG
				std::cout << "\n--Deconstructor B called--\n" << std::endl;
#endif // _DEBUG
			};
		protected:
		private:
	};

	class C : protected B
	{
		public:
			C() {				//Constructor
#ifdef _DEBUG
				std::cout << "\n--Constructor C called--\n" << std::endl;
				s32Prot_ = 23;
				s32Pub_ = 46;
#endif // _DEBUG
			};
				~C() {			//Deconstructor
#ifdef _DEBUG
					std::cout << "\n--Deconstructor C called--\n" << std::endl;
#endif // _DEBUG
				};
		protected:
		private:
	};

	class D : private C
	{
		public:
			D() {			//Constructor
#ifdef _DEBUG
				std::cout << "\n--Constructor D called--\n" << std::endl;
				s32Prot_ = 23;
				s32Pub_ = 46;
#endif // DEBUG
			};
			~D() {			//Deconstructor
#ifdef _DEBUG
				std::cout << "\n--Deconstructor D called--\n" << std::endl;
#endif // DEBUG
			};
		protected:
		private:
	};

	class E : public D
	{
		public:
			E() {		//Constructor
#ifdef _DEBUG
				std::cout << "\n--Constructor E called--\n" << std::endl;
				
#endif // DEBUG
			};
			~E() {		//Deconstructor
#ifdef _DEBUG
				std::cout << "\n--Deconstructor E called--\n" << std::endl;
#endif // DEBUG
			};
		protected:
		private:
	};
}