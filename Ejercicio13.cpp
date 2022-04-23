#include <iostream> 
using namespace std;
#include "headers/staticDS.h"

template<typename T>
Data Estructuras<T>::ref=Data(); 
int main(){
     Array<int> *array;
    bool valor;
    Estructuras<int>::create(&array,6);
    Estructuras<int>::insert(array,3,3);
    Estructuras<int>::insert(array,4,4);
    Estructuras<int>::insert(array,5,5);
    Estructuras<int>::intervalo(&array,3);
    Estructuras<int>::destroy(array);
    return 0;
};