//Filename: LottoEngine.h
//Description: This file is for the declarations
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "INumberSelection.h"

namespace Lotto {

	class LottoEngine
	{
	private:
		INumberSelection* pNumberSelection_; // selection strategy 
		LotteryNumbers myNumbers_;
	public:
		LottoEngine(INumberSelection* pselector);
		LottoEngine(const LottoEngine&) = delete;
		LottoEngine(LottoEngine&&) = delete;
		~LottoEngine() = default;
		LottoEngine();
		void vSetINumberSelection(INumberSelection* pselector);
		LotteryNumbers xDrawingLotteryNumbers(void);
	};
}