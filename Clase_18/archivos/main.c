#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantidadEscrita,longitudTexto;
    FILE* pArchivo;
    char texto[]= "hola mundo !!!";

    pArchivo=fopen("banco.txt","w");
    if(pArchivo == NULL)
    {
        printf("\n Error de apertura");
    }
    longitudTexto=strlen(texto);
    cantidadEscrita=fwrite(texto,sizeof(char),longitudTexto,pArchivo);
    if(cantidadEscrita< longitudTexto)
    {
        printf("\n Error al escribir el archivo");
    }
    fclose(pArchivo);

    return 0;
}

do
{
    cantidadLeida = fread(texto,sizeof(char),1,pArchivo);
}while( cantidadLeida != 1);
