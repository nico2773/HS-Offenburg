#include "Car.h"

Vehicle::Car::Car(uint32_t u32L, uint32_t u32P)
{
#ifdef _DEBUG
   std::cout << "--Car(uint32_t u32L, uint32_t u32P) Constuctor called--" << std::endl;
#endif // _DEBUG

   u32Length_cm_ = u32L;
   u32Power_PS_ = u32P;
}
void Vehicle::Car::vPrintIt()
{
   
#ifdef _DEBUG
   std::cout << "--vPrintIt Constuctor called--" << std::endl;
#endif // _DEBUG
   std::cout << "Length: " << u32Length_cm_ << "\tPower: " << u32Power_PS_ << "\tSize: " << (u32Length_cm_ + u32Power_PS_) << std::endl;
}

bool Vehicle::Car::operator>(const Car& CGet)
{
#ifdef _DEBUG
   std::cout << "--operator>(const Car& CGet) Constuctor called--" << std::endl;
#endif // _DEBUG
   bool bReturn = false;
   
   if ((this->u32Length_cm_ + this->u32Power_PS_) < (CGet.u32Length_cm_ + CGet.u32Power_PS_))
   {
      bReturn = true;
   }
   return bReturn;
}
Vehicle::Car::~Car(void) {
#ifdef _DEBUG
   std::cout << "--~Car(void) Constuctor called--" << std::endl;
#endif // _DEBUG
}