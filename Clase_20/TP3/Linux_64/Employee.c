#include "Employee.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* this;
    this=Employee_new();

    if(
        !Employee_setId(this,id)&&
        !Employee_setNombre(this,nombre)&&
        !Employee_setHorasTrabajadas(this,horasTrabajadas)&&
        !Employee_setSueldo(this,sueldo))
        return this;

    Employee_delete(this);
    return NULL;
}

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_addDesdeLinkedList(Employee* this, int nuevoId)
{
    int retorno=-1;
    char auxNombre[128];
    int auxId=0;
    int auxHorasTrabajadas=0;
    int auxSueldo=0;

    if(this!= NULL)
    {
        auxId=nuevoId;
        utn_setNombre("ingrese nombre de empleado: ",auxNombre,sizeof(auxNombre));
        auxHorasTrabajadas=utn_setEntero("ingrese las horas trabajadas: ",auxHorasTrabajadas);
        auxSueldo=utn_setEntero("ingrese sueldo: ",auxSueldo);
        Employee_setId(this,auxId);
        Employee_setNombre(this,auxNombre);
        Employee_setHorasTrabajadas(this,auxHorasTrabajadas);
        Employee_setSueldo(this,auxSueldo);
        retorno=0;
    }
    return retorno;
}

int Employee_editDesdeLinkedList(Employee* this)
{
    int retorno=-1;
    char auxNombre[128];
    int auxHorasTrabajadas=0;
    int auxSueldo=0;
    int opcion=0;

    if(this!= NULL)
    {
        opcion=utn_setMargenEntero(" modificar:\n 1. nombre\n 2. horas trabajadas\n 3. sueldo\n opcion: ",opcion,1,3);
        switch(opcion)
        {
        case 1:
            utn_setNombre("ingrese nombre de empleado: ",auxNombre,sizeof(auxNombre));
            Employee_setNombre(this,auxNombre);
            break;
        case 2:
            auxHorasTrabajadas=utn_setEntero("ingrese las horas trabajadas: ",auxHorasTrabajadas);
            Employee_setHorasTrabajadas(this,auxHorasTrabajadas);
            break;
        case 3:
            auxSueldo=utn_setEntero("ingrese sueldo: ",auxSueldo);
            Employee_setSueldo(this,auxSueldo);
            break;
        default:
            printf(" esta opcion no existe.\n");
            break;
        }
        retorno=0;
    }
    return retorno;
}

int Employee_sortComparacion(void* elementoUno, void* elementoDos)
{
    int retorno=-1;
    char nombre1[100];
    char nombre2[100];

    if(elementoUno != NULL && elementoDos != NULL)
    {
        Employee_getNombre(elementoUno,nombre1);
        Employee_getNombre(elementoDos,nombre2);

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
