#include "persona.h"
#include "LinkedList.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int nuevoId=0;

Persona* persona_new()
{
    Persona* this;
    this=malloc(sizeof(Persona));
    return this;
}

void persona_delete(Persona* this)
{
    free(this);
}

Persona* persona_newConParametros(int id,char* nombre,char* apellido,char* estado,int salario)
{
    Persona* this;
    this=persona_new();

    if(
    !persona_setId(this,id)&&
    !persona_setNombre(this,nombre)&&
    !persona_setApellido(this,apellido)&&
    !persona_setEstado(this,estado)&&
    !persona_setSalario(this,salario))
        return this;

    persona_delete(this);
    return NULL;
}

Persona* persona_newDesdeArchivoConParametros(char* id,char* nombre,char* apellido,char* estado,char* salario)
{
    Persona* this;
    this=persona_new();
    int auxId=atoi(id);
    int auxSalario=atoi(salario);

    if(
    !persona_setId(this,auxId)&&
    !persona_setNombre(this,nombre)&&
    !persona_setApellido(this,apellido)&&
    !persona_setEstado(this,estado)&&
    !persona_setSalario(this,auxSalario))
        return this;

    persona_delete(this);
    return NULL;
}

int persona_setId(Persona* this,int id)
{
    int retorno=-1;
    if(this != NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int persona_getId(Persona* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int persona_setNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int persona_getNombre(Persona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int persona_setApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int persona_getApellido(Persona* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int persona_setEstado(Persona* this,char* estado)
{
    int retorno=-1;
    if(this!=NULL && estado!=NULL)
    {
        strcpy(this->estado,estado);
        retorno=0;
    }
    return retorno;
}

int persona_getEstado(Persona* this,char* estado)
{
    int retorno=-1;
    if(this!=NULL && estado!=NULL)
    {
        strcpy(estado,this->estado);
        retorno=0;
    }
    return retorno;
}

int persona_setSalario(Persona* this,int salario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->salario=salario;
        retorno=0;
    }
    return retorno;
}

int persona_getSalario(Persona* this,int* salario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *salario=this->salario;
        retorno=0;
    }
    return retorno;
}

int persona_mostrarUno(void* pElement)
{
    int returnAux=-1;
    Persona* elemento;
    if(pElement != NULL)
    {

        elemento=(Persona*)pElement;
        printf("%5d -- %15s -- %15s -- %10s -- %8d\n",elemento->id,elemento->nombre,elemento->apellido,
                                                        elemento->estado, elemento->salario);
        returnAux=0;
    }
    return returnAux;
}

int persona_calcularId(void* pElement)
{
    int returnAux=-1;
    Persona* elemento;
    int auxIdElemento=0;
    if(pElement != NULL)
    {
        elemento=(Persona*)pElement;
        persona_getId(elemento,&auxIdElemento);

        if(auxIdElemento>=returnAux)
        {
            nuevoId=(auxIdElemento+1);
        }
        returnAux=0;
    }
    return returnAux;
}

int persona_addPersona(Persona* this)
{
    int retorno=-1;
    char auxNombre[50];
    char auxApellido[50];
    char auxEstado[15];
    int estado=0;
    int auxId=0;
    int auxSalario=0;

    if(this!= NULL)
    {
        auxId=nuevoId;
        printf("nuevo id: %d\n",nuevoId);
        getc(stdin);
        utn_setNombre("ingrese nombre de la persona: ",auxNombre,sizeof(auxNombre));
        utn_setNombre("ingrese apellido de la persona: ",auxApellido,sizeof(auxApellido));
        estado=utn_setMargenEntero("ingrese el estado (false:0 - true:1) : ",estado,0,1);
        if(estado==0)
        {
            strncpy(auxEstado,"false",sizeof(auxEstado));
        }
        else
        {
            strncpy(auxEstado,"true",sizeof(auxEstado));
        }
        auxSalario=utn_setEntero("ingrese salario: ",auxSalario);
        persona_setId(this,auxId);
        persona_setNombre(this,auxNombre);
        persona_setApellido(this,auxApellido);
        persona_setEstado(this,auxEstado);
        persona_setSalario(this,auxSalario);
        retorno=0;
    }
    return retorno;
}

int persona_editPersona(Persona* this)
{
    int retorno=-1;
    char auxNombre[50];
    char auxApellido[50];
    char auxEstado[15];
    int estado=0;
    int auxSalario=0;

    int opcion=0;
    char quedarse;

    if(this!= NULL)
    {
        do
        {
            opcion=utn_setMargenEntero(" modificar:\n 1. nombre\n 2. apellido\n 3. estado\n 4. salario\n opcion: ",opcion,1,4);
            switch(opcion)
            {
            case 1:
                utn_setNombre("ingrese nombre de la persona: ",auxNombre,sizeof(auxNombre));
                persona_setNombre(this,auxNombre);
                break;
            case 2:
                utn_setNombre("ingrese apellido de la persona: ",auxApellido,sizeof(auxApellido));
                persona_setApellido(this,auxApellido);
                break;
            case 3:
                estado=utn_setMargenEntero("ingrese el estado (false:0 - true:1) : ",estado,0,1);
                if(estado==0)
                {
                    strncpy(auxEstado,"false",sizeof(auxEstado));
                }
                else
                {
                    strncpy(auxEstado,"true",sizeof(auxEstado));
                }
                persona_setEstado(this,auxEstado);
                break;
            case 4:
                auxSalario=utn_setEntero("ingrese salario: ",auxSalario);
                persona_setSalario(this,auxSalario);
                break;
            default:
                printf(" esta opcion no existe.\n");
                break;
            }
            printf(" Desea seguir haciendo modificaciones a este empleado?('s' para quedarse): ");
            quedarse=getc(stdin);
        }while(quedarse=='s');
        retorno=0;
    }
    return retorno;
}

/*LinkedList* mostrarPorId(LinkedList* listaCompras, LinkedList* listaFiltrada)
{
    int id=0;
    if(listaCompras != NULL)
    {
        printf("elige un id como parametro de busqueda: ");
        scanf("%d",&id);
        listaFiltrada = ll_filterArgs(listaCompras,criterioParaLista,&id);
        ll_map(listaFiltrada,mostrarCompra);
    }
    return listaFiltrada;
}

int criterioParaLista(void* pElement, void* id)
{
    int* auxId=0;
    Persona* auxPersona=NULL;
    if(pElement != NULL)
    {
        auxId=(int*)id;
        auxPersona=(Persona*)pElement;
        if(auxPersona->id==*(auxId))
        {
            return 1;
        }
    }
    return 0;
}
*/
int Persona_sortComparacion(void* elementoUno, void* elementoDos)
{
    int retorno=-1;
    char nombre1[100];
    char nombre2[100];

    if(elementoUno != NULL && elementoDos != NULL)
    {
        persona_getNombre(elementoUno,nombre1);
        persona_getNombre(elementoDos,nombre2);

        if(strcmp(nombre1,nombre2)<0)
        {
            retorno=1;
        }
        else if(strcmp(nombre1,nombre2)>0)
        {
            retorno=-1;
        }
    }
    return retorno;
}

