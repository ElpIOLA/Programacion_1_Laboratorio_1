#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

Persona* persona_new(void)
{
    Persona* auxCliente=NULL;
    auxCliente= (Persona*)malloc(sizeof(Persona));

    return auxCliente;
}

Persona* persona_clienteForzado(char* nombre, char* apellido, int id)
{
    Persona* aux;
    aux=persona_new();
    if(aux!= NULL)
    {
        if(persona_setNombre(aux,nombre)==0 ||
           persona_setApellido(aux,apellido)==0 ||
           persona_setId(aux,id)==0)
           {
                persona_deletePersona(aux);
                aux=NULL;
           }
    }
    return aux;
}


int persona_setNombre(Persona* this, char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));//validar el tipo de variable
        return 1;
    }
    return 0;
}

int persona_getNombre(Persona* this,char* nombre)
{
    if(this != NULL && nombre != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        return 1;
    }
    return 0;
}

int persona_setApellido(Persona* this, char* apellido)
{
    if(this != NULL && apellido != NULL)//validar el tipo de variable
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        return 1;
    }
    return 0;
}

int persona_getApellido(Persona* this,char* apellido)
{
    if(this != NULL && apellido != NULL)
    {
        strncpy(apellido,this->apellido,sizeof(this->apellido));
        return 1;
    }
    return 0;
}


int persona_setId(Persona* this, int id)
{
    if(this != NULL && id>0)//validar el tipo de variable
    {
        this->id=id;
        return 1;
    }
    return 0;
}

int persona_GetId(Persona* this, int id)
{
    if(this != NULL)
    {
        id = this->id;
        return id;
    }
    return 0;
}

int persona_setIsEmpty(Persona* this, int isEmpty)
{
    if(this != NULL && isEmpty>0)//validar el tipo de variable
    {
        this->isEmpty=isEmpty;
        return 1;
    }
    return 0;
}

int persona_GetIsEmpty(Persona* this, int isEmpty)
{
    if(this != NULL)
    {
        isEmpty = this->isEmpty;
        return isEmpty;
    }
    return 0;
}

int persona_buscarLugarVacio(Persona* array[], int len)
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


int persona_init(Persona* array[],int len)
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

int persona_buscarPorId(Persona* array[], int len, int id)
{
    Persona* aux;
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


int persona_deletePersona(Persona* this)
{
    int retorno=0;
    if(this != NULL)
    {
        free((void*)this);
        retorno=1;
    }
    return retorno;
}

int persona_listarArray(Persona* array[], int len)
{
    int retorno=0;
    int i;
    int bufferId=0;
    char bufferNombre[1024];
    char bufferApellido[1024];
    int bufferIsEmpty=0;

    if(array != NULL && len>0)
    {
        printf(" id      nombre      apellido      estado\n");
        for(i=0;i<len;i++)
        {
            persona_GetId(array,bufferId);
            persona_getNombre(array,bufferNombre);
            persona_getApellido(array,bufferApellido);
            persona_GetIsEmpty(array,bufferIsEmpty);
            printf("%5d      %10s     %10s     %5d\n",bufferId,
                    bufferNombre,
                    bufferApellido,
                    bufferIsEmpty);
        }

    }
    return retorno;
}

Persona* persona_nuevoConParametros(Persona* arrayPersona, char* id, char* nombre, char* apellido, char* isEmpty)
{
    int auxBufferId=0;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    int auxBufferIsEmpty=0;
    char bufferIsEmpty[1024];

    arrayPersona=persona_new();
    auxBufferId=atoi(bufferId);
    auxBufferIsEmpty=atoi(bufferIsEmpty);
    persona_setNombre(arrayPersona,bufferNombre);
    persona_setApellido(arrayPersona,bufferApellido);
    persona_setId(arrayPersona,auxBufferId);
    persona_setIsEmpty(arrayPersona,auxBufferIsEmpty);

    return arrayPersona;
}
