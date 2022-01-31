//Act 3.1 - Operaciones avanzadas en un BST 
//Salvador Fernando Camacho Hernandez A01634777
//Martes 12 de octubre del 2021

#ifndef TREE_H
#define TREE_H

#include <vector>
#include <queue>
#include "TreeNode.h"

class Tree {
    private:
        TreeNode* root;

    public:
        Tree();
        void insert_node(TreeNode*);
        void preorden();
        void preorden_helper(TreeNode*);
        void inorden();
        void inorden_helper(TreeNode*);
        void postorden();
        void postorden_helper(TreeNode*);
        void level_by_level();
        void level_by_level_helper(TreeNode*);
        void visit(int);
        int height();
        int height_helper(TreeNode*);
        void ancestor(int);
        bool ancestor_helper(TreeNode*, int);
        int what_level_am_I(TreeNode*);
        int what_level_am_I_helper(TreeNode*, int, int);
        void mensaje();
};

Tree::Tree() {
    this -> root = NULL;
}

void Tree::insert_node(TreeNode* node) { //O(log n)
    //Tree is empty
    if (this -> root == NULL)
        this -> root = node;
    //Tree has nodes
    else
        this -> root -> insert(node);
}

void Tree::preorden() { 
    std::cout << "Recorrido preorden:" << std::endl;
    preorden_helper(this -> root);
}

void Tree::preorden_helper(TreeNode* node) { //O(n)
    if (node == NULL) return;

    std::cout << node -> get_data() << " ";
    preorden_helper(node -> get_left_node());
    preorden_helper(node -> get_right_node());
}

void Tree::inorden() {
    std::cout << "Recorrido inorden:" << std::endl;
    inorden_helper(this -> root);
}

void Tree::inorden_helper(TreeNode* node) { //O(n)
    if (node == NULL) return;

    inorden_helper(node -> get_left_node());
    std::cout << node -> get_data() << " ";
    inorden_helper(node -> get_right_node());
}

void Tree::postorden() {
    std::cout << "Recorrido postorden:" << std::endl;
    postorden_helper(this -> root);
}

void Tree::postorden_helper(TreeNode* node) { //O(n)
    if (node == NULL) return;

    postorden_helper(node -> get_left_node());
    postorden_helper(node -> get_right_node());
    std::cout << node -> get_data() << " ";
}

void Tree::level_by_level() {
    std::cout << "Recorrido level by level:" << std::endl;
    level_by_level_helper(this -> root);
}

//https://www.geeksforgeeks.org/level-order-tree-traversal/
void Tree::level_by_level_helper(TreeNode* node) { //O(n)
    //Tree is empty
    if (node == NULL)
        std::cout << "Tree is empty" << std::endl;

    //Crear queue para guardar los nodos por nivel
    std::queue<TreeNode*> q;
    q.push(node);

    while (q.empty() == false) {
        //Imprimir y remover el primer nodo de la queue
        TreeNode* node2 = q.front();
        std::cout << node2 -> get_data() << " ";
        q.pop();

        //Agregar al principio de la queue el hijo izquierdo
        if (node2 -> get_left_node() != NULL)
            q.push(node2 -> get_left_node());

        //Agregar al principio de la queue el hijo derecho
        if (node2 -> get_right_node() != NULL)
            q.push(node2 -> get_right_node());
    }
}

void Tree::visit(int recorrido) { //Recibe un entero que representa el tipo de recorrido - preorden, inorden, postorden o level by level - a hacer por el arbol.
    (recorrido == 1) ? Tree::preorden() :  
    (recorrido == 2) ? Tree::inorden() :
    (recorrido == 3) ? Tree::postorden() :
    (recorrido == 4) ? Tree::level_by_level() :
    Tree::mensaje();
}

int Tree::height() {
    //Getting height of tree
    return height_helper(this -> root);
}

int Tree::height_helper(TreeNode* node) { //O(n)
    int h = 0;
    if (node != NULL) {
        //Traverse left subtree
        int l_height = height_helper(node -> get_left_node());
        //Traverse right subtree
        int r_height = height_helper(node -> get_right_node());
        //Get the greater of the heights
        int max_height = std::max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

void Tree::ancestor(int data) {
    //Tree is empty
    if (this -> root == NULL) 
        std::cout << "Tree is empty" << std::endl;
    //Tree has only one node
    else if (this -> root -> get_data() == data){
        std::cout << "Ancestors of " << data << ": " << std::endl;
        std::cout << data << " is the root of the tree";
    } 
    //Printing ancestors
    else {
        std::cout << "Ancestors of " << data << ": " << std::endl;
        ancestor_helper(this -> root, data);
    }
}

//https://www.youtube.com/watch?v=1-z-kptKTFM
bool Tree::ancestor_helper(TreeNode* node, int data) { //O(n)
    //End of tree and not the node we want
    if (node == NULL) return false;
    //Found the data to get its ancestors
    else if (node -> get_data() == data) return true;
    //Printing the ancestors
    else if (ancestor_helper(node -> get_left_node(), data) || ancestor_helper(node -> get_right_node(), data)) {
        std::cout << node -> get_data() << " ";
        return true;
    }
    else return false;
}

int Tree::what_level_am_I(TreeNode* node) {
    //Getting level of node
    return what_level_am_I_helper(this -> root, node -> get_data(), 0);
}

//https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
int Tree::what_level_am_I_helper(TreeNode* node, int data, int level) { //O(n)
    //Node is empty so height equal -1
    if (node == NULL) return -1;
    //Return level if it's the node we want
    else if (node -> get_data() == data) return level;
    //Traverse left subtree and the level increments
    int l_down_level = what_level_am_I_helper(node -> get_left_node(), data, level + 1);
    //Traverse right subtree and the level increments 
    int r_down_level = what_level_am_I_helper(node -> get_right_node(), data, level + 1);
    //If the node we want is on the left subtree we return down_level
    if (l_down_level != -1) return l_down_level;
    else if (r_down_level != -1) return r_down_level;
    //The node is not on the tree
    return -1;
}

void Tree::mensaje() {
    std::cout << "Opción no válida" << std::endl;
}

#endif //TREE_H