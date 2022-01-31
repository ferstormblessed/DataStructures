//Act 3.4 - Actividad Integral de BST (Evidencia Competencia)
//Francisco José Ramírez Aldaco A01634262
//Salvador Fernando Camacho Hernandez A01634777
//Hector Robles Villareal A01634105
//Sábado 30 de octubre del 2021

#include "Bst.h"

//O(log(n)), hace recursión hasta el fondo del árbol balanceado, que tiene log_2(n) niveles
int avl_tree::height(avl* t) { //Calcula la altura de un subárbol
    int h = 0;
    if (t != NULL) {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

//O(log(n)), porque usa la altura 2 veces, el resto es constante
int avl_tree::difference(avl* t) { //Calcula la diferencia entre el subárbol izquierdo y el derecho
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}

//Rotaciones para balancear el árbol, O(1) porque solo actualizan apuntadores
avl* avl_tree::rr_rotat(avl* parent) {
    avl* t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    return t;
}

avl* avl_tree::ll_rotat(avl* parent) {
    avl* t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
    return t;
}

avl* avl_tree::lr_rotat(avl* parent) {
    avl* t;
    t = parent->l;
    parent->l = rr_rotat(t);
    return ll_rotat(parent);
}

avl* avl_tree::rl_rotat(avl* parent) {
    avl* t;
    t = parent->r;
    parent->r = ll_rotat(t);
    return rr_rotat(parent);
}

avl* avl_tree::balance(avl* t) { //Rota el árbol hasta que quede balanceado
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1) {
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}

//O(log(n)) por el balanceo y porque busca el nodo donde se va a insertar
avl* avl_tree::insert(avl* r, int acc, string ip) { //Inserta un nuevo nodo y balancea el árbol
    if (r == NULL) {
        r = new avl;
        r->acc = acc;
        r->ip = ip;
        r->l = NULL;
        r->r = NULL;
        return r;
    }
    else if (acc < r->acc) {
        r->l = insert(r->l, acc, ip);
        r = balance(r);
    }
    else if (acc >= r->acc) {
        r->r = insert(r->r, acc, ip);
        r = balance(r);
    } return r;
}

//O(log(n)), baja log_2(n) niveles a la derecha y luego imprime 5 nodos
int avl_tree::printTop5(avl* t, int rem) { //Usa la variable rem para imprimir recursivamente las 5 IPs con más accesos
    if (t == NULL)
        return rem;
    rem = printTop5(t->r, rem);
    if (rem > 0) { 
        cout << t->ip << " : " << t->acc << " acceso(s)" << endl;
        rem--;
    }
    rem = printTop5(t->l, rem);
}

//O(1), solo crea un nodo
avl* avl_tree::newNode(int acc, string ip) { //Crea un nuevo nodo
    avl* Node = new avl();
    Node->acc = acc;
    Node->ip = ip;
    Node->l = NULL;
    Node->r = NULL;
    return (Node);
}