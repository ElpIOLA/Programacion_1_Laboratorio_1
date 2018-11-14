#include "LinkedList.h"
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    Empleado* empleados;
    FILE* pArchivo=NULL;
    char string[1024];
    char* bufferId;
    int auxId=0;
    char* bufferNombre;
    char* bufferHT;
    int auxHT=0;

    if(listaEmpleados != NULL && fileName != NULL)
    {
        pArchivo=fopen(fileName,"r");
        if(pArchivo != NULL)
        {
            fscanf(pArchivo,"%s\n",string);
            while(!feof(pArchivo))
            {
                 fscanf(pArchivo,"%s\n",string);
                 empleados=malloc(sizeof(Empleado));

                 bufferId=strtok(string,",");
                 bufferNombre=strtok(NULL,",");
                 bufferHT=strtok(NULL,"\n");
                 auxId=atoi(bufferId);
                 auxHT=atoi(bufferHT);
                 empleados->id=auxId;
                 strcpy(empleados->nombre,bufferNombre);
                 empleados->horasTrabajadas=auxHT;
                 ll_add(listaEmpleados,empleados);
                 printf("%5s--%15s--%5s\n",bufferId,bufferNombre,bufferHT);

            }
        }
        fclose(pArchivo);
    }

    return 1; // OK
}

