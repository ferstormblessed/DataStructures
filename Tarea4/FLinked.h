//Act 2.1 - Implementación de un ADT de estructura de datos lineales 
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 27 de septiembre del 2021

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
        node <T>* last;
        FLinked <T>() {
            first = NULL;
            last = NULL;
        }

        void create(T data) {
			if (!first) {
				// The list is empty
				first = new node<T>;
				first -> data = data;
				first -> next = NULL;
				last = first;
			}
			else {
				// The list isn't empty
				if (last == first) {
					// The list has one element
					last = new node<T>;
					last -> data = data;
					last -> next = NULL;
					first -> next = last;
				}
				else {
					// The list has more than one element
					node<T>* insdata = new node<T>;
					insdata -> data = data;
					insdata -> next = NULL;
					last -> next = insdata;
					last = insdata;
				}
			}
		}

        T read(int index) {
			if (index == 0) {
				// Get the first element
				return this -> first -> data;
			}
			else {
				// Get the index'th element
				node<T>* curr = this -> first;
				for (int i = 0; i < index; ++i) {
					curr = curr -> next;
				}
				return curr -> data;
			}
		}

        void update(int index, T data) {
			if (index == 0) {
				//If index is the first element replace the data
				this -> first -> data = data;
			}
			else {
				// Get the index'th element and replace the data
				node<T>* curr = this -> first;
				for (int i = 0; i < index; ++i) {
					curr = curr -> next;
				}
				curr -> data = data;
			}
		}

        void del(int index) {
			node<T>* temp1 = this -> first;
			if (index == 0) {
				//if index is 0, we change first to point to the next and delete temp1
				first = temp1 -> next;
				delete(temp1);
			}
			else {
				for (int i = 0; i < index - 1; ++i) {
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
