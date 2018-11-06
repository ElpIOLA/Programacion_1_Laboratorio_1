#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"r");
        if(pFile != NULL)
        {
            retorno=0;
            parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivo;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo=fopen(path,"rb");
        if(pArchivo != NULL)
        {
            retorno=0;
            parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        }
        fclose(pArchivo);
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* aux=Employee_new();
    int len=0;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);
        Employee_addDesdeLinkedList(aux,len);
        ll_add(pArrayListEmployee,aux);
        retorno=0;
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* aux;
    int len=0;
    int id=0;
    int i;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);
        id=utn_setMargenEntero("ingresa el ide de un empleado para editar: ",id,1,len);
        if(len > 0 && id > 0 && id <=len)
        {
            for(i=0; i<len; i++)
            {
                if((aux=ll_get(pArrayListEmployee,i))!= NULL && (aux->id)==id)
                {
                    Employee_editDesdeLinkedList(aux);
                    ll_set(pArrayListEmployee,i,aux);
                    controller_ListAFewEmployees(pArrayListEmployee,i);
                    break;
                }
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* aux;
    int len=0;
    int id=0;
    int i;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);
        id=utn_setMargenEntero("ingresa el ide de un empleado para dar de baja: ",id,1,len);
        if(len > 0 && id > 0 && id <=len)
        {
            for(i=0; i<len; i++)
            {
                if((aux=ll_get(pArrayListEmployee,i))!= NULL && (aux->id)==id)
                {
                    Employee_delete(aux);
                    ll_remove(pArrayListEmployee,i);
                    break;
                }
            }
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* aux;
    void* element;
    int i;
    int len=0;

    if(pArrayListEmployee != NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            element=ll_get(pArrayListEmployee,i);
            aux=(Employee*) element;
            printf("%d--%s--%d--%d\n", aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
        retorno=0;
    }
    return retorno;
}

int controller_listEmployeeFromFile(char* path)
{
    int retorno=-1;
    FILE*  pFile;
    char buffer[150];
    char bufferId[10];
    char bufferNombre[50];
    char bufferHorasTrabajadas[20];
    char bufferSalario[20];
    if(path != NULL)
    {
        pFile=fopen(path,"r");
        if(pFile != NULL)
        {
            fscanf(pFile,"%s\n",buffer);
            while(!feof(pFile))
            {
                if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                          bufferNombre,
                          bufferHorasTrabajadas,
                          bufferSalario)==4)
                {
                    printf("%s--%s--%s--%s\n",bufferId,
                           bufferNombre,
                           bufferHorasTrabajadas,
                           bufferSalario);
                }
            }
            retorno=0;
        }
        fclose(pFile);
    }
    return retorno;
}

int controller_ListAFewEmployees(LinkedList* pArrayListEmployee, int index)
{
    int retorno=-1;
    Employee* aux;
    void* element;
    int i;
    int len=0;

    if(pArrayListEmployee != NULL && len > 0 && index > 0 && index <=len)
    {
        len=ll_len(pArrayListEmployee);
        for(i=index-2; i<index+2; i++)
        {
            element=ll_get(pArrayListEmployee,i);
            aux=(Employee*) element;
            printf("%d--%s--%d--%d\n", aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee,Employee_sortComparacion,1);
        retorno=0;
    }
    controller_ListEmployee(pArrayListEmployee);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE *pArchivo=fopen(path,"wb");
    Employee* pEmpleado;
    int i;
    if(pArrayListEmployee != NULL && pArchivo != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmpleado= ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
        }
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

