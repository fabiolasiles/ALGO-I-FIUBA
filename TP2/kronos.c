#include "kronos.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ELASTIC_GIRL 'E'
#define VIOLETA 'V'
#define  DASH 'D'
#define MR_INCREIBLE 'I'
#define MOV_INICIALES_ELASTIC 25
#define MOV_PODER_ELASTIC 3
#define CUADRANTE_ELASTIC 1
#define MAX_ALTO 20 // nose si irian estos margenes ya que van a  ir cambiando constantemente.
#define MAX_ANCHO 20

#define MAX 30

#define MOV_INICIALES_VIOLETA 30
#define MOV_PODER_VIOLETA 0
#define CUADRANTE_VIOLETA 2

#define MOV_INICIALES_DASH 20
#define MOV_PODER_DASH 0
#define CUADRANTE_DASH 3

#define MOV_INICIALES_MR_INCREIBLE 15
#define MOV_PODER_MR_INCREIBLE 0
#define CUADRANTE_MR_INCREIBLE 4

#define PRIMER_CUADRANTE 1
#define SEGUNDO_CUADRANTE 2
#define TERCER_CUADRANTE 3
#define CUARTO_CUADRANTE 4

#define ABAJO_DERECHA 1
#define ARRIBA_IZQUIERDA 2
#define ARRIBA_DERECHA 3


#define LASERS_CONTRASENIA_ACERTADA 6
#define LASERS_CONTRASENIA_NO_ACERTADA 10


        
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


/*
 * Verifica que las coordenadas de los vectores no sean iguales en el caso, de que se repitan asigna una coordenada nueva.
 */

/*void  verificar_coordenadas_personajes(personaje_t personajes[MAX_PERSONAJES], int tope_personajes){
   
    printf("%i,=====el tope es  ==== \n", tope_personajes);
    for(int i=0;i<=tope_personajes;i++){
        printf("%i,%i\n",personajes[i].posicion.fila,personajes[i].posicion.columna);
        

    }
    printf("==========VECTOR==========\n");

    int i = 0;
    int k = 0;
    
    while (k<=tope_personajes-1){
        //printf("cambia de posicicon");
        
        while (i<tope_personajes){
        printf("(%i,%i) COMPARO LA COORDENADA CON (%i,%i)\n",personajes[k].posicion.fila,personajes[k].posicion.columna,personajes[i+1].posicion.fila,personajes[i+1].posicion.columna);
            while ((personajes[k].posicion.fila == personajes[i+1].posicion.fila)&&(personajes[k].posicion.columna == personajes[i+1].posicion.columna)){
                personajes[i+1].posicion = coordenada_aleatoria(20,20);
            }
            i++;
        }
        k=k+1;
        i=k;
        //i=k;
    }
}*/





/*
 * Inicializará el vector de los 4 personajes.
 */ 

void inicializar_personajes(personaje_t personajes[MAX_PERSONAJES],int* tope_personajes){
   (*tope_personajes) = 0; //revisar LOS CUADRANTES DE LOS PERSONAJES
    personajes[(*tope_personajes)] = crear_personaje(ELASTIC_GIRL,PRIMER_CUADRANTE);
    (*tope_personajes)++;
    
    personajes[(*tope_personajes)] = crear_personaje(VIOLETA,CUARTO_CUADRANTE);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(DASH,TERCER_CUADRANTE);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(MR_INCREIBLE,SEGUNDO_CUADRANTE);

}

/*
 * funcion que elige la forma que se llenara el laser
 

void cargar_tipo_laser_aleatorio(int forma_de_laser_aleatorio,int tope_lasers, coordenada_t posicion_del_robot, coordenada_t lasers[MAX_LASERS]){
    switch (forma_de_laser_aleatorio){
        int j=1;
        int k=1;
        ARRIBA_DERECHA:
            for (int i = 0;i<= robot.tope_lasers;i++){
                if (i<3){
                    lasers[i].fila=posicion_del_robot.fil -j;
                    lasers[i].colum=posicion_del_robot.col;
                    j++;
                }else{
                
                    lasers[i].colum =robot_posicion.col+k;
                    laser[i].fila =robot_posicion.fila;
                    k++;
                }
                
            }   

        ARRIBA_IZQUIERDA:
             for (int i = 0;i<= robot.tope_lasers;i++){
                robot.posicicon.fil -1;
                robot.posicicon.col-1;
                robot.posicion[i]=robot.posicion;
            }
        ABAJO_DERECHA:
             for (int i = 0;i<= robot.tope_lasers;i++){
                robot.posicicon.fil +1;
                robot.posicicon.col+1;
                robot.posicion[i]=robot.posicion;
            }
        default:
             for (int i = 0;i<= robot.tope_lasers;i++){
                robot.posicicon.fil +1;
                robot.posicicon.col-1;
                robot.posicion[i]=robot.posicion;
            }
    }

}*/

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
                    //lasers[i].fila = posicion_del_robot.fila -j;
                    //lasers[i].columna = posicion_del_robot.columna;
                    
                    //j++;
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna+j;
                    j++;
                }else{
                    //lasers[i].columna = posicion_del_robot.columna+k;
                    //lasers[i].fila = posicion_del_robot.fila;
                    //k++;
                    lasers[i].fila = posicion_del_robot.fila+k;
                    lasers[i].columna = posicion_del_robot.columna;
                    k++;
                }
                break;   
            case ARRIBA_IZQUIERDA:
                if (i<longitud_lasers){
                    //lasers[i].columna = posicion_del_robot.columna-k;
                    //lasers[i].fila = posicion_del_robot.fila;
                    //k++;
                    lasers[i].fila = posicion_del_robot.fila+j;
                    lasers[i].columna = posicion_del_robot.columna;
                    j++;
                    
                }else{
                    //lasers[i].fila=posicion_del_robot.fila-j;
                    //lasers[i].columna=posicion_del_robot.columna;
                    //j++;
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna-k;
                    k++;
                }
                break;
            case ABAJO_DERECHA:
                if (i<longitud_lasers){
                    //lasers[i].columna=posicion_del_robot.columna+k;
                    //lasers[i].fila =posicion_del_robot.fila;
                    //k++;
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna-j;
                    
                    j++;
                }else{
                    //lasers[i].columna =posicion_del_robot.columna;
                    //lasers[i].fila =posicion_del_robot.fila+j;
                    //j++;
                    lasers[i].fila = posicion_del_robot.fila-k;
                    lasers[i].columna = posicion_del_robot.columna;
                    k++;
                }
                break;
            default:
                if (i<longitud_lasers){
                    //lasers[i].columna =posicion_del_robot.columna;
                    //lasers[i].fila =posicion_del_robot.fila+j;
                    //j++;
                    lasers[i].fila = posicion_del_robot.fila-j;
                    lasers[i].columna = posicion_del_robot.columna;
                    j++;
                   
                }else{
                    //lasers[i].columna = posicion_del_robot.columna-k;
                    //lasers[i].fila = posicion_del_robot.fila;
                    //k++;
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna+k;
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
 * Inicializará cada uno de los robots,cargando la informacion correspondiente
 */

robot_t crear_robot(bool contrasenia_completa, int cuadrante){
    robot_t robot;
    robot.posicion = coordenada_aleatoria(cuadrante);
    if(contrasenia_completa){
        robot.tope_lasers = LASERS_CONTRASENIA_ACERTADA;
    }else{
        robot.tope_lasers = LASERS_CONTRASENIA_NO_ACERTADA;
    }

    llenar_lasers(robot.lasers,robot.tope_lasers,robot.posicion);
    return robot;
}


/*
 * Inicializará el vector de 4 robots.
 */ 

void inicializar_robots(robot_t robots[MAX_ROBOTS], bool contrasenia_completa, int* tope_robots){
    
    printf("SE INICIALIZARA EL ROBOT");

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



//validar coordenada me devuelve TRUE si encontrò ninguna coordena igual a la posicion del robot o a la de los laser
bool validar_coordenada(coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot,coordenada_t coordenada_aleatoria_personaje){
    bool encontrado = false;
    int i = -1;
        if (coordenada_aleatoria_personaje.fila == posicion_del_robot.fila && coordenada_aleatoria_personaje.columna==posicion_del_robot.columna){    
            encontrado = true;
            
        }else{
            while((!encontrado)&& (i<tope_lasers-1)){
                if((coordenada_aleatoria_personaje.fila == lasers[i+1].fila)&&(coordenada_aleatoria_personaje.columna == lasers[i+1].columna)){
                    encontrado = true;
                }
                i++;
            }
        }
        printf("******************************* NO  ES IGUAL************************************************ \n");

    return encontrado;
}

/*
* Asigna una coordenada valida a cada personaje.
*/
coordenada_t  obtener_posicion_personaje(coordenada_t lasers[MAX_LASERS],int tope_lasers,coordenada_t posicion_del_robot, int cuadrante){
        
        coordenada_t coordenada_aleatoria_personaje = coordenada_aleatoria(cuadrante);//recibir por parametro el cuadrante
       
        printf("LA COORDENADA DEL PERSONAJE ES (%i,%i)  \n",coordenada_aleatoria_personaje.fila,coordenada_aleatoria_personaje.columna);
        bool encontrado = false;
        while(!encontrado){
            
            if(validar_coordenada(lasers,tope_lasers,posicion_del_robot,coordenada_aleatoria_personaje)){
                //llamo de vuelta porque se encontrò nuevamente
                coordenada_aleatoria_personaje = coordenada_aleatoria(cuadrante);
                
            }else{
                
                encontrado = true;
                
            }

        }
        

    return coordenada_aleatoria_personaje;

}


/*
* Asignarle a cada personaje sus coordenadas en su correspondiente cuadrante.
*/

void asignar_posiciones_a_personajes(personaje_t personajes[MAX_PERSONAJES],int tope_personajes,robot_t robots[MAX_ROBOTS],int tope_robots){
    
    for(int i =0;i<=tope_personajes;i++){
        int cuadrante= i+1;

        personajes[i].posicion = obtener_posicion_personaje(robots[i].lasers, robots[i].tope_lasers,robots[i].posicion,cuadrante);
    }
    
}

//_______________________________________________________________________________________________________________________
//    ---------------------------INICIALIZACION supertrajes-------------------------


bool validar_coordenada_supertraje(coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot,coordenada_t posicion_del_personaje,coordenada_t coordenada_aleatoria_personaje){
    bool encontrado = false;
    int i = -1;
        if (coordenada_aleatoria_personaje.fila == posicion_del_robot.fila && coordenada_aleatoria_personaje.columna==posicion_del_robot.columna){    
            encontrado = true;
            
        }else if(coordenada_aleatoria_personaje.fila == posicion_del_personaje.fila && coordenada_aleatoria_personaje.columna==posicion_del_personaje.columna){    
            encontrado = true;

        }
        else{
            while((!encontrado)&& (i<tope_lasers-1)){
                if((coordenada_aleatoria_personaje.fila == lasers[i+1].fila)&&(coordenada_aleatoria_personaje.columna == lasers[i+1].columna)){
                    encontrado = true;
                }
                i++;
            }
        }
        printf("******************************* NO  ES IGUAL************************************************ \n");

    return encontrado;
}


coordenada_t obtener_posicion_supertrajes(coordenada_t lasers[MAX_LASERS],int tope_lasers,coordenada_t posicion_del_robot,int cuadrante,coordenada_t posicion_del_personaje){
    coordenada_t coordenada_aleatoria_personaje = coordenada_aleatoria(cuadrante);//recibir por parametro el cuadrante
       
        printf("LA COORDENADA DEL SUPERTRAJEES (%i,%i)  \n",coordenada_aleatoria_personaje.fila,coordenada_aleatoria_personaje.columna);
        bool encontrado = false;
        while(!encontrado){
            
            if(validar_coordenada_supertraje(lasers,tope_lasers,posicion_del_robot,posicion_del_personaje,coordenada_aleatoria_personaje)){
                //llamo de vuelta porque se encontrò nuevamente
                coordenada_aleatoria_personaje = coordenada_aleatoria(cuadrante);
                
            }else{
                
                encontrado = true;
                
            }

        }
        

    return coordenada_aleatoria_personaje;

}


void  asignar_posiciones_a_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES],int tope_supertraje,personaje_t personajes[MAX_PERSONAJES],int tope_personajes,robot_t robots[MAX_ROBOTS],int tope_robots){
    for(int i =0;i<=tope_supertraje;i++){
        int cuadrante= i+1;

        supertrajes[i].posicion = obtener_posicion_supertrajes(robots[i].lasers, robots[i].tope_lasers,robots[i].posicion,cuadrante, personajes[i].posicion);
    }

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
void incializar_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES],int* tope_supertraje){
    (*tope_supertraje)=0;
    
    int cuadrante = 1;
    for(int i = 0; i < 4; i++){
        supertrajes[i] = obtener_supertraje(cuadrante);
        cuadrante++;
        (*tope_supertraje)++;
    }
}



//_______________________________________________________________________________________________________________________
//    --------------------------------------------INICIALIZAR PINZAS-----------------------
 



bool validar_pos_en_cuadrante(coordenada_t pos_aleatoria_de_una_pinza,int cuadrante, coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot,coordenada_t posicion_del_personaje,coordenada_t posicion_del_supertraje){


    bool encontrado = false;
    int i = -1;
        if (pos_aleatoria_de_una_pinza.fila == posicion_del_robot.fila && pos_aleatoria_de_una_pinza.columna==posicion_del_robot.columna){    
            encontrado = true;
            
        }else if(pos_aleatoria_de_una_pinza.fila == posicion_del_personaje.fila && pos_aleatoria_de_una_pinza.columna==posicion_del_personaje.columna){    
            encontrado = true;

        }else if(pos_aleatoria_de_una_pinza.fila == posicion_del_supertraje.fila && pos_aleatoria_de_una_pinza.columna==posicion_del_supertraje.columna){    
            encontrado = true;

        }
        else{
            while((!encontrado)&& (i<tope_lasers-1)){
                if((pos_aleatoria_de_una_pinza.fila == lasers[i+1].fila)&&(pos_aleatoria_de_una_pinza.columna == lasers[i+1].columna)){
                    encontrado = true;
                }
                i++;
            }
        }
        printf("******************************* NO  ES IGUAL************************************************ \n");

    return encontrado;
}

/*

bool validar_pos_en_pinzas(coordenada_t pos_aleatoria_de_una_pinza,coordenada_t pinzas[MAX_PINZAS],int tope_pinzas){
    bool esta_en_pinzas= false;
    if ((tope_pinzas)== 0){
        esta_en_pinzas= false;
        
    }else{
        while(((tope_pinzas>=1))){
            if((pos_aleatoria_de_una_pinza.fila == pinzas[tope_pinzas-1].fila)&&(pos_aleatoria_de_una_pinza.columna == pinzas[tope_pinzas-1].columna)){
                esta_en_pinzas= true;
            }else{
                esta_en_pinzas= false;
            }
        }
        tope_pinzas--;
    }
    return esta_en_pinzas;
}*/

    /*}else if ((tope_pinzas)== 1){

        if((pos_aleatoria_de_una_pinza.fila == pinzas[0].fila)&&(pos_aleatoria_de_una_pinza.columna == pinzas[0].columna)){
            esta_en_pinzas= true;
        }else{
            esta_en_pinzas= false;
        }
    }else if((tope_pinzas)== 2){
        if((pos_aleatoria_de_una_pinza.fila == pinzas[1].fila)&&(pos_aleatoria_de_una_pinza.columna == pinzas[1].columna)){
            esta_en_pinzas= true;
        }else{
            esta_en_pinzas= false;
        }

    }else if((tope_pinzas)== 3){
        if((pos_aleatoria_de_una_pinza.fila == pinzas[3].fila)&&(pos_aleatoria_de_una_pinza.columna == pinzas[3].columna)){
            esta_en_pinzas= true;
        }else{
            esta_en_pinzas= false;
        }
    return esta_en_pinzas;

}*/

/* while((tope_pinzas)<= 1){
    if((pos_aleatoria_de_una_pinza.fila == pinzas[tope_pinzas-1].fila)&&(pos_aleatoria_de_una_pinza.columna == pinzas[tope_pinzas-1].columna)){
            esta_en_pinzas= true;
    }else{
            esta_en_pinzas= false;
    }
    tope_pinzas--;


}
*/



/*
 * funcion para asignar una coordenada valida al vector pinzas
 */

coordenada_t validar_coordenada_pinzas(coordenada_t pinzas[MAX_PINZAS],int tope_pinzas,int cuadrante, coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot,coordenada_t posicion_del_personaje,coordenada_t posicion_del_supertraje){
    //validar elementos_cuadrantes realiza la validacion de la coodenada aleatoria
    //con los elementos  de todos los elementos de un cuadrante
    //validar_pinzas   verifica que  el elemento de la coordenada_aleatoria no este en el vector de las pinzas en el caso que 
    //este pide nuevamente la coordenda y en el caso de que no se lo asigna al vector pinzas.
    
    coordenada_t pos_aleatoria_de_una_pinza = coordenada_aleatoria(cuadrante);
    bool es_valido = false;
    while(!(es_valido)){
        
        
        bool se_encontro_en_elementos_cuadrante=validar_pos_en_cuadrante(pos_aleatoria_de_una_pinza,cuadrante,lasers,tope_lasers,posicion_del_robot,posicion_del_personaje, posicion_del_supertraje);
        //bool se_encontro_en_vector_pinzas= validar_pos_en_pinzas(pos_aleatoria_de_una_pinza,pinzas,tope_pinzas);
        bool se_encontro_en_vector_pinzas = false;

        if((se_encontro_en_elementos_cuadrante ==false )&&(se_encontro_en_vector_pinzas ==false)){
            es_valido = true;
            
        }else{
            
            pos_aleatoria_de_una_pinza = coordenada_aleatoria(cuadrante);
        }
    }
    return pos_aleatoria_de_una_pinza;
    
}

void inicializar_pinzas(coordenada_t pinzas[MAX_PINZAS],int* tope_pinzas,robot_t robots[MAX_ROBOTS],int tope_robots,personaje_t personajes[MAX_PERSONAJES],int tope_personajes,supertraje_t supertrajes[MAX_SUPERTRAJES],int tope_supertrajes){
    //coordenada_t vector_pinzas[MAX_PINZAS];
    (*tope_pinzas) = 0;
    int i = 0; 
    while(i<16){
        if(i<4){ 
        
            pinzas[i]= validar_coordenada_pinzas(pinzas,(*tope_pinzas),PRIMER_CUADRANTE,robots[0].lasers,robots[0].tope_lasers,robots[0].posicion,personajes[0].posicion,supertrajes[0].posicion);//devuelve una coordenada valida
           
            
            (*tope_pinzas)=(*tope_pinzas)+1;
            i++;

        }else if(i<8){
            pinzas[i]= validar_coordenada_pinzas(pinzas,(*tope_pinzas),SEGUNDO_CUADRANTE,robots[1].lasers,robots[1].tope_lasers,robots[1].posicion,personajes[1].posicion,supertrajes[1].posicion);
            (*tope_pinzas)=(*tope_pinzas)+1;
            i++;

        }else if(i<12){
            pinzas[i]= validar_coordenada_pinzas(pinzas,(*tope_pinzas),TERCER_CUADRANTE,robots[2].lasers,robots[2].tope_lasers,robots[2].posicion,personajes[2].posicion,supertrajes[2].posicion);
            (*tope_pinzas)=(*tope_pinzas)+1;
            i++;

        }else if(i<16){
            pinzas[i]= validar_coordenada_pinzas(pinzas,(*tope_pinzas),CUARTO_CUADRANTE,robots[3].lasers,robots[3].tope_lasers,robots[3].posicion,personajes[3].posicion,supertrajes[3].posicion);
            (*tope_pinzas)=(*tope_pinzas)+1;
            i++;
        }

    }
}




//    -------------------------------------------------------------------------
//_______________________________________________________________________________________________________________________





/*
 * Inicializará el juego, cargando toda la información inicial de los robots, los supertrajes, el personaje, los lásers y las pinzas.
 * El campo id_personaje_actual comienza en 1.
 */ 
void inicializar_juego(juego_t* juego, bool contrasenia_completa){
    inicializar_robots(juego->robots,contrasenia_completa,&juego->tope_robots);
    mostrarRobots(juego->robots, juego->tope_robots);//(*juego).tope_robots lo estoy desreferenciando y entrando al campo es decir a su contenido
    inicializar_personajes(juego->personajes,&juego->tope_personajes);//QUITAR EL INICIALIZAR LA POSICION DE LOS PERSONAJES.PONERLO EN LAS PRECONDICIONES
    asignar_posiciones_a_personajes(juego->personajes,juego->tope_personajes,juego->robots,juego->tope_robots);
    incializar_supertrajes(juego->supertrajes,&juego->tope_supertraje);
    asignar_posiciones_a_supertrajes(juego->supertrajes,juego->tope_supertraje,juego->personajes,juego->tope_personajes,juego->robots,juego->tope_robots);
    //asignar_posiciones_a_personajes(juego->personajes,juego->tope_personajes,juego->robots,juego->tope_robots);
    inicializar_pinzas(juego->pinzas,&juego->tope_pinzas,juego->robots,juego->tope_robots,juego->personajes,juego->tope_personajes,juego->supertrajes,juego->tope_supertraje);
}