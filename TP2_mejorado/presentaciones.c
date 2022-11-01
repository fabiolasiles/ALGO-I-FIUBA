#include "presentaciones.h"

void mostrarJuegoGanado(){
    mostrar("JuegoGanado.txt");
}

void mostrarJuegoPerdido(){
    mostrar("juegoPerdido.txt");
}

void mostrar(char* nombre){
    FILE* archivo = fopen(nombre, "r");
    if(archivo == NULL){
        printf("Error en abrir el archivo\n");
    }else{
        char singleLine[150];
        while(!feof(archivo)){
            fgets(singleLine, 150, archivo);
            printf("%s", singleLine);
        }
    }
    fclose(archivo);

}

