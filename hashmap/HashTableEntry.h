//Act 5.1 - Implementación individual de operaciones sobre conjuntos 
//Salvador Fernando Camacho Hernandez A01634777
//Viernes 26 de noviembre del 2021

#ifndef HASHTABLEENTRY_H
#define HASHTABLEENTRY_H

#include <iostream>
#include <string>

using namespace std;

class HashTableEntry {
    public:
        int k; 
        string text;
        HashTableEntry(int, string);
        void showEntry();
};

HashTableEntry::HashTableEntry(int k, string text) {
    this->k = k;
    this->text = text;
}

void HashTableEntry::showEntry() {
    cout << " <-- " << text;
}

#endif //HASHTABLEENTRY_H