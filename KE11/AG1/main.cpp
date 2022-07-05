#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Composite.h"

static void vClientCode(void);

int main(void)
{
	vClientCode();
	_CrtDumpMemoryLeaks();
	return 0;
}

static void vClientCode(void)
{
	std::shared_ptr<MyDesignPattern::Department> pDepat (new MyDesignPattern::Department ("Universitaet", "HS-Offenburg"));
	std::shared_ptr<MyDesignPattern::Employee> pEmpl (new MyDesignPattern::Employee("Rector", "Trahasch"));
	std::shared_ptr<MyDesignPattern::Employee> pEmp2 (new MyDesignPattern::Employee("ProRector", "Muenchenberg"));
	std::shared_ptr<MyDesignPattern::Department> pDepat2(new MyDesignPattern::Department("Faculty", "M+V"));
	std::shared_ptr<MyDesignPattern::Department> pDepat3(new MyDesignPattern::Department("Faculty", "EMI"));

	std::shared_ptr<MyDesignPattern::Employee> pEmp3(new MyDesignPattern::Employee("Dean", "Kohler"));
	std::shared_ptr<MyDesignPattern::Employee> pEmp4(new MyDesignPattern::Employee("Dean", "Mackensen"));
	std::shared_ptr<MyDesignPattern::Employee> pEmp5(new MyDesignPattern::Employee("Vice-Dean", "Felhauer"));
	std::shared_ptr<MyDesignPattern::Employee> pEmp6(new MyDesignPattern::Employee("Vice-Dean", "Hensel"));
	std::shared_ptr<MyDesignPattern::Department> pDepat4(new MyDesignPattern::Department("Study-Programm", "AI"));
	std::shared_ptr<MyDesignPattern::Department> pDepat5(new MyDesignPattern::Department("Study-Programm", "EI"));
	std::shared_ptr<MyDesignPattern::Department> pDepat6(new MyDesignPattern::Department("Study-Programm", "MK"));

	std::shared_ptr<MyDesignPattern::Employee> pEmp7(new MyDesignPattern::Employee("Dean of Study", "Lauer"));
	std::shared_ptr<MyDesignPattern::Employee> pEmp8(new MyDesignPattern::Employee("Dean of Study", "Pfletschinger"));
	std::shared_ptr<MyDesignPattern::Employee> pEmp9(new MyDesignPattern::Employee("Dean of Study", "Kloeffer"));

	pDepat->vAdd(pEmpl);
	pDepat->vAdd(pEmp2);
	pDepat->vAdd(pDepat2);
	pDepat->vAdd(pDepat3);

	pDepat2->vAdd(pEmp3);
	pDepat2->vAdd(pEmp4);
	pDepat2->vAdd(pEmp5);
	pDepat2->vAdd(pEmp6);
	pDepat2->vAdd(pDepat4);
	pDepat2->vAdd(pDepat5);
	pDepat2->vAdd(pDepat6);

	pDepat4->vAdd(pEmp7);
	pDepat5->vAdd(pEmp8);
	pDepat6->vAdd(pEmp9);


	std::cout << pDepat->strGetDescriptionAndName("") << std::endl;
}