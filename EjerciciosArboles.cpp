#include "EjerciciosArboles.h"

int max(int a,int b){
	if (a > b) {
		return a;
	}
	return b;
}

int altura(NodoAB* raiz) {
	if (raiz == NULL) {
		return 0;
	}
	return 1 + max(altura(raiz->izq), altura(raiz->der));
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if (p == NULL && q == NULL) {
		return true;
	}
	else if (p == NULL || q == NULL) {
		return false;
	}
	return (p->dato == q->dato) && sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (raiz == NULL) {
		return (sum == 0);
	}
	int resto = sum - raiz->dato; //hago esto para comparar si llega a 0
	if (raiz->izq == NULL && raiz->der == NULL) {//ver si es hoja
		return (resto == 0);
	}
	bool hayIzq = false;
	bool hayDer = false;
	if (raiz->izq != NULL) {
		hayIzq = existeCaminoConSuma(raiz->izq, resto);
	}
	if (raiz->der != NULL) {
		hayDer = existeCaminoConSuma(raiz->der, resto);
	}
	return hayIzq || hayDer;
}

bool esArbolBalanceado(NodoAB *raiz) {
	if (raiz == NULL) {
		return true;
	}
	int altIzq = altura(raiz->izq);
	int altDer = altura(raiz->der);
	int dif = altIzq - altDer;
	if (dif < 0) {
		dif = -dif;
	}
	if (dif > 1) {
		return false;
	}
	return esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der);
}

NodoLista* concatenar(NodoLista* a, NodoLista* b) {
	if (a == NULL) {
		return b;
	}
	NodoLista* p = a;
	while (p->sig != NULL) {
		p = p->sig;
	}
	p->sig = b;
	return a;                           
}

NodoLista* recorrerAux(NodoAB* raiz, int nivelActual, int nivelBuscado) {
	if (raiz == NULL) {
		return NULL;
	}
	if (nivelActual+1 == nivelBuscado) {
		return new NodoLista(raiz->dato);
	}
	NodoLista* izquierda = recorrerAux(raiz->izq, nivelActual + 1, nivelBuscado);
	NodoLista* derecha = recorrerAux(raiz->der, nivelActual + 1, nivelBuscado);
	return concatenar(izquierda, derecha);
}

NodoLista* enNivel(NodoAB* a, int k) {
	if (k < 0) {
		return NULL;
	}
	return recorrerAux(a, 0, k);
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB* arbol, int x) {
	if (arbol == NULL) {
		return NULL;
	}
	NodoLista* n = NULL;     
	NodoLista* punt = NULL; //recorre todo
	NodoAB* aux = arbol;
	while (aux != NULL) {
		NodoLista* nuevo = new NodoLista(aux->dato);
		if (n == NULL) {
			n = nuevo;      
			punt = nuevo;     
		}
		else {
			punt->sig = nuevo;
			punt = nuevo;
		}
		if (x == aux->dato) {
			break;
		}
		else if (x < aux->dato) {
			aux = aux->izq;
		}
		else {
			aux = aux->der;
		}
	}
	return n;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	if (A->izq == NULL && A->der == NULL) {
		delete A;
		A = NULL;
	}else if (A->der == NULL) {
		NodoAB* aBorrar = A;
		A = A->izq;
		delete aBorrar;
	}
	else if (A->izq == NULL) {
		NodoAB* aBorrar = A;
		A = A->der;
		delete aBorrar;
	}
	else {
		NodoAB* actual = A;
		NodoAB* min = A->der;
		while (min->izq != NULL) {
			actual = min;
			min = min->izq;
		}
		A->dato = min->dato;
		if (actual == A) {
			actual->der = min->der;
		}
		else {
			actual->izq = min->der;
		}
		delete min;
	}
}

bool sumaABB(NodoAB* a, int n) //OPCIONAL
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n) {
	int ret = -1;
	while (a != NULL) {
		if (a->dato > n) {
			ret = a->dato;
			a = a->izq;
		}
		else {
			a = a->der;
		}
	}
	return ret;
}

//PRE:Recibe un árbol binario y un entero mayor o igual a 1(nivel a contar)
//POS: Retorna la cantidad de nodos que existen en el nivel dado, en caso de ser un árbol vacío, devuelve 0
int contarNivel(NodoAB* raiz, int nivel) {
	if (raiz == NULL) {
		return 0;
	}
	if (nivel == 1) {
		return 1;
	}
	return contarNivel(raiz->izq, nivel - 1) + contarNivel(raiz->der, nivel - 1);
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	int ret = 0;
	int nivelM = 0;
	int nivelAct = 1;
	int nodos = 0;
	if (raiz == NULL) {
		return 0;
	}
	while (nivelAct <= nivelHasta) {
		nodos = contarNivel(raiz, nivelAct);
		if (nodos > nivelM) {
			nivelM = nodos;
			ret = nivelAct;
		}
		nivelAct++;
	}
	return ret;
}


/*
 *	EJERCICIO OBLIGATORIO
PRE: recibe un arbol binario
POS: Retorna el nivel con mas nodos, desde el nivel 1 hasta nivelHasta.
	 En caso de que el árbol sea vacio se debera retornar cero.
	 Ante un empate debera retornar el número de nivel mas pequeño.
	 NOTA: Esta operación se puede realizar en O(n).

Ejemplo
Entrada: {1,2,3,#,#,4,#,#,5}, 4
   1
  / \
 2   3
	/
   4
	\
	 5
Retorno: 2
*/

void borrarPares(NodoAB* & a){ //OPCIONAL
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz) { //OPCIONAL
	if (raiz == NULL) {
		return 0;
	}
	else {
		return max(1 + alturaAG(raiz->ph), alturaAG(raiz->sh));
	}
}

int sumaPorNiveles(NodoAG* raiz){
	// IMPLEMENTAR SOLUCION
	return 0;
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	return NULL;
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}
