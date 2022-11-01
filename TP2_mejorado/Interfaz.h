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
void mostrarOpcionesDeJugada();
void mostrarPresentacion();
int obtenerOpcionPresentacion();
bool validarOpcionPresentacion(int opcion);
char obtenerOpcionJugada();
bool validarOpcionJugada(char opcion);
void limpiarPantalla();
void mostrarMensajeDelJuego(bool estado);
void inicializar();



#endif /* __INTERFAZ_H__ */