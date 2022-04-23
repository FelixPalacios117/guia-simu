#include <iostream> 
using namespace std;
 
template <typename T>
int crearArreglo(T **arreglo,int tamanio){
    *arreglo=(T*)malloc(sizeof(T)*tamanio);
    return tamanio;
};
template <typename T>
void destroy(T *arreglo){
    free(arreglo);
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
void hacercopia(T *arreglo,int tamanio){ 
    int tamanio_copia=0;
    if(tamanio%2!=0){
        tamanio_copia=((tamanio/2)+1);//impar
    }else{
        tamanio_copia=(tamanio/2);
    } 
    int *arraycopia;
    int sizecopia=crearArreglo(&arraycopia,tamanio_copia);  
    for(int i=0;i<tamanio_copia;i++){
        *(arraycopia+i)=arreglo[2*i];
    }
    mostrarcopia(arraycopia,sizecopia);
    destroy(arraycopia);  
}; 
int main(){
    int *array;
    int size=crearArreglo(&array,7);  
    array[0]=22;
    array[2]=4;
    array[6]=100;
    hacercopia(array,size);
    destroy(array); 
    return 0;
};