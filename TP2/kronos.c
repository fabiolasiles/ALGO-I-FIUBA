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


#define MOV_INICIALES_VIOLETA 30
#define MOV_PODER_VIOLETA 0
#define CUADRANTE_VIOLETA 2

#define MOV_INICIALES_DASH 20
#define MOV_PODER_DASH 0
#define CUADRANTE_DASH 3

#define MOV_INICIALES_MR_INCREIBLE 15
#define MOV_PODER_MR_INCREIBLE 0
#define CUADRANTE_MR_INCREIBLE 4


#define PRIMER_CUADRANTE_FIL 0
#define PRIMER_CUADRANTE_COL 9
#define SEGUNDO_CUADRANTE_FIL 10
#define SEGUNDO_CUADRANTE_COL 19
#define TERCER_CUADRANTE_FIL 0
#define TERCER_CUADRANTE_COL 9
#define CUARTO_CUADRANTE_FIL 10
#define CUARTO_CUADRANTE_COL 19

#define ABAJO_DERECHA 1
#define ARRIBA_IZQUIERDA 2
#define ARRIBA_DERECHA 3


#define LASERS_CONTRASENIA_ACERTADA 6
#define LASERS_CONTRASENIA_NO_ACERTADA 10


        
/*
 * Asignara una coordenada aleatoria  considerando los rangos (alto y ancho) que se les asignen.
 */

coordenada_t coordenada_aleatoria(int alto,int ancho){
    coordenada_t coordenada;
    coordenada.fila = rand()% alto;
    coordenada.columna = rand()% ancho;
    return coordenada;


}

/*
 * Inicializará cada uno de los personajes,cargando la informacion correspondiente a cada personaje.
 */ 
personaje_t crear_personaje(char nombre_personaje){
    personaje_t personaje;
    if (nombre_personaje == ELASTIC_GIRL){
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_ELASTIC;
        personaje.movimientos_con_poder = MOV_PODER_ELASTIC;
        personaje.cuadrante_inicial = CUADRANTE_ELASTIC;
        personaje.posicion = coordenada_aleatoria(MAX_ALTO,MAX_ANCHO);
    }else if (nombre_personaje == VIOLETA){
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_VIOLETA;
        personaje.movimientos_con_poder = MOV_PODER_VIOLETA;
        personaje.cuadrante_inicial = CUADRANTE_VIOLETA;
        personaje.posicion = coordenada_aleatoria(MAX_ALTO,MAX_ANCHO);
    }else if(nombre_personaje == DASH){
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_DASH;
        personaje.movimientos_con_poder = MOV_PODER_DASH;
        personaje.cuadrante_inicial = CUADRANTE_DASH;
        personaje.posicion = coordenada_aleatoria(MAX_ALTO,MAX_ANCHO);
    }else {
        personaje.poder_activado = false;
        personaje.tiene_supertraje = false;
        personaje.movimientos = MOV_INICIALES_MR_INCREIBLE;
        personaje.movimientos_con_poder = MOV_PODER_MR_INCREIBLE;
        personaje.cuadrante_inicial = CUADRANTE_MR_INCREIBLE;
        personaje.posicion = coordenada_aleatoria(MAX_ALTO,MAX_ANCHO);

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
   (*tope_personajes) = 0;
    personajes[(*tope_personajes)] = crear_personaje(ELASTIC_GIRL);
    (*tope_personajes)++;
    
    personajes[(*tope_personajes)] = crear_personaje(VIOLETA);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(DASH);
    (*tope_personajes)++;
    personajes[(*tope_personajes)] = crear_personaje(MR_INCREIBLE);
  
   //verificar_coordenadas_personajes(personajes,(*tope_personajes));


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
    for (int i = 0;i<tope_lasers;i++){
        switch(forma_de_laser_aleatorio){
            case ARRIBA_DERECHA:
                if (i<3){
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
                if (i<3){
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
                if (i<3){
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
                if (i<3){
                    lasers[i].columna =posicion_del_robot.columna;
                    lasers[i].fila =posicion_del_robot.fila+j;
                    j++;
                   
                }else{
                    lasers[i].columna = posicion_del_robot.columna;
                    lasers[i].fila = posicion_del_robot.fila-k;
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

   int forma_de_laser_aleatorio = 4;
   cargar_tipo_laser_aleatorio(forma_de_laser_aleatorio,tope_lasers,lasers,posicion_del_robot);

}


/*
 * Inicializará cada uno de los robots,cargando la informacion correspondiente
 */

robot_t crear_robot(bool contrasenia_completa, int CUADRANTE_FIL,int CUADRANTE_COL){
    robot_t robot;
    robot.posicion = coordenada_aleatoria(CUADRANTE_FIL,CUADRANTE_COL);
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
    robots[0] = crear_robot(contrasenia_completa,PRIMER_CUADRANTE_FIL,PRIMER_CUADRANTE_COL);
    (*tope_robots)++;
    
    robots[1] = crear_robot(contrasenia_completa,SEGUNDO_CUADRANTE_FIL,SEGUNDO_CUADRANTE_COL);
    (*tope_robots)++;
   
    robots[2] = crear_robot(contrasenia_completa,TERCER_CUADRANTE_FIL,TERCER_CUADRANTE_COL);
    (*tope_robots)++;
    robots[3] = crear_robot(contrasenia_completa,CUARTO_CUADRANTE_FIL,CUARTO_CUADRANTE_COL);
    (*tope_robots)++;

}




/*
 * Inicializará el juego, cargando toda la información inicial de los robots, los supertrajes, el personaje, los lásers y las pinzas.
 * El campo id_personaje_actual comienza en 1.
 */ 
void inicializar_juego(juego_t* juego, bool contrasenia_completa){

    inicializar_robots(juego->robots,contrasenia_completa,&juego->tope_robots);
    inicializar_personajes(juego->personajes,&juego->tope_personajes);
    
}

