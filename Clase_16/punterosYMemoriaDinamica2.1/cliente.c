#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* cliente_new(void)
{
    Cliente* auxCliente=NULL;
    auxCliente= (Cliente*)malloc(sizeof(Cliente));

    return auxCliente;
}

Cliente* cliente_clienteForzado(char* nombre, char* apellido, int id)
{
    Cliente* aux;
    aux=cliente_new();
    if(aux!= NULL)
    {
        if(cliente_setNombre(aux,nombre)==0 ||
           cliente_setApellido(aux,apellido)==0 ||
           cliente_setId(aux,id)==0)
           {
                cliente_deleteCliente(aux);
                aux=NULL;
           }
    }
    return aux;
}


int cliente_setNombre(Cliente* this, char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));//validar el tipo de variable
        return 1;
    }
    return 0;
}

int cliente_getNombre(Cliente* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    if(this != NULL && apellido != NULL)//validar el tipo de variable
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        return 1;
    }
    return 0;
}

int cliente_getApellido(Cliente* this,char* apellido)
{
    if(this != NULL && apellido != NULL)
    {
        strncpy(apellido,this->apellido,sizeof(this->apellido));
        return 1;
    }
    return 0;
}


int cliente_setId(Cliente* this, int id)
{
    if(this != NULL && id>0)//validar el tipo de variable
    {
        this->id=id;
        return 1;
    }
    return 0;
}

int cliente_GetId(Cliente* this, int id)
{
    if(this != NULL)
    {
        id = this->id;
        return id;
    }
    return 0;
}

int cliente_buscarLugarVacio(Cliente* array[], int len)
{
    int retorno=-1;
    int i;

    if(array != NULL)
    {
        for(i=0; i<len; i++)
        {
            if(array[i] == NULL)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}


int cliente_init(Cliente* array[],int len)
{
    int retorno=-1;
    int i;

    if(array != NULL)
    {
        for(i=0; i<len; i++)
        {
            array[i]= NULL;
        }
    }
    return retorno;
}

int cliente_buscarPorId(Cliente* array[], int len, int id)
{
    Cliente* aux;
    int retorno=-1;
    int i;
    if(array != NULL && id>0 && id<len)
    {
        for(i=0;i<len; i++)
        {
            aux =array[i];
            if(aux->id==id)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}


int cliente_deleteCliente(Cliente* this)
{
    int retorno=0;
    if(this != NULL)
    {
        free((void*)this);
        retorno=1;
    }
    return retorno;
}
