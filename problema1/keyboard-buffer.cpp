#include <iostream>
#include "keyboard-buffer.hpp"

using namespace std;

/*****
* constructor de KeyboardBufferNode
******
* Inicializa un nodo con el caracter que se pasa por parametro como dato del nodo.
* Cada nodo representa un elemento de una lista doblemente enlazada
*
* Propiedades:
*   char value: dato que se almacenaen el nodo.
*   KeyboardBufferNode *previous: puntero al nodo anterior en la lista.
*   KeyboardBufferNode *next: puntero al siguiente nodo en la lista.
******
* Input:
*   char value : dato que se almacenara el nodo.
*****/
KeyboardBufferNode::KeyboardBufferNode(char value) {
    this->value = value;
    previous = NULL;
    next = NULL;
}

/*****
* Constructor de KeyboardBuffer
******
* Inicializa una instancia de KeyboardBuffer.
* KeyboardBuffer implementa una lista doblemente enlazada para almacenar los caracteres
* ingresados por un Keyboard.
*
* Propiedades:
*   unsigned int len: largo de la lista.
*   KeyboardBufferNode *head: puntero al primer nodo de la lista.
*   KeyboardBufferNode *tail: puntero al último nodo de la lista.
*   KeyboardBufferNode *cursor: puntero al nodo previo donde se agregará el siguiente caracter.
*                               Si vale NULL significa que el siguiente caracter se agregará
*                               al inicio de la lista.
*****/
KeyboardBuffer::KeyboardBuffer() {
    init();
}

/*****
* destructor de KeyboardBuffer
******
* Destruye el objeto del tipo KeyboardBuffer, liberando la memoria utilizada.
*****/
KeyboardBuffer::~KeyboardBuffer() {
    clean();
}

/*****
* void init
******
* Inicializa las propiedades de la instancia de KeyboardBuffer.
*****/
void KeyboardBuffer::init() {
    len = 0;
    head = NULL;
    tail = NULL;
    cursor = NULL;
}

/*****
* void clean
******
* Libera la memoria utilizada e incializa las propiedades de
* la instancia.
*****/
void KeyboardBuffer::clean() {
    KeyboardBufferNode *node = head;
    while (node != NULL) {
        KeyboardBufferNode *next = node->next;
        delete node;
        node = next;
    }

    init();
}

/*****
* void append
******
* Agrega un nuevo nodo al buffer.
******
* Input:
*   char c : dato que se agrega al buffer en la posicion dada por el cursor.
*****/
void KeyboardBuffer::append(char c) {
    KeyboardBufferNode *node = new KeyboardBufferNode(c);

    if (head == NULL) {
        // inicializa la lista con primer nodo
        head = node;
        tail = node;
        cursor = node;
    }
    else if (cursor == NULL) {
        // agrega nodo al inicio de la lista
        node->next = head;
        head->previous = node;

        head = node;
        cursor = node;
    }
    else if (cursor != tail) {
        // agrega nodo despues del cursor, antes de tail
        node->previous = cursor;
        node->next = cursor->next;

        node->next->previous = node;
        cursor->next = node;

        cursor = node;
    }
    else {
        // agrega nodo al final de la lista (despues del cursor que es igual a tail)
        cursor->next = node;
        node->previous = cursor;

        cursor = node;
        tail = node;
    }


    len++;
}

/*****
* void home
******
* Mueve el cursor antes del inicio de la lista, haciendo que quede "antes" del head. 
*****/
void KeyboardBuffer::home() {
    cursor = NULL;
}

/*****
* void end
******
* Mueve el cursor al final de la lista.
*****/
void KeyboardBuffer::end() {
    cursor = tail;
}

/*****
* void left
******
* Mueve el cursor al nodo anterior de donde esta actualmente.
*****/
void KeyboardBuffer::left() {
    if (cursor != NULL) {
        cursor = cursor->previous;
    }
}

/*****
* void right
******
* Mueve el cursor al siguiente nodo de donde esta actualmente.
*****/
void KeyboardBuffer::right() {
    if (cursor != NULL && cursor != tail) {
        // [head, tail[
        cursor = cursor->next;
    } else if (cursor == NULL) {
        // before head
        cursor = head;
    }
}

/*****
* string str
******
* Retorna un nuevo string con el texto almacenado en el buffer.
* El buffer queda limpio luego de llamar a esta funcion.
******
* Returns:
*   string, retorna el texto almacenado en el buffer.
*****/
string KeyboardBuffer::str() {
    if (len == 0) {
        return "";
    }

    string result = "";

    KeyboardBufferNode *node = head;
    while (node != NULL) {
        result.append(1, node->value);
        node = node->next;
    }

    clean();

    return result;
}
