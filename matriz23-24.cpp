#include <iostream>
using namespace std;

template<typename T>
T** crear(T fila, T columna){
    T **matriz=(T**)malloc(sizeof(T*)*fila);
    for(int i=0;i<fila;i++){
        *(matriz+i)=(T*)malloc(sizeof(T)*columna);
    }
    return matriz;
}
void extraerFila(int **matriz,int filaselect,int fila, int columna){
    for(int i=0;i<fila;i++){
        if(i==filaselect){
            for(int j=0;j<columna;j++){
                cout<<matriz[i][j];
            }
        }
    }
}

int main(){
    int **matriz=crear(4,5);
    int *arreglo=
    extraerFila(matriz,3,4,5);
    return 0;
}