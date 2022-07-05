#pragma once 
#include <iostream> 
namespace MyDesignPattern
{
	class Subject;
	class IObserver
	{
	public:
		virtual ~IObserver() {}
		virtual void vUpdate(Subject*) = 0;
	};
	class Observer : public IObserver
	{
	public:
		Observer() = default;
		virtual ~Observer() = default;
	};
}
