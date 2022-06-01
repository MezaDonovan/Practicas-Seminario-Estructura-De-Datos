
class CLista{

    private:

        CNodo Inicio;
        CNodo Final ;

    public:

        void InsertarInicio(float fData);
        void InsertarFinal(float fData);
        bool IsEmpty();
        int Size();
        void Vaciar();
        CLista();
        ~CLista();
        void Imprime();
        float EliminarInicio();
        float EliminarFinal();
};
