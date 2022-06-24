#pragma once
#include <iostream>
#include <stdio.h>
#include  <cstdio>
#include  <cstdint>
namespace Vehicle {
   class Car
   {
   public:
      Car(uint32_t u32L, uint32_t u32P);
      virtual ~Car(void);
      Car(const Car&) = delete;
      bool operator>(const Car&);
      void vPrintIt(void);
   protected:
   private:
      uint32_t u32Length_cm_;
      uint32_t u32Power_PS_;
   };
}