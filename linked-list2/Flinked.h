//Act 2.2 - Verificación de las funcionalidades de una estructura de datos lineal 
//Salvador Fernando Camacho Hernandez A01634777
//Martes 28 de septiembre del 2021

#ifndef FLINKED_H
#define FLINKED_H

#pragma once
#include <iostream>

using namespace std;

template <class T>
struct node {
    node <T>* next;
    T data;
};

template <class T>
class FLinked {
    public:
        node <T>* first;
        FLinked <T>() {
            first = NULL;
        }

		//https://www.youtube.com/watch?v=IbvsNF22Ud0
		void create(T data, int index) {
			// Create the now to insert
			node<T>* temp1 = new node<T>;
			temp1 -> data = data;
			temp1 -> next = NULL;

			if (index == 0) { // O(1)
				temp1 -> next = first; // The value we are inserting points to what was the first positon
				first = temp1; // The value we are inserting is now the first value of the list
			}
			else {
				node<T>* temp2 = first;
				for (int i = 0; i < index - 1; i++) { // O(n)
					temp2 = temp2 -> next; // Points to the index - 1 position
				}
				temp1 -> next = temp2 -> next; // The value we want to insert in the list points to the index + 1 position
				temp2 -> next = temp1; // The value in the position index - 1 points to the value we are inserting
			}
		}

        T read(int index) {
			if (index == 0) { // O(1)
				// Get the first element
				return this -> first -> data;
			}
			else {
				// Get the index'th element
				node<T>* curr = this -> first;
				for (int i = 0; i < index; ++i) { // O(n)
					curr = curr -> next;
				}
				return curr -> data;
			}
		}

        void update(int index, T data) {
			if (index == 0) { // O(1)
				//If index is the first element replace the data
				this -> first -> data = data;
			}
			else {
				// Get the index'th element and replace the data
				node<T>* curr = this -> first;
				for (int i = 0; i < index; ++i) { // O(n)
					curr = curr -> next;
				}
				curr -> data = data;
			}
		}

        void del(int index) {
			node<T>* temp1 = this -> first;
			if (index == 0) { // O(1)
				//if index is 0, we change first to point to the next and delete temp1
				first = temp1 -> next;
				delete(temp1);
			}
			else {
				for (int i = 0; i < index - 1; ++i) { // O(n)
					temp1 = temp1 -> next; //points to the index-1 position
				}
				node<T>* temp2 = temp1 -> next; //points to the index position
				temp1 -> next = temp2 -> next; // points to the index+1 position
				delete(temp2); //deletes index position
			}
		}

		T operator[](int index) {
			return read(index);
		}
};

#endif // FLINKED_H
