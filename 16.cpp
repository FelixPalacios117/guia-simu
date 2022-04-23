#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>
using namespace std;
int getRand()
{
    int iSecret;
    srand(time(NULL));
    iSecret = rand() % 20 + 1;
    return iSecret;
}
struct Nodo
{
    int data;
    Nodo *ant;
    Nodo *sig;
};

Nodo *crearLista(int n)
{
    Nodo *lista = NULL;
    for (int i = 0; i < n; i++)
    {
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        if (i % 2 == 0)
            nuevo->data = getRand() * (getRand() + i);
        else
            nuevo->data = i;
        if (lista == NULL)
        {
            lista = nuevo;
            lista->ant = NULL;
            lista->sig = NULL;
        }
        else
        {
            nuevo->sig = lista;
            nuevo->ant = NULL;
            lista->ant = nuevo;
            lista = nuevo;
        }
    }
    return lista;
}

void imprimirLista(Nodo *lista)
{
    while (lista)
    {
        cout << lista->data << " ";
        lista = lista->sig;
    }
}

int longitud(Nodo *lista)
{
    int cont = 0;
    while (lista)
    {
        cont++;
        lista = lista->sig;
    }
    return cont;
}

void ordenarMitad(Nodo **lista)
{
    int longitudLista = longitud(*lista);
    Nodo *copiaLista = *lista;
    for (int i = 0; i < (longitudLista / 2) - 1; i++)
    {
        if (copiaLista->sig != NULL && copiaLista->data > (copiaLista->sig)->data)
        {
            swap(copiaLista->data, copiaLista->sig->data);
            i = -1;
            copiaLista = *lista;
        }
        else
        {
            copiaLista = copiaLista->sig;
        }
    }
    return;
}

int main()
{
    int n = 7;
    Nodo *list = crearLista(n);
    imprimirLista(list);
    cout << "\n";
    // cout << longitud(list);
    ordenarMitad(&list);
    imprimirLista(list);

    return 0;
}