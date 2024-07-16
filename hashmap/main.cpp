//Act 5.1 - Implementación individual de operaciones sobre conjuntos 
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 22 de noviembre del 2021

#include "HashMapTable.h"

int main() {
    //create hash tables
    HashMapTable hash_chain;
    HashMapTable hash_quadratic;
    
    //read file
    vector<HashTableEntry> entries = HashMapTable::readFile("entries.txt");

    //put data in hash tables
    HashMapTable::chain(&hash_chain, entries);
    HashMapTable::quadratic(&hash_quadratic, entries);

    //display the hash tables
    //hash_chain.showHash_chain();
    cout << endl;
    hash_quadratic.showHash_quadratic();
    cout << endl;

    return 0;
}