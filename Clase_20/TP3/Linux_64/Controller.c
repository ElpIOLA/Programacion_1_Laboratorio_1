#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

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
    pArchivo=fopen(path,"rb");
    retorno=parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    fclose(pArchivo);
    return 1;
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
    Employee* aux=Employee_new();
    int Employee_add(aux);
    return 1;
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
    return 1;
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
    return 1;
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
    }
    return 1;
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
    return 1;
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
    FILE *pArchivo=fopen(path,"wb");
    Employee* pEmpleado;
    char nombre[100];
    int i;
    int retorno=-1;

    if(pArrayListEmployee != NULL && pArchivo != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmpleado= ll_get(pArrayListEmployee,i);
            Employee_getNombre(pEmpleado,nombre);
            printf("%s\n",nombre);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
        }
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

