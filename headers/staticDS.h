typedef struct Data{
    int n;
    int m;
    Data(){};
} Data;

#include "Array.h"
#include "Array1D.h" 
template <typename T>
class Estructuras{

    private:
        static Data ref;

    public:
        static void create(Array<T>** array, int size){
            ref.n=size;
            *array= new Array1D<T>();
            (*array)->create(ref);
        }
        static void destroy(Array<T>* var){
            //Se invoca el método destroy() del objeto var
            var->destroy();
        }
        static void insert(Array<T> *array,int pos,T value){
            ref.n=pos;
            array->insert(ref,value);
        }
        static void extract(Array<T> *array,int pos, T *value){
            ref.n=pos;
            *value=array->extract(ref);
        }
        static void show(Array<T>* var, bool verbose){
            //Se invoca el método show() del objeto var
            var->show(verbose);
        }
        static void insertarcadados(Array<T> **var,T value){
            (*var)->insertarcadados(value);
        }
        static void sobreescribir(Array<T> **var,T v1,T v2){
            (*var)->sobreescribir(v1,v2);
        }
        static void buscardosveces(Array<T> **var,T v1,bool *valor){
            *valor=(*var)->buscardosveces(v1);
        }
        static void buscarmasdedos(Array<T> **var,T v1,bool *valor){
            *valor=(*var)->buscarmasdedos(v1);
        }
        static void buscarnveces(Array<T> **var,T v1,T n,bool *valor){
            *valor=(*var)->buscarnveces(v1,n);
        }
        static void intervalo(Array<T> **var,T v1){
            (*var)->intervalo(v1);
        }
};