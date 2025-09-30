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

NodoLista* exor(NodoLista* l1, NodoLista* l2) { 
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	if (l1 != NULL && (l2 == NULL || l1->dato < l2->dato)) {
		int val = l1->dato;
		while (l1 != NULL && l1->dato == val) {
			l1 = l1->sig;
		}
		NodoLista* nue = new NodoLista;
		nue->dato = val;
		nue->sig = exor(l1, l2);
		return nue;
	}
	if (l2 != NULL && (l1 == NULL || l2->dato < l1->dato)) {
		int val = l2->dato;
		while (l2 != NULL && l2->dato == val) {
			l2 = l2->sig;
		}
		NodoLista* nue = new NodoLista;
		nue->dato = val;
		nue->sig = exor(l1, l2);
		return nue;
	}
	if (l1 != NULL && l2 != NULL && l1->dato == l2->dato) {
		int val = l2->dato;
		while (l1 != NULL && l1->dato == val) {
			l1 = l1->sig;
		}
		while (l2 != NULL && l2->dato == val) {
			l2 = l2->sig;
		}
		return exor(l1, l2);
	}
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) {
	NodoLista* act = l;
	NodoLista* prev = NULL;
	while (act != NULL) {
		int val = act->dato;
		bool flag = false;
		NodoLista* cont = act->sig;
		while (cont != NULL && cont->dato == val) {
			NodoLista* aBorrar = cont;
			cont = cont->sig;
			delete aBorrar;
			flag = true;
		}
		if (flag) {
			NodoLista* aBorrar = act;
			act = cont;
			if (prev == NULL) {
				l = act;
			}
			else {
				prev->sig = act;
			}
			delete aBorrar;
		}
		else {
			prev = act;
			act = act->sig;
		}
	}
}

bool palindromo(NodoLista* l) //OPCIONAL
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista*& l, NodoLista* secuencia) {
	if (l == NULL || secuencia == NULL) {
		return;
	}
	NodoLista* ant = NULL;
	NodoLista* act = l;
	while (act != NULL) {
		NodoLista* p1 = act;
		NodoLista* p2 = secuencia;
		while (p1 != NULL && p2 != NULL && p1->dato == p2->dato) {
			p1 = p1->sig;
			p2 = p2->sig;
		}
		if (p2 == NULL) {
			NodoLista* aPart = act;
			while (aPart != p1) {
				NodoLista* aBorrar = aPart;
				aPart = aPart->sig;
				delete aBorrar;
			}
			if (ant == NULL) {
				l = p1;
			}
			else {
				ant->sig = p1;
			}
			return;
		}
		ant = act;
		act = act->sig;
	}
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final) //OPCIONAL
{
	// IMPLEMENTAR SOLUCION
}
