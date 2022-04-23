#include <iostream> 
using namespace std;
#include "headers/staticDS.h"

template<typename T>
Data Estructuras<T>::ref=Data(); 
int main(){
    Array<int> *array;
    Estructuras<int>::create(&array,4); 
    Estructuras<int>::insert(array,1,5);
    Estructuras<int>::sobreescribir(&array,0,1);
    Estructuras<int>::show(array,true);
    Estructuras<int>::destroy(array); 
    return 0;
}