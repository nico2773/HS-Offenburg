#pragma once
#include <string>
#include "Subject.h"
namespace MyDesignPattern
{
	class Temperature : public Subject
	{
	public:
		Temperature(std::string strGETDescription_)
		{
			strDescription_ = strGETDescription_;
			f32Temperature_ = 999;
		}
		~Temperature()
		{
		}
		void vSetTemperature(f32_t f32NewValue)
		{
			f32Temperature_ = f32NewValue;
			vNotify();
		}
		std::string strGetState()
		{
			return strDescription_ + ": " + " New Temperature: " + std::to_string(f32Temperature_);
		}
	protected:
	private:
		std::string strDescription_;
		f32_t f32Temperature_;
	};
}