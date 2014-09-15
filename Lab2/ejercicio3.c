/* apuntadores_a_f.c v1.0 
 * Compilarlo con esta instruccion: gcc apuntadores_a_f.c -o apuntadores_a_f -lm 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main() { 
    /* --- Declaración e inicialización --- 
     fabs es una función de valor absoluto 
     sqrt es una función de raíz cuadrada 
     exp es una función de exponente -incluye el número de Euler- 
     y operación es un vector de 3 posiciones 
     que almacenará funciones */ 

    static double (*funcion[3])(double) = {fabs, sqrt, exp}; 
    float x; 
    int i; /* Indice para recorrer el vector */ 

    fprintf(stdout, "\nIntroduzca un numero natural: "); 

    scanf("%f", &x); 

    fprintf(stdout, "\n\nFunciones: Valor Absoluto, Raiz Cuadrada, Exponencial"); 

    for (i=0; i<3 ;++i)
            fprintf(stdout, "\nEl numero %f arroja la siguiente funcion: %lf \n", x, (funcion[i])(x));

    exit (0); 
}
