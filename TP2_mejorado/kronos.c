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
    


    mostrarCoordenadas(coordenadas, tope);
   
}






void imprimir_terreno(juego_t juego){
    char tablero[20][20];

    inicializar_matriz(tablero,20,20);
    //Se podrìa optimizar eso con funciones y no utilizar este for acà
    for (int i=0;i<4;i++){
        llenarRobot(tablero, 20, 20,juego.robots[i].lasers, juego.robots[i].tope_lasers, juego.robots[i].posicion);
        llenar_personaje(tablero, 20, 20,juego.personajes[i].posicion, juego.personajes[i].cuadrante_inicial);
        llenarSuperTraje(tablero,juego.supertrajes[i]);
    }

    //se harcodea por la cantidad de pinzas
    for(int i = 0; i < 16; i++){
        llenarPinza(tablero, juego.pinzas[i]);

    }
    mostrarTablero(tablero, 20, 20);
}








int estado_juego(juego_t juego){
    //codigo --- a veces no todo es lo que parece... leer biennn

    //fijarme que Mr increìble estè en la posición (0,19), si se encuentra ahí ya gané, sino lo está verificar que todos los personajes tengan movimientos que raelizar
    //puesto que sino pierdo sino pasa ninguna de las dos cosas aún se está jugando

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
    //ROTAR EL LASERS
    //SEPARARLO EN DOS CASOS :
    //1-SE USA EL PODER 
    //2-SE REALIZA UN MOVIMIENTO
    // SI ES EL CASO 2)FIJARME QUE LA COORDENADA A LA QUE ME VOY A MOVER SEA VALIDA ES DECIR QUE NO SALGA DEL TERRENO(LOS MARGENES)
    // SI ME SALI DEL TERRENO LE RESTO UN MOVMIENTO AL PERSONAJE E INFORMARLE AL USUARIO QUE NO SE MOVIO.
    //CASO CONTRARIO ME MUEVO DE POSICION =>DEBO FIJARME DE VALIDAR CON QUE ME CHOQUE LASERS,ST O ROBOT,PINZAS Y EL PERSONAJE SIGUIENTE 
    //POR CADA UNA DE ESTAS SE HACEN VALIDACIONES DISTINTAS.
    //SI PISO:
    //-laser:  LOS MOVIMIENTOS VAN A CERO.
    //-robots: LOS MOV VAN A CERO.
    //-supertaje:tengo 3 casos:

    //1- si el st es el cuadrante correspondiente cambio TIENE_SUPERTRAJE = true;
    //2- si no es el sj de el cuadrante correspondiente no pasa nada;
    //3- si la cantidad de movientos menor que 5 es que ya lo utilice y TENGO EL SUPERTRAJEentonces quiere decir que ya use y no puedo utilizar el supertraje
    //        una vez agarrado el st "desaparece(?"
    //
    //-personaje:DE BEDE VERIFICAR 2 COSAS:
                    // 1) si no es el personaje conssecutivo sigo con el personaje en el juego.
                    // 2) si el erpsonaje es el consecutivo debemos cambiar el peronaje y el juego pasa a tener el siguiente personaje.
    //-pinzas: me lleva alrededor del robot las 8 posciones entocnes si piza a las pinzas MUERE.
    


    
    
    //-A QUÉ HACE REFERENCIA CUANDO DICE QUE SE LLEGUE A UN NUEVO PERSONAJE? SERÍA QUE LO PISE? O QUE ENTRE EN SU CUADRANTE?
    //-SE REINICIA LOS MOVIMINETOS CUANDO SE LLEGA AL SIGUIENTE FAMILIAR
    //-EL PODER SE ACTIVA CUANDO SE PISA UN SUPER TRAJE
    //-SE PIERDE EL JUEGO SI SE PISA UN LASER(PERO)
    //-CUANDO SE REALIZA UN MOVIMIENTO SE ROTA LOS LASER A ESTO CUAL ES LA VALIDACIÓN PRIMERA? OSEA SI ME MUEVO ARRIBA Y JUSTO AHÍ ESTABA EL LASER LO ESTARÍA PISANDO? O TENGO QUE CORROBORAR 
    //QUE SE HAGA LA ROTACIÓN Y RECIEN VALIDAR?
    //-SI PISA UNA PINZA LO LLEVA A SU CUADRANTE INICIAL AL REDEDOR DE UN ROBOT, ALREDEDOR HACE REFERENCIA SUS VECINOS CONTINUOS QUE NO TENGAN LASER?
    //- PARA USAR LOS PODERES SE DEBE PISAR EL SUPER TRAJE , SOLO A SU CUADRANTE INICIAL,NO TIENE VALIDEZ SI ES AL CUDRANTE AL CUAL NO PERTENEZCA 
    // SE BORRA EL ST UNA VEZ PISADO, SOLO SE ACTIVA UNA ÚNICA VEZ Y DURA 5 MOVIMIENTOS DEL PRSJE LUEGO NO SE PODRÁ UTILIZAR.

    //IMPORTANTE! AL PISAR EL LASER QUITAR LOS MOVIMIENTOS DEL PERSONAJE! ES LA FORMA DE MATARLO.

}

//------------------------------------------IMPORTANTE---------------------------

/*  -El tp aclara que ningún elemento inicia en la casillera de salida PERO que pasa cuando el laser gira a 45 grados podrìa pisarlo?
    -Cuando gira los lasers y pisa al jugador acaba el juego? aclara cuando el personaje pisa al laser
    -Se solucionò la cant de personajes que habìan solo informaba 3 ahora correcto 4
    -Hay un gran problema a la hora de crear el personaje si bien se le asigna su cuadrante inicial que cada uno pertenece 
     para "solucionar " el problema de que cada personaje esté en cada cuadrante está harcodeado en la funcion asignarPersonaje, puesto al recorrer
     con el for, estoy diciendo que según el orden que se haya guardado en vector personajes así será los cuadrantes, 
     ya que a la hora de crearlo se cambió el orden para que así "matematicamente" a la hora de llamar aasignarPersonaje sea cada personaje el cuadrante
     matricial que corresponde. si bien funciona ahora "bien" no estaría usando su "atributo" del cuadrante del personaje para asignarle su posición sino que se hace al harcodearlo...
    -Quitar lo del cuadrante que no se usa y se pasa como parametro al pedo a la hora de inicializar personaje cuando llama a crearPersonaje.
    -Falta modificar que ningun elemento inicial estè en el casillero de SALIDA
    */