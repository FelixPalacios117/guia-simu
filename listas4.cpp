#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *next;
};
void* crearNodo(){
    return malloc(sizeof(Nodo));
}
void insertar(Nodo **L,int value){
    Nodo *temp=(Nodo*)crearNodo();
    temp->dato=value;
    if(*L==NULL){
        temp->next=NULL;
    }else{
        temp->next=*L;
    }
    *L=temp;
}
void show(Nodo **L){
    if(*L==NULL){
        cout<<"Vacio";
    }
    else{
        Nodo *temp=*L;
        while(temp){
            cout<<temp->dato;
            temp=temp->next;
        }
    }
}
void copiar(Nodo **L,int p1,int p2){
    Nodo *aux=*L;
    int contador=0;
    int dato=0;
    while(aux){
         if(contador==p1){
             dato=aux->dato;
         }
         if(contador==p2){
             aux->dato=dato;
         }
         contador++;
         aux=aux->next;
    }
}

int main(){
    Nodo *L=NULL;
    insertar(&L,2);
    insertar(&L,4);
    copiar(&L,0,1);
    show(&L);
    return 0;
}