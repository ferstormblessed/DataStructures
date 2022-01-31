//Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Sábado 30 de octubre del 2021

#ifndef BST_H
#define BST_H

#include<iostream>
#include <string>
#include <queue>
using namespace std;

struct avl { //Nodo del árbol AVL
    int acc;
    string ip;
    struct avl* l;
    struct avl* r;
};

class avl_tree {
    public:
        static int height(avl*);
        int difference(avl*);
        avl* rr_rotat(avl*);
        avl* ll_rotat(avl*);
        avl* lr_rotat(avl*);
        avl* rl_rotat(avl*);
        avl* balance(avl*);
        avl* insert(avl*, int, string);
        static int printTop5(avl*, int rem=5);
        avl* newNode(int, string);
};

#endif //BST_H