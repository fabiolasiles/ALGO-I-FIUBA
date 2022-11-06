#include "kronos.h"
#include "auxiliares.h"

#include "interfaz.h"
#include "presentaciones.h"


void inicializar_juego(juego_t* juego, bool contrasenia_completa){

    coordenada_t coordenadas[MAX_COORDENNADAS];
    int tope = 0;

    //SE TIENE QUE LLAMAR EN ESTE ORDEN(PRIMERO ROBOTS Y LUEGO LO QUE SEA) PORQUE AL LLAMAR INICIALIZAR LAZER NO SE LE PASA LAS COORDENDAS POR ENDE NO PUEDE VERIFICAR SI YA HUBO ALGUNO ELEMENTO ANTES
    inicializar_robots(juego->robots, contrasenia_completa, &juego->tope_robots);
    asignarPosRobots(juego->robots, juego->tope_robots, coordenadas, &tope);

    inicializar_personajes(juego->personajes, &juego->tope_personajes);
    asignarPosPersonajes(juego->personajes, juego->tope_personajes, coordenadas, &tope);

    inicializar_supertrajes(juego->supertrajes, &juego->tope_supertraje);
    asignarPosSuperTraje(juego->supertrajes, juego->tope_supertraje, coordenadas, &tope);

    asignarPosPinzas(juego->pinzas, &juego->tope_pinzas, coordenadas, &tope);
    juego->id_personaje_actual = 1;
    
    //mostrarCoordenadas(coordenadas, tope);
}


void imprimir_terreno(juego_t juego){

    char tablero[20][20];

    inicializar_matriz(tablero,20,20);
    for (int i=0;i<4;i++){
        llenarRobot(tablero, 20, 20,juego.robots[i].lasers, juego.robots[i].tope_lasers, juego.robots[i].posicion);
        llenar_personaje(tablero, 20, 20,juego.personajes[i].posicion, juego.personajes[i].cuadrante_inicial);
        llenarSuperTraje(tablero,juego.supertrajes[i]);
    }

    for(int i = 0; i < 16; i++){
        llenarPinza(tablero, juego.pinzas[i]); 

    }
    mostrarTablero(tablero, 20, 20);
}


int estado_juego(juego_t juego){

    int estado = SE_SIGUE_JUGANDO;

    if(seGanaElJuego(juego.personajes, juego.tope_personajes)){
        estado = SE_GANA;
    }else if(sePierdeElJuego(juego.personajes, juego.tope_personajes)){
        estado = SE_PIERDE;
    }else{
        estado = SE_SIGUE_JUGANDO;
    }
    
    return estado;
}


void realizar_jugada(juego_t* juego, char movimiento){
    
    int indicePersonaje = obtenerIndicePersonajeActual(juego->id_personaje_actual,juego->personajes,juego->tope_personajes);

    printf("----------------------------TERRENO SIN MOVER EL PERSONAJE-----------\n");
    imprimir_terreno(*juego);
     //ROTAR EL LASERS
    if(movimiento =='C'){
        if(juego->personajes[indicePersonaje].tiene_supertraje){
            juego->personajes[indicePersonaje].poder_activado = true;
        }else{
            printf("NO PUEDES ACTIVAR TU PODER PORQUE NO TIENES EL SUPERTRAJE RECOLECTADO\n");

        }
        
        
    }else if( moverPersonaje(juego->id_personaje_actual,juego->personajes,juego->tope_personajes,movimiento)){
        printf("----------------------------TERRENO LUEGO DE MOVER EL PERSONAJE-----------\n");
        imprimir_terreno(*juego);
        printf("-------------Muevo el Personaje\n");
        if(false){
            printf("---------vacio luego de mover el personaje-\n");
        //1-SE USA EL PODER 
        }else if(estaEnElPersonajeSiguiente(juego->personajes,juego->tope_personajes,indicePersonaje)){
            juego->id_personaje_actual ++;

        }else if(estaEnLasers((juego))){
            juego->personajes[indicePersonaje].movimientos = 0;

        }else if(estaEnRobot(juego->robots,juego->tope_robots,juego->personajes[indicePersonaje])){
            juego->personajes[indicePersonaje].movimientos = 0;

        }else if(estaEnSuperTraje(juego->supertrajes, juego->tope_supertraje, juego->personajes[indicePersonaje]))
        {
            juego->personajes[indicePersonaje].tiene_supertraje = true;
            //serìa necesario informar por pantalla que si el superTraje que pisè es de otro cuadrante?

        }else if(estaEnPinzas(juego->pinzas,juego->tope_pinzas,juego->personajes[indicePersonaje])){
            coordenada_t posicionesVecinas[MAX_COORDENADAS];
            
            int indiceRobotActual = obtenerIndiceDelRobotActual(juego->id_personaje_actual,juego->robots, juego->tope_robots);
            printf("-----------------indice del robot actual %i", indiceRobotActual);
            asignarCoordenadasVecinasAlRobot(juego->robots[indiceRobotActual].posicion,posicionesVecinas);
            coordenada_t coordenadaNueva = obtenerCoordenadaDentroDelTerreno(posicionesVecinas);
            juego->personajes[indicePersonaje].posicion = coordenadaNueva;

            if(estaEnLasers(juego)){
                juego->personajes[indicePersonaje].movimientos = 0;
            }
            //fijarme si està en el laser
            //no se harà pero sería adecaudo fijarme si vuelve a caer en una pinza --> S.Traje.. 
        }
    }else{
        printf("No puede moverse fuera del terreno");
    }
}