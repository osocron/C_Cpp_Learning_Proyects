#include <iostream>
#include <string.h>

using namespace std;

struct nodo {
    int dato;
    char name[30];
    struct nodo *siguiente;
};

struct pila {
    int dato;
    struct pila *sig;
};

int main() {
    struct nodo *n1 = new nodo;
    struct nodo *n2 = new nodo;
    n1-> dato = 6;
    strcpy(n1-> name, "Nuevo nodo");
    n1-> siguiente = NULL;
    printf(n1-> name);
    printf("\n");
    n1 -> siguiente = n2;
    n2->dato = 3;
    strcpy(n2->name,"Nodo dos");
    n2->siguiente = NULL;
    printf(n1->siguiente->name);

    ////////////////////////////////////////////////



    return 0;
}