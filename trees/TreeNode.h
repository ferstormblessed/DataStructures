//Act 3.1 - Operaciones avanzadas en un BST 
//Salvador Fernando Camacho Hernandez A01634777
//Martes 12 de octubre del 2021

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

class TreeNode {
    private:
        int data;
        TreeNode* left_node;
        TreeNode* right_node;
    
    public:
        TreeNode(int);
        int get_data();
        TreeNode* get_left_node();
        TreeNode* get_right_node();
        void insert(TreeNode*);
};

TreeNode::TreeNode(int node_data) { //Recibe la data que va tener el nodo
    this -> data = node_data;
    this -> left_node = NULL;
    this -> right_node = NULL;  
}

int TreeNode::get_data() {
    return this -> data;
}

TreeNode* TreeNode::get_left_node() {
    return this -> left_node;
}

TreeNode* TreeNode::get_right_node() {
    return this -> right_node;
}

void TreeNode::insert(TreeNode* node) { //O(log n)
    //insert in left subtree
    if (node -> get_data() < this -> data) {
        //insert new TreeNode
        if(this -> left_node == NULL) 
            this -> left_node = node;
        //continue traversing left subtree
        else
            this -> left_node -> insert(node);
    }
    //insert in right subtree
    else if (node -> get_data() > this -> data) {
        //insert new TreeNode
        if (this -> right_node == NULL)
            this -> right_node = node;
        //continue traversing right node
        else
            this -> right_node -> insert(node);
    }
}

#endif //TREENODE_H