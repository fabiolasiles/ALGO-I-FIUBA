#include "kronos.h"
#include "increidle.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    printf ("COMIENZA\n");

   // juego_t juego;
    //llamar al tp increidle
    char contrasenia_adivinada[6];
    adivinar_contrasenia(contrasenia_adivinada);
   // bool contrasenia_completa = validar_contrasenia(contrasenia);
    //inicializar_juego(&juego,contrasenia_completa);
    printf ("LO QUE VISUALIZA LO GUARDADO EN EL VECTOR\n");
    for (int i= 0;i<=5;i++){
        printf("eL NUMERO %i es %c\n",i,contrasenia_adivinada[i]);
    }

}
