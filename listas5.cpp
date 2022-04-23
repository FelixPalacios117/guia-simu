#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *next;
    Nodo *prev;
};
void* crearNodo(){
    return malloc(sizeof(Nodo));
}
void insertar(Nodo **L,int value){
    Nodo *temp=(Nodo*)crearNodo();
    temp->dato=value;
    temp->prev=NULL;
    if(*L==NULL){
        temp->next=NULL;
    }else{
        (*L)->prev= temp;
        temp->next=*L;
    }
    *L=temp;
}

void show(Nodo **L){
    if(*L==NULL){
        cout<<"No hay";
    }
    else{
        Nodo *aux=*L;
        while(aux){
            cout<<aux->dato;
            aux=aux->next;
        }
    }
}
void intercambiar(Nodo **L,int p1,int p2){
    Nodo *aux=*L;
    Nodo *aux1;
    Nodo *aux2;
    int contador=0;
    while(aux){
        if(p1==contador){
            aux1=aux;
        }
        if(p2==contador){
            aux2=aux;
        }
        aux=aux->next;
    }
    swap(aux1->dato,aux2->dato);
}
int main(){
    Nodo *L=NULL;
    insertar(&L,2);
    insertar(&L,4);
    intercambiar(&L,0,1);
    show(&L);
    return 0;
}