#include <ostream>

typedef int tElem;

struct nodoABB{
    tElem info;
    nodoABB* izq;
    nodoABB* der;
};

/*****
*   nodoABB* nodeCreator
******
*   crea un nodo cuando la función es invocada, asignando memoria e inicializando los valores del nodo creado, estableciendo
*   la información del nodo con el elemento que se pasó como parámetro en la invocación de la función, y los hijos se inician como nulos
******
*   Input:
*       tElem x : elemento que se establecerá como información en el nodo
******
*   Returns:
*       nodoABB* : nodo nuevo creado que se insertará en un árbol 
*****/

nodoABB* nodeCreator(tElem item){
    nodoABB* nuevoNodo = new(nodoABB);
    nuevoNodo->info = item;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

class RankedABB{
    int numElem;
    
    public:
    nodoABB* raiz;
    RankedABB(){numElem = 0; raiz = NULL;};
    ~RankedABB(){};
    //nodoABB* getRaiz(){return raiz;};
    void insert(tElem x);
    void inOrder(nodoABB* raiz);
    bool find(tElem x);
    int rank(tElem x);
};

/*****
*   void RankedABB::inOrder
******
*   función que recorre el árbol inOrden e imprime en pantalla los valores correspondientes a la información de los nodos que se lean
******
*   Input:
*       nodoABB* raiz : raiz del árbol a recorrer
******
*   Returns:
*       la función no retorna, solo recorre el árbol ya existente
*****/

void RankedABB::inOrder(nodoABB* raiz){
    if (raiz== NULL){return;}
    inOrder(raiz->izq);
    std::cout<<raiz->info<<std::endl;
    inOrder(raiz->der);
}

/*****
*   void inOrderRanker(nodoABB* raiz, tElem item, int &elemMenores)
******
*   función auxiliar a Rank, contabiliza el numero de elementos menores o iguales al solicitado a través de un recorrido inorden y comparando
*   el elemento solicitado con el valor de la información en el nodo
******
*   Input:
*       tElem item : elemento que se desea comparar con el árbol
*       nodoABB* raiz : raiz del árbol al que se accederá para realizar las comparaciones
*       int &elemMenores : paso por referencia de la variable creada para contabilizar los elementos respectivos, se modifica según necesidad en la función
******
*   Returns:
*       la función no retorna, solo modifica la variable ya existente según condiciones
*****/

void inOrderRanker(nodoABB* raiz, tElem item, int &elemMenores){
    if (raiz == NULL){return;}
    inOrderRanker(raiz->izq, item, elemMenores);
    if (raiz->info <= item){elemMenores++;}
    inOrderRanker(raiz->der, item, elemMenores);
}

/*****
*   int RankedABB::rank
******
*   función que recibe un elemento y contabiliza todos los elementos menores o iguales al solicitado que se encuentren en el árbol
*   sin ser necesario que el elemento solicitado se encuentre en el árbol, para esto se hace uso de una función auxiliar
******
*   Input:
*       tElem x : elemento que se desea comparar con el árbol para obtener el número de elementos menores o iguales 
******
*   Returns:
*       int : retorna el numero de elementos presentes en el árbol que son menores o iguales al solicitado
*****/

int RankedABB::rank(tElem x){
    int elemMenores = 0;
    inOrderRanker(raiz,x,elemMenores);
    return elemMenores;
}

/*****
*   void inserter
******
*   función auxiliar que modifica el árbol/subárbol recibido e inserta el elemento X según corresponda, si el elemento ya fue insertado en el árbol
*   el elemento se ignora, en otro caso, se inserta según corresponda en la estructura del árbol    
******
*   Input:
*       nodoABB* &nodo : puntero a la dirección de memoria del árbol creado, permite modificar el nodo a través del paso por referencia
*       tElem x : elemento que se desea insertar en el árbol
******
*   Returns:
*       la función no retorna, solo modifica el árbol ya existente
*****/

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

/*****
*   void RankedABB::insert
******
*   función que recibe un elemento y lo inserta en el árbol a través de una función auxiliar
******
*   Input:
*       tElem x : elemento que se desea ingresar al árbol
******
*   Returns:
*       la función no retorna, solo modifica el árbol ya existente a través de la función auxiliar
*****/

void RankedABB::insert(tElem x){
    inserter(raiz, x);
}

/*****
*   void finder
******
*   función auxiliar a la búsqueda definida en el TDA rankedABB, permite realizar la búsqueda de un elemento de forma recursiva y actualizar
*   el valor del booleano que declara si el elemento se encuentra o no en el árbol
******
*   Input:
*       nodoABB* nodo : nodo del árbol que se analizará en la función, permite pasar la raíz del árbol o subárbol correspondiente a la función de búsqueda
*       tElem x : elemento que se pretende buscar en el árbol, el cual puede o no pertenecer al árbol
*       bool &flag : paso por referencia del valor booleano declarado en la función de búsqueda en el TDA, el cual será modificado a partir de esta función si el valor es encontrado en el árbol
******
*   Returns:
*       void, la función no retorna un valor, pero modifica el valor de flag en el caso de ser necesario
*****/

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

/*****
*   bool RankedABB::find(tElem x)
******
*   función de búsqueda, entrega información acerca de la existencia de cierto elemento en el árbol, haciendo uso de una función auxiliar
******
*   Input:
*       tElem x : elemento que se desea buscar en el árbol
******
*   Returns:
*       bool : retorna un valor respecto a la existencia del elemento en el árbol, si el valor está en el árbol, retorna verdadero, en otro caso, falso
*****/

bool RankedABB::find(tElem x){
    bool flag = false;
    finder(raiz, x, flag);
    return flag;
}

