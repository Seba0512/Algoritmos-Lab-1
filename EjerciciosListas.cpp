#include "EjerciciosListas.h"

NodoLista* invertirParcial(NodoLista* l) {
	if (l == NULL) {            
		return NULL;
	}
	NodoLista* ret = NULL;
	NodoLista* p = l;

	while (p->sig != NULL) { 
		NodoLista* n = new NodoLista(p->dato);
		n->sig = ret; //uno n con lo que tengo de ret
		ret = n; //hago que ret apunte a lo mismo que n
		p = p->sig;
	}
	return ret;              
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n) {
	if (n < 1 || lista == NULL) {
		return; //devuelve la misma lista. el lista == NULL hace que pueda subir de nuevo
	}
	eliminarNesimoDesdeElFinal(lista->sig,n);
	if (n == 1) {
		NodoLista* borrar = lista; //para guardarme 
		lista = lista->sig; 
		delete borrar;
	}
	n--;
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) {
	if (l == NULL) {
		return NULL;
	}
	NodoLista* ret = NULL; 
	for (NodoLista* p = l; p != NULL; p = p->sig) {
		NodoLista* n = new NodoLista(p->dato);
		if (ret == NULL || n->dato < ret->dato) {
			n->sig = ret; //ponemos n al principio
			ret = n; //apuntamos a ese nuevo n
		}
		else {
			NodoLista* q = ret;
			while (q->sig != NULL && q->sig->dato <= n->dato) {
				q = q->sig;
			}
			n->sig = q->sig; //n apunta a lo que seguía después de q
			q->sig = n; //q apunta a n
		}
	}
	return ret;
}

	void listaOrdenadaSelectionSort(NodoLista * &l) {
		NodoLista* act = l;
		while (act != NULL) {
			NodoLista* mNod = act;
			NodoLista* sigu = act->sig;
			while (sigu != NULL) {
				if (sigu->dato < mNod->dato) {
					mNod = sigu;
				}
				sigu = sigu->sig;
			}
			int aux = act->dato;
			act->dato = mNod->dato;
			mNod->dato = aux;
			act = act->sig;
		}
	}


NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2) {
	NodoLista* ret = NULL;
	NodoLista* ult = NULL;
	while (l1 != NULL || l2 != NULL) {
		NodoLista* nue = new NodoLista;
		if (l1 != NULL && (l2 == NULL || l1->dato <= l2->dato)) {
			nue->dato = l1->dato;
			l1 = l1->sig;
		}
		else {
			nue->dato = l2->dato;
			l2 = l2->sig;
		}
		nue->sig = NULL;
		if (ret == NULL) {
			ret = nue;
		}
		else {
			ult->sig = nue;
		}
		ult = nue;
	}
	return ret;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2) {
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	NodoLista* ret = new NodoLista;
	if (l1 != NULL && (l2 == NULL || l1->dato <= l2->dato)) {
		ret->dato = l1->dato;
		ret->sig = intercalarRec(l1->sig, l2);
	} else {
		ret->dato = l2->dato;
		ret->sig = intercalarRec(l1, l2->sig);
	}
	return ret;
}

NodoLista* insComFin(NodoLista* l, int x) //OPCIONAL
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l) //OPCIONAL
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final) //OPCIONAL
{
	// IMPLEMENTAR SOLUCION
}
