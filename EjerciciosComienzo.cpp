#include "EjerciciosComienzo.h"

int suma(int a, int b) {
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
	for (int i = desde; i <= hasta; i++) {
		if (i < hasta) {
			cout << i << "*" << tablaDel << "=" << i * tablaDel << ";";
		} else {
			cout << i << "*" << tablaDel << "=" << i * tablaDel;
		}
	}
}

void simplificar(int n, int d) {
    if (d == 0) {
        cout << "Error" << endl;
    }
    else if (n == 0) {
        cout << "0/" << d << endl;
    }
    else {
        int a = abs(n);
        int b = abs(d);
        int min = (a < b ? a : b);
        int mcd = 1;

        int i = 1;
        while (i <= min) {
            if (a % i == 0 && b % i == 0) mcd = i;
            ++i;
        }
        int num = n / mcd;
        int den = d / mcd;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        cout << num << "/" << den << endl;
    }
}

int ocurrencias123Repetidos(int* vector, int largo) {
    int cant = 0;
    int estado = 0; // 0=esperando 1, 1=esperando 2, 2=esperando 3

    for (int i = 0; i < largo; i++) {
        if (estado == 0) {
            if (vector[i] == 1) {
                estado = 1; // entramos a bloque de 1
            }
        }
        else if (estado == 1) {
            if (vector[i] == 2) {
                estado = 2; // entramos a bloque de 2
            }
            else if (vector[i] != 1) {
                estado = 0; // reiniciar si aparece algo fuera de 1 o 2
            }
        }
        else if (estado == 2) {
            if (vector[i] == 3) {
                cant++;     // encontramos [1,2,3]
                estado = 0; // reiniciamos para buscar otra subsecuencia
            }
            else if (vector[i] != 2) {
                estado = 0; // reiniciar si aparece algo fuera de 2 o 3
            }
        }
    }
    return cant;
}

int maximoNumero(unsigned int n) {
    int num;
    int maximo;
    cin >> num;   // leo el primer número
    maximo = num;    

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > maximo) {
            maximo = num;
        }
    }
    return maximo;
}

void ordenarVecInt(int *vec, int largoVec) {
    for (int i = 0; i < largoVec - 1; i++) {
        int minPos = i; 
        for (int j = i + 1; j < largoVec; j++) {
            if (vec[j] < vec[minPos]) {
                minPos = j;
            }
        }
        int aux = vec[i]; //valor de i guardado asi no se pierde
        vec[i] = vec[minPos];
        vec[minPos] = aux;
    }
}


int* intercalarVector(int* v1, int* v2, int l1, int l2) {
    // Caso especial: si ambos vectores están vacíos
    if (l1 + l2 == 0) {
        return NULL;
    }
    int* resultado = new int[l1 + l2];  // vector nuevo para el resultado
    int i = 0, j = 0;                   // índices para recorrer v1 y v2
    for (int k = 0; k < l1 + l2; k++) { // recorro el nuevo vector
        if (i < l1 && (j >= l2 || v1[i] <= v2[j])) {
            resultado[k] = v1[i]; // pongo el de v1 si corresponde
            i++;
        }
        else {
            resultado[k] = v2[j]; // pongo el de v2 en otro caso
            j++;
        }
    }
    return resultado;
}


bool subconjuntoVector(int* v1, int* v2, int l1, int l2) {
    if (l1 == 0) {
        return true;
    } else if (l2 == 0) {
        return false;
    }
    for (int i = 0; i < l1; i++) {
        bool encontrado = false;
        for (int j = 0; j < l2; j++) {
            if (v1[i] == v2[j]) {
                encontrado = true; 
                break; 
            }
        }
        if (!encontrado) {
            return false;
        }
    }
    return true;
}


char* invertirCase(char* str){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
