/* archivo_texto_a_arreglos_de_valores.c - v1.0
Autor: MTS
Este programa leer un archivo de texto y coloca parte de su
contenido en un arreglo de cadenas de caracteres. Cada entrada
del arreglo es una cadena, no mayor de MAXIMO_TAMANO y cada
cadena del archivo se separa por " ", por "\n" o por EOF. Se
asume además que el archivo a leer tiene un tamaño de lineas
que no supera el valor numérico de MAXIMO_LINEAS_ARCHIVO */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXIMO_TAMANO 135
#define MAXIMO_LINEAS_ARCHIVO 350

/*** Principal ***/
int main (int argc, char **argv) {
    
    //Declarar Variables
    FILE *fp;
    char arreglo_cadena_caracteres[MAXIMO_LINEAS_ARCHIVO][MAXIMO_TAMANO+1];
    char vector[MAXIMO_TAMANO+1];
    /* Arreglo de uso temporal */
    int i, j;
    
    /* Verificación de los argumentos */
    if (argc != 2) {
        fprintf(stderr, "\n%s: ERROR de sintaxis en la llamada", argv[0]);
        fprintf(stderr, "\nUSO: %s <archivo_a_leer>\n", argv[0]);
        exit (1);
    }
    
    /* Apertura del archivo a mostrar */
    if ((fp=fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "\n%s: no puedo abrir %s\n", argv[0], argv[1]);
        exit (2);
    }
    
    /* Esta parte lee el archivo y llena el arreglo de cadena de caracteres
     Cuenta la cantidad de entradas que tendrá el arreglo */
    i=0; 
    j=0;
    while (!feof (fp)) {
        //El %135s => va a leer hasta un maximo de 135 cacaracteres
        fscanf (fp, "%135s", &vector[0]);
        ++i;
        if ( j < MAXIMO_LINEAS_ARCHIVO) 
            strcpy (arreglo_cadena_caracteres[j], vector);
        else 
            break;
        
        ++j;
    }
    
    /* Aqui se imprime el arreglo. Esta línea muestra las líneas vacías */
    for (j=0; j<i; ++j)
        fprintf (stdout, "Entrada %d: %s \n", j, arreglo_cadena_caracteres[j]);
    
    /* Aqui se cierra el archivo y se termina el programa normalmente */
    fclose (fp);
    exit (0);
}