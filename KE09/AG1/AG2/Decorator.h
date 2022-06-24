#pragma once
typedef double f64_t;
#include <stdio.h>
#include <ostream>
#include <iostream>
#include <cstdlib>

namespace MyDesignPattern
{
	class Beverage
	{
	public:
		virtual ~Beverage() {}
		virtual f64_t f64Cost() const = 0;
		virtual std::string strGetDescription() const = 0;
	};

	class Espresso : public Beverage
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
	};

	class Decaf : public Beverage
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
	};

	class HouseBlend : public Beverage
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
	};

	class DarkRoast : public Beverage
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
	};

	class Cocoa : public Beverage
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
	};

	class CondimentDecorator : public Beverage
	{
	protected:
		Beverage* beverage_;
	public:
		CondimentDecorator() = default;
		CondimentDecorator(Beverage* beverage) : beverage_(beverage)
		{
		}
		Beverage* getCondimentDecorator()
		{
			return beverage_;
		}
	};

	class Milk : public CondimentDecorator
	{
	public:
		Milk(Beverage* beverage);
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
	};

	class Mocha : public CondimentDecorator
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
		Mocha(Beverage* beverage);
	};

	class Soy : public CondimentDecorator
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
		Soy(Beverage* beverage);
	};

	class Whip : public CondimentDecorator
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
		Whip(Beverage* beverage);
	};

	class Sugar : public CondimentDecorator
	{
	public:
		f64_t f64Cost() const override;
		std::string strGetDescription() const override;
		Sugar(Beverage* beverage);
	};
}