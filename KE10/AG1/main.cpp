#include "Complex.h"
#include <memory>
#include "CAD_Drawing.h"
#define _CRTDBG_MAP_ALLOC

void TestCreateObject();
void TestMoveObject();
void TestShareObjects(std::unique_ptr<MyMath::Complex>& P1_);
void TestShareObjects(std::shared_ptr<MyMath::Complex> P1_);
int main()
{
	TestCreateObject();

	void TestMoveObject();
	_CrtDumpMemoryLeaks();
	return 0;
}

void TestCreateObject()
{
	std::cout << "\nAufgabe 1.1" << std::endl;
	MyMath::Complex* pComplex1 = new MyMath::Complex();
	pComplex1->vSetf64Real(23);
	pComplex1->vSetf64Img(3);
	std::cout << pComplex1->f64GetArg() << std::endl;
	std::cout << pComplex1->f64GetAbs() << std::endl;

	std::shared_ptr<CAD::Circle> shared_Circle(new CAD::Circle);
	std::shared_ptr<CAD::Rectangle> shared_Rectangle(new CAD::Rectangle);
	std::shared_ptr<CAD::CAD_Drawing> shared_CAD(new CAD::CAD_Drawing);

	//Aufgabe 1.2
	std::cout << "\nAufgabe 1.2" << std::endl;
	std::unique_ptr<MyMath::Complex> unique_P1(new MyMath::Complex());
	std::unique_ptr<MyMath::Complex> unique_P2(new MyMath::Complex());

	unique_P1->vSetf64Real(12);
	unique_P1->vSetf64Img(23);
	std::cout << unique_P1->f64GetAbs() << std::endl;
	unique_P2->vSetf64Real(24);
	unique_P2->vSetf64Img(31);
	std::cout << unique_P2->f64GetAbs() << std::endl;

	auto* pP = unique_P1.release();
	delete pP;
	auto* pP1 = unique_P2.release();
	delete pP1;

	//Aufgabe 1.3
	std::cout << "\nAufgabe 1.3" << std::endl;
	std::shared_ptr<MyMath::Complex> shared_P1(new MyMath::Complex);
	std::shared_ptr<MyMath::Complex> shared_P2(new MyMath::Complex);

	shared_P1->vSetf64Real(12);
	shared_P1->vSetf64Img(23);
	std::cout << shared_P1->f64GetAbs() << std::endl;
	shared_P2->vSetf64Real(24);
	shared_P2->vSetf64Img(31);
	std::cout << shared_P2->f64GetAbs() << std::endl;
	//Aufgabe 1.4
	std::cout << "\nAufgabe 1.4" << std::endl;
	std::unique_ptr<MyMath::Complex> unique_P3(new MyMath::Complex());
	TestShareObjects(shared_P1);
	TestShareObjects(unique_P3);
	
	//Aufgabe 1.5
	std::cout << "\nAufgabe 1.5" << std::endl;
	TestMoveObject();
	//Aufgabe 1.7
	std::cout << "\nAufgabe 1.7" << std::endl;
	shared_CAD->vAddShape(shared_Rectangle);
	shared_CAD->vAddShape(shared_Circle);
	shared_CAD->vDrawIt();
}
void TestShareObjects(std::unique_ptr<MyMath::Complex> &P1_)
{
	P1_->vSetf64Real(4);
	P1_->vSetf64Img(3);
	std::cout << P1_->f64Getf64Real() << " + " << P1_->f64Getf64Img() << std::endl;
}

void TestShareObjects(std::shared_ptr<MyMath::Complex> P1_)
{
	P1_->vSetf64Real(4);
	P1_->vSetf64Img(3);
	std::cout << P1_->f64Getf64Real() << " + " << P1_->f64Getf64Img() << std::endl;
}

void TestMoveObject()
{
	std::unique_ptr<MyMath::Complex> unique_P1(new MyMath::Complex());
	std::shared_ptr<MyMath::Complex> shared_P1(std::move(unique_P1));
}