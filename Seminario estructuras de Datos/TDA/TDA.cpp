#include <iostream>
#include "PilaoCola.h"
#define max 6
using namespace std;

//Estaticas

class CColae: public CPilaoCola{
    private:
		int colaes[max];
		int IndIns;
		int IndElim;
		int tamanio;

	public:

	    void push(float nd);
		float pop();
		void imprimir();
		int Size();
		bool isEmpty();
		bool isFull();
        CColae();
		~CColae();

};

class CPilae:public CPilaoCola{
private:
  int IndIns;
  float Pila[max];

public:
  void push(float nd);
  float pop();
  float tos();
  int Size();
  bool isEmpty();
  bool isFull();
  void imprimir();
   CPilae();
  ~CPilae();
};

//Dinamicas
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
class CLista{

    private:

        CNodo Inicio;
        CNodo Final ;

    public:
         CLista();
        void InsertarInicio(float fData);
        void InsertarFinal(float fData);
        float ImprimeFrente();
        bool IsEmpty();
        int Size();
        void Vaciar();


        void Imprime();
        float EliminarInicio();
        float EliminarFinal();
        ~CLista();
};
//#Funciones CLista
CLista::CLista()
{
    Inicio.pSig = &Final;
    Final.pAnt = &Inicio;
}
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





void CLista::Imprime()
{
    CNodo *nP = Inicio.pSig;
    while(nP != &Final)
    {
        std::cout<<nP -> fCont<< std::endl;
        nP = nP ->pSig;
    }
}

float CLista::ImprimeFrente()
{
    CNodo *nP = Inicio.pSig;
            cout<<nP -> fCont<< endl;
}

float CLista::EliminarInicio()
{
    return Inicio.EliminarSiguiente();
}

float CLista::EliminarFinal()
{
    return Final.pAnt->pAnt->EliminarSiguiente();
}
CLista::~CLista()
{

}

class CPilaD:public CPilaoCola{
private:
  CLista lista;

public:
  void push(float nd);
  float pop();
  float tos();
  int Size();
  bool isEmpty();
  bool isFull();
  void imprimir();
};

void CPilaD::push(float nd) {
   lista.InsertarInicio(nd);
}

float CPilaD::pop() {
    printf("\nAplicando pop...\n");
  return lista.EliminarInicio();
}

float CPilaD::tos() {
    return lista.ImprimeFrente();
}

int CPilaD::Size(){

  return lista.Size();
}

bool CPilaD::isEmpty() {
    return lista.IsEmpty();
}


bool CPilaD::isFull() {

   return lista.Size();
}

void CPilaD::imprimir(){

   lista.Imprime();

  }
class CColaD:public CPilaoCola{
private:
  CLista lista;

public:
  void push(float nd);
  float pop();
  int Size();
  bool isEmpty();
  bool isFull();
  void imprimir();
};
void CColaD::push(float nd){
  lista.InsertarFinal(nd);
}

float CColaD::pop(){
  printf("\nAplicando Pop...\n");
  return lista.EliminarInicio();
}

int CColaD::Size(){
  return lista.Size();
}

bool CColaD::isEmpty(){
  return lista.IsEmpty();
}

bool CColaD::isFull(){
  return false;
}

void CColaD::imprimir(){
  printf("\nDatos En Cola\n");
  lista.Imprime();
}

//Estaticas

CPilae::CPilae(){
    IndIns=0;
}
CPilae::~CPilae(){

}

void CPilae::push(float nd) {
    if (IndIns <= max-1){
        IndIns++;
        Pila[IndIns]=nd;
        }
    }


float CPilae::pop() {

  cout<<"\nAplicando Pop...\n";
  IndIns--;
  Pila[IndIns];
  cout<<"\n";
}

float CPilae::tos() {
    cout<<Pila[IndIns];
    cout<<"\n";
}

int CPilae::Size(){

    printf("\n%d",IndIns);
    cout<<"\n";
}

bool CPilae::isEmpty() {
    if (IndIns==0){
        return 1;}
        else
            return 0;
}


bool CPilae::isFull() {
    if (IndIns==max){
        return 1;}
        else
            return 0;
}

void CPilae::imprimir(){

   	if(isEmpty()==1)
        {
            cout<<"La Pila Esta Vacia"<<endl;
            }
            else
                {
                    cout<<"Datos En Pila"<<endl;
                    cout<<"\n";
                    for(int i=IndIns;i>0;i--)
                        {
                            cout<<Pila[i]<<endl;
                    }
                    }
  }

CColae::CColae()
{
	IndIns=-1;
	IndElim=0;
	tamanio=0;

	for(int i=0;i<max;i++)
	{
		colaes[i]=0;
	}
}

bool CColae::isFull()
{
	if(tamanio==max-1)
		return 1;
	else
		return 0;
}

bool CColae::isEmpty()
{
	if(IndIns==IndElim-1)
		return 1;
	else
		return 0;
}

void CColae::push(float nd)
{
	    tamanio++;
		IndIns++;
		colaes[IndIns]=nd;
}

float CColae::pop()
{
        printf("\nAplicando Pop...\n");
		IndElim++;
		tamanio--;
}

int CColae::Size()
{
    cout<<"\n";
    cout<<tamanio;
    cout<<"\n";
}

void CColae::imprimir()
{
		cout<<"\nDatos En Cola\n"<<endl;
		for(int i=IndElim;i<=IndIns;i++)
		{
		    if (i<=6)
		    cout<<colaes[i]<<endl;
		}
}

CColae::~CColae()
{
  {
	IndIns=-1;
	for(int i;i<max;i++)
		{
			colaes[i]=0;
		}
	}
}

int main(){
	CPilaoCola* pD = 0;
	int opc = 0;
		while (opc != 5){
			cout << "Selecciona el metodo con el que deseas trabajar\n~~1. Cola Dinamica\n~~2. Cola Estatica\n~~3. Pila Dinamica\n~~4. Pila Estatica\n~~5. Salir\n" << endl;
			cin >> opc;
			if (opc == 1)
				pD = new CColaD();
			else if (opc == 2)
				pD = new CColae();
			else if (opc == 3)
				pD = new CPilaD();
			else if (opc == 4)
				pD = new CPilae();
			else if (opc == 5)
				continue;
			else
			{
				cout << "Opcion Invalida" << endl;
				continue;
			}
			break;
		}
		printf("\nAgregando Datos...\n");
		pD->push(0);
        pD->push(1);
        pD->push(2);
        pD->push(3);
		pD->imprimir();
		pD->pop();
		pD->imprimir();
		printf("\nAgregando Datos...\n");
		pD->push(4);
        pD->push(5);
        pD->push(6);
        pD->push(7);
		pD->imprimir();
	}

