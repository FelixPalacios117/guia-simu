#include <iostream>
using namespace std;

template<typename T>
void create(T **array,int size){
    *array=(T*)malloc(sizeof(T)*size);
}
template<typename T>
void invertir(T *array,int size){
    int contador=0;
    T temp=array[size/2];
    for(int i=(size/2)-1;i>1;i--){ 
        array[i]=array[contador];  
        contador++;
    }
    array[0]=temp;
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
int main(){
    int *array;
    create(&array,5);
    array[0]=2;
    array[1]=3;
    mostrarcopia(array,5);
    invertir(array,6);
    mostrarcopia(array,5);
    return 0;
}