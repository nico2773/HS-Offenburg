#pragma once
#include <cstdio>
#include <iostream>
#include <exception>
#include "Complex.h"


namespace MyTemplates {

    //forward declaration of template class 
    template<class T, uint32_t u32S>
    class MyArray;
    //forware declaration of friend method 
    template <class T, uint32_t u32S>
    std::ostream& operator<<(std::ostream& ostr, const MyArray<T, u32S>& crT)
    {
#ifdef _DEBUG
        std::cout << "-- operator<< called--" << std::endl;
#endif // _DEBUG

        std::cout << "Die Arraywerte sind:" << std::endl;
        for (uint32_t i32i = 0; i32i < crT.u32Size_; i32i++)
        {
            std::cout << "Wert an Stelle [" << i32i << "] lautet: " << crT.pElements[i32i] << std::endl;
        }
        return ostr;

    }

   template<class T, uint32_t u32S>
   class MyArray
   {
      public:
         MyArray() {
#ifdef _DEBUG
            std::cout << "-- MyArray Constructor called--" << std::endl;
#endif // _DEBUG

            pElements = new T[u32Size_ = u32S];
         };
         ~MyArray() {
#ifdef _DEBUG
            std::cout << "-- MyArray Deconstructor called--" << std::endl;
#endif // _DEBUG

            delete[] pElements;
         };
         void vResize(uint32_t u32NewSize) 
         {
#ifdef _DEBUG
            std::cout << "-- vResize called--" << std::endl;
#endif // _DEBUG
            if (u32NewSize < 0) 
            {
               throw(std::invalid_argument("Index out of range"));
            }
            T* pE2 = new T[u32NewSize];
            for (uint32_t i32i = 0; i32i < u32NewSize; i32i++)
            {
                pE2[i32i] = pElements[i32i];
            }

            delete[] pElements;     //delete old Values
            pElements = pE2;        //take old Pointer to the same Pointer of the new Pointer (=to the adress)
            pE2 = nullptr;          //reset pointer
            u32Size_ = u32NewSize;  //set the Private Size to new "local" Resize Size 

         };
         T& operator[](uint32_t u32Index)
         {
            if (u32Index < 0 || u32Index >= u32Size_) {
               throw(std::invalid_argument("Index out of range"));
            }

            return (pElements[u32Index]);
         }
         uint32_t Sizerightnow() {
            return u32Size_;
         }

      protected:
      private:
         T* pElements;
         uint32_t u32Size_;

      friend std::ostream& operator<<<T, u32S>(std::ostream& ostr, const MyArray<T, u32S>& cref);
   };
}