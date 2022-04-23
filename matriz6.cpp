#include <iostream>
using namespace std;

template <typename T>
T** crear(T fila,T columna){
    int **matriz=(T**)malloc(sizeof(T*)*fila);
    for(int i=0;i<fila;i++){
        *(matriz+i)=(T*)malloc(sizeof(T)*columna);
    }
    return matriz;
}
template<typename T>
bool cuadrada(T **matriz,int fila, int columna){
    if(fila==columna){
        return true;
    }
    return false;
}
int main(){ 
    int **matriz=crear(4,4);
    matriz[3][0]=22; 
    cout<<cuadrada(matriz,4,3);
    return 0;
}