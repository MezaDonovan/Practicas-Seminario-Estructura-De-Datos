#include <iostream>
#include <time.h>
#include <iostream>
#include <exception>
#include <string>
#include <fstream>

using namespace std;

//CLASES

//-CONTACTO
class Contacto {
    private:
        std::string nombre;
        std::string numero;
    public:
        Contacto();
        Contacto(const Contacto&);
        void setNombre(std::string&);
        void setNumero(std::string&);

        std::string getNumero();
        std::string getNombre();

        void toString();

        Contacto& operator=(const Contacto&);
        bool operator ==(const Contacto&)const;
        bool operator != (const Contacto&)const;
        bool operator <(const Contacto&)const;
        bool operator >(const Contacto&)const;
    };


Contacto::Contacto() {}

Contacto::Contacto(const Contacto& c): nombre(c.nombre), numero(c.numero) {}

void Contacto::setNombre(std::string& n) {
    nombre=n;
    }

void Contacto::setNumero(std::string& n) {
    numero=n;
    }

std::string Contacto::getNumero() {
    return numero;
    }

std::string Contacto::getNombre() {
    return nombre;
    }

void Contacto::toString() {
    std::cout<<"####################################################"<<std::endl;
    std::cout<<"Nombre del contacto: "<<nombre<<std::endl;
    std::cout<<"Numero del contacto: "<<numero<<std::endl;

    }

Contacto& Contacto::operator=(const Contacto& h) {
    numero = h.numero;
    nombre = h.nombre;
    return *this;
    }

bool Contacto::operator ==(const Contacto& h) const {
    return nombre == h.nombre;
    }

bool Contacto::operator !=(const Contacto& h) const {
    return nombre != h.nombre;
    }

bool Contacto::operator <(const Contacto& h) const {
    return nombre < h.nombre;
    }

bool Contacto::operator >(const Contacto& h) const {
    return nombre > h.nombre;
    }


//-LLAMADA

class Llamada {
    private:
        std::string numero;
        std::string tipo;
        std::string tiempo;
    public:
        Llamada();
        Llamada(const Llamada&);
        void setTipo(std::string&);
        void setTiempo(std::string&);
        void setNumero(std::string&);

        std::string getNumero();
        std::string getTiempo();
        std::string getTipo();

        void toString();

        Llamada& operator=(const Llamada&);
        bool operator ==(const Llamada&)const;
    };


Llamada::Llamada() {}

Llamada::Llamada(const Llamada& c): tipo(c.tipo), numero(c.numero),tiempo(c.tiempo) {}

void Llamada::setTiempo(std::string& t) {
    tiempo=t;
    }

void Llamada::setNumero(std::string& n) {
    numero=n;
    }
void Llamada::setTipo(std::string& t) {
    tipo=t;
    }

std::string Llamada::getNumero() {
    return numero;
    }

std::string Llamada::getTiempo() {
    return tiempo;
    }

std::string Llamada::getTipo() {
    return tipo;
    }

void Llamada::toString() {
    std::cout<<"##############################################"<<std::endl;
    std::cout<<"Numero: "<<numero<<std::endl;
    std::cout<<"Tipo: "<<tipo<<std::endl;
    std::cout<<"Hora: "<<tiempo<<std::endl;

    }

Llamada& Llamada::operator=(const Llamada& h) {
    numero = h.numero;
    tiempo = h.tiempo;
    tipo=h.tipo;
    return *this;
    }

bool Llamada::operator ==(const Llamada& h) const {
    return numero == h.numero;
    }


//-ARBOL BINARIO

template <class T>
class BTree {
    private:
        class Node {
            private:
                T* dataPtr;
                Node* left;
                Node* right;
            public:
                class Exception: public std::exception {
                    private:
                        std::string msg;
                    public:
                        explicit Exception(const char* message):msg(message) {}
                        explicit Exception(const std::string& message):msg(message) {}
                        virtual ~Exception() throw () {}
                        virtual const char* what() const throw() {
                            return msg.c_str();
                            }
                    };

                Node();
                Node(const T&);

                ~Node();

                T* getDataPtr()const;
                T getData()const;
                Node*& getLeft();
                Node*& getRight();


                void setDataPtr(T*);
                void setData(const T&);
                void setLeft(Node*&);
                void setRight(Node*&);
            };

    public:
        typedef Node* Position;

    private:
        Position root;

        void copyAll(const BTree<T>&);

        void insertData(Position&, const T&);

        Position& findData(Position&, const T&);
        void findDataNumber(Position&, T&, Position&);

        Position& getLowest(Position&);
        Position& getHighest(Position&);

        void parsePreOrder(Position&);
        void parseInOrder(Position&);
        void parsePostOrder(Position&);

        void copyData(Position&);

        void guardar(Position&,std::ofstream&);
        void cargar(Position&,std::ifstream&);

    public:
        class Exception: public std::exception {
            private:
                std::string msg;
            public:
                explicit Exception(const char* message):msg(message) {}
                explicit Exception(const std::string& message):msg(message) {}
                virtual ~Exception() throw () {}
                virtual const char* what() const throw() {
                    return msg.c_str();
                    }
            };

        BTree();
        BTree(const BTree&);

        ~BTree();

        bool isEmpty() const;

        void insertData(const T&);

        void deleteData(Position&);

        T retrieve(Position&) const;

        int getHeight(Position&);
        int getRightHeight();
        int getLeftHeight();

        Position& findData(const T&);
        void findDataNumber(Position&, T&);

        Position& getLowest();
        Position& getHighest();

        bool isLeaf(Position&) const;

        int getHeight();
        void setRoot(Position&);

        void parsePreOrder();
        void parseInOrder();
        void parsePostOrder();

        void deleteAll();

        BTree& operator=(const BTree<T>&);

        void guardar();
        void cargar();

    };

//NODO
template <class T>
BTree<T>::Node::Node():dataPtr(nullptr),right(nullptr),left(nullptr) {}

template <class T>
BTree<T>::Node::Node(const T& e):dataPtr(new T(e)),right(nullptr),left(nullptr) {
    if(dataPtr==nullptr) {
        throw Exception("Memoria insuficiente, creandoNodo");
        }
    }

template <class T>
BTree<T>::Node::~Node() {
    delete dataPtr;
    }

template <class T>
T* BTree<T>::Node::getDataPtr() const {
    return dataPtr;
    }

template <class T>
T BTree<T>::Node::getData() const {
    if(dataPtr==nullptr) {
        throw Exception("Datos inexistentes, getData");
        }
    return *dataPtr;
    }

template <class T>
typename BTree<T>::Position& BTree<T>::Node::getLeft() {
    return left;
    }


template <class T>
typename BTree<T>::Position& BTree<T>::Node::getRight()  {
    return right;
    }

template <class T>
void BTree<T>::Node::setDataPtr(T* p) {
    dataPtr=p;
    }

template <class T>
void BTree<T>::Node::setData(const T& e) {
    if(dataPtr==nullptr) {
        if((dataPtr=new T(e))==nullptr) {
            throw Exception("Memoria no disponible, setData");
            }
        }
    else {
        *dataPtr=e;
        }
    }

template <class T>
void BTree<T>::Node::setRight(Position& p) {
    right=p;
    }

template <class T>
void BTree<T>::Node::setLeft(Position& p) {
    left=p;
    }






//BTree

//CopyALL
template <class T>
void BTree<T>::copyData(Position& r) {
    if(r==nullptr) {
        return;
        }
    insertData(r->getData());
    copyData(r->getLeft());
    copyData(r->getRight());
    }

template <class T>
void BTree<T>::copyAll(const BTree<T>& l) {
    Position pos(l.root);
    copyData(pos);
    }


//Constructor
template <class T>
BTree<T>::BTree():root(nullptr) {}

//Constructor Copia
template <class T>
BTree<T>::BTree(const BTree& t):root(nullptr) {
    copyAll(t);
    }

//Destructor
template <class T>
BTree<T>::~BTree() {
    deleteAll();
    }

//IsEmpty
template <class T>
bool BTree<T>::isEmpty() const {
    return root==nullptr;
    }


//InsertData
template <class T>
void BTree<T>::insertData(const T& e) {
    insertData(root,e);
    }

template <class T>
void BTree<T>::insertData(Position& r, const T& e) {
    if(r==nullptr) {
        try {
            if((r=new Node(e))==nullptr) {
                throw Exception("Memoria insuficiente, insertData");
                }
            }
        catch(typename Node::Exception ex) {
            throw Exception(ex.what());
            }
        }
    else {
        if(e < r->getData()) {
            insertData(r->getLeft(),e);
            }
        else {
            insertData(r->getRight(),e);
            }
        }
    }

//deleteData
template <class T>
void BTree<T>::deleteData(Position& r) {
    int diteMoi(0);
    if(root==nullptr or r==nullptr) {
        throw Exception("Insuficiencia de datos, deleteData");
        }

    if(isLeaf(r)) {
        delete r;
        r=nullptr;
        }

    else {
        Position repPos;
        if(r->getLeft()!=nullptr) {
            repPos=getHighest(r->getLeft());
            diteMoi+= 2;
            }
        else {
            repPos=getLowest(r->getRight());
            }
        r->setData(repPos->getData());
        if(diteMoi==2) {
            deleteData(getHighest(r->getLeft()));
            }
        else {
            deleteData(getLowest(r->getRight()));
            }
        }
    }


//retrieve
template <class T>
T BTree<T>::retrieve(Position& r) const {
    return r->getData();
    }


//FindData
template <class T>
typename BTree<T>::Position& BTree<T>::findData(const T& e) {
    return findData(root,e);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::findData(Position& r, const T& e) {
    if(r==nullptr or r->getData()==e) {
        return r;
        }
    if(e < r->getData()) {
        return findData(r->getLeft(),e);
        }
    return findData(r->getRight(),e);
    }

template <class T>
void BTree<T>::findDataNumber(Position& a, T& e) {
    return findDataNumber(root,e,a);
    }

template <class T>
void BTree<T>::findDataNumber(Position& r, T& e, Position& a) {
    if(r==nullptr) {
        return;
        }
    if(r->getData().getNumero()==e.getNumero()){
        a=r;
    }
    findDataNumber(r->getLeft(), e, a);
    findDataNumber(r->getRight(), e, a);
    }

//getLowest
template <class T>
typename BTree<T>::Position& BTree<T>::getLowest() {
    return getLowest(root);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getLowest(Position& r) {
    if(r==nullptr or r->getLeft()==nullptr) {
        return r;
        }
    return getLowest(r->getLeft());
    }

//getHighest
template <class T>
typename BTree<T>::Position& BTree<T>::getHighest() {
    return getHighest(root);
    }

template <class T>
typename BTree<T>::Position& BTree<T>::getHighest(Position& r) {
    if(r==nullptr or r->getRight()==nullptr) {
        return r;
        }
    return getHighest(r->getRight());
    }

//isLeaf
template <class T>
bool BTree<T>::isLeaf(Position& r) const {
    return r!=nullptr and r->getLeft()==r->getRight();
    }

//getHeight
template <class T>
int BTree<T>::getHeight() {
    return getHeight(root);
    }


template <class T>
int BTree<T>::getHeight(Position& r) {
    if(r==nullptr) {
        return 0;
        }

    int lH(getHeight(r->getLeft()));
    int rH(getHeight(r->getRight()));

    return(lH > rH ? lH : rH) + 1;
    }

template <class T>
int BTree<T>::getRightHeight() {
    return getHeight(root->getRight());
    }


template <class T>
int BTree<T>::getLeftHeight() {
    return getHeight(root->getLeft());
    }

//parsePreOrder
template <class T>
void BTree<T>::parsePreOrder() {
    parsePreOrder(root);
    }

template <class T>
void BTree<T>::parsePreOrder(Position& r) {
    if(r==nullptr) {
        return;
        }
    std::cout<<r->getData()<<",";
    parsePreOrder(r->getLeft());
    parsePreOrder(r->getRight());
    }

//parseInOrder
template <class T>
void BTree<T>::parseInOrder() {
    parseInOrder(root);
    }

template <class T>
void BTree<T>::parseInOrder(Position& r) {
    if(r==nullptr) {
        return;
        }
    parseInOrder(r->getLeft());
    r->getData().toString();
    parseInOrder(r->getRight());
    }


//parsePostOrder
template <class T>
void BTree<T>::parsePostOrder() {
    parsePostOrder(root);
    }


template <class T>
void BTree<T>::parsePostOrder(Position& r) {
    if(r==nullptr) {
        return;
        }
    parsePostOrder(r->getLeft());
    parsePostOrder(r->getRight());
    std::cout<<r->getData()<<",";
    }

//deleteAll
template <class T>
void BTree<T>::deleteAll() {
    if(isEmpty()) {
        return;
        }
    while(!isEmpty()) {
        deleteData(root);
        }
    }

template <class T>
BTree<T>& BTree<T>::operator=(const BTree<T>& t) {
    if(!t.isEmpty()) {
        deleteAll();
        }
    copyAll(t);
    return *this;
    }






template <class T>
void BTree<T>::guardar() {
    std::ofstream file;
    file.open("Contactos.txt",std::ios::out);
    if(file.fail()){
        std::cout<<"No se pudo abrir el archivo";
        return;
    }
    guardar(root,file);
    file.close();
    }

template <class T>
void BTree<T>::guardar(Position& r, std::ofstream& file) {
    std::string line;
    if(r==nullptr) {
        return;
        }
    file<<r->getData().getNombre()<<"\n";
    file<<r->getData().getNumero()<<"\n";
    if(r->getLeft()==nullptr){
        file<<"0\n";
    }
    else{
        file<<"1\n";
    }
    if(r->getRight()==nullptr){
        file<<"0\n";
    }
    else{
        file<<"1\n";
    }
    guardar(r->getLeft(),file);
    guardar(r->getRight(),file);
    }

template <class T>
void BTree<T>::cargar() {
    deleteAll();
    std::ifstream file;
    file.open("Contactos.txt",std::ios::in);
    if(file.fail()){
        std::cout<<"No se pudo abrir el archivo";
        return;
    }
    cargar(root,file);
    file.close();
    }

template <class T>
void BTree<T>::cargar(Position& r, std::ifstream& file) {
    Contacto user;
    std::string line;
    if(isEmpty()){
        r=new Node();
        }
    if(r==nullptr) {
        return;
        }
    std::getline(file,line);
    user.setNombre(line);
    std::getline(file,line);
    user.setNumero(line);
    r->setData(user);
    std::getline(file,line);
    if(line=="1"){
        r->getLeft()=new Node();
        }
    else{
        r->getLeft()=nullptr;
        }
    std::getline(file,line);
    if(line=="1"){
        r->getRight()=new Node();
        }
    else{
        r->getRight()=nullptr;
        }
    cargar(r->getLeft(),file);
    cargar(r->getRight(),file);
    }

//-Clase de LISTA

template <class T>
class List {
    private:
        class Node {
            private:
                T* dataPtr;
                Node* prev;
                Node* next;
            public:
                class Exception: public std::exception {
                    private:
                        std::string msg;
                    public:
                        explicit Exception(const char* message):msg(message) {}
                        explicit Exception(const std::string& message):msg(message) {}
                        virtual ~Exception() throw () {}
                        virtual const char* what() const throw() {
                            return msg.c_str();
                            }
                    };

                Node();
                Node(const T&);

                ~Node();
                T* getDataPtr()const;
                T getData()const;
                Node* getNext() const;
                Node* getPrev() const;

                void setDataPtr(T*);
                void setData(const T&);
                void setPrev(Node*);
                void setNext(Node*);
            };
    public:
        typedef Node* Position;

    private:
        Node* header;
        void copyAll(const List<T>&);
        bool isValidPos(Node*)const;

        void guardar(Position&,std::ofstream&);
        void cargar(Position&,std::ifstream&);

    public:
        class Exception: public std::exception {

            private:
                std::string msg;
            public:
                explicit Exception(const char* message):msg(message) {}
                explicit Exception(const std::string& message):msg(message) {}
                virtual ~Exception() throw () {}
                virtual const char* what() const throw() {
                    return msg.c_str();
                    }
            };

        List();
        List(const List<T>&);
        ~List();

        bool isEmpty()const;
        void insertData(Node*, const T&);
        void deleteData(Node*);

        Node* getFirstPos()const;
        Node* getLastPos()const;
        Node* getPrevPos(Node*)const;
        Node* getNextPos(Node*)const;

        Node* findData(const T&)const;
        T retrive(Node*) const;
        void toString();
        void deleteAll();
        List<T>& operator = (const List<T>&);

        void guardar();
        void cargar();

    };

template <class T>
List<T>::Node::Node():dataPtr(nullptr),next(nullptr),prev(nullptr) {}

template <class T>
List<T>::Node::Node(const T& e):dataPtr(new T(e)),next(nullptr),prev(nullptr) {
    if(dataPtr==nullptr){
        throw Exception("Memoria insuficiente, creandoNodo");
        }
    }

template <class T>
List<T>::Node::~Node(){
    delete dataPtr;
    }

template <class T>
T* List<T>::Node::getDataPtr() const{
    return dataPtr;
    }

template <class T>
T List<T>::Node::getData() const {
    if(dataPtr==nullptr){
        throw Exception("Datos inexistentes, getData");
        }
    return *dataPtr;
    }

template <class T>
typename List<T>::Node* List<T>::Node::getPrev() const{
    return prev;
    }


template <class T>
typename List<T>::Node* List<T>::Node::getNext() const {
    return next;
    }

template <class T>
void List<T>::Node::setDataPtr(T* p){
    dataPtr=p;
    }

template <class T>
void List<T>::Node::setData(const T& e) {
    if(dataPtr==nullptr){
        if((dataPtr=new T(e))==nullptr){
            throw Exception("Memoria no disponible, setData");
            }
        }
    else{
        *dataPtr=e;
        }
    }

template <class T>
void List<T>::Node::setNext(Node* p) {
    next=p;
    }

template <class T>
void List<T>::Node::setPrev(Node* p){
    prev=p;
    }


//Lista
template <class T>
void List<T>::copyAll(const List<T>& l) {
    Node* aux(l.header->getNext());
    Node* newNode;
    while(aux != l.header){
        try{
            if((newNode=new Node(aux->getData()))==nullptr){
                throw Exception("Memoria no disponible, copyAll");
                }
            } catch (typename Node::Exception ex){
                throw Exception(ex.what());
                }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux=aux->getNext();
        }
    }

template <class T>
bool List<T>::isValidPos(Node* p) const {
    Node* aux(header->getNext());
    while(aux!=header) {
        if(aux==p) {
            return true;
            }
        aux=aux->getNext();
        }
    return false;
    }

template <class T>
List<T>::List(): header(new Node) {
    if(header==nullptr){
        throw Exception("Memoria no disponible, inicializando lista");
        }
    header->setPrev(header);
    header->setNext(header);
    }

template <class T>
List<T>::List(const List<T>& l): List() {
    copyAll(l);
    }

template <class T>
List<T>::~List() {
    deleteAll();
    delete header;
    }

template <class T>
bool List<T>::isEmpty() const {
    return header->getNext()==header;
    }

template <class T>
void List<T>::insertData(Node* p, const T& e) {
    if(p!=nullptr and !isValidPos(p)){
        throw Exception("Posicion invalida, insertData");
        }
    Node* aux;
    try{
        aux=new Node(e);
        } catch(typename Node::Exception ex){
            throw Exception(ex.what());
            }
    if(aux==nullptr){
        throw Exception("Memoria no disponible, insertData");
        }
    if(p==nullptr){
        p=header;
        }
    aux->setPrev(p);
    aux->setNext(p->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);
    }

template <class T>
void List<T>::deleteData(Node* p) {
    if(!isValidPos(p)){
        throw Exception("Posicion invalida, deleteData");
        }
    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    delete p;
    }

template <class T>
typename List<T>::Node* List<T>::getFirstPos() const {
    if(isEmpty()){
        return nullptr;
        }
    return header->getNext();
    }

template <class T>
typename List<T>::Node* List<T>::getLastPos() const {
    if(isEmpty()){
        return nullptr;
        }
    return header->getPrev();
    }

template <class T>
typename List<T>::Node* List<T>::getPrevPos(Node* p) const {
    if(!isValidPos(p) or p== header->getNext()){
        return nullptr;
        }
    return p->getPrev();
    }

template <class T>
typename List<T>::Node* List<T>::getNextPos(Node* p) const {
    if(!isValidPos(p) or p== header->getPrev()){
        return nullptr;
        }
    return p->getNext();
    }

template <class T>
typename List<T>::Node* List<T>::findData(const T& e) const {
    Node* aux(header->getNext());
    while(aux != header){
        if(aux->getData()==e){
            return aux;
            }
        aux=aux->getNext();
        }

    return nullptr;
    }

template <class T>
T List<T>::retrive(Node* p) const {
    if(!isValidPos(p)){
        throw Exception("Posicion invalida, retrieve");
        }

    return p->getData();
    }

template <class T>
void List<T>::toString(){
    Node* aux(header->getNext());
    while(aux!=header){
        aux->getData().toString();
        aux=aux->getNext();
        }
    }

template <class T>
void List<T>::deleteAll() {
    Node* aux;
    while(header->getNext() != header){
        aux=header->getNext();
        header->setNext(aux->getNext());
        delete aux;
        }
    header->setPrev(header);
    }

template <class T>
List<T>& List<T>::operator =(const List<T>& l) {
    deleteAll();
    copyAll(l);
    return *this;
    }

template <class T>
void List<T>::guardar() {
    std::ofstream file;
    file.open("Llamadas.txt",std::ios::out);
    if(file.fail()){
        std::cout<<"No se pudo abrir el archivo";
        return;
    }
    guardar(header,file);
    file.close();
    }

template <class T>
void List<T>::guardar(Position& r, std::ofstream& file) {
    Position aux;
    std::string line;
    if(r==nullptr) {
        return;
        }
    aux=r->getNext();
    while(aux!=header){
        file<<aux->getData().getNumero()<<"\n";
        file<<aux->getData().getTipo()<<"\n";
        file<<aux->getData().getTiempo();
        if(aux->getNext()==header){
            file<<"0\n";
        }
        else{
            file<<"1\n";
            }
        aux=aux->getNext();
        }
    }

template <class T>
void List<T>::cargar() {
    deleteAll();
    std::ifstream file;
    file.open("Llamadas.txt",std::ios::in);
    if(file.fail()){
        std::cout<<"No se pudo abrir el archivo";
        return;
    }
    cargar(header,file);
    file.close();
    }

template <class T>
void List<T>::cargar(Position& r, std::ifstream& file) {
    Llamada user;
    std::string line;
    while(line!="0"){
        std::getline(file,line);
        user.setNumero(line);
        std::getline(file,line);
        user.setTipo(line);
        std::getline(file,line);
        user.setTiempo(line);
        std::getline(file,line);
        insertData(getFirstPos(),user);
        }

    }

int main() {
    BTree<Contacto> arbolContactos;
    BTree<Contacto>::Position pos;
    List<Llamada>::Position pos1;
    List<Llamada> callList;
    char opc;
    do{
        char op,sel;
        //Dario 666 llamada perdida
        cout<<"\nBienvenido a nuestra aplicacion de Llamadas Telefonicas"<<endl;
        cout<<"Que desea Verificar en esta ocasion?"<<endl;
        cout<<"°°|| 1- Lista de Contactos. ||°°"<<endl;
        cout<<"°°|| 2- Lista de Llamadas.  ||°°"<<endl;
        cout<<"°°|| 3- Salir.              ||°°"<<endl;
        fflush(stdin);
        cout<<"Selecciona la opcion que deseas: ";
        cin>>op;
        if(op=='1') {
            do {
                cout<<"|°Agenda de Contactos°|"<<endl;
                cout<<"Selecciona la opcion que deseas"<<endl;
                cout<<"1- Añadir contacto             "<<endl;
                cout<<"2- Borrar Contacto            "<<endl;
                cout<<"3- Editar contacto           "<<endl;
                cout<<"4- Localizar Contacto              "<<endl;
                cout<<"5- Mostrar la lista de contactos  "<<endl;
                cout<<"6- Exportar Contactos                      "<<endl;
                cout<<"7- Importar Contactos                       "<<endl;
                cout<<"8- Volver al Menu Principal                      "<<endl;
                fflush(stdin);
                cout<<"Selecciona la opcion que deseas: ";
                cin>>sel;
                switch(sel) {
                    case '1': {
                        int e,i=0;
                        cout<<"Numero de contactos a agregar: ";
                        cin>>e;
                        do {
                            Contacto cont;
                            string nombre,numero;
                            cout<<"Alias Del Contacto: ";
                            fflush(stdin);
                            getline(cin,nombre);
                            cont.setNombre(nombre);
                            cout<<"Numero Telefonico del contacto: ";
                            fflush(stdin);
                            getline(cin,numero);
                            cont.setNumero(numero);
                            arbolContactos.insertData(cont);
                            cout<<"Contacto añadido a su Agenda"<<endl;
                            i++;
                            }
                        while(i!=e);
                        }
                    break;


                    case '2': {
                        Contacto cont;
                        string nombre;
                        cout<<"Alias del contacto: ";
                        fflush(stdin);
                        getline(cin,nombre);
                        cont.setNombre(nombre);
                        arbolContactos.deleteData(arbolContactos.findData(cont));
                        cout<<"Eliminacion Exitosa"<<endl;
                        }
                    break;


                    case '3': {
                        Contacto cont;
                        Contacto *aux;
                        string nombre,num;
                        char sel2;
                        cout<<"Alias del contacto a editar: ";
                        fflush(stdin);
                        getline(cin,nombre);
                        cont.setNombre(nombre);
                        cout<<"Selecciona lo que deseas hacer"<<endl;
                        cout<<"1-Cambiar Alias"<<endl;
                        cout<<"2-Cambiar Numero Telefonico"<<endl;
                        fflush(stdin);
                        cout<<"Opcion Seleccionada: ";
                        cin>>sel2;
                        if(sel2=='1') {
                            cout<<"Nuevo Alias del contacto: ";
                            fflush(stdin);
                            getline(cin,nombre);
                            pos=arbolContactos.findData(cont);
                            aux=pos->getDataPtr();
                            aux->setNombre(nombre);
                            cout<<"Contacto Exitosamente Modificado"<<endl;
                            }
                        else if(sel2=='2') {
                            cout<<"Nuevo Numero Celular: ";
                            fflush(stdin);
                            getline(cin,num);
                            pos=arbolContactos.findData(cont);
                            aux=pos->getDataPtr();
                            aux->setNumero(num);
                            cout<<"Contacto Exitosamente Modificado"<<endl;
                            }
                        else {
                            cout<<"X -Opcion Invalida- X"<<endl;
                            }
                        }
                    break;


                    case '4': {
                        Contacto cont;
                        Contacto *aux;
                        string nombre;
                        cout<<"Alias del Contacto: ";
                        fflush(stdin);
                        getline(cin,nombre);
                        cont.setNombre(nombre);
                        pos=arbolContactos.findData(cont);
                        aux=pos->getDataPtr();
                        aux->toString();
                        }
                    break;


                    case '5':
                        arbolContactos.parseInOrder();
                        break;

                    case '6':
                        arbolContactos.guardar();
                        cout<<"Contactos Exportados Exitosamente"<<endl;
                        break;

                    case '7':
                        arbolContactos.cargar();
                        cout<<"Contactos Importados Exitosamente"<<endl;
                        break;
                    }

                fflush(stdin);
                }
            while(sel!='8');
            }

        else if(op=='2') {
            do{
                char sel1;
                int val;
                cout<<"|°Agenda de Llamadas°|"<<endl;
                cout<<"Que desea Verificar en esta ocasion?"<<endl;
                cout<<"1-Añadir Llamadas             "<<endl;
                cout<<"2-Borrar Llamadas            "<<endl;
                cout<<"3-Filtrar Llamadas por tipo   "<<endl;
                cout<<"4- Mostrar Lista de llamadas   "<<endl;
                cout<<"5- Exportar Llamadas      "<<endl;
                cout<<"6-Importar Llamadas          "<<endl;
                cout<<"7- Volver al Menu Principal       "<<endl;
                fflush(stdin);
                cout<<"Selecciona la opcion que deseas: ";
                cin>>sel;
                switch(sel){
                    case '1':
                        {
                            int e,i=0;
                            cout<<"Numero de llamadas a Añadir: ";
                            cin>>e;
                            do{
                                Llamada call;
                                string text;

                                cout<<"Numero Telefonico: ";
                                fflush(stdin);
                                getline(cin,text);
                                call.setNumero(text);

                                cout<<"Tipo de Llamada(Entrante,Perdida o Saliente): ";
                                fflush(stdin);
                                getline(cin,text);
                                call.setTipo(text);

                                time_t rawtime;
                                struct tm * timeinfo;
                                time(&rawtime);
                                timeinfo=localtime(&rawtime);
                                text=asctime(timeinfo);
                                call.setTiempo(text);

                                callList.insertData(callList.getFirstPos(),call);
                                cout<<"Llamada Exitosa"<<endl;
                                i++;
                            }while(i!=e);
                        }
                        break;


                    case '2':
                        {
                            Llamada call;
                            string text;
                            cout<<"Numero Telefonico del que desea Eliminar una llamada: "<<endl;
                            fflush(stdin);
                            getline(cin,text);
                            call.setNumero(text);
                            callList.deleteData(callList.findData(call));
                            cout<<"Llamada Exitosamente Eliminada"<<endl;
                        }
                        break;


                    case '3':
                            {
                            cout<<"Filtro de llamadas: "<<endl;
                            cout<<"1.-Llamadas telefonicas perdidas"<<endl;
                            cout<<"2.-Llamadas telefonicas salientes"<<endl;
                            cout<<"3.-Llamadas telefonicas entrantes"<<endl;
                            cout<<"4.-Llamadas telefonicas por numero Telefonico"<<endl;
                            cout<<"5.-Llamadas telefonicas por Alias"<<endl;
                            cout<<"6.-Llamadas telefonicas por numero Telefonico con Alias"<<endl;
                            cout<<"Seleccion: ";
                            cin>>sel1;
                            switch(sel1){
                                case '1':
                                    {
                                        val=0;
                                        string text="Perdida";
                                        Llamada *call;
                                        pos1=callList.getFirstPos();
                                        while(pos1!=callList.getLastPos()->getNext()){
                                            call=pos1->getDataPtr();
                                            if(call->getTipo()==text){
                                                call->toString();
                                                val=1;
                                            }
                                            pos1=pos1->getNext();
                                        }
                                        if(val==0){
                                            cout<<"No existen llamadas perdidas"<<endl;
                                        }
                                    }
                                    break;

                                case '2':
                                    {
                                        val=0;
                                        string text="Saliente";
                                        Llamada *call;
                                        pos1=callList.getFirstPos();
                                        while(pos1!=callList.getLastPos()->getNext()){
                                            call=pos1->getDataPtr();
                                            if(call->getTipo()==text){
                                                call->toString();
                                                val=1;
                                            }
                                            pos1=pos1->getNext();
                                        }
                                        if(val==0){
                                            cout<<"No existen llamadas salientes"<<endl;
                                        }
                                    }
                                    break;

                                case '3':
                                    {
                                        val=0;
                                        string text="Entrante";
                                        Llamada *call;
                                        pos1=callList.getFirstPos();
                                        while(pos1!=callList.getLastPos()->getNext()){
                                            call=pos1->getDataPtr();
                                            if(call->getTipo()==text){
                                                call->toString();
                                                val=1;
                                            }
                                            pos1=pos1->getNext();
                                        }
                                        if(val==0){
                                            cout<<"No existen llamadas entrantes"<<endl;
                                        }
                                    }
                                    break;

                                case '4':
                                    {
                                        val=0;
                                        string text;
                                        cout<<"Numero: ";
                                        fflush(stdin);
                                        getline(cin,text);
                                        Llamada *call;
                                        pos1=callList.getFirstPos();
                                        while(pos1!=callList.getLastPos()->getNext()){
                                            call=pos1->getDataPtr();
                                            if(call->getNumero()==text){
                                                call->toString();
                                                val=1;
                                            }
                                            pos1=pos1->getNext();
                                        }
                                        if(val==0){
                                            cout<<"No existen llamadas de este numero"<<endl;
                                        }
                                    }
                                    break;


                                case '5':
                                    {
                                        BTree<Contacto>::Position axt;
                                        val=0;
                                        Contacto cont;
                                        Contacto *aux;
                                        Llamada *call;
                                        string text;
                                        cout<<"Alias del contacto: ";
                                        fflush(stdin);
                                        getline(cin,text);
                                        cont.setNombre(text);
                                        axt=arbolContactos.findData(cont);
                                        if(axt==nullptr){
                                            cout<<"No existe este Alias"<<endl;
                                        }
                                        else{
                                            aux=axt->getDataPtr();
                                            text=aux->getNumero();
                                            pos1=callList.getFirstPos();
                                            while(pos1!=callList.getLastPos()->getNext()){
                                                call=pos1->getDataPtr();
                                                if(call->getNumero()==text){
                                                    aux=axt->getDataPtr();
                                                    cout<<"Alias del contacto: "<<aux->getNombre()<<endl;
                                                    call->toString();
                                                    val=1;
                                                }
                                                pos1=pos1->getNext();
                                            }
                                            if(val==0){
                                                cout<<"No existen llamadas de este Alias"<<endl;
                                            }
                                        }
                                    }
                                    break;

                                case '6':
                                    {
                                        BTree<Contacto>::Position axt;
                                        val=0;
                                        Contacto cont;
                                        Contacto *aux;
                                        Llamada *call;
                                        string text;
                                        cout<<"Numero del Alias: ";
                                        fflush(stdin);
                                        getline(cin,text);
                                        cont.setNumero(text);
                                        arbolContactos.findDataNumber(axt,cont);
                                        if(axt==nullptr){
                                            cout<<"No existe el Alias Solicitado"<<endl;
                                        }
                                        else{
                                            aux=axt->getDataPtr();
                                            text=aux->getNumero();
                                            pos1=callList.getFirstPos();
                                            while(pos1!=callList.getLastPos()->getNext()){
                                                call=pos1->getDataPtr();
                                                if(call->getNumero()==text){
                                                    aux=axt->getDataPtr();
                                                    cout<<"Alias del contacto: "<<aux->getNombre()<<endl;
                                                    call->toString();
                                                    val=1;
                                                }
                                                pos1=pos1->getNext();
                                            }
                                            if(val==0){
                                                cout<<"No existen llamadas de este alias"<<endl;
                                            }
                                        }
                                    }
                                    break;

                                default:
                                    cout<<"Opcion Invalida"<<endl;
                                }
                            }
                        break;


                    case '4':
                        callList.toString();
                        break;

                    case '5':
                        callList.guardar();
                        cout<<"Exportacion Exitosa De Las Llamadas!"<<endl;
                        break;

                    case '6':
                        callList.cargar();
                        cout<<"Importacion Exitosa De Las Llamadas!"<<endl;
                        break;

                    }

                fflush(stdin);
                }while(sel!='7');
            }
            else if (op=='3'){
                opc='3';
                printf("\nGracias por utilizar nuestra aplicacion!\n");
            }
            else{
                cout<<"Opcion Invalida"<<endl;
            }
        fflush(stdin);
        }while(opc!='3');
    }

