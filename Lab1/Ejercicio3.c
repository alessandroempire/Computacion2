/* copia_archivo_binario.c v1.0
Autor: MTS */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*** Principal ***/
int main (int argc, char **argv){
    FILE *fp, *fp2;
    void *buffer;
    
    /* Verificación de los argumentos */
    if (argc != 3) {
        fprintf(stderr, "\n%s: ERROR de sintaxis en la llamada", argv[0]);
        fprintf(stderr, "\nUSO: %s <archivo_a_copiar> <archivo_destino>\n", argv[0]);
        exit (1);
    }
    
    /* Apertura del archivo a mostrar */
    if ((fp=fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "\n%s: no puedo abrir %s\n", argv[0], argv[1]);
        exit (2);
    }
    
    /* Se crea el archivo destino de la copia */
    if ((fp2=fopen(argv[2], "ab")) == NULL) {
        fprintf(stderr, "\n%s: no puedo abrir %s\n", argv[0], argv[2]);
        exit (3);
    }
    
    rewind(fp); //Rebobinando el archivo a copiar
    
    /* Aquí se copia el contenido del archivo */
    while (!feof(fp)) {
        fread (&buffer, sizeof(buffer), 1, fp);
        fwrite(&buffer, sizeof(buffer), 1, fp2);
    }
    
    /* Aqui se cierran los archivos y se termina el programa normalmente */
    fclose (fp);
    fclose (fp2);
    exit (0);
}