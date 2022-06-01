#include <iostream>

using namespace std;

#ifndef CNODOS_H_INCLUED

#define CNODOS_H_INCLUED
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
#endif // CNODOS_H_INCLUED

#ifndef LISTA_H_INCLUED


#define LISTA_H_INCLUED

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
//Funciones CLista

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
#endif // LISTA_H_INCLUED

#ifndef PILA_H_INCLUED
#define PILA_H_INCLUED


class CPila{
private:
  CLista lista;

public:
  void push(float nd);
  float pop();
  float tos();
  int size();
  bool isEmpty();
  bool isFull();
  void imprimir();
};
void CPila::push(float nd) {
   lista.InsertarInicio(nd);
}

float CPila::pop() {

  return lista.EliminarInicio();
}

float CPila::tos() {
    return lista.ImprimeFrente();
}

int CPila::size(){

  return lista.Size();
}

bool CPila::isEmpty() {
    return lista.IsEmpty();
}


bool CPila::isFull() {

   return lista.Size();
}

void CPila::imprimir(){

   lista.Imprime();

  }
  #endif // PILA_H_INCLUED

  #ifndef COLA_H_INCLUED
#define COLA_H_INCLUED
class CCola {
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
void CCola::push(float nd){
  lista.InsertarFinal(nd);
}

float CCola::pop(){
  return lista.EliminarInicio();
}

int CCola::Size(){
  return lista.Size();
}

bool CCola::isEmpty(){
  return lista.IsEmpty();
}

bool CCola::isFull(){
  return false;
}

void CCola::imprimir(){
  lista.Imprime();
}
#endif // COLA_H_INCLUED

int main()
{
    CPila pila;
    CLista lista;
    CCola cola;
  char opc;
  int op;
  float data;
  int ic=0,ip=0;
  int cd=0;
  int sm;
  do{
  cout<<"-Elija la opcion que desee-\n~1~PILA\n~2~COLA\n~3~SALIR"<<endl;
  cin>>op;
  switch (op){
      case 1:
          do{
          printf("\nIngrese una opcion para el submenu");
          printf("\n1-IsEmpty\n2-IsFull\n3-push\n4-pop\n5-tos\n6-size\n7-Imprimir\n8-Salir del submenu\n\n");
          scanf("%d",&sm);
          switch(sm){
          case 1:
              pila.isEmpty();
              if (pila.isEmpty() == true){
                printf("\nLa pila esta vacia\n");
              }else
              printf("\nLa pila no Esta vacia\n");
            break;
          case 2:
              pila.size();
              if (pila.size() == cd){
                printf("\nLa pila no esta llena\n");
              }else
              printf("\nLa pila  Esta llena\n");
              break;
            break;
          case 3:
          printf("Deme la cantidad de datos a ingresar: ");
          scanf("%d",&cd);
          do{
                cout<<"Ingrese un Dato:\t";
          cin>>data;
          pila.push(data);//Inserta inicio
          ip++;
          }while (ip<cd);
          break;
          case 4:
              cout<<"\nAplicando pop...\n"<<pila.pop()<<endl;//elimina inicio
            break;
          case 5:
              printf("\nAplicando tos\n");
              pila.tos();
            break;
          case 6:
             cout<<"\nTamano de la pila: " <<pila.size()<<endl;
            break;
          case 7:
            cout<<"\nImprimiendo la pila...\n"<< endl;pila.imprimir();cout<<endl;
            break;
          case 8:
            cout<<"\nSaliendo del submenu\n"<< endl;
            ip==0;
            break;
            }}while (sm !=8 );
            break;
case 2:
          do{
          printf("\nIngrese una opcion para el submenu");
          printf("\n1-IsEmpty\n2-IsFull\n3-push\n4-pop\n5-size\n6-Imprimir\n7-Salir del submenu\n\n");
          scanf("%d",&sm);
          switch(sm){
          case 1:
              cola.isEmpty();
              if (cola.isEmpty() == true){
                printf("\nLa Cola esta vacia\n");
              }else
              printf("\nLa Cola no Esta vacia\n");
            break;
          case 2:
              cola.Size();
              if (cola.Size() == cd){
                printf("\nLa Cola no esta llena\n");
              }else
              printf("\nLa Cola Esta llena\n");
              break;
            break;
          case 3:
          printf("Deme la cantidad de datos a ingresar: ");
          scanf("%d",&cd);
          do{
                cout<<"Ingrese un Dato:\t";
          cin>>data;
          cola.push(data);//inserta al final
          ic++;
          }while (ic<cd);
          break;
          case 4:
              cout<<"\nAplicando pop...\n"<<cola.pop()<<endl;//elimina inicio
            break;
          case 5:
             cout<<"\nTamano de la cola: " <<cola.Size()<<endl;
            break;
          case 6:
            cout<<"\nImprimiendo la cola...\n"<< endl;cola.imprimir();cout<<endl;
            break;
          case 7:
            cout<<"\nSaliendo del submenu\n"<< endl;
             ic==0;
            break;
            }}while (sm !=7 );
            break;

}}while(op!=3);
printf("Hasta luego!");
}
