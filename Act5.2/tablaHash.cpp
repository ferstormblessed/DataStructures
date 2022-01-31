#include "Dato.h"
#include "tablaHash.h"
#include <iostream>
#include <algorithm>

using namespace std;
HashTable::HashTable(int size) { //Crea una HashTable vacía
    this->size = size;
    table = new vector<HashTableEntry>[size];
    status = vector<char>(size, 'v');
}

int HashTable::hashFunc(long long key) { //Calcula el hash de una determinada clave, O(1)
    return (key % size);
}

void HashTable::chain(long long key, string text) { //Encadena el nuevo valor si la posición está ocupada, O(1)
    HashTableEntry e(key, text);              //(Manejo de desbordamiento por encadenamiento)
    int h = hashFunc(key);
    table[h].push_back(e);
    status[h] = 'o';
}

void HashTable::removeVal(long long key) { //Elimina un elemento, asumiendo que está encadenado
    int h = hashFunc(key);        //O(1) asumiendo que las claves están distribuidas uniformemente
    vector<HashTableEntry>::iterator i;
    for (i = table[h].begin(); i != table[h].end(); i++) {
        if ((*i).key == key) break;
    }
    if (i != table[h].end()) table[h].erase(i);
    if (table[h].size() == 0) status[h] = 'b';
}

void HashTable::displayDetails(string ip) {
    cout << ip;
    bool found = false;
    ip.erase(remove(ip.begin(), ip.end(), '.'), ip.end()); //Le quita los puntos y el puerto a las Ips
    long long key = stoll(ip); //Hace la ip un long
    int h = hashFunc(key);
    for (auto x : table[h])
        if (x.key == key) {
            cout << " --> " << Dato::decodeResumen(x.text);
            found = true;
            break;
        }
    if (!found) cout << " --> Not found";
    cout << endl;
}

void HashTable::displayAll() {
    for (int i=0; i<size; i++) {
        if (status[i] == 'o') {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x.text;
            cout << endl;
        }
    }
}
