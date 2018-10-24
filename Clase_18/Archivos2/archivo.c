#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"
#include "persona.h"

int archivo_leerPersona(void* arrayPersona, FILE* archivo, int len)
{
    Persona* auxArrayPersona=arrayPersona;
    int retorno=0;
    int auxBufferId=0;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    int auxBufferIsEmpty=0;
    char bufferIsEmpty[1024];

    archivo=fopen("data.csv","r");
    if(auxArrayPersona != NULL && archivo != NULL)
    {
        retorno=1;
        while(!feof(archivo))
        {
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                   bufferNombre,
                   bufferApellido,
                   bufferIsEmpty);

            auxBufferId=atoi(bufferId);
            auxBufferIsEmpty=atoi(bufferIsEmpty);
            persona_setNombre(auxArrayPersona,bufferNombre);
            persona_setApellido(auxArrayPersona,bufferApellido);
            persona_setId(auxArrayPersona,auxBufferId);
            persona_setIsEmpty(arrayPersona,auxBufferIsEmpty);
        }
        fclose(archivo);
    }
    else
    {
        printf("\nError. no existe");
    }

    return retorno;
}
