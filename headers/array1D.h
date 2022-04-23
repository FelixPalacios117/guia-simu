template <typename T>

class Array1D: public Array<T>{
    private:
    T* array;
    int size;

    public:

    void create(Data length) override{
        size=length.n;
        array=(T*) malloc(sizeof(T)*size);
    }
    void init() override{
        for(int i=0;i<size;i++){
            array[i]=(T)0;
        }
    }
    void insert(Data pos,T value) override{
        array[pos.n]=value;
    }
    T extract(Data pos) override{
        return array[pos.n];
    }
    void destroy() override{
        free(array);
    }
    void insertarcadados(T value) override{
        for(int i=0;i<size;i++){
            array[i]=value;
            i++;
        }
         show(false);
    } 
     void show(bool verbose) override {
            if(verbose)
                for(int i = 0; i < size; i++)
                    //Se especifica explícitamente el valor de cada elemento
                    //almacenado en el arreglo, uno por línea.
                    cout << "Element #" << i+1 << " is: " << array[i] << "\n";
            else{
                //Se muestra el contenido del arreglo como una secuencia de datos
                //representando las distintas posiciones mediante el uso de ','.

                //Se abre la secuencia
                cout << "[ ";

                //Se recorre el arreglo hasta la penúltima posición
                for(int i = 0; i < size-1; i++)
                    //Se coloca el dato en la posición actual seguido de ','
                    cout << array[i] << ", ";
                
                //Se coloca el dato de la última posición seguido del cierre de la secuencia
                cout << array[size-1] << " ]\n";
            }
        }
        bool buscarmasdedos(T v1) override{
            int contador=0;
            for(int i=0;i<size;i++){
                if(array[i]==v1 ){
                    contador++;
                }
            }
            if(contador>=2){
                return true;
            }
            return false;
        }
        bool buscardosveces(T v1) override{
            int contador=0;
            for(int i=0;i<size;i++){
                if(array[i]==v1 ){
                    contador++;
                }
            }
            if(contador==2){
                return true;
            }
            return false;
        }
        bool buscarnveces(T v1, T n) override{
            int contador=0;
            for(int i=0;i<size;i++){
                if(array[i]==v1){
                    contador++;
                }
            }
            if(contador==n){
                return true;
            }
            return false;
        }
        void intervalo(T v1) override{
             cout << "[ "; 
            for(int i=v1-1;i<v1+1;i++){
                cout << array[i] << ", "; 
            }
            cout << array[v1+1] << " ]\n";
        }
        void sobreescribir(T v1,T v2) override{
            for(int i=0;i<size;i++){
                if(array[i]==v1){
                    array[i]=v2;
                }
            }
        }
};