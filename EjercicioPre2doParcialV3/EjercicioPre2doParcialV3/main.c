#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(char* fileName,LinkedList* listaCompras);

int main()
{
    // Definir lista de compras
    LinkedList* listaCompras=ll_newLinkedList();
    LinkedList* listaFiltrada=NULL;

    // Crear lista compras
    //...

    // Leer compras de archivo data.csv
    if(parser_parseCompras("data.csv",listaCompras)==1)
    {
        // Filtrar
        //TODO
        listaFiltrada=mostrarPorId(listaCompras,listaFiltrada);
        // Calcular montos
        printf("Calculando montos totales...\n");
        ll_map(listaCompras,com_calcularMonto);
        ll_map(listaCompras,mostrarCompra);
        //TODO

        // Generar archivo de salida
        if(generarArchivoInforme("informe.csv",listaFiltrada)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo compras\n");


    return 0;
}

int generarArchivoInforme(char* fileName,LinkedList* listaCompras)
{
    Compra* auxiliar;
    FILE* pArchivo=NULL;
    int returnAux=-1;
    int i=0;
    if(fileName != NULL && listaCompras != NULL)
    {
        returnAux=0;
        pArchivo=fopen(fileName,"w");
        if(pArchivo != NULL)
        {
            fprintf(pArchivo,"nombreCliente,idProducto,precioUnitario,unidades,iva,montoTotal\n");
            while(i<ll_len(listaCompras))
            {
                auxiliar=(Compra*)ll_get(listaCompras,i);
                fprintf(pArchivo,"%s,%d,%.2f,%d,%.2f,%.2f\n",auxiliar->nombreCliente, auxiliar->idProducto,
                                                            auxiliar->precioUnitario, auxiliar->unidades,
                                                            auxiliar->iva, auxiliar->montoTotal);
                i++;
            }
        returnAux=1;
        }
        fclose(pArchivo);
        ll_map(listaCompras,mostrarCompra);
    }
    return returnAux;
}
