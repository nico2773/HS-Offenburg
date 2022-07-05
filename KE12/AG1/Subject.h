#pragma once 
#include <memory> 
#include <string> 
#include <list> 
#include "Observer.h"
typedef float f32_t;

namespace MyDesignPattern
{
	class ISubject
	{
	public:
		virtual void vAttach(std::shared_ptr <MyDesignPattern::IObserver>) = 0;
		virtual void vDetach(std::shared_ptr <MyDesignPattern::IObserver>) = 0;
		virtual void vNotify() = 0;
	};
	class Subject : public ISubject
	{
	public:
		Subject() = default;
		virtual ~Subject() = default;
		virtual std::string strGetState() = 0;
		void vAttach(std::shared_ptr <MyDesignPattern::IObserver> obs) override
		{
			observers_.push_back(obs);
		}
		void vDetach(std::shared_ptr <MyDesignPattern::IObserver> obs) override
		{
			observers_.remove(obs);
		}
		void vNotify() override
		{
#ifdef _DEBUG
			std::cout << "vNotify()"<<std::endl;
#endif //_DEBUG
			for (auto ait : observers_)
			{
				ait->vUpdate(this);
			}
		}
	protected:
		std::list<std::shared_ptr <MyDesignPattern::IObserver>> observers_;
	};
}