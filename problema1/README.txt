Tarea 2 - Problema 1: El Teclado Descompuesto
=============================================

--------------------------------------------------------------------
REQUERIMENTOS DEL AMBIENTE PARA COMPILAR
--------------------------------------------------------------------
- Sistema operativo: Linux
- Compilador g++
- Contar con herramienta Make
- Ver Dockerfile

--------------------------------------------------------------------
COMPILACIÓN
--------------------------------------------------------------------
- Comando de compilacion:
  $ make

- Genera el archivo: broken-keyboard

--------------------------------------------------------------------
EJECUCIÓN
--------------------------------------------------------------------
- Se requiere de un archivo de texto con las entradas que seran procesadas.
  Debe estar en el mismo directorio del programa ejecutable:
    teclado-entrada.txt

- Comando para ejecutar la tarea:
  $ ./broken-keyboard

- El archivo con los resultado se encontrara en el mismo directorio:
    teclado-salida.txt

--------------------------------------------------------------------
CONSIDERACIONES AL MOMENTO DE COMPILAR
--------------------------------------------------------------------
Esta aplicacion se desarrollo utilizando un contenedor Docker:
  alpine:3.15.4
Con:
  g++ 10.3.1 20211027
  GNU Make 4.3.
