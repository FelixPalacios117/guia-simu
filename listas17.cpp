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
    Nodo *aux=(Nodo*)crearNodo();
    aux->dato=value;
    aux->prev=NULL;
    if(*L==NULL){
        aux->next=NULL;
    }else{
        (*L)->prev=aux;
        aux->next=*L;
    }
    *L=aux;
}
void show(Nodo **L){
    if(*L==NULL){
        cout<<"No hay";
    }else{
        Nodo *aux=*L;
    while(aux){
        cout<<aux->dato;
        aux=aux->next;
    }
    }
}

 void destroy(Nodo **L) {
    //Variable auxiliar para el proceso
    Nodo *temp;

    //Se recorre la lista hasta el final
    while(*L != NULL){
        //Se copia la referencia al nodo actual en la
        //variable auxiliar para "rescatarlo"
        temp = *L;
 
        //Acá es donde perderíamos la referencia al nodo
        //actual si no lo hubiéramos "rescatado"
        *L = (*L)->next; 
        //A través de la variable auxiliar, liberamos
        //el nodo previamente "rescatado"
        free(temp);
    }
    //Al final del proceso, L habrá quedado apuntando a NULL,
    //lo cual está bien ya que se interpreta como una lista
    //vacía, y eso es coherente con la operación realizada.
}

void reversa(Nodo **L){  
    Nodo *invertida = NULL; 
    Nodo *Lcopy = *L; 
    Nodo *temp;
 
    while(Lcopy != NULL){ 
        temp = (Nodo*) crearNodo(); 
        temp->dato = Lcopy->dato; 
        temp->prev = NULL; 
        if(invertida == NULL) 
            temp->next = NULL;
        else{ 
            invertida->prev = temp; 
            temp->next = invertida;
        } 
        invertida = temp; 
        Lcopy = Lcopy->next;
    } 
    destroy(&Lcopy); 
    *L = invertida; 

}
int main(){
    Nodo *L=NULL;
    insertar(&L,2);
    insertar(&L,4);
    insertar(&L,6);
    show(&L);
    //destroy(&L);
    reversa(&L);
    show(&L);
    return 0;
}