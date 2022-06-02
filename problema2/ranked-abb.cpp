#include <ostream>

typedef int tElem;

struct nodoABB{
    tElem info;
    nodoABB* izq;
    nodoABB* der;
};

nodoABB* nodeCreator(tElem item){
    nodoABB* nuevoNodo = new(nodoABB);
    nuevoNodo->info = item;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

class ABB{
    int numElem;
    
    public:
    nodoABB* raiz;
    ABB(){numElem = 0; raiz = NULL;};
    ~ABB(){};
    //nodoABB* getRaiz(){return raiz;};
    void insert(tElem x);
    void inOrder(nodoABB* raiz);
    bool find(tElem x);
    int rank(tElem x);
};

void ABB::inOrder(nodoABB* raiz){
    if (raiz== NULL){return;}
    inOrder(raiz->izq);
    std::cout<<raiz->info<<std::endl;
    inOrder(raiz->der);
}

void inOrderRanker(nodoABB* raiz, tElem item, int &elemMenores){
    if (raiz == NULL){return;}
    inOrderRanker(raiz->izq, item, elemMenores);
    if (raiz->info <= item){elemMenores++;}
    inOrderRanker(raiz->der, item, elemMenores);
}

int ABB::rank(tElem x){
    int elemMenores = 0;
    inOrderRanker(raiz,x,elemMenores);
    return elemMenores;
}

void inserter(nodoABB* &nodo, tElem x){
    if (nodo == NULL){
        nodo = nodeCreator(x); 
        std::cout<<"insertado"<<std::endl;
        return;
    }
    if(nodo->info == x){
        std::cout<<"no se inserta"<<std::endl;
        return;
    }
    if(x > nodo->info){
        std::cout<<"mayor, movimiento a nodo derecho"<<std::endl;
        inserter(nodo->der, x);
    }else if(x < nodo->info){
        std::cout<<"menor, movimiento a nodo izquierdo"<<std::endl;
        inserter(nodo->izq, x);
    }
}

void ABB::insert(tElem x){
    inserter(raiz, x);
}

void finder(nodoABB* nodo, tElem x, bool &flag){
    if (nodo == NULL){
        return;
    }
    else if (nodo->info == x){
        flag = true;
        return;
    }
    else if (x > nodo->info){
        finder(nodo->der,x,flag);
    }else if(x < nodo->info){
        finder(nodo->izq,x,flag);
    }
}

bool ABB::find(tElem x){
    bool flag = false;
    finder(raiz, x, flag);
    return flag;
}

