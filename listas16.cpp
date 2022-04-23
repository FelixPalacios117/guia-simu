#include <iostream>
using namespace std;

struct Nodo{
    int data;
    Nodo * next;
    Nodo * prev;
};
void* createNode(){
    return malloc(sizeof(Nodo));
}
void insert(Nodo **L,int value){ 
    Nodo* temp = (Nodo*) createNode(); 
    temp->data = value; 
    temp->prev = NULL; 
    if(*L == NULL) 
        temp->next = NULL;
    else{
        //Si la lista no está vacía, el nodo anterior al nodo
        //que actualmente está al inicio de la lista será el
        //nuevo nodo
        (*L)->prev = temp; 
        //El nodo siguiente al nuevo nodo, será el que está
        //actualmente al inicio de la lista
        temp->next = *L;
    } 
    *L = temp;
}

void show(Nodo **L){ 
        if(*L == NULL){
            cout << "La lista está vacía.\n";
            return;
        } 
        Nodo *Lcopy = *L;

        //Variable auxiliar para mostrar el contenido de la lista
        int index = 1;

        //Se recorre la lista hasta el final
        while(Lcopy != NULL){
            //Se especifica explícitamente el valor de cada elemento
            //almacenado en la lista, uno por línea, indicando la posición
            //haciendo uso de la variable auxiliar
            cout << "Element #" << index << " is: " << Lcopy->data << "\n";
            //Se le suma 1 a la variable auxiliar
            index++;

            //Se avanza al siguiente nodo de la lista
            Lcopy = Lcopy->next;
        }  
}

int main(){
    Nodo *L=NULL;
    insert(&L,2);
    insert(&L,3);
    show(&L);
    return 0;
}