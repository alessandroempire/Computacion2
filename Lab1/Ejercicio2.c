/* muestra_archivo_texto_como_binario.c v1.0 */
#include <stdio.h>
#include <stdlib.h>
#define NRO_ELEMENTOS 1

/*** Prototipos de Funciones ***/
void mostrar_archivo (FILE *ap, char memoria[]);
void rebanar_archivo (FILE *ap, char memoria[]);
void convierte(char n);

/*** Principal ***/
int main (int argc, char **argv) {
    
    FILE *fp;
    char buffer[NRO_ELEMENTOS];
    char tecla;
    
    /* Verificación de los argumentos */
    if (argc != 2) {
        fprintf(stderr, "\n%s: ERROR de sintaxis en la llamada", argv[0]);
        fprintf(stderr, "\nUSO: %s <archivo_a_visualizar>\n", argv[0]);
        exit (1);
    }
    
    /* Apertura del archivo a mostrar */
    if ((fp=fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "\n%s: no puedo abrir %s\n", argv[0], argv[1]);
        exit (2);
    }
    
    fprintf(stdout, "\nEl archivo en su formato de texto contiene:\n");
    
    /* Aqui se invoca el procedimiento */
    mostrar_archivo (fp, buffer); //Funcion que imprime lo que tiene el archivo
    
    fprintf(stdout, "\nOprima una tecla para continuar ");
    scanf ("%c", &tecla);
    
    fprintf(stdout, "\nEl archivo en su formato binario contiene:\n");
    
    /* Aqui se rebana el archivo y se muestra en binario */
    rebanar_archivo (fp, buffer);
    
    /* Aqui se cierran los archivos y se termina el programa normalmente */
    fclose (fp);
    exit (0);
    }

    /* Esta rutina muestra el contenido de un archivo de caracteres
    Atención: Esta solución puede ser modificada con fscanf de este modo:
    fscanf (ap, "%c", memoria); */
    void mostrar_archivo (FILE *ap, char memoria[]) {
        int cant_leida;

        while (!feof (ap)) {
            if ((cant_leida = fread(memoria, sizeof(void), NRO_ELEMENTOS, ap)) != 1)
                break;
            
            fprintf(stdout, "%c", *memoria);
        }
        rewind (ap); //Lleva el File pointer al comienzo del archivo
    }
    
    /* Esta rutina rebana el contenido de un archivo de caracteres */
    void rebanar_archivo (FILE *ap, char memoria[]) {
        int cant_leida;
        
        while (!feof (ap)) {
            if ((cant_leida=fread(memoria, sizeof(void), NRO_ELEMENTOS, ap)) != 1)
                    break;
            
            convierte (*memoria);
        }
        rewind (ap);
    }
    
    /* Esta rutina convierte ASCII a binario */
    void convierte (char n) {
        int i;
        for(i=7; i>=0; i--) 
            printf("%c", (n & (1 << i)) ? '1' : '0');
        printf(" ");
}
    
    /*
     * a = (b == 0) ? 1 : 0
     * a tendra valor 1 si b == 0, en caso contrario a tendra valor 0
     */