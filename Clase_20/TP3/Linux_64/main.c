#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    static int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {

        printf( " Menu\n"
                " 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                " 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                " 3. Alta de empleado\n"
                " 4. Modificar datos de empleado\n"
                " 5. Baja de empleado\n"
                " 6. Listar empleados\n"
                " 7. Ordenar empleados\n"
                " 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                " 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                " 10. Salir\n"
                " opcion: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            if(!controller_loadFromText("data.csv",listaEmpleados)&&
                    !controller_ListEmployee(listaEmpleados)&&
                    !controller_saveAsBinary("data.bin",listaEmpleados))
            {
                flag=1;
                printf(" Se cargo el archivo de texto!!\n");
            }
            break;
        case 2:
            if(flag>0)
            {
                if(!controller_loadFromBinary("data.bin",listaEmpleados)&&
                        !controller_ListEmployee(listaEmpleados))
                {
                    printf(" Se cargo el archivo!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }
            }
            else
            {
                printf(" El archivo en binario aun no existe. Primero cargar el archivo .csv\n");
            }
            break;
        case 3:
            if(flag>0)
            {
                if(!controller_addEmployee(listaEmpleados)&&
                        !controller_ListEmployee(listaEmpleados))
                {
                    printf(" Se agrego el empleado!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }
            }
            else
            {
                printf(" Antes de dar de alta un empleado cargar el archivo con su lista\n");
            }
            break;
        case 4:
            if(flag>0)
            {
                if(!controller_ListEmployee(listaEmpleados) &&
                    !controller_editEmployee(listaEmpleados))
                {
                    printf(" Se modifico el empleado!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }
            }
            else
            {
                printf(" Antes de modificar un empleado cargar el archivo con su lista\n");
            }
            break;
        case 5:
            if(flag>0)
            {
                if(!controller_ListEmployee(listaEmpleados)&&
                        !controller_removeEmployee(listaEmpleados))
                {
                    printf(" Se dio de baja el empleado!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }
            }
            else
            {
                printf(" Antes de dar de baja un empleado cargar el archivo con su lista\n");
            }
            break;
        case 6:
            if(!controller_listEmployeeFromFile("data.csv"))
            {
                printf(" lista mostrada!!\n");
            }
            else
            {
                printf(" Error\n.");
            }
            break;
        case 7:
            if(flag>0)
            {
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf(" Empleados ordenados!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }
            }
            break;
        case 8:
            if(flag>0)
            {
                if(!controller_saveAsText("data (copia).csv",listaEmpleados))
                {
                    printf(" Lista guardada!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }
            }
            else
            {
                printf(" No podes guardar la lista si no la cargaste antes.\n");
            }
            break;
        case 9:
            if(flag>0)
            {
                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf(" Lista guardada!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }
            }
            else
            {
                printf(" No podes guardar la lista si no la cargaste antes.\n");
            }
            break;
        case 10:
            if(flag>0)
            {
                ll_deleteLinkedList(listaEmpleados);
            }
            break;
        default:
            printf(" Esta opcion no Existe!!\n");
            break;
        }
    }
    while(option != 10);
    return 0;
}
