//Filename: INumberselection.cpp
//Description: This file is for the define
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "INumberSelection.h"
#include <set>
#include <time.h>

//RandomSelection
void Lotto::RandomSelection::vSelectNumbers(LotteryNumbers& rLotteryNumbers) {
	uint32_t u32counter = 0;
	uint32_t u32Number = 1;
	std::set<uint32_t> SetSelectedNumbers_;
	time_t time_;

	srand(time(0));
	
	std::cout << "Zufaellige Auswahl getroffen!\nZahlen werden automatisch fuer Sie ausgewaehlt!!" << std::endl;
	while (u32counter < rLotteryNumbers.u32NumbersCount_) {
		
		u32Number = rand() % 49 + 1;

		if (SetSelectedNumbers_.find(u32Number) == SetSelectedNumbers_.end() && u32Number < 50 && u32Number > 0) {
			SetSelectedNumbers_.insert(u32Number);
			rLotteryNumbers.au32Numbers_[u32counter] = u32Number;
			u32counter++;
		}
		else
		{
			std::cout << "Der Computer ist Kaputt" << std::endl;
		}
	}
}

//ManualSelection
void Lotto::ManualSelection::vSelectNumbers(LotteryNumbers& rLotteryNumbers) {
	uint32_t u32counter = 0;
	uint32_t u32Number = 0;
	std::set<uint32_t> SetSelectedNumbers_;


	std::cout << "Manuele Auswahl getroffen! \nZahlen eingeben und mit Enter - Bestätigen! Diesen Vorgang 6 mal Wiederholen." << std::endl;
	while (u32counter < rLotteryNumbers.u32NumbersCount_) {
		std::cin >> u32Number;

		if (SetSelectedNumbers_.find(u32Number) == SetSelectedNumbers_.end() && u32Number < 50 && u32Number > 0) {
			SetSelectedNumbers_.insert(u32Number);
			rLotteryNumbers.au32Numbers_[u32counter] = u32Number;
			u32counter++;
		}
		else
		{
			std::cout << "Die eingegebene Zahl ist ungueltig! Bitte eine Zahl von 1 bis 49 eingeben!!!" << std::endl;
		}
	}
}

//LinearSelection
void Lotto::LinearSelection::vSelectNumbers(LotteryNumbers& rLotteryNumbers) {
	uint32_t u32counter = 0;
	static uint32_t u32Number = 1;
	std::set<uint32_t> SetSelectedNumbers_;


	std::cout << "Steigende Auswahl getroffen! \nZahlen werden automatisch fuer Sie aufsteigend gewaehlt!!\n" << std::endl;
	while (u32counter < rLotteryNumbers.u32NumbersCount_) {
		if (SetSelectedNumbers_.find(u32Number) == SetSelectedNumbers_.end() && u32Number < 50 && u32Number > 0) {
			SetSelectedNumbers_.insert(u32Number);
			
			rLotteryNumbers.au32Numbers_[u32counter] = u32Number;
			u32Number++;
			u32counter++;
		}
		else
		{
			std::cout << "Die Zahl beginnt wieder von 1!" << std::endl;
			u32Number = 1;
		}
	}
}
