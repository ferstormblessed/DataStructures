//https://www.geeksforgeeks.org/c-program-hashing-chaining/
//https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
//https://www.educative.io/edpresso/how-to-implement-a-hash-table-in-cpp


#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int T_S = 200;
class HashTableEntry {
public:
    int k;
    string text;
    HashTableEntry(int k, string text) {
        this->k = k;
        this->text = text;
    }
};
class HashMapTable {
private:
    HashTableEntry** t;
public:
    HashMapTable() {
        t = new HashTableEntry * [T_S];
        for (int i = 0; i < T_S; i++) {
            t[i] = NULL;
        }
    }
    int HashFunc(int k) {
        return k % T_S;
    }
    void Insert(int k, string text) {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k == k) {
            h = HashFunc(h + 1);
        }
        if (t[h] != NULL)
            delete t[h];
        t[h] = new HashTableEntry(k, text);
    }
    string SearchKey(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL)
            return "";
        else
            return t[h]->text;
    }
    void Remove(int k) {
        int h = HashFunc(k);
        while (t[h] != NULL) {
            if (t[h]->k == k)
                break;
            h = HashFunc(h + 1);
        }
        if (t[h] == NULL) {
            cout << "No Element found at key " << k << endl;
            return;
        }
        else {
            delete t[h];
        }
        cout << "Element Deleted" << endl;
    }
    ~HashMapTable() {
        for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
                delete t[i];
            delete[] t;
        }
    }
};
int main() {
    HashMapTable hash;
   
    hash.Insert(1, "hola");
    hash.Insert(4, "adios");
    hash.Insert(2, "Anne");


    cout << hash.SearchKey(2);
    hash.Remove(2);


    return 0;
}