#include <iostream>
using namespace std;

struct Node{
    int dato;
    Node *next;
};
void *crearNodo(){
    return malloc(sizeof(Node));
}
void insertar(Node **L,int value){
    Node *copy=(Node*)crearNodo();
    copy->dato=value;
    if(*L==NULL){
        copy->next=NULL;
    }else{
        copy->next=*L;
    }
    *L=copy;
}
void show(Node *L){
    if(L==NULL){
        cout<<"Vacioo";
    }else{
        Node *copy=L;
        while(copy!=NULL){
            cout<<copy->dato;
            copy=copy->next;
        }
    }
}
void copiar(Node **L,int v1,int v2){  
    Node *temp =*L;
    while(temp){
        if(temp->dato==v1){ 
            temp->dato=v2; 
        }
        temp=temp->next;
    } 
}


int main(){
    Node *L=NULL;
    insertar(&L,2);
    insertar(&L,3);
    insertar(&L,4);
    copiar(&L,4,9);
        show(L);
    return 0;
}