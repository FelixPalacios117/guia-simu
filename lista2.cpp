#include <iostream>
using namespace std;

struct Node{
    int dato;
    Node *next;
};
void *crearNodo(){
    return malloc(sizeof(Node));
}

void insert(int value,Node** L){
    Node* temp=(Node*)crearNodo();
    temp->dato=value;
    if(*L==NULL){
        temp->next=NULL;
    }else{
        temp->next=*L;
    }
    *L=temp;
}
void mostrar(Node *L){
    if(L==NULL){
        cout<<"No hay nada";
        return;
    }
    Node *copy=L;
    while(copy!=NULL){
        cout<<copy->dato;
        copy = copy->next;
    }
}
void colocarAlfinal(Node **L,int valor){
    Node* temp = (Node*) crearNodo();
    temp->dato = valor;
    if(*L==NULL){
        *L = temp;
    }else{
        Node* aux = *L;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = temp;  
    } 
}

int main(){
    Node *L= NULL;
    insert(2,&L);
    insert(4,&L);
    colocarAlfinal(&L,5);
    mostrar(L);
    return 0;
}