#ifndef __INTERFAZ_H__
#define __INTERFAZ_H__
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include "presentaciones.h"
#include "kronos.h"
#include "auxiliares.h"
#include "increidle.h"

#define INICIAR_JUEGO 1
#define SALIR 2
#define SARLIR_JUEGO 'M'
#define JUEGO_GANADO true
#define JUEGO_PERDIDO false
#define GANADO 1
#define PERDIDO -1
#define SIGUE_JUGANDO 0

/*
 * Visualiza el menu de opciones para mover el personaje,activar el poder, o salir del programa.
 */

void mostrarOpcionesDeJugada();


/*
 * Visualiza el menu para "iniciar" o "salir del juego".
 */
 
void mostrarPresentacion();


/*
 * Se obtiene una opcion que corresponde a  "iniciar" o "salir del juego".
 */
 
int obtenerOpcionPresentacion();


/*
 * Verifica que la opcion elegida sea "iniciar" o "salir del juego" de ser asi devuelve true
 * de lo contrario false.
 */
 
bool validarOpcionPresentacion(int opcion);


/*
 * Se obtiene una opcion que corresponde a mover el personaje,activar el poder, o salir del programa.
 */
 
char obtenerOpcionJugada();


/*
 * Verifica que la opcion elegida sea de las correspondientes a mover el personaje,activar el poder, o salir del programa.
 * De ser asi devuelve true, de lo contrario false.
 */
 
bool validarOpcionJugada(char opcion);


/*
 * Limpia la pantalla
 */
 
void limpiarPantalla();


/*
 * Visualiza el mensaje para informar el resultado del juego GANADO o PERDIDO.
 */
 
void mostrarMensajeDelJuego(bool estado);


/*
 * Inicializa el juego.
 */
 
void inicializar();



#endif /* __INTERFAZ_H__ */