#include <iostream>
using namespace std;

template<typename T>
T** crear(T fila,T columna){
    T **matrix = (T**) malloc(sizeof(T*)*fila);   
    for(int i = 0; i < fila; i++){ 
        *(matrix+i) = (T*) malloc(sizeof(T)*columna);
    }  
    return matrix;
}    

template <typename T>
void insert(T **matrix,int fila,int columna, T value){ 
    matrix[fila][columna]= value;
}
template <typename T>
T extract(T**matrix,int fila, int columna) { 
    return *(*(matrix+fila)+columna);
    //return matrix[fila][columna];
}
void recorrerMatrix(int **matrix, int n, int m){
    for(int j=0;j<m;j++){
        cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<*(*(matrix+i)+j);
        }
    }
}

void recorrerMatrix2(int **matrix, int n, int m){
    for(int j=0;j<n;j++){
        cout<<"\n";
        for(int i=0;i<m;i++){
            cout<<*(*(matrix+j)+i);
        }
    }
}
int main(){
    int **matrix=crear(4,4);
    insert(matrix,0,2,22);
    insert(matrix,1,2,100);    
    //recorrerMatrix(matrix,4,4);
    recorrerMatrix2(matrix,4,4);
    return 0;
}