#include <iostream>
#define max 6
using namespace std;

#ifndef PILA_H_INCLUED
#define PILA_H_INCLUED


class CPila{
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
   CPila();
  ~CPila();
};

CPila::CPila(){
    IndIns=0;
}
CPila::~CPila(){

}

void CPila::push(float nd) {
    if (IndIns <= max-1){
        IndIns++;
        Pila[IndIns]=nd;
        }
    }


float CPila::pop() {
  cout<<"\n";
  cout<<Pila[IndIns];
  IndIns--;
  Pila[IndIns];
  cout<<"\n";
}

float CPila::tos() {
    cout<<Pila[IndIns];
    cout<<"\n";
}

int CPila::Size(){

    printf("\n%d",IndIns);
    cout<<"\n";
}

bool CPila::isEmpty() {
    if (IndIns==0){
        return 1;}
        else
            return 0;
}


bool CPila::isFull() {
    if (IndIns==max){
        return 1;}
        else
            return 0;
}

void CPila::imprimir(){

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
  #endif // PILA_H_INCLUED

  #ifndef COLA_H_INCLUED
#define COLA_H_INCLUED
using namespace std;
class CCola
{
	private:
		int cola[max];
		int IndIns;
		int IndElim;
		int tamanio;
	public:
		CCola();
	    void push(float nd);
		float pop();
		void imprimir();
		int Size();
		bool isEmpty();
		bool isFull();
		~CCola();
};

CCola::CCola()
{
	IndIns=-1;
	IndElim=0;
	tamanio=0;

	for(int i=0;i<max;i++)
	{
		cola[i]=0;
	}
}

bool CCola::isFull()
{
	if(tamanio==max-1)
		return 1;
	else
		return 0;
}

bool CCola::isEmpty()
{
	if(IndIns==IndElim-1)
		return 1;
	else
		return 0;
}

void CCola::push(float nd)
{
	    tamanio++;
		IndIns++;
		cola[IndIns]=nd;
}

float CCola::pop()
{
		cout<<cola[IndElim]<<endl;
		IndElim++;
		tamanio--;
}

int CCola::Size()
{
    cout<<"\n";
    cout<<tamanio;
    cout<<"\n";
}

void CCola::imprimir()
{
		cout<<"Datos En Cola"<<endl;
		for(int i=IndElim;i<=IndIns;i++)
		{
			cout<<cola[i]<<endl;
		}
}

CCola::~CCola()
{
  {
	IndIns=-1;
	for(int i;i<max;i++)
		{
			cola[i]=0;
		}
	}
}
#endif // COLA_H_INCLUED

int main()
{
    CPila pila;
    CCola cola;
  char opc;
  int op;
  float data;
  int sm;
  do{
  cout<<"-Elija la opcion que desee-\n-1-PILA ESTATICA\n-2-COLA ESTATICA\n-3-SALIR"<<endl;
  cin>>op;
  switch (op){
      case 1:
          do{
          printf("\nIngrese una opcion para el submenu");
          printf("\n1-IsEmpty\n2-IsFull\n3-push\n4-pop\n5-tos\n6-size\n7-Imprimir\n8-Salir del submenu\n\n");
          scanf("%d",&sm);
          switch(sm){
          case 1:
             if (pila.isEmpty()==1)
                cout<<"\nLa Pila Esta Vacia\n";
                else
                    cout<<"\nLa Pila No Esta Vacia\n";
            break;
          case 2:
             if (pila.isFull()==1)
                cout<<"\nLa Pila Esta Llena\n";
                else
                    cout<<"\nLa Pila No Esta Llena\n";
            break;
          case 3:
             if (pila.isFull()==1){
                cout<<"\nLa Pila Esta Llena\n";
                break;}
                else
                    cout<<"Ingrese un Dato:\t"<<endl;
                    cin>>data;
                    pila.push(data);//Inserta inicio
          break;
          case 4:
             if (pila.isEmpty()==1){
                cout<<"\nLa Pila Esta Vacia\n";
                break;}
                else
                    cout<<"\nAplicando pop...\n"<<endl;
                    pila.pop();//elimina inicio
                break;
          case 5:
             if (pila.isEmpty()==1){
                cout<<"\nLa Pila Esta Vacia\n";
                break;}
                else
                    cout<<("\nAplicando tos\n")<<endl;
                    pila.tos();
                    break;
          case 6:
             if (pila.isEmpty()==1){
                cout<<"\nLa Pila Esta Vacia\n";
                break;}
                else
                cout<<"\nTamanio de la pila: "<<endl;
                pila.Size();
                break;
          case 7:
             if (pila.isEmpty()==1){
                cout<<"\nLa Pila Esta Vacia\n";
                break;}
                else
                cout<<"\nImprimiendo la pila...\n"<< endl;
                pila.imprimir();
                break;
          case 8:
            cout<<"\nSaliendo del submenu\n"<< endl;
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
              if (cola.isEmpty() == true){
                printf("\nLa Cola esta vacia\n");
                break;
              }else
              printf("\nLa Cola no Esta vacia\n");
            break;
          case 2:
              if (cola.isFull() == true){
                printf("\nLa Cola esta llena\n");
                break;
              }else
              printf("\nLa Cola no Esta llena\n");
              break;
            break;
          case 3:
              if (cola.isFull() == true){
                printf("\nLa Cola esta llena\n");
                break;}
                else
                    cout<<"Ingrese un Dato:\t\n";
                    cin>>data;
                    cola.push(data);//inserta al final
                    break;
          case 4:
              if (cola.isEmpty() == true){
                printf("\nLa Cola esta Vacia\n");
                break;}
                else
                    cout<<"\nAplicando pop...\n"<<endl;
                    cola.pop();
                    break;
          case 5:
              if (cola.isEmpty() == true){
                printf("\nLa Cola esta Vacia\n");
                break;}
                else
                    cout<<"\nTamano de la cola: " <<endl;
                    cola.Size();
                    break;
          case 6:
              if (cola.isEmpty() == true){
                printf("\nLa Cola esta Vacia\n");
                break;}
                else
                    cout<<"\nImprimiendo la cola...\n"<< endl;
                    cola.imprimir();
                    break;
          case 7:
            cout<<"\nSaliendo del submenu\n"<< endl;
            break;
            }}while (sm !=7 );
            break;

}}while(op!=3);
printf("Hasta luego!");
}
