#include <iostream>
using namespace std;//ascendente y descendente

template <typename T>
int crearArreglo(T **arreglo,int tamanio){
    *arreglo=(T*)malloc(sizeof(T)*tamanio);
    return tamanio;
};
template <typename T>
void insert(T *arreglo,int tamanio){
    for(int i=0;i<tamanio;i++){
        arreglo[i]=i;
    }
}
template <typename T>
void selectionSortAsc(T *array, int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) { 
      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    } 
    T temp=array[min_idx];
    array[min_idx]=array[step];
    array[step]=temp; 
  }
};
template <typename T>
void selectionSortDesc(T*array,int size){
     for (int step = 0; step < size - 1; step++) {
    int max_idx = step;
    for (int i = step + 1; i < size; i++) { 
      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] > array[max_idx])
        max_idx = i;
    } 
    T temp=array[max_idx];
    array[max_idx]=array[step];
    array[step]=temp; 
  }
}
template <typename T>
void show(T *array,int size){
    cout<<'[';
    for(int i=0;i<size;i++){
        cout<<array[i];
        if(size-i!=1){
            cout<<',';
        }
    }
    cout<<']';
};

int main(){
    int *array;
    int size=crearArreglo(&array,7);  
    insert(array,size);
    array[0]=22;
    array[4]=99; 
    selectionSortAsc(array,7);
    show(array,7);
    selectionSortDesc(array,7);
    show(array,7);
    return 0;
}