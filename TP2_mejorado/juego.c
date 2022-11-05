#include "kronos.h"
#include "Interfaz.h"
#include "increidle.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    //inicializar();
    coordenada_t posicionDelRobot;
    posicionDelRobot.fila = 5;
    posicionDelRobot.columna= 5;
    coordenada_t posicionesVecinas[MAX_COORDENADAS];
    int tope = 8;
    asignarCoordenadasVecinasAlRobot(posicionDelRobot,posicionesVecinas);
    for(int i=0;i<tope;i++){
        mostrarCoordenada(posicionesVecinas[i]);
    }
    return 0;

}
