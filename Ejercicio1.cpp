#include <iostream> 
using namespace std;
#include "headers/staticDS.h"

template<typename T>
Data Estructuras<T>::ref=Data();

void arreglos(int n, int m){
    for(int i=0;i<n;i++){
        Array<int> *array;
        Estructuras<int>::create(&array,m);
        Estructuras<int>::insert(array,2,i+1);
        Estructuras<int>::show(array,false); 
    }
}

int main(){
    arreglos(3,4);
    return 0;
};
