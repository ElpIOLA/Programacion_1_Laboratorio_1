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
    char quedarse;
    do
    {

        printf( "Menu\n"
                "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                "3. Alta de empleado\n"
                "4. Modificar datos de empleado\n"
                "5. Baja de empleado\n"
                "6. Listar empleados\n"
                "7. Ordenar empleados\n"
                "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                "10. Salir\n"
                "opcion: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            controller_ListEmployee(listaEmpleados);
            controller_saveAsBinary("data.bin",listaEmpleados);
            flag=1;
            break;
        case 2:
            if(flag>0)
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
                controller_ListEmployee(listaEmpleados);
            }
            break;
        case 3:
            if(flag>0)
            {
                controller_addEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);
            }
            break;
        case 4:
            if(flag>0)
            {
                do
                {
                    controller_ListEmployee(listaEmpleados);
                    controller_editEmployee(listaEmpleados);
                    printf("desea seguir haciendo modificaciones a este empleado?('s' para quedarse): ");
                    quedarse=getc(stdin);
                }
                while(quedarse=='s');
            }
            break;
        case 5:
            if(flag>0)
            {
                controller_ListEmployee(listaEmpleados);
                controller_removeEmployee(listaEmpleados);
            }
            break;
        case 6:
            controller_listEmployeeFromFile("data.csv");
            break;
        case 7:
            if(flag>0)
            {
                controller_sortEmployee(listaEmpleados);
            }
            break;
        case 8:
            if(flag>0)
            {
                controller_saveAsText("data(bckup).csv",listaEmpleados);
            }
            break;
        case 9:
            if(flag>0)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            break;
        }
    }
    while(option != 10);
    return 0;
}
