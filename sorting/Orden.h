#pragma once
#include <vector>

class Orden
{
public:
	static void ordIntercambio(int [], int );

	static void burbuja(int[], int);

	static void burbuja2(int[], int);

	static void burbuja2(std::vector<int> &);


	static void ordSeleccion(int[], int);

	static void ordInsercion(int[], int);

	static void mergeSort(int arr[], int l, int r);

	static void quickSort(int [], int , int );


private:
	static void swap(int*, int*);
	static void merge(int arr[], int, int, int);
	static int partition(int[], int, int);

};

