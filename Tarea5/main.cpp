//Act 2.2 - Verificación de las funcionalidades de una estructura de datos lineal 
//Salvador Fernando Camacho Hernandez A01634777
//Martes 28 de septiembre del 2021

#include <iostream>
#include "Flinked.h"

using namespace std;

int main() {

    FLinked<int> list; // Create linked list

    //Casos de prueba

    list.create(3,0); // Add int 3 to position 0
    list.create(4,1); // Add int 4 to position 1
    list.create(5,2); // Add int 5 to position 2

    // Print list
    cout << list[0] << " " << list[1] << " " << list[2] << endl;

    list.create(0,0); // Add int 0 to position 0, which moves all the existent numbers in the list

    //Print list
    cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << endl;

    list.create(20,2); // Add int 20 to position 2, which moves all the numbers after position 2

    // Print list
    cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << " " << list[4] << endl;

    list.create(100,5); // Add int 100 to the end of the list

    //Print list
    cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << " " << list[4] << " " << list[5] << endl << endl;

    FLinked<int> list1;

    //Adding numbers to the list
    list1.create(9,0);
    list1.create(10,1);
    list1.create(11,2);
    list1.create(12,3);
    list1.create(13,4);

    //Printing the list
    for (int i = 0; i < 5; i++) {
        cout << list1[i] << " ";
    }

    //Reading specific positions
    cout << endl << endl;
    cout << "Elemento 0: " << list1.read(0) << endl;
    cout << "Elemento 2: " << list1.read(2) << endl;
    cout << "Elemento 4: " << list1.read(4) << endl;
    cout << endl;

    //Updating specific positions
    cout << "Updating postion 0 with a number 0" << endl << "Updating postion 3 with a number 3" << endl << "Updating postion 4 with a number 4" << endl << endl;
    list1.update(0,0);
    list1.update(3,3);
    list1.update(4,4);

    //Printing the list
    for (int i = 0; i < 5; i++) {
        cout << list1[i] << " ";
    }

    //Deleting specific positions
    cout << endl << endl << "Deleting position 0" << endl;
    list1.del(0);
    //Printing the list
    for (int i = 0; i < 4; i++) {
        cout << list1[i] << " ";
    }
    cout << endl << endl << "Deleting position 3" << endl;
    list1.del(3);

    //Printing the list
    for (int i = 0; i < 3; i++) {
        cout << list1[i] << " ";
    }

    cout << endl << endl;
    
    return 0;
}