#pragma once
#include "Subject.h"
#include <iostream>
#include <ios>
#include <string>
#include <fstream>
namespace MyDesignPattern
{
	class Display : public Observer
	{
	public:
		Display(std::string str)
		{
			strNameofDisplay = str;
		}
		~Display()
		{
			
		}
		void vUpdate(Subject* pSubject)
		{
			std::cout << strNameofDisplay << " - " << pSubject->strGetState() << "\n";
		}

	protected:
	private:
		std::string strNameofDisplay;
	};
}
