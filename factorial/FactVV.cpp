// FactVV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Facto.h"

int main()
{
    std::cout << "mi programa de factoriales\n";

    int result = Facto::FactI(5);
    std::cout << "el resultado es : " << result  << std::endl; 

     result = Facto::FactR(5);
    std::cout << "el resultado recursivo : " << result << std::endl;

}

