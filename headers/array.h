template <typename T>
class Array{
    public: 
        //virtual ndimensions category() = 0;
 
        virtual void create(Data dim) = 0;
 
        //virtual Data getDim() = 0;
 
        virtual void init() = 0;
   
        virtual void insert(Data pos, T value) = 0;
 
        virtual T extract(Data pos) = 0;
 
        virtual void destroy() = 0;
 
        //virtual bool search(T value) = 0;
 
        //virtual int count(T value) = 0;
 
        //virtual void reverse() = 0;
 
        virtual void show(bool verbose) = 0;
        virtual void insertarcadados(T value)=0;
        virtual void sobreescribir(T v1,T v2)=0;
        virtual bool buscardosveces(T v1)=0;
        virtual bool buscarmasdedos(T v1)=0;
        virtual bool buscarnveces(T v1,T n)=0;
        virtual void intervalo(T v1)=0;
};