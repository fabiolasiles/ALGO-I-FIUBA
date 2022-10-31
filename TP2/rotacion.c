void cargar_tipo_laser_aleatorio(int forma_de_laser_aleatorio,int tope_lasers,coordenada_t lasers[MAX_LASERS], coordenada_t posicion_del_robot){
    int j=1;
    int k=1;
    int longitud_lasers = (tope_lasers/2);
    for (int i = 0;i<tope_lasers;i++){
        switch(forma_de_laser_aleatorio){
            case 1://ARRIBA_DERECHA:
                if (i<longitud_lasers){
                   
                    lasers[i].fila = posicion_del_robot.fila+j;
                    lasers[i].columna = posicion_del_robot.columna;
                    j++;
                   

                }else{
                    
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna+k;
                    k++;
                    
                }
                break;
            case 2://
                if (i<longitud_lasers){

                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna+j;
                    j++;
                    

                    
                }else{
                    
                    lasers[i].fila = posicion_del_robot.fila+k;
                    lasers[i].columna = posicion_del_robot.columna;
                    k++;
                }
                break;
            case 3://ABAJO_DERECHA:
                if (i<longitud_lasers){
                   
                    lasers[i].fila = posicion_del_robot.fila+j;
                    lasers[i].columna = posicion_del_robot.columna;
                    j++;
                    
                }else{
                    
                    
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna-k;
                    k++;
                }
                break;
            case 4://
                if (i<longitud_lasers){
                    
                    
                    lasers[i].fila = posicion_del_robot.fila+j;
                    lasers[i].columna = posicion_del_robot.columna;
                    j++;
                    
                    
                }else{
                   
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna-k;
                    k++;
                }
                break;
            case 5://ABAJO_IZQUIERDA:
                if (i<longitud_lasers){//ABAJO_IZQUIERDA:
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna -j;
                    j++;
                   
                }else{
                    
                    lasers[i].fila =posicion_del_robot.fila-k;
                    lasers[i].columna =posicion_del_robot.columna; 
                    k++;
                break;
                }
            case 6://
                if (i<longitud_lasers){
                    
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna-j;
                    
                    j++;
                    
                }else{
                    lasers[i].fila = posicion_del_robot.fila-k;
                    lasers[i].columna = posicion_del_robot.columna;
                    k++;
                }
                break; 
            case 7://ARRIBA_IZQUIERDA:
                if (i<longitud_lasers){
                    
                    lasers[i].fila = posicion_del_robot.fila-j;
                    lasers[i].columna = posicion_del_robot.columna;
                    j++;
                   
                    
                }else{
                    
                   
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna+k;
                    k++;
                }
                break;
            case 8://
                if (i<longitud_lasers){
                    
                    lasers[i].fila = posicion_del_robot.fila-j;
                    lasers[i].columna = posicion_del_robot.columna;
                    j++;
                   
                    
                }else{
                    
                    lasers[i].fila = posicion_del_robot.fila;
                    lasers[i].columna = posicion_del_robot.columna+k;
                    k++;
                }
                break;
           
            
        
        }
            
    }

}