#include "kronos.h"
#include "increidle.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CONTRASENIA 6
#define CONTRASENIA "KRONOS"

/*
 * PRE: -
 * POST:  Verifica que se haya descubierto la contraseña de forma completa en el caso afirmativo devuelve true, sino false.
 */
bool validar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]){
    return (strcmp(contrasenia_adivinada,CONTRASENIA)==0);
}




int main(){
    
    srand((unsigned)time(NULL));

    char contrasenia_adivinada[MAX_CONTRASENIA];
    
    adivinar_contrasenia(contrasenia_adivinada);
     
    
    bool contrasenia_completa = validar_contrasenia(contrasenia_adivinada);
   

    juego_t juego;

    inicializar_juego(&juego,contrasenia_completa);
    /*printf("INFO ELASTIC");
    printf("ELASTIC  se encuentra en las coordenadas(%i,%i) \n",juego.personajes[0].posicion.fila,juego.personajes[0].posicion.columna);
        printf("DASH  ESTA EN EL CUADRANTE(%i) \n",juego.personajes[2].cuadrante_inicial);

    printf("\n");*/
    
   
   

}
