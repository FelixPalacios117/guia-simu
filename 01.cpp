#include <iostream>
using namespace std;

int** crearMatrix(int n, int m){
    int **matrix=(int**) malloc(sizeof(int *)*n);
    for(int i=0; i<n;i++)
        *(matrix +i) = (int *) malloc(sizeof(int)*m);

    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            *(*(matrix+i)+j)= j;
        }
    }
    return matrix;
}

void recorrerMatrix(int **matrix, int n, int m){
    for(int j=0;j<m;j++){
        cout<<"\n";
        for(int i=0;i<n;i++){
            cout<<*(*(matrix+i)+j);
        }
    }
}

int main(){
    int n=3,m=2;
    int **matrix = crearMatrix(n,m);
    recorrerMatrix(matrix,3,2);
    

    return 0;
}