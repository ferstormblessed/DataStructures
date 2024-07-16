//Act 1.1 - Funciones iterativas, Recursivas y su analisis de complejidad
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 16 de agosto de 2021

#include <iostream>
#include "Sumas.h"

int main(){

    std::cout << "Caso prueba 1 (100)" << std::endl;
    std::cout << "Suma iterativa: " << Sumas::sumaIterativa(100) << "  ->  Costo lineal - O(n)"<< std::endl;
    std::cout << "Suma Recursiva: " << Sumas::sumaRecursiva(100) << "  ->  Costo Lineal - O(n)" << std::endl;
    std::cout << "Suma Directa: " << Sumas::sumaDirecta(100) << "  ->  Costo Constante - O(1)" << std::endl;

    std::cout << std::endl << "Caso prueba 2 (50)" << std::endl;
    std::cout << "Suma iterativa: " << Sumas::sumaIterativa(50) << "  ->  Costo lineal - O(n)"<< std::endl;
    std::cout << "Suma Recursiva: " << Sumas::sumaRecursiva(50) << "  ->  Costo Lineal - O(n)" << std::endl;
    std::cout << "Suma Directa: " << Sumas::sumaDirecta(50) << "  ->  Costo Constante - O(1)" << std::endl;

    std::cout << std::endl << "Caso prueba 3 (10)" << std::endl;
    std::cout << "Suma iterativa: " << Sumas::sumaIterativa(10) << "  ->  Costo lineal - O(n)"<< std::endl;
    std::cout << "Suma Recursiva: " << Sumas::sumaRecursiva(10) << "  ->  Costo Lineal - O(n)" << std::endl;
    std::cout << "Suma Directa: " << Sumas::sumaDirecta(10) << "  ->  Costo Constante - O(1)" << std::endl;
    
    std::cout << std::endl << "Caso prueba 4 (5)" << std::endl;
    std::cout << "Suma iterativa: " << Sumas::sumaIterativa(5) << "  ->  Costo lineal - O(n)"<< std::endl;
    std::cout << "Suma Recursiva: " << Sumas::sumaRecursiva(5) << "  ->  Costo Lineal - O(n)" << std::endl;
    std::cout << "Suma Directa: " << Sumas::sumaDirecta(5) << "  ->  Costo Constante - O(1)" << std::endl;

    return 0;
} 