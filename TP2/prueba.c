/*
 * Verifica que las coordenadas de los vectores no sean iguales en el caso, de que se repitan asigna una coordenada nueva.
 */
void  verificar_coordenadas_personajes(personaje_t personajes[MAX_PERSONAJES], int tope_personajes){
   
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
}




void cargar_vector_coordenadas(coordenada_t coordenadas[MAX_COORDENADAS],int alto_cuadrante,int ancho_cuadrante,int tope){
    for(int i= 0;i<tope;i++){
        vectores[i] = coordenada_aleatoria(alto_cuadrante,ancho_cuadrante);
    }
    verificar_coordenadas_personajes(coordenadas,alto_cuadrante,ancho_cuadrante,tope);


}

cargar_lasers(coordenada_t coordenada_inicial){
    //cargar posicion random                        
    switch (posicicon_random){
        1:
            cargar_lasers_derecha(coordenada_inicial);
        2: 
            cargar_lasers_izquerda(coordenada_inicial);
        3:
            cargar_lasers_arriba(coordenada_inicial);
        default:
            cargar_lasers_abajo(coordenada_inicial);

    }

}


void llenar_coordenadas_robots(int alto_cuadrante, int ancho_cuadrante){

    coordenada_t coordenada_inicial = coordenada_aleatoria(alto_cuadrante,ancho_cuadrante);
    cargar_lasers(coordenada_inicial);



    vectores[i] = coordenada_aleatoria(alto_cuadrante,ancho_cuadrante);

}