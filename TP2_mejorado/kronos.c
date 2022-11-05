#include "kronos.h"
#include "auxiliares.h"


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
    
    mostrarCoordenadas(coordenadas, tope);
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
        printf("---");
        
    }else if( moverPersonaje(juego->id_personaje_actual,juego->personajes,juego->tope_personajes,movimiento)){
        printf("----------------------------TERRENO LUEGO DE MOVER EL PERSONAJE-----------\n");
        imprimir_terreno(*juego);
        printf("-------------Muevo el Personaje\n");
        if(true){
            printf("---------vacio luego de mover el personaje-\n");
        //1-SE USA EL PODER 
        }else if(estaEnElPersonajeSiguiente(juego->personajes,juego->tope_personajes,indicePersonaje)){
            juego->id_personaje_actual ++; 

            
        //-personaje:DE BEDE VERIFICAR 2 COSAS:
                        // 1) si no es el personaje conssecutivo sigo con el personaje en el juego.
                        // 2) si el erpsonaje es el consecutivo debemos cambiar el peronaje y el juego pasa a tener el siguiente personaje.

        }else if(estaEnLasers((juego))){
            juego->personajes[indicePersonaje].movimientos = 0;

        }else if(estaEnRobot(juego->robots,juego->tope_robots,juego->personajes[indicePersonaje])){
            juego->personajes[indicePersonaje].movimientos = 0;
//estaEnSupertraje(juego->supertrajes,juego->tope_supertraje)
        }else if(true){
            //-supertaje:tengo 3 casos:

        //1- si el st es el cuadrante correspondiente cambio TIENE_SUPERTRAJE = true;
        //2- si no es el sj de el cuadrante correspondiente no pasa nada;
        //3- si la cantidad de movientos menor que 5 es que ya lo utilice y TENGO EL SUPERTRAJEentonces quiere decir que ya use y no puedo utilizar el supertraje
        //        una vez agarrado el st "desaparece(?"

        }else if(estaEnPinzas(juego->pinzas,juego->tope_pinzas,juego->personajes[indicePersonaje])){
            coordenada_t posicionesVecinas[MAX_COORDENADAS];
            
            int indiceRobotActual = obtenerIndiceDelRobotActual(indicePersonaje,juego->robots, juego->tope_robots);
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