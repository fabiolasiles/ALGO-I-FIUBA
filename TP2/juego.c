#include "kronos.h"
#include "increidle.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CONTRASENIA 6
#define CONTRASENIA "KRONOS"


bool validar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]){

    
    /*for (int i= 0;i<=5;i++){
        printf("CONTRASENIA POSTA %i es %c\n",i,contrasenia[i]);
    }
    printf("_________________________________________");*/
    /*printf("_________________________________________");
    for (int i= 0;i<=5;i++){
        printf("eL NUMERO %i es %c\n",i,contrasenia_adivinada[i]);
    }
    printf("_________________________________________");
    
    
    if(strcmp(contrasenia_adivinada,CONTRASENIA)==0){//ENTONCES SI ES IGUAL A CERO ES FALSE???
        
        return true;
    }else{
        printf("  nooooooooooooooo ES LA CONTRASENIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
        return false;
    }*/
    return (strcmp(contrasenia_adivinada,CONTRASENIA)==0);
}




int main(){
    
    char contrasenia_adivinada[MAX_CONTRASENIA];
    
    adivinar_contrasenia(contrasenia_adivinada);
    
    bool contrasenia_completa = validar_contrasenia(contrasenia_adivinada);

    juego_t juego;

    inicializar_juego(&juego,contrasenia_completa);
    

}
