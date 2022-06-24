//Filename: main.cpp
//Description: This file is for the main Programm
//Author: Nicolas Wajs
//Date: 10.05.2022

#include "A.h"

//Aufgabe1.2 
// ----------------
//             A    |   B   |    C   |    D   |    E      
//s32Priv_     0K       --       --       --      --
//s32Prot_     0k       0k       0k       0k      --
//s32Pub_      0k       0K       0k       0k      --

//Aufgabe1.4
//It doenst work because of the parent class B relationship with class C! Its the protected method!
// Hoo::A* aClassDyn = new Hoo::C;      ERROR!
// Hoo::A* aClassDyn = new Hoo::B       WORKS!

//Aufgabe1.5
// Yes it works, because of Get'er Functions..

int main()
{
    Hoo::A aklass;
    Hoo::E eklass;
    Hoo::A* aClassDyn = new Hoo::A;
    Hoo::B* bClassDyn = new Hoo::B;
    std::cout << "Klassengroesse A: " << sizeof(Hoo::A) << std::endl;
    std::cout << "Klassengroesse B: " << sizeof(Hoo::B) << std::endl;
    std::cout << "Klassengroesse C: " << sizeof(Hoo::C) << std::endl;
    std::cout << "Klassengroesse D: " << sizeof(Hoo::D) << std::endl;
    std::cout << "Klassengroesse E: " << sizeof(Hoo::E) << std::endl;
    std::cout << "Klassengroesse Foo: " << sizeof(Hoo::Foo) << std::endl;

    std::cout << "Size aClassDyn: " << sizeof(aClassDyn) << std::endl;
    std::cout << "Size bClassDyn: " << sizeof(bClassDyn) << std::endl;

    return 0;
}
