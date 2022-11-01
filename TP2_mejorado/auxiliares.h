#ifndef __AUXILIARES_H__
#define __AUXILIARES_H__

#define MAX_COORDENADAS 600
#define MAX 30

#include <stdbool.h>
#include "kronos.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONTRASENIA 6
#define CONTRASENIA "KRONOS"


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
#define MAX_COORDENNADAS 500

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

#define CUADRANTE_SALIDA 4

#define ABAJO_DERECHA 1
#define ARRIBA_IZQUIERDA 2
#define ARRIBA_DERECHA 3


#define LASERS_CONTRASENIA_ACERTADA 6
#define LASERS_CONTRASENIA_NO_ACERTADA 10


#define SALIDA_FILA 0
#define SALIDA_COLUMNA 19

#define SE_PIERDE -1
#define SE_GANA 1
#define SE_SIGUE_JUGANDO 0




/*
 * PRE: -
 * POST:  Verifica que se haya descubierto la contraseña de forma completa en el caso afirmativo devuelve true, sino false.
 */
bool validar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]);



//-----------------------------------------------------------ESTADOS DEL JUEGO--------------------------------------------------------------------------
bool seGanaElJuego(personaje_t personajes[MAX_PERSONAJES], int tope);

bool sePierdeElJuego(personaje_t personajes[MAX_PERSONAJES], int tope);


//-----------------------------------------------------------TERRENO--------------------------------------------------------------------------
void inicializar_matriz(char matriz[20][20], int fila, int col);

void llenarRobot(char matriz[20][20],int topeFil, int topeCol, coordenada_t coordenadas[], int topeCoord, coordenada_t robotCoord);

void llenar_personaje(char matriz[20][20],int topeFil, int topeCol,coordenada_t coordenada_personaje, int cuadranteInicial);

void mostrarTablero(char matriz[20][20], int topeFila, int topeCol);

void llenarSuperTraje(char matriz[20][20], supertraje_t supertraje);

void llenarPinza(char matriz[20][20], coordenada_t pinza);


//-----------------------------------------------------------PINZAS--------------------------------------------------------------------------
void asignarPosPinzas(coordenada_t pinzas[MAX_PINZAS], int* tope_pinzas, coordenada_t coordenadas[MAX], int* topeCoord);


//-----------------------------------------------------------SUPER TRAJES--------------------------------------------------------------------------
void asignarPosSuperTraje(supertraje_t superTrajes[MAX_SUPERTRAJES], int tope, coordenada_t coordenadas[MAX], int* topeCoord);

supertraje_t obtener_supertraje(int cuadrante);

void inicializar_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES],int* tope_supertraje);



//--------------------------------------------------------------PERSONAJES------------------------------------------------------------------------
void asignarPosPersonajes(personaje_t personajes[MAX_PERSONAJES], int tope, coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord);

personaje_t crear_personaje(char nombre_personaje,int cuadrante);

void inicializar_personajes(personaje_t personajes[MAX_PERSONAJES],int* tope_personajes);




//----------------------------------------------------------------ROBOTS-----------------------------------------------------------------------------

void inicializar_robots(robot_t robots[MAX_ROBOTS], bool contrasenia_completa, int* topeRobot);
void asignarPosRobots(robot_t robots[MAX_ROBOTS], int topeRobot, coordenada_t coordenadas[MAX_COORDENNADAS], int* topeCoord);



//--------------------------------------------------------------COORDENDADAS---------------------------------------------------------------------------
bool comparararCoordenadas(coordenada_t coordenada1, coordenada_t coordenada2);
bool buscarCoordenada(coordenada_t coordenadas[MAX_COORDENADAS], int topeCoord, coordenada_t coordenada);
coordenada_t obtenerCordeAleatoriaValida(coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord, int cuadrante);
coordenada_t coordenada_aleatoria(int cuadrante);

void asignarCoordenadas(coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord, coordenada_t coordenadasParaAsignar[MAX_LASERS], int topeLasers);



//--------------------------------------------------------------VISUALIZACIONES------------------------------------------------------------------------
void mostrarCoordenada(coordenada_t coordenada);

void mostrarCoordenadas(coordenada_t coordenadas[MAX], int tope);

void mostrarRobots(robot_t robots[MAX_ROBOTS], int topeRobot);



void cargar_tipo_laser_aleatorio(int forma_de_laser_aleatorio,int tope_lasers,coordenada_t lasers[MAX_LASERS], coordenada_t posicion_del_robot);
void llenar_lasers( coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot);
void inicializar_robots(robot_t robots[MAX_ROBOTS], bool contrasenia_completa, int* tope_robots);
robot_t crear_robot(bool contrasenia_completa, int cuadrante);

#endif /* __AUXILIARES_H__ */