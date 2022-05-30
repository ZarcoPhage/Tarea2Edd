#include <ostream>

typedef int tElem;

struct nodoABB{
    elem info;
    nodoABB* izq;
    nodoABB* der;
}

class arbolBin{
    nodoABB* raiz;
    int numElem;

    arbolBin(){raiz=NULL;numElem = O};
    ~arbolBin(){};
    void clear();
    void insert(tElem item);
    void remove(tElem item);
    bool find(tElem item);
    int rank(tElem item); //retorna cantidad de elementos menores o iguales a un item, aunque este item esté o no almacenado en el ABB
    int size();
};

int rank(tElem item){
    int counter = 0;
    return ranker(&counter, raiz, item);
}

void ranker(int &contador, nodoABB* nodo, tElem item){
    if (nodo == NULL){
        return;
    }
    if ((nodo->info)<=item){
        contador++;
        ranker(contador, nodo->izq, item);
    }
}

bool arbolBin::find(tElem item){
    return finder(raiz, item)    
}

bool finder(nodoABB* nodo, tElem item){
    if (nodo == NULL){
        return false;
    };
    if ((nodo->info)==item){
        return true;
    }
    if (item > (nodo->info)){
        return finder((nodo-> der),item);
    }else{
        return finder((nodo-> izq), item);
    }
}

void arbolBin::insert(tElem item){
    nodoABB nuevoNodo;
    nuevoNodo.info = item;
    nuevoNodo.izq = nuevoNodo.der = NULL;
    temp = findInsertionPlace(item,raiz,&nuevoNodo)
    numElem++;
}

void findInsertionPlace(tElem item, nodoABB* nodo, nodoABB &nuevoNodo){
    if (nodo == NULL){
        nuevoNodo = nodo;
        return;
    if (item > (nodo->info)){
        findInsertionPlace(item, nodo->der, nuevoNodo);
    }
    else if (item < (nodo->info)){
        findInsertionPlace(item,nodo->izq,nuevoNodo);
    }
}

void arbolBin::clear(){
    leafDeleter(raiz);
    raiz = NULL;
    numElem = O;
}

void leafDeleter(nodoABB* nodo){
    if (nodo == NULL){
        return;
    };
    leafDeleter(nodo->izq);
    leafDeleter(nodo->der);
    delete nodo;
}

