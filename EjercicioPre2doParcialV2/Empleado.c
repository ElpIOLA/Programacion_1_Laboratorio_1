#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Empleado* this;
    this=Empleado_new();

    if(
        !Empleado_setId(this,id)&&
        !Empleado_setNombre(this,nombre)&&
        !Empleado_setHorasTrabajadas(this,horasTrabajadas)&&
        !Empleado_setSueldo(this,sueldo))
        return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int mostrarEmpleados(void* pElement)
{
    Empleado* elemento;
    if(pElement != NULL)
    {
        elemento=(Empleado*)pElement;
        printf("%5d--%15s--%5d--%5d\n",elemento->id,elemento->nombre,elemento->horasTrabajadas,elemento->sueldo);
    }
    return 0;
}

int em_calcularSueldo(void* p)
{
    Empleado* elemento;
    int horasTrabajadas;
    if(p != NULL)
    {
        elemento=(Empleado*)p;
        Empleado_getHorasTrabajadas(elemento,&horasTrabajadas);
        if(horasTrabajadas <= 120)
        {
            Empleado_setSueldo(elemento,180);
        }
        else if(horasTrabajadas > 120 && horasTrabajadas<= 160)
        {
            Empleado_setSueldo(elemento,240);
        }
        else if(horasTrabajadas > 160 && horasTrabajadas <= 240)
        {
            Empleado_setSueldo(elemento,350);
        }
    }
    return 0;
}
