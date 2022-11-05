#include "Interfaz.h"

void mostrarPresentacion(){
    printf("-------------------------------------------------------------BIENVENIDO AL JUEGO DEL TP2---------------------------------------------\n");
    printf("|----------OPCIONES--------|\n");
    printf("| 1. INICIAR EL JUEGO      |\n");
    printf("| 2. SALIR                 |\n");
    printf("| -------------------------|\n");
}

void mostrarOpcionesDeJugada(){
    printf("\n\n\n");
    printf("|---------OPCIONES------|\n");
    printf("| 1. (W) ARRIBA         |\n");
    printf("| 2. (S) ABAJO          |\n");
    printf("| 3. (A) IZQUIERDA      |\n");
    printf("| 4. (D) DERECHA        |\n");
    printf("| 5. (C) PODER          |\n");
    printf("| 6. (M) ARRUGAR        |\n");
    printf("| ----------------------|\n");
}

void limpiarPantalla(){
    system("clear");
}

int obtenerOpcionPresentacion(){
    int opcion = 0;
    bool opcionCorrecta = false;
    do
    {
        mostrarPresentacion();
        printf("\n\nINGRESE UNA OPCIÒN\n");
        scanf("%i", &opcion);
        if(validarOpcionPresentacion(opcion)){
            opcionCorrecta = true; 
        }else{
            printf("----------INGRESÓ UNA OPCIÓN INCORRECTA!----\n");
            sleep(2);
            
        }
        limpiarPantalla();

    } while (!opcionCorrecta);
    return opcion;

}

bool validarOpcionPresentacion(int opcion){
    return (opcion == 1 || opcion == 2);
}

bool validarOpcionJugada(char opcion){
    bool esCorrecto = false;
    if(toupper(opcion) == 'W' || toupper(opcion) == 'S' || toupper(opcion) == 'A' || toupper(opcion) == 'D' || toupper(opcion) == 'C' || toupper(opcion) == 'M') esCorrecto = true;
    return esCorrecto;
    // return (toupper(opcion) == 'W' || toupper(opcion) == 'S' || toupper(opcion) == 'A' || toupper(opcion) == 'D' || toupper(opcion) == 'C');
}

char obtenerOpcionJugada(){
    char opcion;
    bool opcionCorrecta = false;
    do
    {
        mostrarOpcionesDeJugada();
        printf("\n\nINGRESE UNA OPCIÒN DE JUEGO\n");
        scanf(" %c", &opcion);
        if(validarOpcionJugada(opcion)){
            opcionCorrecta = true; 
        }else{
            printf("----------INGRESÓ UNA OPCIÓN INCORRECTA!----\n");
            sleep(3);// espera de tiempo de 3 segundos
        }
        limpiarPantalla();

    } while (!opcionCorrecta);
    return opcion;
    
}

void mostrarMensajeDelJuego(bool estado){

    limpiarPantalla();
    if(estado == JUEGO_GANADO){
        mostrarJuegoGanado();
        
    }else if(estado == JUEGO_PERDIDO){
        mostrarJuegoPerdido();
    }

    printf("\n\n\n\n\n---> El juego se cerrará en 3 segundos! <----");
    sleep(3);
    limpiarPantalla();

}

void inicializar(){

    int opcionPresentacion = obtenerOpcionPresentacion();

    if(opcionPresentacion == INICIAR_JUEGO){

        juego_t juego;

        srand((unsigned)time(NULL));
        char contrasenia_adivinada[MAX_CONTRASENIA];
        adivinar_contrasenia(contrasenia_adivinada);
        bool contrasenia_completa = validar_contrasenia(contrasenia_adivinada);

        limpiarPantalla();
        inicializar_juego(&juego, contrasenia_completa);
        imprimir_terreno(juego);
        
        char opcionDeJugada = obtenerOpcionJugada();
        bool finDelJuego = false;
        //bool juegoGanado = false;
        while(!finDelJuego && toupper(opcionDeJugada) != SARLIR_JUEGO){

            realizar_jugada(&juego, opcionDeJugada);
            /*
            if(estado_juego(juego) == GANADO){
                // juegoGanado = JUEGO_GANADO;
                finDelJuego = true;
                mostrarMensajeDelJuego(JUEGO_GANADO);
            }else if(estado_juego(juego) == PERDIDO){
                finDelJuego = true;
                mostrarMensajeDelJuego(JUEGO_PERDIDO);
            }else{ //sigue en juego
                imprimir_terreno(juego);
                opcionDeJugada = obtenerOpcionJugada();

            }*/
            break;

        }

        if(toupper(opcionDeJugada) == SARLIR_JUEGO){
            limpiarPantalla();
            printf("------- LASTIMA QUE NO HAYAS QUERIDO SEGUIR JUGANDO, ESPERO VUELVAS PRONTO A INTENTARLO ;) -------\n");
            printf("Hasta pronto! ---> El juego se cerrará en 3 segundos!\n");
            sleep(3);
            limpiarPantalla();
        }

    }else if(opcionPresentacion == SALIR){
        limpiarPantalla();
        printf("----------------------ESPERMOS QUE VUELVAS PRONTO DECIDIDO PARA JUGAR----------------\n");
        printf("SE CERRARÁ EL PROGRAMA EN 3 SEGUDNOS\n");
        sleep(3);
        limpiarPantalla();
    }
}