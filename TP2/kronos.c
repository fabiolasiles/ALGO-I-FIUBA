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
 * Inicializará el juego, cargando toda la información inicial de los robots, los supertrajes, el personaje, los lásers y las pinzas.
 * El campo id_personaje_actual comienza en 1.
 */ 
void inicializar_juego(juego_t* juego, bool contrasenia_completa){
    inicializar_personajes(juego->personajes,&juego->tope_personajes);
    
}

