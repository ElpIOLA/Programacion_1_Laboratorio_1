#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "archivo.h"

int main()
{
    FILE*pArchivo=NULL;
    //FILE*pBackup;
    Persona* arrayPersona[LIMITE_PERSONA];

    archivo_leerPersona(arrayPersona,pArchivo,LIMITE_PERSONA);

    persona_listarArray(arrayPersona,LIMITE_PERSONA);

    return 0;
}

/*pArchivo=fopen("data.csv","r");
    pBackup=fopen("backup.csv","w");
    //char buffer[4096];
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferIsEmpty[1024];

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            // '^' significa todo menos y luego le indicas  lo que no queresque copie (en este caso la ',')
            // cuando queres que avance luego de agregarle lo que no queres que copie,
            // lo pones fuera de la mascara como abajo
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                   bufferNombre,
                   bufferApellido,
                   bufferIsEmpty);
            //fprintf(pBackup,"%s\n",buffer,
            printf("%s-%s-%s-%s\n",bufferId,
                    bufferNombre,
                    bufferApellido,
                    bufferIsEmpty);
        }

        fclose(pArchivo);
        fclose(pBackup);
    }
    else
    {
        printf("\nError. no existe");
    }*/
