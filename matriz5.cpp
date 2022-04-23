#include <iostream>
using namespace std;

template <typename T>
T** crear(T n){
    int **matriz=(T**)malloc(sizeof(T*)*n);
    for(int i=0;i<n;i++){
        *(matriz+i)=(T*)malloc(sizeof(T)*n);
    }
    return matriz;
}

int main(){ 
    int **matriz=crear(4);
    matriz[3][0]=22;
    cout<<matriz[3][0];
    return 0;
}