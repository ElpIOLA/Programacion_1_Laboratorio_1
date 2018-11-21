#include "LinkedList.h"
#include "Compra.h"
#include "Parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser_parseCompras(char* fileName, LinkedList* lista)
{
    Compra* auxiliar;
    FILE* pArchivo=NULL;
    char string[500];
    char* nombreCliente;
    char* idProducto;
    char* precioUnitario;
    char* unidades;
    char* iva;
    int auxIdProducto;
    float auxPrecioUnitario;
    int auxUnidades;
    float auxIva;

    if(lista != NULL && fileName != NULL)
    {
        pArchivo=fopen(fileName,"r");
        if(pArchivo != NULL)
        {
            fscanf(pArchivo,"%s\n",string);
            while(!feof(pArchivo))
            {
                fscanf(pArchivo,"%s\n",string);
                auxiliar=Compra_new();
                nombreCliente=strtok(string,",");
                idProducto=strtok(NULL,",");
                precioUnitario=strtok(NULL,",");
                unidades=strtok(NULL,",");
                iva=strtok(NULL,"\n");
                if(!verificarInt(idProducto,&auxIdProducto,unidades,&auxUnidades) &&
                    !verificarFloat(precioUnitario,&auxPrecioUnitario,iva,&auxIva))
                {
                        Compra_setIdProducto(auxiliar,auxIdProducto);
                        Compra_setIva(auxiliar,auxIva);
                        Compra_setNombreCliente(auxiliar,nombreCliente);
                        Compra_setPrecioUnitario(auxiliar,auxPrecioUnitario);
                        Compra_setUnidades(auxiliar,auxUnidades);
                        Compra_setMontoTotal(auxiliar,0.0);
                        ll_add(lista,auxiliar);
                }
            }
        }
        fclose(pArchivo);
    }
    return 1; // OK
}

int verificarInt(char* idProducto,int* auxIdProducto,char* unidades,int* auxUnidades)
{
    int returnAux=-1;

    if(idProducto != NULL && unidades != NULL)
    {
        *auxIdProducto=atoi(idProducto);
        *auxUnidades=atoi(unidades);
        returnAux=0;
    }
    return returnAux;
}

int verificarFloat(char* precioUnitario,float* auxPrecioUnitario,char* iva,float* auxIva)
{
    int returnAux=-1;

    if(precioUnitario != NULL && iva != NULL)
    {
        *auxPrecioUnitario=atof(precioUnitario);
        *auxIva=atof(iva);
        returnAux=0;
    }
    return returnAux;
}
