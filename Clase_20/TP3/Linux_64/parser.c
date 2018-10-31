#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int retorno=-1;
    char buffer[150];
    char bufferId[10];
    int auxEnteroId=0;
    char bufferNombre[50];
    char bufferHorasTrabajadas[20];
    int auxEnteroHorasTrabajadas=0;
    char bufferSalario[20];
    int auxEnteroSalario=0;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile,"%s\n",buffer);
        while(!feof(pFile))
        {
            auxiliar=Employee_new();
            if((fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                       bufferNombre,
                       bufferHorasTrabajadas,
                       bufferSalario)==4) &&
                       !verificarId(bufferId,auxEnteroId) &&
                       !verificarNombre(bufferNombre) &&
                       !verificarHorasTrabajadas(bufferHorasTrabajadas,auxEnteroHorasTrabajadas) &&
                       !verificarSalario(bufferSalario, auxEnteroSalario))
            {
            auxEnteroId=atoi(bufferId);
            auxEnteroHorasTrabajadas=atoi(bufferHorasTrabajadas);
            auxEnteroSalario=atoi(bufferSalario);
            Employee_setId(auxiliar,auxEnteroId);
            Employee_setNombre(auxiliar,bufferNombre);
            Employee_setHorasTrabajadas(auxiliar,auxEnteroHorasTrabajadas);
            Employee_setSueldo(auxiliar,auxEnteroSalario);
            ll_add(pArrayListEmployee,auxiliar);
            }
        /*printf("%s-%s-%s-%s\n",bufferId,
               bufferNombre,
               bufferHorasTrabajadas,
               bufferSalario);*/


    }
    retorno=0;
}
return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pEmpleado;

    if(pFile != NULL)
    {
        retorno=0;
        while(!feof(pFile))
        {
            pEmpleado= Employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            printf("%s\n",pEmpleado->nombre);
            ll_add(pArrayListEmployee,pEmpleado);

        }
    }
    return retorno;
}
