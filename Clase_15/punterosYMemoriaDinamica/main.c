#include <stdio.h>
#include <stdlib.h>
#define len 20

int* newArray(int tamanio);
int* redimensionarArray(int* entero,int nuevoTamanio);
int initArray(int* entero, int limite, int valor);
int printArray(int* entero, int limite);
int deleteArray(int* entero);

int main()
{
    int* pEnteros;
    pEnteros=newArray(len);
    if(pEnteros != NULL)
    {
        printf(" creado\n");
        initArray(pEnteros,len,1);
        printf(" inicializado\n");
        printArray(pEnteros,len);
        printf(" mostrado\n");
        pEnteros=redimensionarArray(pEnteros,30);
        if(pEnteros != NULL)
        {
            printf(" redimensionado\n");
            initArray(pEnteros,30,1);
            printf(" inicializado\n");
            printArray(pEnteros,30);
            printf(" mostrado\n");
            deleteArray(pEnteros);
            printf(" borrado\n");
        }
    }
    return 0;
}

int* newArray(int tamanio)
{
    int* retorno=NULL;

    int* arrayIntAux= malloc(sizeof(int)*len);
    if(arrayIntAux != NULL && tamanio>0)
    {
        retorno=arrayIntAux;
    }

    return retorno;
}

int initArray(int* entero, int limite,int valor)
{
    int i;
    int flag=-1;

    if(entero != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            *(entero+i)=valor;
            flag=0;
        }
    }
    return flag;
}

int printArray(int* entero, int limite)
{
    int i;
    int flag=-1;

    if(entero != NULL && limite>0)
    {
        for(i=0; i<limite; i++)
        {
            printf(" %p - [%d] - %d\n", (entero+i), i, *(entero+i));
            flag=0;
        }
    }
    return flag;
}

int deleteArray(int* entero)
{
    int flag=-1;

    if(entero != NULL)
    {
        free(entero);
        flag=0;
    }
    return flag;
}

int* redimensionarArray(int* entero,int nuevoTamanio)
{
    int* retorno=NULL;

    int* arrayIntAux= realloc(entero,sizeof(int)*nuevoTamanio);
    if(arrayIntAux != NULL && nuevoTamanio>0)
    {
        retorno=arrayIntAux;
    }

    return retorno;
}
