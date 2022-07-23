/* 
Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una vez cargados los liste por pantalla

2 funciones:
    Cargar los nombres.
    Listar los nombres
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    /* -------------    PARA CARGAR UN NOMBRE   -------------
            char *Buff; //variable auxiliar 
            char *Nombre;

            Buff = (char *) malloc(100* sizeof(char));
            printf("Ingrese el nombre a cargar: \n");
            gets(Buff);

            Nombre = (char *) malloc((strlen(Buff) + 1) * sizeof(char));
            strcpy(Nombre,Buff);
    ----------------------------------------------------------*/

    char *Buff; //variable auxiliar 
    char *Nombres[5];

    Buff = (char*) malloc(100 * sizeof(char)); //Que pasaria si a la reserva la realizo dentro del Bucle
    for (int i = 0; i <  5; i++)
    {
        
        printf("Ingrese el Nombre que desea cargar:\n");
        gets(Buff);
        Nombres[i] = (char*) malloc(( strlen(Buff) + 1) * sizeof(char));    
        strcpy(Nombres[i],Buff);
    }
    
    for (int j = 0; j < 5; j++)
    {
        printf("\n");
        puts(Nombres[j]);
    }
    
    // No olvidarse de liverar la memoria de los punteros...
    free(Buff);
    return 0;
}