#include<stdio.h>
#include<stdbool.h>

//_________________________________________C O N S T A N T E S _________________________________________________________//

#define MAX_NUMEROS 5
#define NUMERO_CORRECTO 95
#define NUMERO_MINIMO 1
#define NUMERO_MAXIMO 100

#define OPCION_CORRECTA_CODIGO_DE_MEDIA 'A'
#define OPCION_CORRECTA_MASCOTA_DE_LILO 'C'
#define OPCION_CORRECTA_TIGRE_DE_LA_PRINCESA 'C'

#define LETRA_CONTRASENIA_UNO 'K'
#define LETRA_CONTRASENIA_DOS 'R'
#define LETRA_CONTRASENIA_TRES 'O'
#define LETRA_CONTRASENIA_CUATRO 'N'
#define LETRA_CONTRASENIA_CINCO 'S'
#define LETRA_INCOGNITA 'X'


#define PRIMERA_OPCION 'A'
#define SEGUNDA_OPCION 'B'
#define TERCERA_OPCION 'C'
#define CUARTA_OPCION 'D'


//__________________________ F U N C I O N E S     Y    P R O C E D I M I E N T O S_____________________________________//




/*
 * PRE:-
 * POST: Funcion que determina si la opcion dada es alguna de las indicadas.
 */

bool validar_opcion_elegida(char opcion){
    return (opcion == PRIMERA_OPCION || opcion == SEGUNDA_OPCION || opcion == TERCERA_OPCION|| opcion == CUARTA_OPCION);
}


/*
 * PRE:-
 * POST: La funcion devuelve "true" si el numero ingresado esta entre el rango de NUMERO_MINIMO y NUMERO_MAXIMO, en caso contrario devuelve "false".
 */

bool validar_rango_rayo(int respuesta_cuatro){
    return(respuesta_cuatro>=NUMERO_MINIMO && respuesta_cuatro<=NUMERO_MAXIMO);
}


/*
 * PRE: -
 * POST:  Realiza la primera pregunta al usuario, hasta que sea  la respuesta sea una de las opciones presentadas.
 */

char pregunta_codigo_de_media(char* opcion_pregunta_uno){
    while (!validar_opcion_elegida((*opcion_pregunta_uno))){
        printf("¿Cuál es el código de emergencia utilizado en Monsters Inc.");
        printf("cuando uno de los personajes tiene una media humana pegada a su cuerpo?\n");
        printf(" (A) 3312\n");
        printf(" (B) 3317\n");
        printf(" (C) 2312\n");
        printf(" (D) 2031\n");
        scanf(" %c",opcion_pregunta_uno);
    }
    return (*opcion_pregunta_uno);
}


/*
 * PRE: -
 * POST:  Realiza la segunda pregunta al usuario, hasta que sea  la respuesta sea una de las opciones presentadas.
 */

char pregunta_mascota_de_lilo(char* opcion_pregunta_dos){
    while (!validar_opcion_elegida((*opcion_pregunta_dos))){
        printf("¿Cuál era el nombre del pez mascota de Lilo?\n");
        printf(" (A) Stich\n");
        printf(" (B) Pez\n");
        printf(" (C) Pato\n");
        printf(" (D) Aurelio\n");
        scanf(" %c",opcion_pregunta_dos);
    }
    return (*opcion_pregunta_dos);
}


/*
 * PRE: -
 * POST:  Realiza la cuarta pregunta al usuario, hasta que sea  la respuesta este entre el rango valido.
 */

int pregunta_numero_rayo(int* respuesta_cuatro){
    while (!validar_rango_rayo((*respuesta_cuatro))){
        printf("¿Qué número lleva el Rayo McQueen?\n");
        printf(" Por favor ingrese un numero del 1 al 100 inclusive\n");
        scanf("%i",respuesta_cuatro);
    }
    return (*respuesta_cuatro);
}


/*
 * PRE: -
 * POST:  Realiza la quinta pregunta al usuario, hasta que sea  la respuesta sea una de las opciones presentadas.
 */

char pregunta_tigre_de_la_princesa_jazmin(char* opcion_pregunta_tres){
    while (!validar_opcion_elegida((*opcion_pregunta_tres))){
        printf("¿Cómo se llama el tigre de la princesa Jazmín?\n");
        printf(" (A) Zafiro\n");
        printf(" (B) Abú\n");
        printf(" (C) Rajah\n");
        printf(" (D) Jafar\n");
        scanf(" %c",opcion_pregunta_tres);
    }
    return (*opcion_pregunta_tres);
}


/*
 *PRE:-
 *POST: Devuelve "true" si el numero ingresado es primo y "false" si no lo es.
 */

bool es_primo(int num){

    bool primo = true;
    for(int i = 2;i < num; i++){
        if (num % i == 0){
            primo = false;
        }
    }
    return (primo ==true && num != 1 && num !=0);
}


/*
 * PRE:-
 * POST: Funcion que determina si el numero esta dentro del rango indicado.
 */

bool verificar_rango(int numero){
    return(numero>= NUMERO_MINIMO && numero<=NUMERO_MAXIMO);
}


/*
 * PRE: Procedimiento que recibe un vector vacio de numeros enteros y su tope.
 * POST: Se almacenana en el vector cinco numeros pedidos, hasta que se encuentren dentro de un rango determinado, de caso 
 *      contrario vuelve a pedirse el numero.
 */

void cargar_numeros(int numeros[MAX_NUMEROS],int *tope_numeros){
    int numero;
    while ((*tope_numeros) < MAX_NUMEROS){
        printf("Por favor ingrese 5 numeros entre 1 y 100 \n");
        scanf("%i",&numero);
        if (verificar_rango(numero)){
            numeros[(*tope_numeros)]= numero;
            (*tope_numeros)++;
        }
    }
}


/*
 * PRE:-
 * POST: Funcion que verifica que todos los numeros del vector sean primos.
 */

bool verificar_son_primos(int numeros[MAX_NUMEROS],int tope_numeros){
    bool son_primos = true;
    int i = 0;

    while (i<tope_numeros && son_primos){
        
        if (!es_primo(numeros[i])){
            
            son_primos = false;
        }
        i++;

    }
    return son_primos;
}


/*
 * PRE:-
 * POST: Asigna la letra correspondiente de la contraseña  en el caso de que la respuesta sea la
 *     correcta de lo contrario muestra una "X".
 */

char comprobar_numero(int respuesta,char letra_contrasenia){
  char letra;
    if (respuesta == NUMERO_CORRECTO){
        letra = letra_contrasenia;    
    }else{
        letra = LETRA_INCOGNITA; 
    }
    return letra;
} 

/*
 *PRE:-
 *POST: Asigna la letra correspondiente de la contraseña  en el caso de que la respuesta sea la
 *     correcta de lo contrario muestra una "X".
 */

char comprobar_letra(char respuesta,char letra_correcta,char letra_contrasenia){
    char letra;
    if (respuesta == letra_correcta){
        letra = letra_contrasenia;    
    }else{
        letra = LETRA_INCOGNITA; 
    }
    return letra;

}


/*
 * PRE:-
 * POST: Asigna la letra correspondiente de la contraseña  en el caso de que la respuesta sea verdadera
 *     de lo contrario muestra una "X".
 */

char asignar_letra(bool respuesta_tres){
    char letra;
    if (respuesta_tres){
        letra = LETRA_CONTRASENIA_TRES;   
    }else{
        letra = LETRA_INCOGNITA; 
    }
    return letra;

}


/*
 * PRE: Recibe respuestas validadas a las  cinco preguntas hechas previamente.
 * POST: Compueba si las repuestas coinciden con las validas y muestra por pantalla todas las letras acertadas de la contraseña.
 */

void  comprobar_mostrar_respuestas(char respuesta_uno,char respuesta_dos,bool respuesta_tres,int respuesta_cuatro,char respuesta_cinco){
    
    char primer_letra_contrasenia = comprobar_letra(respuesta_uno,OPCION_CORRECTA_CODIGO_DE_MEDIA,LETRA_CONTRASENIA_UNO);
    char segunda_letra_contrasenia = comprobar_letra(respuesta_dos,OPCION_CORRECTA_MASCOTA_DE_LILO,LETRA_CONTRASENIA_DOS);
    char tercera_letra_contrasenia = asignar_letra(respuesta_tres);
    char sexta_letra_contrasenia = asignar_letra(respuesta_tres);
    char cuarta_letra_contrasenia = comprobar_numero(respuesta_cuatro,LETRA_CONTRASENIA_CUATRO);
    char quinta_letra_contrasenia = comprobar_letra(respuesta_cinco,OPCION_CORRECTA_TIGRE_DE_LA_PRINCESA,LETRA_CONTRASENIA_CINCO);
    
    printf("-%c%c%c%c%c%c-",primer_letra_contrasenia,segunda_letra_contrasenia,tercera_letra_contrasenia,cuarta_letra_contrasenia,sexta_letra_contrasenia,quinta_letra_contrasenia);
}


//____________________________________P R O G R A M A     P R I N C I P A L ____________________________________________//

int main(){

    char opcion_pregunta = 't';
    char opcion_pregunta_dos = 'c';
    char opcion_pregunta_cinco= 't';
    int respuesta_cuatro = 101;
    bool respuesta_tres;
    int numeros[MAX_NUMEROS];
    int tope_numeros = 0;
    char respuesta_uno,respuesta_dos,respuesta_cinco;

    respuesta_uno = pregunta_codigo_de_media(&opcion_pregunta);
    respuesta_dos = pregunta_mascota_de_lilo(&opcion_pregunta_dos);
    cargar_numeros(numeros,&tope_numeros);
    respuesta_tres = verificar_son_primos(numeros,tope_numeros);  
    respuesta_cuatro = pregunta_numero_rayo(&respuesta_cuatro);
    respuesta_cinco= pregunta_tigre_de_la_princesa_jazmin(&opcion_pregunta_cinco);

    comprobar_mostrar_respuestas(respuesta_uno,respuesta_dos,respuesta_tres,respuesta_cuatro,respuesta_cinco);
    return 0;
}