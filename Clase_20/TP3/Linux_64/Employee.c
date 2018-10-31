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
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
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

int verificarId(char* stringId, int enteroConvertido)
{
    int retorno=-1;
    if(stringId != NULL)
    {
        // invocar validacion, agregar validaciones especificas y convertir
        retorno=0;
    }
    return retorno;
}

int verificarNombre(char* stringNombre)
{
    int retorno=-1;
    if(stringNombre != NULL)
    {
        // invocar validacion, agregar validaciones especificas y convertir
        retorno=0;
    }
    return retorno;
}

int verificarHorasTrabajadas(char* stringHorasTrabajadas, int enteroConvertido)
{
    int retorno=-1;
    if(stringHorasTrabajadas != NULL)
    {
        // invocar validacion, agregar validaciones especificas y convertir
        retorno=0;
    }
    return retorno;
}

int verificarSalario(char* stringSalario, int enteroConvertido)
{
    int retorno=-1;
    if(stringSalario != NULL)
    {
        // invocar validacion, agregar validaciones especificas y convertir
        retorno=0;
    }
    return retorno;
}

int Employee_add(Employee* this)
{
    int auxid;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(this!= NULL)
    {

    }


}
