#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *next;
};

void* crearNodo(){
    return malloc(sizeof(Nodo));
}

void insert(Nodo **L,int value){
    Nodo *nuevo=(Nodo*)crearNodo();
    nuevo->dato=value;
    if(*L==NULL){
        nuevo->next=NULL;
    }
    else{
        nuevo->next=*L;
    }
    *L=nuevo;
}

void show(Nodo **L){
    Nodo *aux=*L;
    while(aux){
        cout<<aux->dato;
        aux=aux->next;
    }
}

void invertir(Nodo **L){
    Nodo *invertida=NULL;
    Nodo *temp;
    Nodo *Lcopy=*L;
    while(Lcopy){
        temp=(Nodo*)crearNodo();
        temp->dato=Lcopy->dato; 
        if(invertida==NULL){
           temp->next=NULL;
        }
        else{
            temp->next=invertida;
        }
        invertida=temp;
        Lcopy=Lcopy->next;
    }
    *L=invertida;
}

int main(){
    Nodo *L=NULL;
    insert(&L,2);
    insert(&L,5);
    show(&L);
    invertir(&L);
    show(&L);
    return 0;
}