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

void mostrarRobots(robot_t robots[MAX_ROBOTS], int topeRobot){
    for(int i = 0 ; i < topeRobot; i++){
        printf("---------Posiciòn del Robot : ---------\n");
        mostrarCoordenada(robots[i].posicion);
        printf("--------Posiciones de sus Lasers : -----------\n");
        mostrarCoordenadas(robots[i].lasers, robots[i].tope_lasers);


    }
    
}

bool validar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]){
    return (strcmp(contrasenia_adivinada,CONTRASENIA)==0);
}



//_______________________________________________________________________________________________________________________


//-------------------------------------------- -------------------------FUNCIONES SOBRE ESTADOS DEL JUEGO----------------------------------------------------------------------------------

bool seGanaElJuego(personaje_t personajes[MAX_PERSONAJES], int tope){

    coordenada_t coordSalida;
    coordSalida.fila = SALIDA_FILA;
    coordSalida.columna = SALIDA_COLUMNA;

    int pos = 0;
    bool seGana = false;
    while(!seGana){
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
    while(!sePierde){
        if(personajes[pos].movimientos == 0) sePierde = true; // para consultar, solo aplica a los movimientos y no movimientos con poder ?
        pos++;
    }
    return sePierde;
}


//_________________________________________________________________________________FIN__________________________________________________________________________







//-------------------------------------------- -------------------------FUNCIONES SOBRE PINZAS----------------------------------------------------------------------------------


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

    printf("--------------------------------------------------------------PINZAS---------------------------------------\n");
    mostrarCoordenadas(pinzas, *tope_pinzas);
    printf("------------------------------------------------------------------------------------------------------------\n");
}




//_________________________________________________________________________________FIN__________________________________________________________________________







//-------------------------------------------- -------------------------FUNCIONES SOBRE SUPER TRAJES----------------------------------------------------------------------------------




//Asigno 
void asignarPosSuperTraje(supertraje_t superTrajes[MAX_SUPERTRAJES], int tope, coordenada_t coordenadas[MAX_COORDENNADAS], int* topeCoord){
    int cuadrante  = 1;
    printf("--------------------------------------------TOPE DEL SUPER TRAJE\n");
    printf("%i", tope);
    printf("----------------------------SUPER TRAJES-----------------");
    for(int i = 0; i < tope; i++){
        superTrajes[i].posicion = obtenerCordeAleatoriaValida(coordenadas, topeCoord, cuadrante);
        cuadrante++;
        
        mostrarCoordenada(superTrajes[i].posicion);
    }
    printf("---------------------------------------------------------");
}



/*
 * procedimiento que llena los supertrajes
 */



supertraje_t obtener_supertraje(int cuadrante){
    supertraje_t supertraje;
    if(cuadrante == PRIMER_CUADRANTE){
        supertraje.cuadrante = PRIMER_CUADRANTE;
        supertraje.recolectado = false;
        supertraje.usado = false;
    }else if (cuadrante == SEGUNDO_CUADRANTE){
        supertraje.cuadrante = SEGUNDO_CUADRANTE;
        supertraje.recolectado = false;
        supertraje.usado = false;
    }else if(cuadrante == TERCER_CUADRANTE){
        supertraje.cuadrante = TERCER_CUADRANTE;
        supertraje.recolectado = false;
        supertraje.usado = false;
    }else if(cuadrante == CUARTO_CUADRANTE){
        supertraje.cuadrante = CUARTO_CUADRANTE;
        supertraje.recolectado = false;
        supertraje.usado = false;
    }
    return supertraje;

}






/*
*fucion que incializa  un vector de 4 supertrajes.
*/
void inicializar_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES], int* tope_supertraje){
    (*tope_supertraje)=0;
    
    int cuadrante = 1;
    for(int i = 0; i < 4; i++){
        supertrajes[i] = obtener_supertraje(cuadrante);
        cuadrante++;
        (*tope_supertraje)++;
    }
}






//_________________________________________________________________________________FIN__________________________________________________________________________








//-------------------------------------------- -------------------------FUNCIONES SOBRE COORDENADAS----------------------------------------------------------------------------------
//Devuelve true si dos coordenadas son iguales, sino devuelve false
bool comparararCoordenadas(coordenada_t coordenada1, coordenada_t coordenada2){
    return (coordenada1.fila == coordenada2.fila && coordenada1.columna == coordenada2.columna);
}


//Retorna true si encontro la coordenada dentro del vector de coordenadas, caso contrario devuelve false
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

//Obtengo una coordenada aleatoria(respecto de su cuadrante) validado(que no se repita con el vector de coordenadas) y a su vez asigna dicha coord en las coordenadas
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
    //asigno la coordenada vàlida a las coordenadas y incremento el tope
    coordenadas[*topeCoord] = coordenadaAleatoria;
    *topeCoord = *topeCoord + 1;

    return coordenadaAleatoria;

}

/*
 * Asignara una coordenada aleatoria  considerando los rangos (alto y ancho) que se les asignen.
 */

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

//asigna los elementos del 2do vector al primero
void asignarCoordenadas(coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord, coordenada_t coordenadasParaAsignar[MAX_LASERS], int topeLasers){ //max_lasers podrìa ser uno genèrico
    //Un detalle:puedo en este caso tener coordenadas iguales, xq puede haber laser que se chocan, podrìamos pasar las coordendas sin repetir duda...
    for(int i = 0; i < topeLasers; i++){
        coordenadas[*topeCoord] = coordenadasParaAsignar[i];
        *topeCoord = *topeCoord + 1;
    }
    

}
//_________________________________________________________________________________FIN__________________________________________________________________________













//---------------------------------------------------------------------FUNCIONES SOBRE ROBOTS------------------------------------------------------------------

/*
 * funcion que elige la forma que se llenara el laser
 */

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





/*
 * Procedimiento que llenara los lasers del robot correspondiente a cada cuadrante.
 */ 

void llenar_lasers( coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot){

   int forma_de_laser_aleatorio = rand() % 4 + 1;
   cargar_tipo_laser_aleatorio(forma_de_laser_aleatorio,tope_lasers,lasers,posicion_del_robot);

}


/*
 * Inicializará el vector de 4 robots.
 */ 

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


/*
 * Inicializará cada uno de los robots,cargando la informacion correspondiente
 */

robot_t crear_robot(bool contrasenia_completa, int cuadrante){
    robot_t robot;
    //robot.posicion = coordenada_aleatoria(cuadrante);
    if(contrasenia_completa){
        robot.tope_lasers = LASERS_CONTRASENIA_ACERTADA;
    }else{
        robot.tope_lasers = LASERS_CONTRASENIA_NO_ACERTADA;
    }

    //llenar_lasers(robot.lasers,robot.tope_lasers,robot.posicion);
    return robot;
}

//Asigno cada posiciòn aleatorio a cada robot sin repetirse y en su cuadrante correspondiente, ademàs dichas posiciones seràn guardaddas en el vector coorendadas
void asignarPosRobots(robot_t robots[MAX_ROBOTS], int tope, coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord){
    int cuadrante = 1;
    for(int i = 0; i <= tope; i++){
        robots[i].posicion = obtenerCordeAleatoriaValida(coordenadas,topeCoord, cuadrante);
        llenar_lasers(robots[i].lasers, robots[i].tope_lasers, robots[i].posicion);
        //asignamos el vector laser al vector coordenada
        asignarCoordenadas(coordenadas, topeCoord, robots[i].lasers, robots[i].tope_lasers);
        cuadrante++;
    }

}






//_________________________________________________________________________________FIN__________________________________________________________________________








//--------------------------------------------------- -----------------FUNCIONES SOBRE PERSONAJES--------------------------------------------------------------

//asigna cada posición aleatoria a cada personaje sin repetirse y en su cuadrante correspondiente, además dichas posiciones serán guardadas en el vector coordenadas
void asignarPosPersonajes(personaje_t personajes[MAX_PERSONAJES], int tope, coordenada_t coordenadas[MAX_COORDENNADAS], int* topeCoord){
    int cuadrante = 1;
    for(int i = 0; i <= tope; i++){
        personajes[i].posicion = obtenerCordeAleatoriaValida(coordenadas,topeCoord, cuadrante);
        cuadrante++;
    }
}


/*
 * Inicializará cada uno de los personajes,cargando la informacion correspondiente a cada personaje.
 */ 

personaje_t crear_personaje(char nombre_personaje,int cuadrante){
    personaje_t personaje;
    if (nombre_personaje == ELASTIC_GIRL){

        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_ELASTIC;
        personaje.movimientos_con_poder = MOV_PODER_ELASTIC;
        personaje.cuadrante_inicial = CUADRANTE_ELASTIC;
        //personaje.posicion = coordenada_aleatoria(cuadrante);


    }else if (nombre_personaje == VIOLETA){
        
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_VIOLETA;
        personaje.movimientos_con_poder = MOV_PODER_VIOLETA;
        personaje.cuadrante_inicial = CUADRANTE_VIOLETA;
        //personaje.posicion = coordenada_aleatoria(cuadrante);
    }else if(nombre_personaje == DASH){

        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_DASH;
        personaje.movimientos_con_poder = MOV_PODER_DASH;
        personaje.cuadrante_inicial = CUADRANTE_DASH;
        //personaje.posicion = coordenada_aleatoria(cuadrante);
    }else {
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_MR_INCREIBLE;
        personaje.movimientos_con_poder = MOV_PODER_MR_INCREIBLE;
        personaje.cuadrante_inicial = CUADRANTE_MR_INCREIBLE;
        //personaje.posicion = coordenada_aleatoria(cuadrante);//REVISAR LOS CUADRANTESDE LOS PERSONJES 

    }
    return personaje;
}



void inicializar_personajes(personaje_t personajes[MAX_PERSONAJES],int* tope_personajes){
   (*tope_personajes) = 0; //revisar LOS CUADRANTES DE LOS PERSONAJES
    personajes[(*tope_personajes)] = crear_personaje(ELASTIC_GIRL,PRIMER_CUADRANTE);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(MR_INCREIBLE,SEGUNDO_CUADRANTE);
    (*tope_personajes)++;
    
    personajes[(*tope_personajes)] = crear_personaje(DASH,TERCER_CUADRANTE);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(VIOLETA,CUARTO_CUADRANTE);
    (*tope_personajes)++;
    

}


//-----------------------------------------------------------------------------------------FIN PERSONAJES ------------------------------------------------------------------------
//_______________________________________________________________________________________________________________________





//-----------------------------------------------------------------------------------------MOSTRAR TERRENO-----------------------------------------------------------------------
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
           if (matriz[coordenadas[i].fila][coordenadas[i].columna] != 'R'){ //VERIFICAR SI ES EL IF  QUE ME FALTABA
                matriz[coordenadas[i].fila][coordenadas[i].columna] = 'L';
           }
        }
    }
    matriz[robotCoord.fila][robotCoord.columna] = 'R'; //VER VARIABLES CAMBIARLAS
}

void llenar_personaje(char matriz[20][20],int topeFil, int topeCol,coordenada_t coordenada_personaje, int cuadranteInicial){
    //matriz[coordenada_personaje.fila][coordenada_personaje.columna] = 'P';
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
    matriz[supertraje.posicion.fila][supertraje.posicion.columna] = 'T';
}

void llenarPinza(char matriz[20][20], coordenada_t pinza){
    matriz[pinza.fila][pinza.columna] = 'P';
}

//___________________________________________________________________________FIN MOSTRAR TERRENO_______________________________________________________________________________

//----------------------------------------------------------------------------------------- FUNCIONES REALIZAR JUGADA ----------------------------------------------------------------------

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

/*
 * Funcion que verifica que el moviento realizado esta o no dentro de la matriz.
 */

bool EstaEnLaMatriz(coordenada_t posNueva){
	return ((0<=posNueva.fila && posNueva.fila<=19) && (0<=posNueva.columna && posNueva.columna<=19));
}

/*
 * Busca el  id de un personaje  en el vector personajes y devuelve su posicion se asume que la cantidad de personajes(tope) 
 * es mayor que cero y que siempre habra un personaje con el id valido.
 */
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



/*
 * Moverá el personaje hacia la dirección que se ingreso.
 * Si se sale de la matriz se le resta un movimiento 
 * Si movio el personaje correctamente devuelve  true sino false
 */
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







/* 
 * Verifica si el personaje esta en alguna posicion donde esten cualquiera de los lasers.
 */


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


/* 
 * Verifica si el personaje esta en alguna posicion donde esten cualquiera de los robot.
 */

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

/* 
 * Verifica si el personaje esta en alguna posicion donde este cualquiera pinza.
 */

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


/*
 * Busca la posicion del robot actual correspondiente al personaje con el  que se esta jugando.
 */
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




//___________________________________________________________________________FIN _______________________________________________________________________________