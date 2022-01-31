#include <iostream>
#include "Orden.h"
#include "search.h"
#include <vector>

using namespace std;


int main()
{
    
    int array[10] = { 2,4,5,6,7,3,2,4,5,6 };

    int array2[7] = { 29,3,42,17,30,15,8 };

    int array3[7] = { 6,9,2,0,7,5,4 };

    //se puede
    vector<int> vect{ 10, 20, 30 };

    //se puede
    vector<int> unVector;
    unVector.push_back(6);
    unVector.push_back(9);
    unVector.push_back(2);
    unVector.push_back(0);
    unVector.push_back(7);
    unVector.push_back(5);
    unVector.push_back(4);

     int tam = (int)unVector.size();

    Orden::burbuja2(unVector);

    cout << tam << " fue el tama�o" << endl;

    
    //Orden::quickSort(unVector., 0, (sizeof(array2) / sizeof(array2[0]) - 1));

    //Orden::ordSeleccion(array2, 7);

    //Orden::ordIntercambio(array, 10);
    //Orden::burbuja(array, 10);

   // Orden::ordInsercion(array2, 7);

    //Orden::burbuja2(array2, 7);

    int size = sizeof(array2);
    int size2 = sizeof(int);
    int size3 = sizeof(array[0]);

    //std::cout << size << " " << size2 <<  " " << size3 << std::endl;


    Orden::mergeSort(array2 , 0 ,   (sizeof(array2)/sizeof(array2[0]) - 1));

    Orden::quickSort(array3, 0, (sizeof(array2) / sizeof(array2[0]) - 1));



    for (int i = 0; i < 7; i++)
       std::cout << array3[i] << " ";

    /*int a = search::busquedaBin(array2, 7, 29);

    std::cout << std::endl;

    if (a == 0)
        std::cout << "nel";
    else
        std::cout << "si" << a;
    */



}

