// Preferences_ADA.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/*
Laboratorio Divide y Venceras
Analisis y Diseño de Algoritmos
21/05/2025
Integrantes:
    Cristian Mellado Baca
    Manuel Charaja Quispe
*/

#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int ini, int mid, int fin) {
    int i = ini, j = mid + 1, k = 0, count = 0;
    int temp[20];
    
    while (i <= mid && j <= fin) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
            cout << (mid - i + 1)<<" ";
            //cout << count<<" ";
        }
    }

    while (i <= mid){
        temp[k++] = arr[i++];
    }
        
    while (j <= fin) {
        temp[k++] = arr[j++];
    }
       
    for (i = 0; i < k; i++) {
        arr[ini + i] = temp[i];
    }

    return count;
}

int sortAndCount(int arr[], int ini, int fin) {
    if (ini >= fin)
        return 0;

    int mid = (ini + fin) / 2; //para partir la lista

    int INICIO = sortAndCount(arr, ini, mid); //la primera mitad
    int FINAL = sortAndCount(arr, mid + 1, fin); //la segunda mitad

    int Merge = mergeAndCount(arr, ini, mid, fin); //para combinar

    return INICIO + FINAL + Merge;
}

int main() {
    cout << "Array Inicial" << endl;
    int arr[] = {3,7,10,14,18,19,2,11,16,17,23,25};

    for (int* p = arr; p < arr + 12; p++) {
        cout << *p << " ";
    }
    cout << endl;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Inversiones: ";
    int totalInversiones = sortAndCount(arr, 0, n - 1);
    cout <<endl<< "Numero de inversiones: " << totalInversiones << endl<<endl;

    cout << "Array Final" << endl;
    for (int *p = arr; p < arr+12; p++) {
        cout << *p<<" ";
    }

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
