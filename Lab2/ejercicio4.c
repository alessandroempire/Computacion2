#include <stdio.h>
#include <string.h>

void prueba (char *a, char *b, int (*cmp)(const char *st1, const char *st2)){

    printf ("\nVerificando la igualdad de las cadenas...");

    (!(cmp) (a, b))? printf ("\n\nCadenas iguales\n"): printf ("\n\nCadenas diferentes\n");
}

int main (){

    char s1[80], s2[80];

    int (*apunt)(const char *c1, const char*c2);

    /* Asigna la dirección de la función en el apuntador */
    apunt=strcmp;
    
    printf ("\nIntroduzca una cadena de a lo sumo 80 caracteres: ");

    gets (s1);

    printf ("\nIntroduzca otra cadena de a lo sumo 80 caracteres: ");

    gets (s2);

    prueba (s1, s2, apunt);
}