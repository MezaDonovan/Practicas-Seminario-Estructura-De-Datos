#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Classes

class CMotor{
public:
	int iCilindros;
	int iCilindrada;
	CMotor();
	~CMotor();
	void imprimir();
};

class CAuto
{
protected:
	CMotor* engine;
	float speed;
public:
	CAuto();
	~CAuto();
	void acelerar();
	void imprimirNoVirtual();
	virtual void imprimirVirtual();
};

class CNode
{
private:
	CNode* pNext;
	CNode* pPrevious;
	CAuto* fData;
	friend class CList;
public:
	void insertInFront(CAuto* fNewData);
	CAuto* deleteInFront();
};

class CList
{
private:
	CNode* beginning;
	CNode* end;
public:
	CList();
	~CList();

	void insertBeginning(CAuto* data);
	void insertEnd(CAuto* data);
	bool isEmpty();
	int size();
	void empty();
	void imprimir();
	void imprimirNoVirtual();
	CAuto* deleteBeginning();
	CAuto* deleteEnd();
};

class CPatrulla : public CAuto
{
public:
	CPatrulla();
	~CPatrulla();
	void acelerar();
	void imprimirNoVirtual();
	virtual void imprimirVirtual();
};

class CPatrullaArtillada : public CPatrulla
{
public:
	CPatrullaArtillada();
	~CPatrullaArtillada();
	void acelerar();
	void imprimirNoVirtual();
	virtual void imprimirVirtual();
};

class Taxi : public CAuto
{
public:
	Taxi();
	~Taxi();
	void acelerar();
	void imprimirNoVirtual();
	virtual void imprimirVirtual();
};

class ToretosCar : public CAuto
{
public:
	ToretosCar();
	~ToretosCar();
	void acelerar();
	void turbo();
	void imprimirNoVirtual();
	virtual void imprimirVirtual();
};



//Funciones nodo

void CNode::insertInFront(CAuto* fNewData)
{
	CNode* newNode = new CNode();
	newNode->pNext = this->pNext;
	newNode->pPrevious = this;
	newNode->pNext->pPrevious = newNode;
	this->pNext = newNode;
	newNode->fData = fNewData;
}

CAuto* CNode::deleteInFront()
{
	CAuto* stored = this->pNext->fData;
	CNode* deleted = this->pNext;
	this->pNext = deleted->pNext;
	deleted->pNext = nullptr;
	deleted->pPrevious = nullptr;
	this->pNext->pPrevious = this;
	return stored;
}

//Funciones Lista

CList::CList()
{
	beginning = new CNode();
	end = new CNode();
	beginning->pNext = end;
	end->pPrevious = beginning;
}

CList::~CList()
{
	empty();
}

void CList::insertBeginning(CAuto* data)
{
	beginning->insertInFront(data);
}

void CList::insertEnd(CAuto* data)
{
	end->pPrevious->insertInFront(data);
}

bool CList::isEmpty()
{
	return (beginning->pNext == end);
}

int CList::size()
{
	int nodeCounter = 0;
	CNode* n = new CNode();
	n = beginning;
	n = n->pNext;
	while (n != end)
	{
		nodeCounter += 1;
		n = n->pNext;
	}
	return nodeCounter;
}

void CList::empty()
{
	CNode* n = new CNode();
	n = beginning;
	n = n->pNext;
	while (n != end)
	{
		n = n->pNext;
		delete n->pPrevious;
	}
	beginning->pNext = end;
	end->pPrevious = beginning;
}

void CList::imprimir()
{
	CNode* n = beginning->pNext;
	for (int i = 0; i <= size() - 1; i++)
	{
		n->fData->imprimirVirtual();
		n = n->pNext;
	}
}

void CList::imprimirNoVirtual()
{
	CNode* n = beginning->pNext;
	for (int i = 0; i <= size() - 1; i++)
	{
		n->fData->imprimirNoVirtual();
		n = n->pNext;
	}
}

CAuto* CList::deleteBeginning()
{
	return beginning->deleteInFront();
}

CAuto* CList::deleteEnd()
{
	return end->pPrevious->pPrevious->deleteInFront();
}

//Funciones Taxi

Taxi::Taxi()
{
	std::cout << "Creando Taxi..." << std::endl;
}

Taxi::~Taxi()
{
	std::cout << "Destruyendo Taxi..." << std::endl;
}

void Taxi::acelerar()
{
	speed += 5;
}

void Taxi::imprimirNoVirtual()
{
	std::cout << "Velocidad del Taxi " << speed << ". Motor:" << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje del Motor:." << std::endl;
}

void Taxi::imprimirVirtual()
{
	std::cout << "Velocidad del Taxi " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje del Motor." << std::endl;
}

//Funciones Auto

CAuto::CAuto()
{
	std::cout << "Creando Auto..." << std::endl;
	speed = 0;
	engine = new CMotor();
}

CAuto::~CAuto()
{
	std::cout << "Borrando Auto..." << std::endl;
}

void CAuto::acelerar()
{
	speed += 1;
}


void CAuto::imprimirNoVirtual()
{
	std::cout << "Su auto va a esta velocidad: " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje del motor." << std::endl;
}

void CAuto::imprimirVirtual()
{
	std::cout << "La velocidad actual de su Auto es: " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " Cilindraje del motor." << std::endl;
}

//Funciones Motor

CMotor::CMotor()
{
	std::cout << "Creando su Motor..." << std::endl;
	iCilindros = rand() % 8 + 2;
	iCilindrada = iCilindros * (rand() % 300 + 800);
}

CMotor::~CMotor()
{
	std::cout << "Destruyendo Motor..." << std::endl;
}

void CMotor::imprimir()
{
	std::cout << "Motor " << iCilindrada << "cc, " << iCilindros << " cilindraje del motor." << std::endl;
}

//Funciones Patrulla

CPatrulla::CPatrulla()
{
	std::cout << "Creando Patrulla..." << std::endl;
}

CPatrulla::~CPatrulla()
{
	std::cout << "Destruyendo Patrulla..." << std::endl;
}

void CPatrulla::acelerar()
{
	speed += 2;
}

void CPatrulla::imprimirNoVirtual()
{
	std::cout << "La velocidad de la Patrulla es: " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje del Motor." << std::endl;
}

void CPatrulla::imprimirVirtual()
{
	std::cout << "La velocidad de la Patrulla es: " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje del Motor." << std::endl;
}

//Funciones PatrullaArtillada

CPatrullaArtillada::CPatrullaArtillada()
{
	std::cout << "Creando Patrulla Artillada..." << std::endl;
}

CPatrullaArtillada::~CPatrullaArtillada()
{
	std::cout << "Destruyendo Patrulla Artillada..." << std::endl;
}

void CPatrullaArtillada::acelerar()
{
	speed += 1.5;
}

void CPatrullaArtillada::imprimirNoVirtual()
{
	std::cout << "Velocidad de Patrulla Artillada : " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje de Motor." << std::endl;
}

void CPatrullaArtillada::imprimirVirtual()
{
	std::cout << "Velocidad de Patrulla Artillada : " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje de Motor." << std::endl;
}

//Funciones Toreto

ToretosCar::ToretosCar()
{
	std::cout << "Creando auto de Toreto..." << std::endl;
}

ToretosCar::~ToretosCar()
{
	std::cout << "Destruyendo auto de Toreto..." << std::endl;
}

void ToretosCar::acelerar()
{
	speed += 3;
}

void ToretosCar::turbo()
{
	speed += 10;
}

void ToretosCar::imprimirNoVirtual()
{
	std::cout << "La velocidad de Toreto es: " << speed << ". Motor: " << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje del Motor:." << std::endl;
}

void ToretosCar::imprimirVirtual()
{
	std::cout << "La velocidad de Toreto es: " << speed << ". Motor" << engine->iCilindrada << "cc, " << engine->iCilindros << " cilindraje del Motor:." << std::endl;
}


int main()
{
	CAuto* pA;
	CList* list = new CList();
	char a;
	int chc = 0, chc2 = 0;

	while (chc != 8)
	{
		switch (chc)
		{
		case 0:
			chc2 = 0;
			cout<< "Bienvenido a la fabrica de autos"<< endl;
			cout<< "Elija el Modelo de Auto que desee crear"<< endl;
			cout << "1. Auto\n2. Patrulla\n3. Patrulla Artillada\n4. Taxi\n5. Toreto\n6. Lista de Vehiculos \n7. Lista Virtual de Vehiculos \n8. Salir\n" << endl;
			cin >> chc;
			break;
		case 1:
		{
			pA = new CAuto();
			list->insertEnd(pA);
			chc2 = 0;
			while (chc2 != 4)
			{
				switch (chc2)
				{
				case 0:
					cout << "Opciones\n1. Acelerar\n2. Datos\n3. Datos Virtuales\n4. Regresar al menu menu" << endl;
					cin >> chc2;
					break;
				case 1:
					pA->acelerar();
					chc2 = 0;
					break;
				case 2:
					pA->imprimirNoVirtual();
					chc2 = 0;
					break;
				case 3:
					pA->imprimirVirtual();
					chc2 = 0;
					break;
				default:
					cout << "opcion invalida" << endl;
					chc2 = 0;
					break;
				}
			}
			cout << "Regresando..." << endl;
			chc = 0;
			break;
		}
		case 2:
		{
			pA = new CPatrulla();
			list->insertEnd(pA);
			chc2 = 0;
			while (chc2 != 4)
			{
				switch (chc2)
				{
				case 0:
					cout << "Opcion\n1. Acelerar\n2. Datos \n3. Datos Virtuales\n4. Regresa al menu" << endl;
					cin >> chc2;
					break;
				case 1:
					((CPatrulla*)pA)->acelerar();
					chc2 = 0;
					break;
				case 2:
					pA->imprimirNoVirtual();
					chc2 = 0;
					break;
				case 3:
					pA->imprimirVirtual();
					chc2 = 0;
					break;
				default:
					cout << "opcion invalida" << endl;
					chc2 = 0;
					break;
				}
			}
			cout << "Regresando..." << endl;
			chc = 0;
			break;
		}
		case 3:
		{
			pA = new CPatrullaArtillada();
			list->insertEnd(pA);
			chc2 = 0;
			while (chc2 != 4)
			{
				switch (chc2)
				{
				case 0:
					cout << "Opciones\n1. Acelerar\n2. Datos \n3. Datos Virtuales\n4. Regresar al menu" << endl;
					cin >> chc2;
					break;
				case 1:
					((CPatrullaArtillada*)pA)->acelerar();
					chc2 = 0;
					break;
				case 2:
					pA->imprimirNoVirtual();
					chc2 = 0;
					break;
				case 3:
					pA->imprimirVirtual();
					chc2 = 0;
					break;
				default:
					cout << "opcion invalida" << endl;
					chc2 = 0;
					break;
				}
			}
			cout << "Regresando..." << endl;
			chc = 0;
			break;
		}
		case 4:
		{
			pA = new Taxi();
			list->insertEnd(pA);
			chc2 = 0;
			while (chc2 != 4)
			{
				switch (chc2)
				{
				case 0:
					cout << "Opciones\n1. Acelerar\n2. Datos \n3. Datos Virtuales\n4. Regresar al menu" << endl;
					cin >> chc2;
					break;
				case 1:
					((Taxi*)pA)->acelerar();
					chc2 = 0;
					break;
				case 2:
					pA->imprimirNoVirtual();
					chc2 = 0;
					break;
				case 3:
					pA->imprimirVirtual();
					chc2 = 0;
					break;
				default:
					cout << "Opcion invalida" << endl;
					chc2 = 0;
					break;
				}
			}
			cout << "Regresando..." << endl;
			chc = 0;
			break;
		}
		case 5:
		{
			pA = new ToretosCar();
			list->insertEnd(pA);
			chc2 = 0;
			while (chc2 != 5)
			{
				switch (chc2)
				{
				case 0:
					cout << "Opciones\n1. Acelerar\n2. Turbo \n3. Datos \n4. Datos Virtuales \n5. Salir al menu" << endl;
					cin >> chc2;
					break;
				case 1:
					((ToretosCar*)pA)->acelerar();
					chc2 = 0;
					break;
				case 2:
					((ToretosCar*)pA)->turbo();
					chc2 = 0;
					break;
				case 3:
					pA->imprimirNoVirtual();
					chc2 = 0;
					break;
				case 4:
					pA->imprimirVirtual();
					chc2 = 0;
					break;
				default:
					cout << "Opcion invalida" << endl;
					chc2 = 0;
					break;
				}
			}
			cout << "Regresando..." << endl;
			chc = 0;
			break;
		}
		case 6:
		{
			list->imprimirNoVirtual();
			chc = 0;
			break;
		}
		case 7:
		{
			list->imprimir();
			chc = 0;
			break;
		}
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	}
	cout << "\n Hasta luego!" << endl;
}
