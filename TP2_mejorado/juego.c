#include "kronos.h"
#include "Interfaz.h"
#include "increidle.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void asignarCoordAMatriz(char matriz[20][20], int fila , int columna, coordenada_t coodenadas[MAX_COORDENADAS], int tope){
    for(int i = 0; i < tope; i++){
        matriz[coodenadas[i].fila][coodenadas[i].columna] = 'R';
    }
}

int main(){
/*
    coordenada_t coordenadas[MAX_COORDENADAS];
    coordenada_t coordenadaRobot;
    coordenadaRobot.fila = 15;
    coordenadaRobot.columna = 8;
    asignarCoordenadasVecinasAlRobot(coordenadaRobot, coordenadas);
    char matriz[20][20];
    inicializar_matriz(matriz, 20, 20);
    asignarCoordAMatriz(matriz, 20, 20, coordenadas, 8);
    mostrarTablero(matriz, 20, 20);
*/
    inicializar();
    return 0;

}
