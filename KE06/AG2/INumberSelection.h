//Filename: INumberSelection.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 10.05.2022

#pragma once
#include <stdio.h>
#include <cstdint>
#include <iostream>

namespace Lotto {
	const uint32_t u32cNumberNumbers = 6U;
	struct LotteryNumbers
	{
	public:
		uint32_t u32MinLotteryNumber_ = 1U;
		uint32_t u32MaxLotteryNumber_ = 49U;
		uint32_t u32NumbersCount_ = u32cNumberNumbers;
		uint32_t au32Numbers_[u32cNumberNumbers] = { 0 };
	};

	class INumberSelection {
	public:
		INumberSelection() = default;
		~INumberSelection() = default;
		INumberSelection(const INumberSelection&) = default;
		INumberSelection(INumberSelection&&) = default;

		virtual void vSelectNumbers(LotteryNumbers& rLotteryNumbers) = 0;
	protected:
	private:
	};

	class RandomSelection : public INumberSelection {
	public:
		RandomSelection() = default;
		~RandomSelection() = default;
		RandomSelection(const RandomSelection&) = default;
		RandomSelection(RandomSelection&&) = default;

		void vSelectNumbers(LotteryNumbers& rLotteryNumbers);
	protected:
	private:
	};

	class ManualSelection : public INumberSelection {
	public:
		ManualSelection() = default;
		~ManualSelection() = default;
		ManualSelection(const ManualSelection&) = default;
		ManualSelection(ManualSelection&&) = default;

		void vSelectNumbers(LotteryNumbers& rLotteryNumbers);
	protected:
	private:
	};

	class LinearSelection : public INumberSelection {
	public:
		LinearSelection() = default;
		~LinearSelection() = default;
		LinearSelection(const LinearSelection&) = default;
		LinearSelection(LinearSelection&&) = default;

		void vSelectNumbers(LotteryNumbers& rLotteryNumbers);
	protected:
	private:
	};

}