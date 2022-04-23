#include <iostream> 
using namespace std;
#include "headers/staticDS.h"

template<typename T>
Data Estructuras<T>::ref=Data(); 
int main(){
    Array<int> *array;
    bool valor;
    Estructuras<int>::create(&array,3);
    Estructuras<int>::buscardosveces(&array,0,&valor);
    cout<<valor;
    Estructuras<int>::buscarmasdedos(&array,0,&valor);
    cout<<valor;
    Estructuras<int>::buscarnveces(&array,0,3,&valor);
    cout<<valor;
return 0;
};