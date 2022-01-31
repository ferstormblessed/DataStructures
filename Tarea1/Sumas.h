//Act 1.1 - Funciones iterativas, Recursivas y su analisis de complejidad
//Salvador Fernando Camacho Hernandez A01634777
//Lunes 16 de agosto de 2021

#ifndef SUMAS_H
#define SUMAS_H

class Sumas{
    public:
        static int sumaIterativa(int);
        static int sumaRecursiva(int);
        static int sumaDirecta(int);
};

int Sumas::sumaIterativa(int n){ //O(n) Lineal
    int suma = 0;
    for (int i = 0; i <= n; i++)
        suma += i;
    return suma;
}

int Sumas::sumaRecursiva(int n){ //O(n) Lineal
    if (n == 0)
        return 0;
    else
        return n + Sumas::sumaRecursiva(n - 1);
}

int Sumas::sumaDirecta(int n){ //O(1) Constante  
    return float(n * (n + 1) / 2);
}

#endif //SUMAS_H