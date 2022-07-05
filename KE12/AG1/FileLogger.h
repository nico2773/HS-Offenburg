#pragma once
#include "Subject.h"
#include <iostream>
#include <ios>
#include <string>
#include <fstream>

namespace MyDesignPattern
{
	class FileLogger : public Observer
	{
	public:
		FileLogger(std::string str)
		{
			strFileName_ = str;
		}
		~FileLogger()
		{
		}
		void vUpdate(Subject* pSubject)
		{
			std::ofstream filelogger(strFileName_, std::ios_base::out | std::ios_base::app);
			filelogger << pSubject->strGetState() << "\n";
		}

	protected:
	private:
		std::string strFileName_;
	};
}
