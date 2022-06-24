#pragma once
#include "Decorator.h"
#include <vector>

namespace MyDesignPattern {

	class Sales
	{
	public:
		Sales() = default;
		Sales(const Sales& r) = delete;
		virtual ~Sales();
		void AddBeverage(MyDesignPattern::Beverage*);
		f64_t f64GetTotalSales();
		void vPrintAllBeverages();
	private:
		std::vector<MyDesignPattern::Beverage*> VectorBeverages_;
		void vDeleteBeveragesRecursive(MyDesignPattern::Beverage* ait);
	};
}