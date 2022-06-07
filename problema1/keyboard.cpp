#include <iostream>
#include <fstream>
#include "keyboard.hpp"
#include "keyboard-buffer.hpp"

using namespace std;

/*****
* bool processFile
******
* Transforma cada linea del archivo de texto de entrada, de acuerdo a las
* reglas del teclado descompuesto, y las guarda en el archivo de texto de salida.
******
* Input:
*   string inputfile : ruta del archivo de texto de entrada.
*   string outputfile : ruta del archivo de texto de salida.
******
* Returns:
*   bool, un valor que indica si se proceso o no el archivo de entrada y se genero el de salida
*       true: si se proceso el archivo de entrada y se genero el de salida.
*       false: si no puede abrir el archivo de entrada o generar el de salida.
*****/
bool Keyboard::processFile(string inputFile, string outputFile) {
    ifstream input_keyboard;
    ofstream output_keyboard;
    string line;

    // Abre archivo de entrada
    input_keyboard.open(inputFile);
    if (!input_keyboard.is_open()) {
        cerr << "Error no fue posible abrir el archivo de entrada: '" << inputFile << "'" << endl;
        return false;
    }

    // Abre archivo de salida
    output_keyboard.open(outputFile);
    if (!output_keyboard.is_open()) {
        cerr << "Error no fue posible abrir el archivo de salida: '" << outputFile << "'" << endl;
        input_keyboard.close();
        return false;
    }

    // Procesa cada linea del archivo de entrada
    // cuyo resultado almacena en el archivo de salida
    while (getline(input_keyboard, line)) {
        output_keyboard << processLine(line) << endl;
    }
    
    input_keyboard.close();
    output_keyboard.close();

    return true;
}

/*****
* string processLine
******
* Procesa cada caracter de la linea del texto de acuerdo a las reglas de teclado descompuesto.
* Dependiendo del caracter, se determina el movimiento del cursor o agregar dicho caracter.
******
* Input:
*   string line : linea de texto que sera procesada.
******
* Returns:
*   string, retorna el texto resultante de aplicar las reglas del teclado descompuesto a line.
*****/
string Keyboard::processLine(string line) {
    string result;
    KeyboardBuffer *buffer = new KeyboardBuffer();

    unsigned int length = line.length();
    for (unsigned int i = 0; i < length; i++) {
        char c = line[i];

        switch (c) {
            case '>':
                buffer->right();
                break;
            case '<':
                buffer->left();
                break;
            case '[':
                buffer->home();
                break;
            case ']':
                buffer->end();
                break;
            default:
                buffer->append(c);
        }
    }

    result = buffer->str();

    delete buffer;

    return result;
}
