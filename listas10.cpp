#include <iostream>
using namespace std;

struct Nodo{
    int data;
    Nodo *next;
};
void* crearNodo(){
    return malloc(sizeof(Nodo));
}
void insert(int value,Nodo **L){
    Nodo *lista=(Nodo*)crearNodo();
    lista->data=value;
    if(*L==NULL){
        lista->next=NULL;
    }else{
        lista->next=*L;
    }
    *L=lista;
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
void intervalo(int n, int d, Nodo **L){
    Nodo *aux=*L;
    int contador=0;
    while(aux){
        if(aux->data>=n-d || aux->data<=n+d){
            contador++;
            aux=aux->next;  
        }  
    }
    cout<<"Hay "<<contador;
}
int main(){
    Nodo *L=NULL;
    insert(4,&L);
    insert(6,&L);
    show(&L);
    intervalo(5,2,&L);
    return 0;
}