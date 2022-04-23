#include <iostream>
using namespace std;
 
int** crear(int fila, int columna){
    int **matriz=(int**)malloc(sizeof(int*)*fila);
    for(int i=0;i<fila;i++){
        *(matriz+i)=(int*)malloc(sizeof(int)*columna);
    }
    return matriz;
}  
void sumar(int **matriz,int** matriz1, int*** referencia,int n,int m){
    for(int i=0;i<n*m;i++){
        *(*(*referencia+(i/m))+(i%m))=matriz[i/m][i%m]+matriz1[i/m][i%m];
    }
    for(int i=0;i<n*m;i++){
        if(i%m==0){
            cout<<endl;
        }
        cout<<*(*(*referencia+(i/m))+(i%m))<<" ";
    }
}
void insertar(int **matriz,int** matriz1,int*** referencia,int n,int m){
    for(int i=0;i<n*m;i++){
        matriz[i/m][i%m]=i;
        matriz1[i/m][i%m]=i;
         *(*(*referencia+(i/m))+(i%m))=i;
    } 
}
int main(){
    int **matriz=crear(4,5);
    int **segundamatriz=crear(4,5);
    int **matrizreferencia=crear(4,5);
    insertar(matriz,segundamatriz,&matrizreferencia,4,5);
    sumar(matriz,segundamatriz,&matrizreferencia,4,5); 
    return 0;
}