#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "controller.h"
#include "utn.h"
#include "LinkedList.h"
#include "persona.h"

int controller_menu(void)
{
    int option=0;
    static int flag=0;
    LinkedList* listaPersonas=ll_newLinkedList();
    LinkedList* listanegra=ll_newLinkedList();
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
            if(!controller_loadFromText("persona.csv",listaPersonas)&&
                    !controller_saveAsBinary("persona.bin",listaPersonas))
            {
                flag=1;
                printf(" Se cargo el archivo de texto!!\n");
            }
            break;
        case 2:
            if(flag>0 || !controller_verificarBinario("persona.bin"))
            {
                if(!controller_loadFromBinary("persona.bin",listaPersonas)&&
                        !controller_ListPersona(listaPersonas))
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
                if(!controller_addPersona(listaPersonas))
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
                if(!controller_ListPersona(listaPersonas) &&
                        !controller_editPersona(listaPersonas))
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
                if(!controller_ListPersona(listaPersonas)&&
                        !controller_removePersona(listaPersonas))
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
            if(!controller_listPersonaFromFile("persona.csv"))
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
                /*if(!controller_sortEmployee(listaPersonas))
                {
                    printf(" Empleados ordenados!!\n");
                }
                else
                {
                    printf(" Error.\n");
                }*/
            }
            break;
        case 8:
            if(flag>0)
            {
                if(!controller_saveAsText("persona.csv",listaPersonas))
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
                if(!controller_saveAsBinary("persona.bin",listaPersonas))
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
                ll_deleteLinkedList(listaPersonas);
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




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* lista)
{
    int retorno=-1;
    FILE* pFile;
    if(path != NULL && lista != NULL)
    {
        pFile=fopen(path,"r");
        if(pFile != NULL)
        {
            retorno=0;
            parser_LoadText(pFile,lista);
        }
        fclose(pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* lista)
{
    int retorno=-1;
    FILE* pArchivo;
    if(path != NULL && lista != NULL)
    {
        pArchivo=fopen(path,"rb");
        if(pArchivo != NULL)
        {
            retorno=0;
            parser_loadBinary(pArchivo,lista);
        }
        fclose(pArchivo);
    }
    return retorno;
}


/** \brief Alta de persona
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_addPersona(LinkedList* lista)
{
    int returnAux=-1;
    Persona* nuevapersona=NULL;
    if(lista != NULL)
    {
        ll_map(lista,persona_calcularId);
        nuevapersona=persona_new();
        persona_addPersona(nuevapersona);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Modificar datos de persona
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_editPersona(LinkedList* lista)
{
    int returnAux=-1;
    Persona* aux=NULL;
    int id=0;
    int i;
    if(lista != NULL)
    {
        id=utn_setMargenEntero("ingresa el ide de un empleado para editar: ",id,1,ll_len(lista));
        if(ll_len(lista) > 0 && id > 0 && id <=ll_len(lista))
        {
            i=0;
            startIterator(lista,i);
            while(i<ll_len(lista))
            {
                if((aux=ll_getNext(lista))!= NULL && (aux->id)==id)
                {
                    persona_editPersona(aux);
                    ll_set(lista,i,aux);
                    break;
                }
                i++;
            }
        }
        returnAux=0;
    }
    return returnAux;
}

/** \brief Baja de persona
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_removePersona(LinkedList* lista)
{
    int returnAux=-1;
    Persona* aux=NULL;
    int id=0;
    int i;
    if(lista != NULL)
    {
        id=utn_setMargenEntero("ingresa el ide de un empleado para editar: ",id,1,ll_len(lista));
        if(ll_len(lista) > 0 && id > 0 && id <=ll_len(lista))
        {
            i=0;
            startIterator(lista,i);
            while(i<ll_len(lista))
            {
                if((aux=ll_getNext(lista))!= NULL && (aux->id)==id)
                {
                    ll_remove(lista,i);
                    break;
                }
                i++;
            }
        }
        returnAux=0;
    }
    return returnAux;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee != NULL)
    {
        printf(" Espera...\n");
        ll_sort(pArrayListEmployee,Persona_sortComparacion,0);
        retorno=0;
    }
    controller_ListPersona(pArrayListEmployee);
    return retorno;
}

int controller_ListPersona(LinkedList* lista)
{
    int returnAux=-1;
    if(lista != NULL)
    {
        ll_map(lista,persona_mostrarUno);
    }
    return returnAux;
}

int controller_listPersonaFromFile(char* path)
{
    int retorno=-1;
    FILE* pArchivo=NULL;
    char string[1080];

    if(path != NULL)
    {
        pArchivo=fopen(path,"r");
        if(pArchivo != NULL)
        {
            while(!feof(pArchivo))
            {
                fscanf(pArchivo,"%[^\n]\n",string);
                printf("%s\n",string);
            }
            retorno=0;
        }
        fclose(pArchivo);
    }
    return retorno;
}
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* lista)
{
    int retorno=-1;
    FILE *pArchivo=fopen(path,"w");

    if(lista != NULL && pArchivo != NULL)
    {
        parser_saveText(pArchivo,lista);
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* lista)
{
    int retorno=-1;
    FILE *pArchivo=fopen(path,"wb");
    if(lista != NULL && pArchivo != NULL)
    {
        parser_saveBinary(pArchivo,lista);
        retorno=0;
    }
    fclose(pArchivo);
    return retorno;
}

int controller_verificarBinario(char* path)
{
    int retorno=-1;
    FILE* pArchivo=NULL;

    if(path != NULL)
    {
        pArchivo=fopen(path,"rb");
        if(pArchivo != NULL)
        {
            retorno=0;
        }
        fclose(pArchivo);
    }
    return retorno;
}

int controller_verificarTexto(char* path)
{
    int retorno=-1;
    FILE* pArchivo=NULL;

    if(path != NULL)
    {
        pArchivo=fopen(path,"r");
        if(pArchivo != NULL)
        {
            retorno=0;
        }
        fclose(pArchivo);
    }
    return retorno;
}
