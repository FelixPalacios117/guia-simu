#include <iostream>
using namespace std; 
  

int create(int tamanio,int** array){ 
    *array=(int*) malloc(sizeof(int)*tamanio);
    return tamanio;
};
void destroy(int *array){
    free(array);
};
void insert(int valor,int* array,int posicion){
    *(array+posicion)=valor;
}
void mostrar(int *array,int tamanio){
    for(int i=0;i<tamanio;i++){
        cout<<"una forma "<<*(array+i)<<endl;
        cout<<"otra forma "<<array[i]<<endl;
    }
}
int pares(int *array,int n){
    int par=0;
    for(int i=0;i<n;i++){
        if(*(array+i)%2==0){//pares
            par++;
        }
    }
    return par;
}
int impares(int *array,int n){
    int par=0;
    for(int i=0;i<n;i++){
        if(*(array+i)%2!=0){//pares
            par++;
        }
    }
    return par;
}
int main(){
    int *array;
    int tamanio=create(4,&array);
    insert(52,array,2);
    insert(433389,array,3);  
    cout<<"hay "<<pares(array,tamanio)<<" pares"<<endl; 
    cout<<"hay "<<impares(array,tamanio)<<" impares"<<endl; 
    mostrar(array,tamanio);
    destroy(array); 
    return 0;
};