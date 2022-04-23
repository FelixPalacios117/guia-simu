#include <iostream>
using namespace std;

struct Node{
    int valor;
    Node *next;
}; 
typedef Node Node;

void* createNode(){ 
    return malloc(sizeof(Node));
}

void insert(int value,Node **L){
        //Se crea un nuevo nodo  
        Node* temp = (Node*) createNode(); 
        temp->valor = value; 
        //Se verifica si la lista se encuentra actualmente vacía
        if(*L == NULL)
            //Si la lista está vacía, el nodo siguiente al nuevo
            //nodo no existe aún, por lo que se define como NULL
            temp->next = NULL;
        else
            //Si la lista no está vacía, el nodo siguiente al nuevo
            //nodo es el nodo que actualmente está al inicio de la
            //lista
            temp->next = *L; 
        //Se define el inicio de la lista como el nuevo nodo
        *L = temp;
}
void show(bool verbose,Node *L){ 
            if(L == NULL){
                cout << "La lista está vacía.\n";
                return;
            } 
            //Se copia el puntero al inicio de la lista enlazada
            //simple para no perder la referencia durante el
            //proceso de recorrido
            Node* Lcopy = L; 
            if(verbose){ 
                int index = 1; 
                while(Lcopy != NULL){
                    //Se especifica explícitamente el valor de cada elemento 
                    cout << "Element #" << index << " is: " << Lcopy->valor << "\n"; 
                    index++; 
                    //Se avanza al siguiente nodo de la lista
                    Lcopy = Lcopy->next;
                }       
            }else{
                //Se muestra el contenido de la lista como una secuencia de datos  
                while(Lcopy != NULL){
                    //Se coloca el dato actual seguido de '->'
                    cout << Lcopy->valor << " -> "; 
                    //Se avanza al siguiente nodo de la lista
                    Lcopy = Lcopy->next;
                }
                //El último dato conecta con NULL, indicando el final de la lista
                cout << "NULL\n";
            }
}

template <typename T>
int crearArreglo(T **arreglo,int tamanio){
    *arreglo=(T*)malloc(sizeof(T)*tamanio);
    return tamanio;
};
int extension(Node * L)  { 
        int cont = 0;

        //Se copia el puntero al inicio de la lista enlazada
        //simple para no perder la referencia durante el
        //proceso de recorrido
        Node * Lcopy = L; 
        //Se recorre la lista hasta el final
        while(Lcopy != NULL){
            //Si entramos al while, hay un nodo no evaluado
            //Se actualiza el contador
            cont++;

            //Se avanza al siguiente nodo de la lista
            Lcopy = Lcopy->next;
        } 
        //Se retorna el resultado
        return cont;
}

template<typename T>
void mostrarcopia(T* arreglo,int tamanio){
    cout<<'[';
    for(int i=0;i<tamanio;i++){
        cout<<*(arreglo+i);
        if(tamanio-i!=1){
            cout<<",";
        }
    }
    cout<<']';
}

template <typename T>
void hacercopia(T *arreglo,Node *L,int cantidad){  
    int *arraycopia;
    int sizecopia=crearArreglo(&arraycopia,cantidad);  
     Node * Lcopy = L; 
     int cont=0;
        //Se recorre la lista hasta el final
        while(Lcopy != NULL){ 
            *(arraycopia+cont)=arreglo[Lcopy->valor]; 
            Lcopy = Lcopy->next;
            cont++;
        } 
    mostrarcopia(arraycopia,sizecopia); 
}; 

int main(){
    Node * lista=NULL; 
    int *array;
    insert(2,&lista);
    insert(3,&lista); 
    show(false,lista);
    crearArreglo(&array,4);
    array[3]=99;
    array[1]=99;
    hacercopia(array,lista,extension(lista));
    return 0;
};