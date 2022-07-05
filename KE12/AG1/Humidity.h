#pragma once
#include <string>
#include "Subject.h"
namespace MyDesignPattern
{
	class Humidity : public Subject
	{
	public:
		Humidity(std::string strGETDescription_)
		{
			strDescription_ = strGETDescription_;
			f32Humidity_ = 999;
		}
		~Humidity()
		{
		}
		void vSetHumidity(f32_t f32NewValue)
		{
			f32Humidity_ = f32NewValue;
			vNotify();
		}
		std::string strGetState()
		{
			return strDescription_ + ": " + " New Humidity: " + std::to_string(f32Humidity_);
		}
	protected:
	private:
		std::string strDescription_;
		f32_t f32Humidity_;
	};
}