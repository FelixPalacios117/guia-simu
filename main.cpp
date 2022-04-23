#include <iostream> 
using namespace std;
#include "headers/staticDS.h"

template<typename T>
Data Estructuras<T>::ref=Data();
int main(){
    int valor;
    Array<int> *array;
    Estructuras<int>::create(&array,2);
    Estructuras<int>::insert(array,2,3);
    Estructuras<int>::extract(array,2,&valor);
    cout<<""<<valor<<"\n";
    Estructuras<int>::destroy(array);
    return 0;
};