
class CNodo{

    friend class CLista;

private:

    float fCont;

    CNodo* pSig;

    CNodo* pAnt;

public:

    void InsertarAdelante(float fData);

    float EliminarSiguiente();

};
