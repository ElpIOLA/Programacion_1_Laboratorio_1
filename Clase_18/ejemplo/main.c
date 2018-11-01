#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

void mostrar(Cliente* arrayPunterosCliente[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        printf("\nApellido: %s" ,arrayPunterosCliente[i]->apellido);
    }
}

int main()
{
    /*
    ﻿id,first_name,last_name,is_empty
    1,Eric,Knight,false
    */

    Cliente* arrayPunterosCliente[1024];
    int i;
    FILE* pArchivo = fopen("data.csv","r");
   // FILE* pArchivoBkp = fopen("dataBkp.csv","w");
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferIsEmpty [1024];

    if(pArchivo != NULL)
    {
        fscanf(pArchivo,"%s\n",bufferId);
        i=0;
        while(!feof(pArchivo))
        {
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",
                                    bufferId,
                                    bufferNombre,
                                    bufferApellido,
                                    bufferIsEmpty);
            //fprintf(pArchivoBkp,"%s\n",buffer);


            arrayPunterosCliente[i] = cliente_newConParametros(bufferId,
                                    bufferNombre,
                                    bufferApellido,
                                    bufferIsEmpty);
            i++;

        }
        fclose(pArchivo);
    //    fclose(pArchivoBkp);
    }
    else
    {
        printf("\nError no existe!!!");
    }

    mostrar(arrayPunterosCliente,i);


    return 0;
}












