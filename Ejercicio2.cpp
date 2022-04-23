#include <iostream> 
using namespace std;
#include "headers/staticDS.h"

template<typename T>
Data Estructuras<T>::ref=Data();

int main(){
    Array<int> *array;
    Estructuras<int>::create(&array,4);
    Estructuras<int>::insertarcadados(&array,15);
    return 0;
};