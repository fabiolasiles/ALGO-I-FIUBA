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
#define MAX_ALTO 20 
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

#define MOVIMIENTO 1

#define DERECHA 'D'
#define IZQUIERDA 'A'
#define ABAJO 'S'
#define ARRIBA 'W' 

#define ERROR -1
#define EXITOSO 1




/*
 * Verifica que se haya descubierto la contraseña de forma completa en el caso afirmativo devuelve true, sino false.
 */
bool validar_contrasenia(char contrasenia_adivinada[MAX_CONTRASENIA]);


//-----------------------------------------------------------ESTADOS DEL JUEGO--------------------------------------------------------------------------


/*
 * Funcion que verifica que  el ultimo personaje se encuentra en la coordenada de salida, en tal caso devuelve true sino false.
 */

bool seGanaElJuego(personaje_t personajes[MAX_PERSONAJES], int tope);


/*
 * Funcion que verifica si el personaje tiene movimientos para jugar, en tal caso devuelve true sino false.
 */

bool sePierdeElJuego(personaje_t personajes[MAX_PERSONAJES], int tope);


//-----------------------------------------------------------TERRENO--------------------------------------------------------------------------


/*
 * Inicializa una  matriz  de 20x20  con "*" para simular el terreno donde se va a jugar.
 */

void inicializar_matriz(char matriz[20][20], int fila, int col);


/*
 * Llena la matriz con las posiciones correspondientes del robot y sus lasers, simbolizados por la letra "R"  y  "L" respectivamente.
 */

void llenarRobot(char matriz[20][20],int topeFil, int topeCol, coordenada_t coordenadas[], int topeCoord, coordenada_t robotCoord);


/*
 * Llena el la matriz con  las posiciones de cada personaje representadas por un 
 * caracter diferente(E,V,D,I).
 */

void llenar_personaje(char matriz[20][20],int topeFil, int topeCol,coordenada_t coordenada_personaje, int cuadranteInicial);


/*
 * Visualiza la  matriz que simboliza nuestro terreno, cargada con los elementos que posea (personaje,robots, lasers,supertraje y/o pinzas).
 */

void mostrarTablero(char matriz[20][20], int topeFila, int topeCol);


/*
 * Llena la matriz con las posiciones correspondientes al supertraje simbolizados por la letra "S".
 */
void llenarSuperTraje(char matriz[20][20], supertraje_t supertraje);


/*
 * Llena la matriz con las posiciones correspondientes a la pinza simbolizados por la letra "P".
 */

void llenarPinza(char matriz[20][20], coordenada_t pinza);


//-----------------------------------------------------------PINZAS--------------------------------------------------------------------------


/*
 * Asigna posiciones aleatorias a cada pinza verificando que no se repitan y en su cuadrante correspondiente, ademàs dichas posiciones seràn guardadas en el vector coordendadas.
 */

void asignarPosPinzas(coordenada_t pinzas[MAX_PINZAS], int* tope_pinzas, coordenada_t coordenadas[MAX], int* topeCoord);


//-----------------------------------------------------------SUPER TRAJES--------------------------------------------------------------------------


/*
 * Asigna posiciones aleatorias a cada supertraje verificando que no se repitan y en su cuadrante correspondiente, ademàs dichas posiciones seràn guardadas en el vector coordendadas.
 */

void asignarPosSuperTraje(supertraje_t superTrajes[MAX_SUPERTRAJES], int tope, coordenada_t coordenadas[MAX], int* topeCoord);


/*
 * Carga la informacion correspondiente a cada supertraje.
 */

supertraje_t obtener_supertraje(int cuadrante);


/*
 * Incializa  un vector de 4 supertrajes.
 */

void inicializar_supertrajes(supertraje_t supertrajes[MAX_SUPERTRAJES],int* tope_supertraje);


//--------------------------------------------------------------PERSONAJES------------------------------------------------------------------------


/*
 * Asigna una posición aleatoria a cada personaje sin repetirse y en su cuadrante correspondiente, además dichas posiciones serán guardadas en el vector coordenadas.
 */

void asignarPosPersonajes(personaje_t personajes[MAX_PERSONAJES], int tope, coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord);


/*
 * Inicializará cada uno de los personajes,cargando la informacion correspondiente a cada personaje.
 */ 

personaje_t crear_personaje(char nombre_personaje,int cuadrante);


/*
 * Inicializará el vector de  personajes con  4 personajes.
 */
void inicializar_personajes(personaje_t personajes[MAX_PERSONAJES],int* tope_personajes);


//----------------------------------------------------------------ROBOTS-----------------------------------------------------------------------------


/*
 * Inicializará el vector de 4 robots.
 */

void inicializar_robots(robot_t robots[MAX_ROBOTS], bool contrasenia_completa, int* tope_robots);


/*
 * Asigna posiciones aleatorias a cada robot verificando que no se repitan y en su cuadrante correspondiente, ademàs dichas posiciones seràn guardadas en el vector coordenadas.
 */

void asignarPosRobots(robot_t robots[MAX_ROBOTS], int topeRobot, coordenada_t coordenadas[MAX_COORDENNADAS], int* topeCoord);


/*
 * Inicializará cada uno de los robots,cargando la informacion correspondiente del tope segun se adivine la contraseña o no.
 */
 
robot_t crear_robot(bool contrasenia_completa, int cuadrante);


/*
 * Procedimiento que llenara los lasers del robot correspondiente a cada cuadrante.
 */ 

void llenar_lasers( coordenada_t lasers[MAX_LASERS], int tope_lasers,coordenada_t posicion_del_robot);


//--------------------------------------------------------------COORDENDADAS---------------------------------------------------------------------------


/*
 * Compara si dos coordenadas son iguales, de ser asi devuelve true, sino devuelve false
 */
bool comparararCoordenadas(coordenada_t coordenada1, coordenada_t coordenada2);


/*
 * Busca una coordenada dentro del vector de coordenadas, si la encuentra devuelve true, sino false.
 */

bool buscarCoordenada(coordenada_t coordenadas[MAX_COORDENADAS], int topeCoord, coordenada_t coordenada);


/*
 * Obtiene una coordenada aleatoria(respecto de su cuadrante) validando que no se repite con el vector de coordenadas, y a su vez asigna esa coordenada al vector.
 */

coordenada_t obtenerCordeAleatoriaValida(coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord, int cuadrante);


/*
 * Asignara una coordenada aleatoria valida dentro de los rangos del cuadrante dado.
 */

coordenada_t coordenada_aleatoria(int cuadrante);


/*
 * Asigna coordenadas de un vector hacia el otro.
 */

void asignarCoordenadas(coordenada_t coordenadas[MAX_COORDENADAS], int* topeCoord, coordenada_t coordenadasParaAsignar[MAX_LASERS], int topeLasers);


//--------------------------------------------------------------VISUALIZACIONES------------------------------------------------------------------------


/*
 * Visualiza  la fila y columna de una coordenada
 */

void mostrarCoordenada(coordenada_t coordenada);


/*
 * Visualiza un vector de coordenadas
 */

void mostrarCoordenadas(coordenada_t coordenadas[MAX], int tope);


/*
 * Visualiza la posicion del robot y sus lasers.
 */

void mostrarRobots(robot_t robots[MAX_ROBOTS], int topeRobot);


/*
 * Procedimiento que llenara el laser segun alguna de las 4 formas  de "L". 
 */

void cargar_tipo_laser_aleatorio(int forma_de_laser_aleatorio,int tope_lasers,coordenada_t lasers[MAX_LASERS], coordenada_t posicion_del_robot);


//--------------------------------------------------------------FUNCIONES REALIZAR JUGADA-----------------------------------------------------------------------


/*
 * Devuelve el cuadrante correspondiente a una coordenada dada.
 */

int obtenerCuadrante(coordenada_t coordenada);


/*
 * Se obtiene una posicion nueva de acuerdo a la opcion ingresada.
 */
coordenada_t obtenerCoordenadaDelMovimiento(coordenada_t posDelPersonaje, char opcion);


/*
 * Funcion que verifica que una posicion este dentro de la matriz de ser asi devuelve true,
 * sino false.
 */

bool EstaEnLaMatriz(coordenada_t posNueva);


/*
 * Busca el  id de un personaje  en el vector personajes y devuelve su posicion, se asume que la cantidad de personajes(tope) 
 * es mayor que cero y que siempre habra un personaje con el id valido.
 */

int obtenerIndicePersonajeActual(int id, personaje_t personajes[MAX_PERSONAJES], int tope);


/*
 * Moverá el personaje hacia la dirección que se ingreso.
 * Si se sale de la matriz se le resta un movimiento 
 * Si movio el personaje correctamente devuelve  true sino false
 */

bool moverPersonaje(int idPersonajeActual,personaje_t personajes[MAX_PERSONAJES],int tope_personajes,char opcion);


/* 
 * Verifica si el personaje esta en alguna posicion donde esten cualquiera de los lasers de ser asi
 * devuelve true sino false.
 */

bool estaEnLasers(juego_t* juego);


/* 
 * Verifica si el personaje esta en alguna posicion donde esten cualquiera de los robot de ser asi
 * devuelve true sino false.
 */

bool estaEnRobot(robot_t robots[MAX_ROBOTS],int tope_robots, personaje_t personaje);


/* 
 * Verifica si el personaje esta en alguna posicion donde este cualquier pinza de ser asi
 * devuelve true sino false.
 */

bool estaEnPinzas(coordenada_t pinzas[MAX_PINZAS],int tope_pinzas,personaje_t personaje);


/*
 * Busca la posicion del robot actual correspondiente al personaje con el  que se esta jugando.
 */

int obtenerIndiceDelRobotActual(int id, robot_t robots[MAX_ROBOTS], int tope);


/*
 * Verifica que la coordenada este dentro de la matriz
 */

bool coordenadaEstaDentroDelTerreno(coordenada_t coordenada);


/*
 * Obtiene posicion valida dentro del terreno, del vector de posiciones que rodean al robot.
 */

coordenada_t obtenerCoordenadaDentroDelTerreno(coordenada_t posicionesVecinas[MAX_COORDENADAS]);


/*
 * Verifica si el personaje actual llega a la posicion de otro personaje y es el siguiente
 * devuelva true, en caso contrario false.
 */

bool estaEnElPersonajeSiguiente(personaje_t personajes[MAX_PERSONAJES],int tope_personajes,int indicePersonaje);


/*
 * Carga un  vector con las 8 posiciones que rodean al robot. 
 */

void asignarCoordenadasVecinasAlRobot(coordenada_t posicionDelRobot,coordenada_t posicionesVecinas[MAX_COORDENADAS]);


#endif /* __AUXILIARES_H__ */