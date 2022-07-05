//Filename: Shape.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 10.05.2022
#pragma once
#include <stdio.h>
#include <cstdint>
#include <iostream>
namespace CAD {

	class Shape {
	public:
		Shape();
		~Shape();
		virtual void vDraw()=0;
		uint32_t u32GetNumberofInstances();
	protected:
		static uint32_t u32NumberofInstances_c;
	private:
		
	};
}