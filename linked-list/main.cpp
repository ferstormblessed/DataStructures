//Act 2.1 - Implementación de un ADT de estructura de datos lineales 
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 27 de septiembre del 2021

#include <iostream>
#include "FLinked.h"

using namespace std;

int main() {

    FLinked<int> list;

    //Adding numbers to the list
    list.create(9);
    list.create(10);
    list.create(11);
    list.create(12);
    list.create(13);

    //Printing the list
    for (int i = 0; i < 5; i++) {
        cout << list[i] << " ";
    }

    //Reading specific positions
    cout << endl << endl;
    cout << "Elemento 0: " << list.read(0) << endl;
    cout << "Elemento 2: " << list.read(2) << endl;
    cout << "Elemento 4: " << list.read(4) << endl;
    cout << endl;

    //Updating specific positions
    cout << "Updating postion 0 with a number 0" << endl << "Updating postion 3 with a number 3" << endl << "Updating postion 4 with a number 4" << endl << endl;
    list.update(0,0);
    list.update(3,3);
    list.update(4,4);
    //Printing the list
    for (int i = 0; i < 5; i++) {
        cout << list[i] << " ";
    }

    //Deleting specific positions
    cout << endl << endl << "Deleting position 0" << endl;
    list.del(0);
    //Printing the list
    for (int i = 0; i < 4; i++) {
        cout << list[i] << " ";
    }
    cout << endl << endl << "Deleting position 3" << endl;
    list.del(3);
    //Printing the list
    for (int i = 0; i < 3; i++) {
        cout << list[i] << " ";
    }

    return 0;
}
