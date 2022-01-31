//Act 1.2 - Algoritmos de Busqueda y Ordenamiento
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 6 de septiembre de 2021

#include <iostream>
#include <vector>
#include "Ordenamiento.h"

void Ordenamiento::ordenaIntercambio(std::vector<int> &vect){  // O(n^2) 
    int i, j, aux; /* se realizan n-1 pasadas, a[o] ... a[n-2] */
	for (i = 0; i <= vect.size() - 2; i++){/* coloca m�nimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= vect.size() - 1; j++){
			if (vect[i] > vect[j]){
				aux = vect[i];
				vect[i] = vect[j];
				vect[j] = aux;
			}
        }
    }
}

void Ordenamiento::ordenaBurbuja(std::vector<int> &vect){ // O(n^2) 
    int i, j;
	for (i = 0; i < vect.size() ; i++){
		// Last i elements are already in place  
		for (j = i+1; j < vect.size() ; j++){
			if (vect[i] > vect[j]){
				swap(&vect[i], &vect[j]);
            }
        }
    }
}

void Ordenamiento::ordenaMerge(std::vector<int> &vect, int l, int r){ // O(nlog(n))
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		ordenaMerge(vect, l, m);
		ordenaMerge(vect, m + 1, r);

		merge(vect, l, m, r);
    }
}

void Ordenamiento::merge(std::vector<int> &vect, int start, int mid, int end){
	int start2 = mid + 1;

	// If the direct merge is already sorted 
	if (vect[mid] <= vect[start2]) {
		return;
	}

	// Two pointers to maintain start 
	// of both arrays to merge 
	while (start <= mid && start2 <= end) {

		// If element 1 is in right place 
		if (vect[start] <= vect[start2]) {
			start++;
		}
		else {
			int value = vect[start2];
			int index = start2;

			// Shift all the elements between element 1 
			// element 2, right by 1. 
			while (index != start) {
				vect[index] = vect[index - 1];
				index--;
			}
			vect[start] = value;

			// Update all the pointers 
			start++;
			mid++;
			start2++;
		}
	}
}

int Ordenamiento::busqSecuencial(std::vector<int> &vect, int clave){ //O(n)
    for (int i = 0; i < vect.size(); i++){
        if (clave == vect[i]){
            return i;
        }
    }
    return -1;
}

int Ordenamiento::busqBinaria(std::vector<int> &vect, int clave){ //O(log(n))
	int central, bajo, alto, valorCentral;
	bajo = 0;
	alto = vect.size() - 1;
	while (bajo <= alto) {
		central = (bajo + alto) / 2;
		valorCentral = vect[central];
		if (clave == valorCentral)
			return central;
		else if (clave < valorCentral)
			alto = central - 1;
		else
			bajo = central + 1;
	}
	return -1;
}

void Ordenamiento::swap(int* val1, int* val2){
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void Ordenamiento::print(std::vector<int> vector){
    for (int i = 0; i < vector.size(); i++){
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

int main(){

	std::cout << "CASO 1" << std::endl;

    std::vector<int> v1Inter{ 6, 5, 7, 3, 9, 10, 1, 4 };
    std::vector<int> v1Burb{ 6, 5, 7, 3, 9, 10, 1, 4 };
    std::vector<int> v1Merge{ 6, 5, 7, 3, 9, 10, 1, 4 };
    std::vector<int> v1Sec{ 6, 5, 7, 3, 9, 10, 1, 4 };
    std::vector<int> v1Bin{ 6, 5, 7, 3, 9, 10, 1, 4 };

    std::cout << "Vector original: " << std::endl;
    Ordenamiento::print(v1Inter);

    std::cout << "Vector ordenado - Intercambio: " << std::endl;
    Ordenamiento::ordenaIntercambio(v1Inter);
    Ordenamiento::print(v1Inter);

    std::cout << "Vector ordenado - Burbuja: " << std::endl;
    Ordenamiento::ordenaBurbuja(v1Burb);
    Ordenamiento::print(v1Burb);

    std::cout << "Vector ordenado - Merge: " << std::endl;
    Ordenamiento::ordenaMerge(v1Merge, 0, v1Merge.size() - 1);
    Ordenamiento::print(v1Merge);

    std::cout << "Busqueda secuencial:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqSecuencial(v1Sec, 10) << std::endl << std::endl;

    std::cout << "Busqueda binaria:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqBinaria(v1Bin, 10) << std::endl;

	std::cout << "CASO 2" << std::endl;

	std::vector<int> v2Inter{ 15, 4, 6, 3, 2, 89, 9 };
    std::vector<int> v2Burb{ 15, 4, 6, 3, 2, 89, 9 };
    std::vector<int> v2Merge{ 15, 4, 6, 3, 2, 89, 9 };
    std::vector<int> v2Sec{ 15, 4, 6, 3, 2, 89, 9 };
    std::vector<int> v2Bin{ 15, 4, 6, 3, 2, 89, 9 };

    std::cout << "Vector original: " << std::endl;
    Ordenamiento::print(v2Inter);

    std::cout << "Vector ordenado - Intercambio: " << std::endl;
    Ordenamiento::ordenaIntercambio(v2Inter);
    Ordenamiento::print(v2Inter);

    std::cout << "Vector ordenado - Burbuja: " << std::endl;
    Ordenamiento::ordenaBurbuja(v2Burb);
    Ordenamiento::print(v2Burb);

    std::cout << "Vector ordenado - Merge: " << std::endl;
    Ordenamiento::ordenaMerge(v2Merge, 0, v2Merge.size() - 1);
    Ordenamiento::print(v2Merge);

    std::cout << "Busqueda secuencial:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqSecuencial(v2Sec, 10) << std::endl << std::endl;

    std::cout << "Busqueda binaria:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqBinaria(v2Bin, 10) << std::endl;

	std::cout << "CASO 3" << std::endl;

	std::vector<int> v3Inter{ 10, 4, 7, 1, 34, 11, 2 };
    std::vector<int> v3Burb{ 10, 4, 7, 1, 34, 11, 2 };
    std::vector<int> v3Merge{ 10, 4, 7, 1, 34, 11, 2 };
    std::vector<int> v3Sec{ 10, 4, 7, 1, 34, 11, 2 };
    std::vector<int> v3Bin{ 10, 4, 7, 1, 34, 11, 2 };

    std::cout << "Vector original: " << std::endl;
    Ordenamiento::print(v3Inter);

    std::cout << "Vector ordenado - Intercambio: " << std::endl;
    Ordenamiento::ordenaIntercambio(v3Inter);
    Ordenamiento::print(v3Inter);

    std::cout << "Vector ordenado - Burbuja: " << std::endl;
    Ordenamiento::ordenaBurbuja(v3Burb);
    Ordenamiento::print(v3Burb);

    std::cout << "Vector ordenado - Merge: " << std::endl;
    Ordenamiento::ordenaMerge(v3Merge, 0, v3Merge.size() - 1);
    Ordenamiento::print(v3Merge);

    std::cout << "Busqueda secuencial:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqSecuencial(v3Sec, 10) << std::endl << std::endl;

    std::cout << "Busqueda binaria:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqBinaria(v3Bin, 10) << std::endl;

	std::cout << "CASO 4" << std::endl;

	std::vector<int> v4Inter{ 1, 2, 8, 6, 4, 3, 12 };
    std::vector<int> v4Burb{ 1, 2, 8, 6, 4, 3, 12 };
    std::vector<int> v4Merge{ 1, 2, 8, 6, 4, 3, 12 };
    std::vector<int> v4Sec{ 1, 2, 8, 6, 4, 3, 12 };
    std::vector<int> v4Bin{ 1, 2, 8, 6, 4, 3, 12 };

    std::cout << "Vector original: " << std::endl;
    Ordenamiento::print(v4Inter);

    std::cout << "Vector ordenado - Intercambio: " << std::endl;
    Ordenamiento::ordenaIntercambio(v4Inter);
    Ordenamiento::print(v4Inter);

    std::cout << "Vector ordenado - Burbuja: " << std::endl;
    Ordenamiento::ordenaBurbuja(v4Burb);
    Ordenamiento::print(v4Burb);

    std::cout << "Vector ordenado - Merge: " << std::endl;
    Ordenamiento::ordenaMerge(v4Merge, 0, v4Merge.size() - 1);
    Ordenamiento::print(v4Merge);

    std::cout << "Busqueda secuencial:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqSecuencial(v4Sec, 10) << std::endl << std::endl;

    std::cout << "Busqueda binaria:\nValor = 10\nPosicion (en vector original) = " << Ordenamiento::busqBinaria(v4Bin, 10) << std::endl;

    return 0;
}