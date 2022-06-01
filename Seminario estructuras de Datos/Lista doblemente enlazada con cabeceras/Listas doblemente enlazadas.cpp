#include <iostream>
#include "CNodo.h"
#include "CLista.h"

using namespace std;

//#Funciones CNodo

void CNodo::InsertarAdelante(float fData)
{

    CNodo *pNuevo = new CNodo;
    pNuevo -> pSig = this -> pSig;
    pNuevo -> pAnt = this;
    this -> pSig = pNuevo;
    this -> pSig -> pSig -> pAnt = pNuevo;
    pNuevo -> fCont =fData;
}

float CNodo::EliminarSiguiente()
{
    float nN;
    CNodo * nP = this -> pSig;
    nN = nP -> fCont;
    this -> pSig = this -> pSig -> pSig;
    this -> pSig -> pAnt = this;
    delete nP; return nN;
}

//#Funciones CLista

void CLista::InsertarInicio(float fData)
{
    Inicio.InsertarAdelante(fData);
}

void CLista::InsertarFinal(float fData)
{
    Final.pAnt->InsertarAdelante(fData);
}

bool CLista::IsEmpty()
{
    if(Inicio.pSig == &Final)
    {
        return true;
    }
    return false;
}

int CLista::Size()
{
    int ctn = 0;

    CNodo *nP = Inicio.pSig;

    while(nP != &Final)
    {
        ctn++;
        nP = nP -> pSig;
    }
    return ctn;
}

void CLista::Vaciar()
{
    CNodo *nP=Inicio.pSig;
    CNodo *nN;
    while (nP != &Final)
    {
        nN = nP;
        nP = nP ->pSig;
        delete nN;
    }
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}

CLista::CLista()
{
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}

CLista::~CLista()
{

}

void CLista::Imprime()
{
    CNodo *nP = Inicio.pSig;
    while(nP != &Final)
    {
        cout<<nP -> fCont<< endl;
        nP = nP ->pSig;
    }
}

float CLista::EliminarInicio()
{
    return Inicio.EliminarSiguiente();
}

float CLista::EliminarFinal()
{
    return Final.pAnt->pAnt->EliminarSiguiente();
}

//#Main
int main()
{
  int nn;

  CLista lista;

  printf("Ingrese el numero de nodos que desea ingresar a la lista:\t");
  scanf("%d",&nn);

  float data;

  cout << "\n";
  for(int i = 1; i <= nn; i++) {
    printf("Introduzca un nodo:\t");
    cin >> data;
    lista.InsertarInicio(data);
  }
  cout << "\n";
  cout << "Tamano de la lista:\t\n"
  << lista.Size() <<"  nodos" ;
  cout << "\n\n";
  cout << "Lista Impresa:\n\n";
  lista.Imprime();
  cout << "\n";
  cout << "Elemento Inicial a eliminar: \t" << lista.EliminarInicio() << endl;
  cout << "Elemento Final a eliminar: \t" << lista.EliminarFinal() << endl;
  cout << "\n";
  cout << "Imprimiendo la Lista Para Verificar que se eliminaron:\n" << endl;
  lista.Imprime();
  cout << "\n";
  cout << "Llamando la funcion vaciar...\n" << endl;
  lista.Vaciar();
  cout << "Imprimiendo la Lista Para Verificar que este Vacia:\n" << endl;
  lista.Imprime();
}
