#include <iostream>
#include "keyboard.hpp"

using namespace std;

/*****
* int main
******
* Función principal del programa que invoca el procesamiento del archivo de entrada
* ("teclado-entrada.txt"), generando un archivo de salida ("teclado-salida.txt")
******
* Returns:
*   int, retorna el estado de salida
*   0: si procesa el archivo de entrada y genera el de salida
*   1: si no puede abrir el archivo de entrada o generar el de salida
*****/
int main() {
    Keyboard kb;
    string inputFile = "teclado-entrada.txt";
    string outputFile = "teclado-salida.txt";

    cout << endl;
    cout << "Tarea 2 - Problema 1: El Teclado Descompuesto" << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;

    if (!kb.processFile(inputFile, outputFile)) {
        cout << endl;
        return 1;
    }

    cout << "'" << inputFile << "' fue procesado exitosamente." << endl;
    cout << "Revise el archivo de salida: '" << outputFile << "'." << endl;
    cout << endl;

	return 0;
};
