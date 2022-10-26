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

void inicializar_matriz(char matriz[20][20], int fila, int col){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j< col; j++){
            matriz[i][j] = '*'; 
        }
    }
}

void llenar(char matriz[20][20],int topeFil, int topeCol, coordenada_t coordenadas[], int topeCoord, coordenada_t robotCoord){
    for(int i = 0; i < topeCoord; i++){
        if(coordenadas[i].fila >= 0 && coordenadas[i].columna >= 0 && coordenadas[i].fila <=19 && coordenadas[i].columna<=19){
            matriz[coordenadas[i].fila][coordenadas[i].columna] = 'L';
        }
    }
    matriz[robotCoord.fila][robotCoord.columna] = 'R'; //VER VARIABLES CAMBIARLAS
}

void llenar_personaje(char matriz[20][20],int topeFil, int topeCol,coordenada_t coordenada_personaje){
    matriz[coordenada_personaje.fila][coordenada_personaje.columna] = 'P';


}

void mostrarTablero(char matriz[20][20], int topeFila, int topeCol){
    for(int i = 0; i < topeFila; i++){
        for(int j = 0; j< topeCol; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}

/*
void rotacion_lasers(coordenada_t lasers[MAX_LASERS],int tope_lasers){
    int j=1;

    for (int i=0 ;i<tope_lasers;i++){
        if (i<3){
            lasers[i].fila =(lasers[i].fila+i+1);
        }else{
            lasers[i].columna=(lasers[i].columna-j);
            j++;
        }
    }
}
void inializarMatriz(char matriz[20][20], int fila, int col){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j< col; j++){
            matriz[i][j] = '*'; 
        }
    }
}

void llenarTablero(char matriz[20][20],int topeFil, int topeCol, coordenada_t coordenadas[], int topeCoord, coordenada_t robotCoord){
    for(int i = 0; i < topeCoord; i++){
        if(coordenadas[i].fila >= 0 && coordenadas[i].columna >= 0){
            matriz[coordenadas[i].fila][coordenadas[i].columna] = 'L';
        }
    }
    matriz[robotCoord.fila][robotCoord.columna] = 'R';
}

void mostrarTablero(char matriz[20][20], int topeFila, int topeCol){
    for(int i = 0; i < topeFila; i++){
        for(int j = 0; j< topeCol; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}*/


int main(){
    
    srand((unsigned)time(NULL));

    char contrasenia_adivinada[MAX_CONTRASENIA];
    
    adivinar_contrasenia(contrasenia_adivinada);
    printf("LINEA 65");
     
    
    bool contrasenia_completa = validar_contrasenia(contrasenia_adivinada);
   printf("LINEA 69");

    juego_t juego;
    printf("SE DESCUBRIO LA CONTRASEÑA");

    inicializar_juego(&juego,contrasenia_completa);
    /*coordenada_t coordenada_laser_uno,coordenada_laser_dos,coordenada_laser_tres,coordenada_laser_cua,coordenada_laser_cinco,coordenada_laser_seis;
    coordenada_laser_uno.fila = 2;
    coordenada_laser_uno.columna = 2;
    coordenada_laser_dos.fila = 2;
    coordenada_laser_dos.columna = 3;
    coordenada_laser_tres.fila = 2;
    coordenada_laser_tres.columna = 4;
    coordenada_laser_cua.fila = 3;
    coordenada_laser_cua.columna = 1;
    coordenada_laser_cinco.fila = 4;
    coordenada_laser_cinco.columna = 1;
    coordenada_laser_seis.fila = 5;
    coordenada_laser_seis.columna = 1;*/

    //coordenada_t coorRobot;
    //coorRobot.fila = 2;
    //coorRobot.columna = 1;
    char tablero[20][20];
    //inicializarJuego2(tablero, 20, 20);
    inicializar_matriz(tablero,20,20);
    for (int i=0;i<4;i++){
      //llenar(char matriz[20][20],int topeFil, int topeCol, coordenada_t coordenadas[], int topeCoord, coordenada_t robotCoord){
        llenar(tablero, 20, 20,juego.robots[i].lasers, juego.robots[i].tope_lasers, juego.robots[i].posicion);
        llenar_personaje(tablero, 20, 20,juego.personajes[i].posicion);
    //  llenar_personaje(char matriz[20][20],int topeFil, int topeCol,coordenada_t coordenada_personaje)
    }
    mostrarTablero(tablero, 20, 20);
    
    /*coordenada_t lasers[6] = {coordenada_laser_uno,coordenada_laser_dos,coordenada_laser_tres,coordenada_laser_cua,coordenada_laser_cinco,coordenada_laser_seis};

    rotacion_lasers(lasers,6);
    rotacion_lasers(lasers,6);
    for (int i=0 ;i<6;i++){
        printf("%i,%i \n",lasers[i].fila,lasers[i].columna);
       
    }
    

    coordenada_t coorRobot;
    coorRobot.fila = 2;
    coorRobot.columna = 1;
    char tablero[20][20];
    inicializarJuego2(tablero, 20, 20);
    llenarTablero(tablero, 20, 20, lasers, 6, coorRobot);
    mostrarTablero(tablero, 20 , 20);*/

    /*printf("INFO ELASTIC");
    printf("ELASTIC  se encuentra en las coordenadas(%i,%i) \n",juego.personajes[0].posicion.fila,juego.personajes[0].posicion.columna);
        printf("DASH  ESTA EN EL CUADRANTE(%i) \n",juego.personajes[2].cuadrante_inicial);

    printf("\n");*/
    
   
   

}
