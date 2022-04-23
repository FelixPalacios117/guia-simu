#include <iostream>
using namespace std;

template<typename T>
T** crearMatrizIdentidad(T n){
    T **matriz=(T**)malloc(sizeof(T*)*n);
    for(int i=0;i<n;i++){
        *(matriz+i)=(T*)malloc(sizeof(T)*n);
    }
    for(int i=0;i<n*n;i++){
        matriz[i/n][i%n]=1; 
        i+=n;
    }
    for(int i = 0; i < n*n; i++) { 
        if(i%n==0){
            cout<<endl;
        }
        cout<<matriz[i/n][i%n];
    }
    return matriz;
}
int main(){
    int **matriz;
    matriz=crearMatrizIdentidad(4);
    return 0;
}