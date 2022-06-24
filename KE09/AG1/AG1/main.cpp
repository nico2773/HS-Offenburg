#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <algorithm>
#include <fstream>

//const uint32_t cau32Lookup[] = {1000U, 2000U, 3000U, 4000U, 5000U, 6000U, 7000U, 8000U, 9000U, 10000U};
const uint32_t cau32Lookup[] = { 1000000U, 2000000U, 3000000U, 4000000U, 5000000U, 6000000U, 7000000U, 8000000U, 9000000U, 10000000U};

int main()
{
	std::set<int32_t>::iterator itset;
	
	std::ofstream OutputFile; 
	OutputFile.open("PerformanceContainer.txt");
	std::cout << "Eleme\tList\tVec1\tVec2\tSet\tfl_l\tl_vec1\tl_vec2\tl_set1\tl_set2" << std::endl;
	OutputFile << "Eleme\tList\tVec1\tVec2\tSet\tfl_l\tl_vec1\tl_vec2\tl_set1\tl_set2" << std::endl;
	for (auto ait : cau32Lookup)
	{
		std::list<uint32_t> u32list;
		std::vector<uint32_t> u32vector1;
		std::vector<uint32_t> u32vector2;
		u32vector2.reserve(ait); //auto iterator of loop, Element of cau32Lookup
		std::set<uint32_t> u32set;

		std::cout << ait << "\t";
		OutputFile << ait << "\t";

		// u32list
		auto astart_time = std::chrono::steady_clock::now();
		for (uint32_t u32i = 0; u32i < ait; u32i++)
		{
			u32list.push_back(u32i);
		}
		auto aend_time = std::chrono::steady_clock::now();
		std::cout <<std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// vector
		astart_time = std::chrono::steady_clock::now();
		for (uint32_t u32i = 0; u32i < ait; u32i++)
		{
			u32vector1.push_back(u32i);
		}
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// vector 2 
		astart_time = std::chrono::steady_clock::now();
		for (uint32_t u32i = 0; u32i < ait; u32i++)
		{
			u32vector2.push_back(u32i);
		}
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// set 
		astart_time = std::chrono::steady_clock::now();
		for (uint32_t u32i = 0; u32i < ait; u32i++)
		{
			u32set.insert(u32i);
		}
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// fltime 
		astart_time = std::chrono::steady_clock::now();
		std::list<uint32_t>::iterator u32fl_list = std::find(u32list.begin(), u32list.end(), ait - 1U);
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// fl_vector1 
		astart_time = std::chrono::steady_clock::now();
		std::vector<uint32_t>::iterator u32flvector1 = std::find(u32vector1.begin(), u32vector1.end(), ait - 1U);
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// fl_vector2 
		astart_time = std::chrono::steady_clock::now();
		std::vector<uint32_t>::iterator u32flvector2 = std::find(u32vector1.begin(), u32vector1.end(), ait - 1U);
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// fl_set1
		astart_time = std::chrono::steady_clock::now();
		std::set<uint32_t>::iterator u32flset = std::find(u32set.begin(), u32set.end(), ait - 1U);
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\t";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\t";

		// fl_set2
		astart_time = std::chrono::steady_clock::now();
		std::set<uint32_t>::iterator u32flset2 = u32set.find(ait-1U);
		aend_time = std::chrono::steady_clock::now();
		std::cout << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << " ms\n";
		OutputFile << std::chrono::duration_cast<std::chrono::microseconds> (aend_time - astart_time).count() << "\n";
	}
	OutputFile.close();
}