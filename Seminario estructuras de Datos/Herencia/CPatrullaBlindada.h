class CPatrullaArtillada:public CPatrulla
{
    private:

        int Blindaje=360;
        float Velocidad=0;

    public:
        void CPatrullaArtillada_Imprimir();
        float CPatrullaArtillada_Acelerar();
        CPatrullaArtillada();
        ~CPatrullaArtillada();
};
