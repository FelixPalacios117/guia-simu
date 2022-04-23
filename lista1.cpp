#include <iostream>
using namespace std;
struct Nodo
{
    int data;
    Nodo *sig;
};

Nodo *crearLista(int n)
{
    Nodo *list = NULL;
    for (int i = 0; i < n; i++)
    {
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        nuevo->data = i;
        nuevo->sig = list;
        list = nuevo;
    }
    return list;
}
void imprimirLista(Nodo **lista)
{
    if (*lista == NULL)
        return;
    else
    {
        cout << (*lista)->data << "\n";
        imprimirLista(&((*lista)->sig));
    }
    return;
}

Nodo *funcionValorV(Nodo **lista, int v)
{
    int cont = 0;
    Nodo *aux = *lista;
    while (*lista != NULL)
    {
        cont++;
        if ((cont % 2) == 0)
        {
            Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
            nuevo->data = v;
            nuevo->sig = (*lista)->sig;
            (*lista)->sig = nuevo;
            *lista = (*lista)->sig;
        }
        *lista = (*lista)->sig;
    }
    return aux;
}

int main()
{
    int n = 4;
    Nodo *lista = crearLista(n);
    imprimirLista(&lista);
    cout << "\n";
    lista = funcionValorV(&lista, 8);
    imprimirLista(&lista);

    return 0;
}