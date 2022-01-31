//Act 1.2 - Algoritmos de Busqueda y Ordenamiento
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 6 de septiembre de 2021

#include <vector>

class Ordenamiento{
    public:
        static void ordenaIntercambio(std::vector<int> &);
        static void ordenaBurbuja(std::vector<int> &);
        static void ordenaMerge(std::vector<int> &, int, int);
        static int busqSecuencial(std::vector<int> &, int);
        static int busqBinaria(std::vector<int> &, int);
        static void print(std::vector<int>);
    private:
	    static void swap(int*, int*);
        static void merge(std::vector<int> &, int, int, int);
};