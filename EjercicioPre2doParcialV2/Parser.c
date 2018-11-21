#include "LinkedList.h"
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    Empleado* empleados;
    FILE* pArchivo=NULL;
    char string[500];
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
                empleados=Empleado_new();
                bufferId=strtok(string,",");
                bufferNombre=strtok(NULL,",");
                bufferHT=strtok(NULL,"\n");
                    transformar(bufferId,&auxId,bufferHT,&auxHT);
                    Empleado_setId(empleados,auxId);
                    Empleado_setNombre(empleados,bufferNombre);
                    Empleado_setHorasTrabajadas(empleados,auxHT);
                    ll_add(listaEmpleados,empleados);


            }
        }
        fclose(pArchivo);
        //ll_map(listaEmpleados,mostrarEmpleados);
    }

    return 1; // OK
}

void transformar(char* id, int* auxId, char* hT, int* auxHT)
{
    if(id != NULL && hT != NULL)
    {
        *auxId=atoi(id);
        *auxHT=atoi(hT);
    }

}
