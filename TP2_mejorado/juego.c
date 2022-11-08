#include "kronos.h"
#include "Interfaz.h"
#include "increidle.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*


void primeraRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2); 

    int j = 1;
    int k = 1;

    for (int i = 0;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila -j;
            lasersRotados[i].columna = posicion_del_robot.columna;
            j++;
            
        }else{
           
            lasersRotados[i].fila = posicion_del_robot.fila;
            lasersRotados[i].columna = posicion_del_robot.columna+k;
            k++;
            
        }
    }
}


void segundaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila -j;
            lasersRotados[i].columna = posicion_del_robot.columna+j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila+k;
            lasersRotados[i].columna = posicion_del_robot.columna+k;
            k++;   
        }
    }

}

void terceraRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
   
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila ;
            lasersRotados[i].columna = posicion_del_robot.columna+j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila+k;
            lasersRotados[i].columna = posicion_del_robot.columna;
            k++;   
        }
    }
    

}

void cuartaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila +j ;
            lasersRotados[i].columna = posicion_del_robot.columna+j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila+k;
            lasersRotados[i].columna = posicion_del_robot.columna-k;
            k++;   
        }
    }
    
}

void quintaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){

    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila +j ;
            lasersRotados[i].columna = posicion_del_robot.columna;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila;
            lasersRotados[i].columna = posicion_del_robot.columna-k;
            k++;   
        }
    }
   

}

void sextaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila +j;
            lasersRotados[i].columna = posicion_del_robot.columna-j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila-k;
            lasersRotados[i].columna = posicion_del_robot.columna-k;
            k++;   
        }
    }

}

void septimaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila ;
            lasersRotados[i].columna = posicion_del_robot.columna-j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila-k;
            lasersRotados[i].columna = posicion_del_robot.columna;
            k++;   
        }
    }
   

}

void octavaRotacion(coordenada_t posicion_del_robot,int tope_lasers,coordenada_t lasersRotados[MAX_COORDENADAS]){
    int longitud_lasers = (tope_lasers/2);
    int j = 1;
    int k = 1;
    for (int i = 0 ;i<tope_lasers;i++){    
        if (i<longitud_lasers){
            lasersRotados[i].fila = posicion_del_robot.fila -j;
            lasersRotados[i].columna = posicion_del_robot.columna-j;
            j++;
            
        }else{
            
            lasersRotados[i].fila = posicion_del_robot.fila-k;
            lasersRotados[i].columna = posicion_del_robot.columna+k;
            k++;   
        }
    }
    

}
*/


int main(){
    inicializar();


    return 0;

}
