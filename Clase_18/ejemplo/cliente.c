
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* cliente_new()
{
    Cliente* this;
    this=malloc(sizeof(Cliente));
    return this;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_newConParametros(char* idCliente,char* nombre,char* apellido,char*isEmpty)
{
    Cliente* this;
    this=cliente_new();
    int isEmptyInt;
    int idClienteInt = atoi(idCliente);
    if(strcmp(isEmpty, "true"))
        isEmptyInt = 1;
    else
        isEmptyInt = 0;

    if(
    !cliente_setIdCliente(this,idClienteInt)&&
    !cliente_setNombre(this,nombre)&&
    !cliente_setApellido(this,apellido)&&
    !cliente_setIsEmpty(this,isEmptyInt))
        return this;

    cliente_delete(this);
    return NULL;
}

int cliente_setIdCliente(Cliente* this,int idCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idCliente=idCliente;
        retorno=0;
    }
    return retorno;
}

int cliente_getIdCliente(Cliente* this,int* idCliente)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idCliente=this->idCliente;
        retorno=0;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_setApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int cliente_setIsEmpty(Cliente* this,int isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->isEmpty=isEmpty;
        retorno=0;
    }
    return retorno;
}

int cliente_getIsEmpty(Cliente* this,int* isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *isEmpty=this->isEmpty;
        retorno=0;
    }
    return retorno;
}

