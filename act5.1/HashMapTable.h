//Act 5.1 - Implementación individual de operaciones sobre conjuntos 
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 22 de noviembre del 2021

#ifndef HASHMAPTABLE_H
#define HASHMAPTABLE_H

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <fstream>
#include <sstream>
#include "HashTableEntry.h" 

const int T_S = 10; //length of hash table

class HashMapTable {
    private:
        vector< vector<HashTableEntry> > t;
    public:
        HashMapTable();
        static int HashFunc(int);
        void Insert_chain(int, string);
        void Insert_quadratic(int, string);
        static vector<HashTableEntry> readFile(string);
        static void chain(HashMapTable*, vector<HashTableEntry>);
        static void quadratic(HashMapTable*, vector<HashTableEntry>);
        void showHash_chain();
        void showHash_quadratic();
};

HashMapTable::HashMapTable() {   
    t.resize(T_S); //set size of hash table
}

int HashMapTable::HashFunc(int k) {
    return k % T_S;
}

void HashMapTable::Insert_chain(int k, string text) { //O(1)
    int h = HashMapTable::HashFunc(k);
    //create entry
    HashTableEntry entry(k, text);
    //push the entry to the list
    t[h].push_back(entry);
}

void HashMapTable::Insert_quadratic(int k, string text) { //O(n)
    int h = HashMapTable::HashFunc(k);
    HashTableEntry entry(k, text);
    int cont = 0;
    //check if the position is occupied
    while(!t[h].empty()) { // O(n)
        cont++;
        //get another value for h
        h = HashMapTable::HashFunc(k + cont * cont);
    }
    //push the entry to the list
    t[h].push_back(entry);
}

//Reads a file where the data is stored and returns a vector
vector<HashTableEntry> HashMapTable::readFile(string file) {
    vector<HashTableEntry> entries;

    ifstream ifs;
    ifs.open(file);
    string line;

    while(getline(ifs, line)) {
        stringstream s;
        s << line;
        int _k;
        string _text, coma;
        s >> _k >> coma >> _text;
        HashTableEntry entry(_k, _text);
        entries.push_back(entry);
    }

    ifs.close();
    return entries;
}

void HashMapTable::chain(HashMapTable* hash, vector<HashTableEntry> entries) {
    for(int i = 0; i < entries.size(); i++) {
        HashTableEntry entry = entries[i];
        int _k = entry.k;
        string _text = entry.text;
        hash->Insert_chain(_k, _text);
    }
}

void HashMapTable::quadratic(HashMapTable* hash, vector<HashTableEntry> entries) {
    for(int i = 0; i < entries.size(); i++) {
        HashTableEntry entry = entries[i];
        int _k = entry.k;
        string _text = entry.text;
        hash->Insert_quadratic(_k, _text);
    }
}

void HashMapTable::showHash_chain() {
    for(int i = 0; i < T_S; i++) {
        cout << i;
        if(!t[i].empty()) {
            for(int j = 0; j < t[i].size(); j++)
                t[i][j].showEntry();
        }
        cout << endl;
    }
}

void HashMapTable::showHash_quadratic() {
    for(int i = 0; i < T_S; i++) {
        cout << i;
        if(!t[i].empty())
            t[i][0].showEntry();
        cout << endl;
    }
    
}

#endif //HASHMAPTABLE_H