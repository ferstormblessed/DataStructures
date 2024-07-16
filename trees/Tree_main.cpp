//Act 3.1 - Operaciones avanzadas en un BST 
//Salvador Fernando Camacho Hernandez A01634777
//Martes 12 de octubre del 2021

#include "Tree.h"

int main() {

    //Crear arbol
    Tree arbol;

    //Creacion de nodos
    TreeNode* root = new TreeNode(10);
    TreeNode* node_1 = new TreeNode(12);
    TreeNode* node_2 = new TreeNode(15);
    TreeNode* node_3 = new TreeNode(7);
    TreeNode* node_4 = new TreeNode(11);
    TreeNode* node_5 = new TreeNode(9);
    TreeNode* node_6 = new TreeNode(2);
    TreeNode* node_7 = new TreeNode(2);
    TreeNode* node_8 = new TreeNode(72);

    TreeNode* node_9 = new TreeNode(10);

    //Insercion de nodos
    arbol.insert_node(root);
    arbol.insert_node(node_1);
    arbol.insert_node(node_2);
    arbol.insert_node(node_3);
    arbol.insert_node(node_4);
    arbol.insert_node(node_5);
    arbol.insert_node(node_6);
    arbol.insert_node(node_7);
    arbol.insert_node(node_8);

    //Recorrido preorden
    arbol.visit(1);
    std::cout << std::endl << std::endl;

    //Recorrido inorden
    arbol.visit(2);
    std::cout << std::endl << std::endl;

    //Recorrido postorden
    arbol.visit(3);
    std::cout << std::endl << std::endl;

    //Recorrido level by level
    arbol.visit(4);
    std::cout << std::endl << std::endl;

    //Altura del arbol
    std::cout << "Altura del arbol: " << arbol.height() << std::endl << std::endl;

    //Ancestros. If the data is not part of the tree, the function prints nothing
    arbol.ancestor(root -> get_data());
    std::cout << std::endl;
    arbol.ancestor(node_4 -> get_data());
    std::cout << std::endl;
    arbol.ancestor(node_8 -> get_data());
    std::cout << std::endl;

    //What level am I
    std::cout << std::endl << "Nivel de " << root -> get_data() << ": " << arbol.what_level_am_I(root) << std::endl;
    std::cout << std::endl << "Nivel de " << node_1 -> get_data() << ": " << arbol.what_level_am_I(node_1) << std::endl;
    std::cout << std::endl << "Nivel de " << node_8 -> get_data() << ": " << arbol.what_level_am_I(node_8) << std::endl;
    std::cout << std::endl << "Nivel de " << node_4 -> get_data() << ": " << arbol.what_level_am_I(node_4) << std::endl;
    std::cout << std::endl << "Nivel de " << node_9 -> get_data() << ": " << arbol.what_level_am_I(node_9) << std::endl << std::endl;

    return 0;
}