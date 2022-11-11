#include "auxiliares.h"
#include "kronos.h"


void mostrarCoordenada(coordenada_t coordenada){
    printf("FIL : %i\n", coordenada.fila);
    printf("COL : %i\n", coordenada.columna);
}


void mostrarCoordenadas(coordenada_t coordenadas[MAX], int tope){
    for(int i = 0; i < tope ; i++){
        mostrarCoordenada(coordenadas[i]);
    }
}
/*
void mostrarRobots(robot_t robots[MAX_ROBOTS], int topeRobot){
    for(int i = 0 ; i < topeRobot; i++){
        printf("---------Posiciòn del Robot : ---------\n");
        mostrarCoordenada(robots[i].posicion);
        printf("--------Posiciones de sus Lasers : -----------\n");
        mostrarCoordenadas(robots[i].lasers, robots[i].tope_lasers);


    }    
}*/


bool validar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]){
    return (strcmp(contrasenia_adivinada,CONTRASENIA)==0);
}


//_______________________________________________________________________________________________________________________

//FUNCIONES SOBRE ESTADOS DEL JUEGO----------------------------------------------------------------------------------


bool seGanaElJuego(personaje_t personajes[MAX_PERSONAJES], int tope){

    coordenada_t coordSalida;
    coordSalida.fila = SALIDA_FILA;
    coordSalida.columna = SALIDA_COLUMNA;

    int pos = 0;
    bool seGana = false;
    while(!seGana && pos < tope){
        if(personajes[pos].cuadrante_inicial == CUADRANTE_SALIDA && comparararCoordenadas(coordSalida, personajes[pos].posicion)){
            seGana = true;
        }
       pos++;
    }
    return seGana;
}


bool sePierdeElJuego(personaje_t personajes[MAX_PERSONAJES], int tope){
    bool sePierde = false;
    int pos = 0;
    while(!sePierde && pos < tope){
        if(personajes[pos].movimientos == 0){
            sePierde = true;
        } 
        pos++;
    }
    return sePierde;
}


//_______________________________________________________________________________________________________________________________________________________

//FUNCIONES SOBRE PINZAS----------------------------------------------------------------------------------


void asignarPosPinzas(coordenada_t pinzas[MAX_PINZAS], int* tope_pinzas, coordenada_t coordenadas[MAX], int* topeCoord){
    (*tope_pinzas) = 0;
    int pos = 0; 
    while(pos < 16){
        if(pos < 4){
            pinzas[pos] = obtenerCordeAleatoriaValida(coordenadas, topeCoord, PRIMER_CUADRANTE);
            (*tope_pinzas)++;
            pos++;

        }else if(pos < 8){
            pinzas[pos] = obtenerCordeAleatoriaValida(coordenadas, topeCoord, SEGUNDO_CUADRANTE);
            (*tope_pinzas)++;
            pos++;

        }else if(pos < 12){
            pinzas[pos] = obtenerCordeAleatoriaValida(coordenadas, topeCoord, TERCER_CUADRANTE);
            (*tope_pinzas)++;
            pos++;

        }else if(pos < 16){
            pinzas[pos] = obtenerCordeAleatoriaValida(coordenadas, topeCoord, CUARTO_CUADRANTE);
            (*tope_pinzas)++;
            pos++;
        }

    } 
    //mostrarCoordenadas(pinzas, *tope_pinzas);    
}


//_______________________________________________________________________________________________________________________________________________

//FUNCIONES SOBRE SUPERTRAJES----------------------------------------------------------------------------------


void asignarPosSuperTraje(supertraje_t superTrajes[MAX_SUPERTRAJES], int tope, coordenada_t coordenadas[MAX_COORDENNADAS], int* topeCoord){
    
    int cuadrante  = 1;
    for(int i = 0; i < tope; i++){
        superTrajes[i].posicion = obtenerCordeAleatoriaValida(coordenadas, topeCoord, cuadrante);
        cuadrante++;
        
       // mostrarCoordenada(superTrajes[i].posicion);
    }
}


supertraje_t obtener_supertraje(int cuadrante){
    supertraje_t supertraje;
    if(cuadrante == PRIMER_CUADRANTE){
        supertraje.cuadrante = PRIMER_CUADRANTE;
        supertraje.recolectado = false;
        supertraje.usado = false;
    }else if (cuadrante == SEGUNDO_CUADRANTE){
        supertraje.cuadrante = CUARTO_CUADRANTE; //modificado a 4to
        supertraje.recolectado = false;
        supertraje.usado = false;
    }else if(cuadrante == TERCER_CUADRANTE){
        supertraje.cuadrante = TERCER_CUADRANTE;
        supertraje.recolectado = false;
        supertraje.usado = false;
    }else if(cuadrante == CUARTO_CUADRANTE){
        supertraje.cuadrante = SEGUNDO_CUADRANTE; //modificado a 2do..
        supertraje.recolectado = false;
        supertraje.usado = false;
    }
    return supertraje;
}


void inicializar_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES], int* tope_supertraje){
    (*tope_supertraje)=0;
    
    int cuadrante = 1;
    for(int i = 0; i < 4; i++){
        supertrajes[i] = obtener_supertraje(cuadrante);
        cuadrante++;
        (*tope_supertraje)++;
    }
}


//______________________________________________________________________________________________________________________________________________________

//FUNCIONES SOBRE COORDENADAS----------------------------------------------------------------------------------


bool comparararCoordenadas(coordenada_t coordenada1, coordenada_t coordenada2){
    return (coordenada1.fila == coordenada2.fila && coordenada1.columna == coordenada2.columna);
}


bool buscarCoordenada(coordenada_t coordenadas[MAX_COORDENNADAS], int topeCoord, coordenada_t coordenada){
    bool seEncontro = false;
    int pos = 0;
    while(!seEncontro && pos < topeCoord){
        if(comparararCoordenadas(coordenadas[pos], coordenada)){
            seEncontro = true;
        }
        pos++;
    }
    return seEncontro;
}


coordenada_t obtenerCordeAleatoriaValida(coordenada_t coordenadas[MAX_COORDENNADAS], int* topeCoord, int cuadrante){
    coordenada_t coordenadaAleatoria = coordenada_aleatoria(cuadrante);
    bool encontrado = false;
    while(!encontrado){
            
        if(buscarCoordenada(coordenadas,*topeCoord, coordenadaAleatoria)){
            coordenadaAleatoria = coordenada_aleatoria(cuadrante);   
        }else{
            encontrado = true;
        }
    }
    coordenadas[*topeCoord] = coordenadaAleatoria;
    *topeCoord = *topeCoord + 1;

    return coordenadaAleatoria;
}


coordenada_t coordenada_aleatoria(int cuadrante){
    coordenada_t coordenada;
    if(PRIMER_CUADRANTE == cuadrante){
        coordenada.fila = rand()% 10;
        coordenada.columna = rand()% 10; 
    }else if(SEGUNDO_CUADRANTE == cuadrante){
        coordenada.fila = rand()% 10;
        coordenada.columna = rand()% 10 + 10;
    }else if(TERCER_CUADRANTE == cuadrante){
        coordenada.fila = rand()% 10 + 10;
        coordenada.columna = rand()%10;
    }else if(CUARTO_CUADRANTE == cuadrante){
        coordenada.fila = rand()% 10 + 10;
        coordenada.columna = rand()%10 + 10;
    }

    return coordenada;
}


void asignarCoordenadas(coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord, coordenada_t coordenadasParaAsignar[MAX_LASERS], int topeLasers){ 
    for(int i = 0; i < topeLasers; i++){
        coordenadas[*topeCoord] = coordenadasParaAsignar[i];
        *topeCoord = *topeCoord + 1;
    }
}


//_________________________________________________________________________________________________________________________________________________________

//FUNCIONES SOBRE ROBOTS------------------------------------------------------------------


void cargar_tipo_laser_aleatorio(int forma_de_laser_aleatorio,int tope_lasers,coordenada_t lasers[MAX_LASERS], coordenada_t posicion_del_robot){
    int j=1;
    int k=1;
    int longitud_lasers = (tope_lasers/2);
    for (int i = 0;i<tope_lasers;i++){
        switch(forma_de_laser_aleatorio){
            case ARRIBA_DERECHA:
                if (i<longitud_lasers){
                    lasers[i].fila = posicion_del_robot.fila -j;
                    lasers[i].columna = posicion_del_robot.columna;
                    
                    j++;
                }else{
                    lasers[i].columna = posicion_del_robot.columna+k;
                    lasers[i].fila = posicion_del_robot.fila;
                    k++;
                }
                break;   
            case ARRIBA_IZQUIERDA:
                if (i<longitud_lasers){
                    lasers[i].columna = posicion_del_robot.columna-k;
                    lasers[i].fila = posicion_del_robot.fila;
                    k++;
                    
                }else{
                    lasers[i].fila=posicion_del_robot.fila-j;
                    lasers[i].columna=posicion_del_robot.columna;
                    j++;
                }
                break;
            case ABAJO_DERECHA:
                if (i<longitud_lasers){
                    lasers[i].columna=posicion_del_robot.columna+k;
                    lasers[i].fila =posicion_del_robot.fila;
                    k++;
                }else{
                    lasers[i].columna =posicion_del_robot.columna;
                    lasers[i].fila =posicion_del_robot.fila+j;
                    j++;
                }
                break;
            default:
                if (i<longitud_lasers){
                    lasers[i].columna =posicion_del_robot.columna;
                    lasers[i].fila =posicion_del_robot.fila+j;
                    j++;
                   
                }else{
                    lasers[i].columna = posicion_del_robot.columna-k;
                    lasers[i].fila = posicion_del_robot.fila;
                    k++;
                break;
                }
        
        }
            
    }

}


void llenar_lasers( coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot){

   int forma_de_laser_aleatorio = rand() % 4 + 1;
   cargar_tipo_laser_aleatorio(forma_de_laser_aleatorio,tope_lasers,lasers,posicion_del_robot);
}


void inicializar_robots(robot_t robots[MAX_ROBOTS], bool contrasenia_completa, int* tope_robots){

    (*tope_robots) = 0;
    
    robots[0] = crear_robot(contrasenia_completa, PRIMER_CUADRANTE);
    (*tope_robots)++;
    
    robots[1] = crear_robot(contrasenia_completa, SEGUNDO_CUADRANTE);
    (*tope_robots)++;
   
    robots[2] = crear_robot(contrasenia_completa, TERCER_CUADRANTE);
    (*tope_robots)++;
    robots[3] = crear_robot(contrasenia_completa, CUARTO_CUADRANTE);
    (*tope_robots)++;
}


robot_t crear_robot(bool contrasenia_completa, int cuadrante){

    robot_t robot;
    
    if(contrasenia_completa){
        robot.tope_lasers = LASERS_CONTRASENIA_ACERTADA;
    }else{
        robot.tope_lasers = LASERS_CONTRASENIA_NO_ACERTADA;
    }

    return robot;
}


void asignarPosRobots(robot_t robots[MAX_ROBOTS], int tope, coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord){
    
    int cuadrante = 1;
    for(int i = 0; i <= tope; i++){
        robots[i].posicion = obtenerCordeAleatoriaValida(coordenadas,topeCoord, cuadrante);
        llenar_lasers(robots[i].lasers, robots[i].tope_lasers, robots[i].posicion);
    
        asignarCoordenadas(coordenadas, topeCoord, robots[i].lasers, robots[i].tope_lasers);
        cuadrante++;
    }
}


//_________________________________________________________________________________________________________________________________________________________

//FUNCIONES SOBRE PERSONAJES--------------------------------------------------------------


void asignarPosPersonajes(personaje_t personajes[MAX_PERSONAJES], int tope, coordenada_t coordenadas[MAX_COORDENNADAS], int* topeCoord){
    int cuadrante = 1;
    for(int i = 0; i <= tope; i++){
        personajes[i].posicion = obtenerCordeAleatoriaValida(coordenadas,topeCoord, cuadrante);
        cuadrante++;
    }
}


personaje_t crear_personaje(char nombre_personaje,int cuadrante){
    
    personaje_t personaje;
    if (nombre_personaje == ELASTIC_GIRL){

        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_ELASTIC;
        personaje.movimientos_con_poder = MOV_PODER_ELASTIC;
        personaje.cuadrante_inicial = CUADRANTE_ELASTIC;
    
    }else if (nombre_personaje == VIOLETA){
        
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_VIOLETA;
        personaje.movimientos_con_poder = MOV_PODER_VIOLETA;
        personaje.cuadrante_inicial = CUADRANTE_VIOLETA;
        
    }else if(nombre_personaje == DASH){

        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_DASH;
        personaje.movimientos_con_poder = MOV_PODER_DASH;
        personaje.cuadrante_inicial = CUADRANTE_DASH;
        
    }else {
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_MR_INCREIBLE;
        personaje.movimientos_con_poder = MOV_PODER_MR_INCREIBLE;
        personaje.cuadrante_inicial = CUADRANTE_MR_INCREIBLE;
    }
    return personaje;
}


void inicializar_personajes(personaje_t personajes[MAX_PERSONAJES],int* tope_personajes){
   (*tope_personajes) = 0; 
    personajes[(*tope_personajes)] = crear_personaje(ELASTIC_GIRL,PRIMER_CUADRANTE);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(MR_INCREIBLE,SEGUNDO_CUADRANTE);
    (*tope_personajes)++;
    
    personajes[(*tope_personajes)] = crear_personaje(DASH,TERCER_CUADRANTE);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(VIOLETA,CUARTO_CUADRANTE);
    (*tope_personajes)++;
}


//_____________________________________________________________________________________________________________________

//FUNCIONES DE MOSTRAR TERRENO-----------------------------------------------------------------------


void inicializar_matriz(char matriz[20][20], int fila, int col){
    for(int i = 0; i < fila; i++){
        for(int j = 0; j< col; j++){
            matriz[i][j] = '*'; 
        }
    }
}


void llenarRobot(char matriz[20][20],int topeFil, int topeCol, coordenada_t coordenadas[], int topeCoord, coordenada_t robotCoord){
    for(int i = 0; i < topeCoord; i++){
        if(coordenadas[i].fila >= 0 && coordenadas[i].columna >= 0 && coordenadas[i].fila <=19 && coordenadas[i].columna<=19){
           if (matriz[coordenadas[i].fila][coordenadas[i].columna] != 'R'){
                matriz[coordenadas[i].fila][coordenadas[i].columna] = 'L';
           }
        }
    }
    matriz[robotCoord.fila][robotCoord.columna] = 'R';
}


void llenar_personaje(char matriz[20][20],int topeFil, int topeCol,coordenada_t coordenada_personaje, int cuadranteInicial){

    if(cuadranteInicial == PRIMER_CUADRANTE){
        matriz[coordenada_personaje.fila][coordenada_personaje.columna] = 'E';
    }else if(cuadranteInicial == SEGUNDO_CUADRANTE){
        matriz[coordenada_personaje.fila][coordenada_personaje.columna] = 'V';
    }else if(cuadranteInicial == TERCER_CUADRANTE){
        matriz[coordenada_personaje.fila][coordenada_personaje.columna] = 'D';
    }else if(cuadranteInicial == CUARTO_CUADRANTE){
        matriz[coordenada_personaje.fila][coordenada_personaje.columna] = 'I';
    }
}


void mostrarTablero(char matriz[20][20], int topeFila, int topeCol){
    for(int i = 0; i < topeFila; i++){
        for(int j = 0; j< topeCol; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}


void llenarSuperTraje(char matriz[20][20], supertraje_t supertraje){
    //if(supertraje.posicion.fila >= 0 && supertraje.posicion.columna >= 0) // si es negativo es porque el super traje ya fue obtenido por el personaje
    if(!supertraje.recolectado)
        matriz[supertraje.posicion.fila][supertraje.posicion.columna] = 'T';
}


void llenarPinza(char matriz[20][20], coordenada_t pinza){
    matriz[pinza.fila][pinza.columna] = 'P';
}


//__________________________________________________________________________________________________________________________________________________________________

//FUNCIONES  DE REALIZAR JUGADA ----------------------------------------------------------------------


coordenada_t obtenerCoordenadaDelMovimiento(coordenada_t posDelPersonaje, char opcion){
	coordenada_t posicionNueva;
	switch(opcion){
		case IZQUIERDA:
			posicionNueva.fila=posDelPersonaje.fila;
			posicionNueva.columna=posDelPersonaje.columna-MOVIMIENTO;
			break;
		case DERECHA:
			posicionNueva.fila=posDelPersonaje.fila;
			posicionNueva.columna=posDelPersonaje.columna+MOVIMIENTO;
			break;
		case ARRIBA:
			posicionNueva.columna=posDelPersonaje.columna;
			posicionNueva.fila=posDelPersonaje.fila-MOVIMIENTO;
			break;
		case ABAJO:
			posicionNueva.columna=posDelPersonaje.columna;
			posicionNueva.fila=posDelPersonaje.fila+MOVIMIENTO;
			break;
       
	}

	return posicionNueva;
}


bool EstaEnLaMatriz(coordenada_t posNueva){
	return ((0<=posNueva.fila && posNueva.fila<=19) && (0<=posNueva.columna && posNueva.columna<=19));
}


int obtenerIndicePersonajeActual(int id, personaje_t personajes[MAX_PERSONAJES], int tope){

	int i = 0;
	bool encontrado= false;
	while (!(encontrado) && i < tope){
		if (id == personajes[i].cuadrante_inicial){
			encontrado = true;
		}
		i++;
	}
	return i - 1;
}


bool moverPersonaje(int idPersonajeActual,personaje_t personajes[MAX_PERSONAJES],int tope_personajes,char opcion){
   bool estado = false;
   printf("----------------------ID PERSONAJE ACTUAL : %i\n", idPersonajeActual);
   int indicePersonaje = obtenerIndicePersonajeActual(idPersonajeActual, personajes, tope_personajes);
   printf("el indice actual es : %i\n", indicePersonaje);
   coordenada_t posNueva = obtenerCoordenadaDelMovimiento(personajes[indicePersonaje].posicion,opcion);
   printf("-------------la nueva coordenada--------\n");
   mostrarCoordenada(posNueva);

    if(EstaEnLaMatriz(posNueva)){
        personajes[indicePersonaje].posicion = posNueva; 
		estado = true;
    }
	personajes[indicePersonaje].movimientos --; 
	return estado;  
}


bool estaEnLasers(juego_t*  juego){
	
	int i=0;
	
    bool encontrado = false;
    int indicePersonaje = obtenerIndicePersonajeActual(juego->id_personaje_actual,juego->personajes,juego->tope_personajes);
    while(i<juego->tope_robots && encontrado==false){
        encontrado = buscarCoordenada(juego->robots[i].lasers, juego->robots[i].tope_lasers, juego->personajes[indicePersonaje].posicion);
        
        i++;   
    }
    return encontrado;
}


bool estaEnRobot(robot_t robots[MAX_ROBOTS],int tope_robots, personaje_t personaje){
    int i = 0;
    bool encontrado = false;
    while((i<tope_robots)&&(!encontrado)){
        if (comparararCoordenadas(robots[i].posicion,personaje.posicion)){
            encontrado = true;
        }
        i++;
    }

  return encontrado;
}


bool estaEnPinzas(coordenada_t pinzas[MAX_PINZAS], int tope_pinzas,personaje_t personaje){
     int i = 0;
    bool encontrado = false;
    while((i<tope_pinzas)&&(!encontrado)){
        if (comparararCoordenadas(pinzas[i],personaje.posicion)){
            encontrado = true;
        }
        i++;
    }
  return encontrado;
}


int obtenerCuadrante(coordenada_t coordenada){
    int cuadrante;
    if((coordenada.fila>=0)&& (coordenada.fila<=9)){
        if((coordenada.columna>=0)&&(coordenada.columna<=9)){
            cuadrante=  PRIMER_CUADRANTE;

        }else if((coordenada.columna>=10)&&(coordenada.columna<=19)){
            cuadrante=  CUARTO_CUADRANTE;
        }

    }else if((coordenada.fila>=10)&& (coordenada.fila<=19)){
        if((coordenada.columna>=0)&&(coordenada.columna<=9)){
            cuadrante=  TERCER_CUADRANTE;

        }else if((coordenada.columna>=10)&&(coordenada.columna<=19)){
            cuadrante=  SEGUNDO_CUADRANTE;
        }
    }
    return cuadrante;
}


void asignarCoordenadasVecinasAlRobot(coordenada_t posicionDelRobot,coordenada_t posicionesVecinas[MAX_COORDENADAS]){
        posicionesVecinas[0].fila = posicionDelRobot.fila-1;
        posicionesVecinas[0].columna = posicionDelRobot.columna;
        posicionesVecinas[1].fila = posicionDelRobot.fila;
        posicionesVecinas[1].columna = posicionDelRobot.columna+1;
        posicionesVecinas[2].fila = posicionDelRobot.fila+1;
        posicionesVecinas[2].columna = posicionDelRobot.columna;
        posicionesVecinas[3].fila = posicionDelRobot.fila;
        posicionesVecinas[3].columna = posicionDelRobot.columna-1;


        posicionesVecinas[4].fila = posicionesVecinas[0].fila;
        posicionesVecinas[4].columna = posicionesVecinas[3].columna;
        
        posicionesVecinas[5].fila = posicionesVecinas[0].fila;
        posicionesVecinas[5].columna = posicionesVecinas[1].columna;

        posicionesVecinas[6].fila = posicionesVecinas[2].fila;
        posicionesVecinas[6].columna = posicionesVecinas[1].columna;

        posicionesVecinas[7].fila = posicionesVecinas[2].fila;
        posicionesVecinas[7].columna = posicionesVecinas[3].columna;
}


int obtenerIndiceDelRobotActual(int id, robot_t robots[MAX_ROBOTS], int tope){
	int i = 0;
    int cuadrante;
	bool encontrado= false;
	while (!(encontrado) && i < tope ){
        cuadrante = obtenerCuadrante(robots[i].posicion);
		if (id == cuadrante){
            
			encontrado = true;
		}
		i++;
	}
    printf("------------------------CUADRANTE DEL ROBOT QUE ENCONTRÈ!-------%i", cuadrante);
    printf("\n-----------------------------ID : %i", id);
	return i - 1;
}


bool coordenadaEstaDentroDelTerreno(coordenada_t coordenada){
    return (coordenada.fila>=0 && coordenada.fila<=19 && coordenada.columna>=0 && coordenada.columna<=19);
}


coordenada_t obtenerCoordenadaDentroDelTerreno(coordenada_t posicionesVecinas[MAX_COORDENADAS]){
    int indiceAleatoria = rand()% 9;
    bool estaEnTerreno = false;
    while(!estaEnTerreno){
        estaEnTerreno = coordenadaEstaDentroDelTerreno(posicionesVecinas[indiceAleatoria]);
        if(!estaEnTerreno){
            indiceAleatoria = rand()%9;
        }
    }
    return posicionesVecinas[indiceAleatoria];
}


bool estaEnElPersonajeSiguiente(personaje_t personajes[MAX_PERSONAJES],int tope_personajes,int indicePersonaje){
    int i =0;
    bool seEncontro =false;
    personaje_t personajeActual = personajes[indicePersonaje];
    while(i<=tope_personajes && (!seEncontro)){
        if((i!= indicePersonaje)){
            if (comparararCoordenadas(personajeActual.posicion,personajes[i].posicion) && personajeActual.cuadrante_inicial +1 == personajes[i].cuadrante_inicial){
                seEncontro = true;
            }

        }
        i++;

    }
    return seEncontro;
}


bool estaEnSuperTraje(supertraje_t supertrajes[MAX_SUPERTRAJES], int tope_supertraje, personaje_t personaje){
    bool seEncontro = false;
    int i = 0;
    while(!seEncontro && i < tope_supertraje){
        if(comparararCoordenadas(personaje.posicion, supertrajes[i].posicion) && personaje.cuadrante_inicial == supertrajes[i].cuadrante){
            seEncontro = true;
            supertrajes[i].recolectado = true;
            //Para "eliminarlo" se asigna los negativos, ya que a la hora de mostrarlos hay una validaciòn el cual no muetra si està en negativo,
            //supertrajes[i].posicion.fila = -1;
            //supertrajes[i].posicion.columna = -1;
        }
        i++;
    }
    return seEncontro;
}


//____________________________________________________________________FIN _______________________________________________________________________________

//ROTACION ROBOTS--------------------------------------------------------------------------------------
void primeraRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2); 

    int j = 1;
    int k = 1;

    for (int i = 0;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila -j;
            lasersRotados[i].columna = posicion_del_robot.columna;
            j++;
            
        }else{
           
            lasersRotados[i].fila = posicion_del_robot.fila;
            lasersRotados[i].columna = posicion_del_robot.columna+k;
            k++;
            
        }
    }
}


void segundaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila -j;
            lasersRotados[i].columna = posicion_del_robot.columna+j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila+k;
            lasersRotados[i].columna = posicion_del_robot.columna+k;
            k++;   
        }
    }

}

void terceraRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
   
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila ;
            lasersRotados[i].columna = posicion_del_robot.columna+j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila+k;
            lasersRotados[i].columna = posicion_del_robot.columna;
            k++;   
        }
    }
    

}

void cuartaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila +j ;
            lasersRotados[i].columna = posicion_del_robot.columna+j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila+k;
            lasersRotados[i].columna = posicion_del_robot.columna-k;
            k++;   
        }
    }
    
}

void quintaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){

    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila +j ;
            lasersRotados[i].columna = posicion_del_robot.columna;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila;
            lasersRotados[i].columna = posicion_del_robot.columna-k;
            k++;   
        }
    }
   

}

void sextaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila +j;
            lasersRotados[i].columna = posicion_del_robot.columna-j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila-k;
            lasersRotados[i].columna = posicion_del_robot.columna-k;
            k++;   
        }
    }

}

void septimaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila ;
            lasersRotados[i].columna = posicion_del_robot.columna-j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila-k;
            lasersRotados[i].columna = posicion_del_robot.columna;
            k++;   
        }
    }
   

}

void octavaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila -j;
            lasersRotados[i].columna = posicion_del_robot.columna-j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila-k;
            lasersRotados[i].columna = posicion_del_robot.columna+k;
            k++;   
        }
    }
    

}


void obtenerLasersNuevosRotados(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS], int opcion){
   
    switch(opcion){
        case 1 : 
            primeraRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
        case 2 : 
            segundaRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
        case 3 :
            terceraRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
        case 4 : 
            cuartaRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
        case 5 : 
            quintaRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
        case 6 : 
            sextaRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
        case 7 :
            septimaRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
        case 8 : 
            octavaRotacion(posicion_del_robot,tope_lasers,lasersRotados);
            break;
    }

}



int reconocerTipoDeLaser(robot_t robot){
    coordenada_t vectorAux[MAX];
    primeraRotacion(robot.posicion,robot.tope_lasers,vectorAux);
    if (verificarCoordenadasIguales(robot.lasers, robot.tope_lasers, vectorAux)){
        return 1;
    }
    segundaRotacion(robot.posicion,robot.tope_lasers,vectorAux);
    if (verificarCoordenadasIguales(robot.lasers, robot.tope_lasers, vectorAux)){
        return 2;
    }
    terceraRotacion(robot.posicion, robot.tope_lasers, vectorAux);
    if(verificarCoordenadasIguales(robot.lasers,robot.tope_lasers, vectorAux)){
        return 3;
    }
    cuartaRotacion(robot.posicion,robot.tope_lasers,vectorAux);
    if (verificarCoordenadasIguales(robot.lasers, robot.tope_lasers, vectorAux)){
        return 4;
    }
    quintaRotacion(robot.posicion, robot.tope_lasers, vectorAux);
    if(verificarCoordenadasIguales(robot.lasers, robot.tope_lasers, vectorAux)){
        return 5;
    }
    sextaRotacion(robot.posicion,robot.tope_lasers,vectorAux);
    if (verificarCoordenadasIguales(robot.lasers, robot.tope_lasers, vectorAux)){
        return 6;
    }
    septimaRotacion(robot.posicion, robot.tope_lasers, vectorAux);
    if(verificarCoordenadasIguales(robot.lasers,robot.tope_lasers, vectorAux)){
        return 7;
    }
    octavaRotacion(robot.posicion,robot.tope_lasers,vectorAux);
    if (verificarCoordenadasIguales(robot.lasers, robot.tope_lasers, vectorAux)){
        return 8;
    }
    return -1;//verificar 

}



void asignarLaserRotados(coordenada_t lasers[MAX_LASERS], int tope, coordenada_t laserNuevo[MAX_LASERS]){
    for(int i = 0 ; i < tope; i++){
        lasers[i] = laserNuevo[i]; 
    }
}


void rotarRobots(robot_t robots[MAX], int topeRobots){
    int  tipoDeRotacion= 0;
    coordenada_t vectorNuevoLasers[MAX];
    for(int i = 0;i<topeRobots;i++){
        tipoDeRotacion = reconocerTipoDeLaser(robots[i]);
        obtenerLasersNuevosRotados(robots[i].posicion, robots[i].tope_lasers, vectorNuevoLasers, tipoDeRotacion%8+1);
        asignarLaserRotados(robots[i].lasers, robots[i].tope_lasers, vectorNuevoLasers);
    }

}


bool verificarCoordenadasIguales(coordenada_t coordenada1[MAX_COORDENADAS],int tope, coordenada_t coordenada2[MAX_COORDENADAS]){
    int i = 0;
    bool todosIguales = true;
    while(todosIguales && i < tope){
        if(!comparararCoordenadas(coordenada1[i], coordenada2[i])){
           
            todosIguales = false;
        }
        i++;
    }
    return todosIguales;
}