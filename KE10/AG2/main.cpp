#include <stdio.h>
#include <stdint.h>
#include <ostream>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <thread>

void TestContainerLambda();
void ExecuteSort(std::function<void(void)> lambda);
void SortParallel(void);

struct Circle
{
	double dX;
	double dY;
	double dRadius;
};

int main() {
	//Aufgabe 2.3
	int iVal1= 5;
	int iVal2 = 10;
	double dVal1 = 200;
	double dVal2 = 400;
	std::string String1 = "Hallo";
	std::string String2 = "Prof";
	
	
	//Aufgabe 2.1
	
	auto lambda1 = []()
	{
		std::cout << "Hello Lambda" << std::endl;
	};
	//aufgabe 2.2

	std::function<int32_t(int32_t, int32_t)> lambda2 = [](int32_t s32Val1, int32_t s32Val2)
	{
		return s32Val1 + s32Val2;
	};
	//Aufgabe 2.3
	
	auto lambda3 = [](auto aValue1, auto aValue2)
	{
		return aValue1 + aValue2;
	};
	std::cout << "\nAufgabe 2.1" << std::endl;
	lambda1();
	std::cout << "\nAufgabe 2.2" << std::endl;
	std::cout << lambda2(4, 5) << std::endl;
	std::cout << "\nAufgabe 2.3" << std::endl;
	std::cout << lambda3(iVal1, iVal2) << std::endl;
	std::cout << lambda3(dVal1, dVal2) << std::endl;
	std::cout << lambda3(iVal1, dVal2) << std::endl;
	std::cout << lambda3(String1, String2) << std::endl;
	
	TestContainerLambda();
	SortParallel();
}

void TestContainerLambda() {
	//Aufgabe 2.4
	std::vector<Circle> vCircle;
	std::vector<double> vCircleX;
	vCircle.push_back(Circle(0, 0, 0));
	vCircle.push_back(Circle(10, 10, 10));
	vCircle.push_back(Circle(-10, -10, -10));
	vCircle.push_back(Circle(0, 10, 20));
	std::vector<Circle> vCircle2;
	vCircle2.push_back(Circle(0, 0, 0));
	vCircle2.push_back(Circle(10, 10, 10));
	vCircle2.push_back(Circle(-10, -10, -10));
	vCircle2.push_back(Circle(0, 10, 20));
	//Aufgabe 2.4.1
	auto it = std::find_if(vCircle.begin(), vCircle.end(), [](const Circle& c)
		{
			return c.dRadius > 10;
		});

	//Aufgabe 2.4.2
	std::sort(vCircle.begin(), vCircle.end(), [](const Circle& lh, const Circle& rh)
		{
			return lh.dX < rh.dX;
		});

	//Aufgabe 2.4.3
	std::for_each(vCircle.begin(), vCircle.end(), [&vCircleX](const Circle& setCircleX)
		{
			vCircleX.push_back(double(setCircleX.dX));
		});

	//Aufgabe 2.4.4
	std::for_each(vCircleX.begin(), vCircleX.end(), [](const double& dXpos)
		{
			std::cout << dXpos << std::endl;
		});

	//Aufgabe 2.5
	  auto lambda5 = [](const Circle& lh, const Circle& rh)
		{
			return lh.dRadius < rh.dRadius;
		};

	  ExecuteSort([&vCircle2]() {
		  std::sort(vCircle2.begin(), vCircle2.end(), [](Circle& lh, Circle& rh)
			  {
				  return lh.dX < rh.dX;
			  });
		  });
	  std::for_each(vCircle2.begin(), vCircle2.end(), [] (const Circle& dXpos)
		  {
			  std::cout << dXpos.dRadius << std::endl;
		  });
}

void ExecuteSort(std::function<void(void)> lambda) {
	std::cout << "\nAufgabe 2.5" << std::endl;
	lambda();
}
void SortParallel(void)
{
	std::cout << "\nAufgabe 2.6" << std::endl;
	std::vector<Circle> vCircle2;
	vCircle2.push_back(Circle(0, 0, 0));
	vCircle2.push_back(Circle(10, 10, 10));
	vCircle2.push_back(Circle(-10, -10, -10));
	vCircle2.push_back(Circle(0, 10, 20));
	std::thread t([&vCircle2] ()
		{
		std::sort(vCircle2.begin(), vCircle2.end(), [](Circle& lh, Circle& rh)
			{
				return lh.dX < rh.dX;
			});
		});
	std::for_each(vCircle2.begin(), vCircle2.end(), [](const Circle& dXpos)
		{
			std::cout << dXpos.dRadius << std::endl;
		});
	if (t.joinable())
	{
		t.join();
	}
}