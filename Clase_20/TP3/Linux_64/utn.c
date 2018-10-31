#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

float utn_setFlotante(char mensaje[], float flotante)
{
    int flag=0;
    char auxFlt[15];
    float num;

    if(mensaje != NULL && auxFlt != NULL && sizeof(auxFlt) > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(auxFlt,sizeof(auxFlt),stdin);
            if((flag=utn_validarFlotante(auxFlt,sizeof(auxFlt))))
            {
                num=atof(auxFlt);
                flotante= num;
            }
            else
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag!=1);
    }
    return flotante;
}



int utn_setEntero(char mensaje[], int entero)
{
    int flag=0;
    char auxIntg[15];
    int num;

    if(mensaje != NULL && auxIntg != NULL && sizeof(auxIntg) > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(auxIntg,sizeof(auxIntg),stdin);
            if((flag=utn_validarEntero(auxIntg,sizeof(auxIntg))))
            {

                num=atoi(auxIntg);
                entero= num;
            }
            else
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag!=1);
    }
    return entero;
}


int utn_setNombre(char mensaje[], char texto[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(mensaje !=NULL && texto != NULL && len > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(texto,len,stdin);
            auxlen=strlen(texto);
            if(!(flag=utn_validarAlfabetico(texto, len)))
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag== 0);
        token=strtok(texto,"\n");
        strncpy(texto,token,auxlen);
    }
    return flag;
}


int utn_setTexto(char mensaje[], char texto[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(mensaje !=NULL &&texto != NULL && len > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(texto,len,stdin);
            auxlen=strlen(texto);
            if(!(flag=utn_validarAlfanumerico(texto, len)))
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag== 0);
        token=strtok(texto,"\n");
        strncpy(texto,token,auxlen);
    }
    return flag;
}

int utn_setCuit(char mensaje[], char cuit[], int len)
{
    int flag=0;
    int auxlen;
    char* token;
    if(mensaje !=NULL &&cuit != NULL && len > 0)
    {
        printf("%s",mensaje);
        do
        {
            __fpurge(stdin);
            fgets(cuit,len,stdin);
            auxlen=strlen(cuit);
            if(!(flag=utn_validarCuit(cuit, len)))
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(flag== 0);
        token=strtok(cuit,"\n");
        strncpy(cuit,token,auxlen);
    }
    return flag;
}

int utn_setMargenEntero(char mensaje[], int entero, int min, int max)
{
    if(mensaje!= NULL)
    {
        printf("%s",mensaje);
        do
        {
            entero=utn_setEntero("",entero);
            if(entero < min || entero > max)
            {
                printf("error. intenta de nuevo: ");
            }
        }
        while(entero < min || entero > max);
    }
    return entero;
}


float utn_setMargenFlotante(char mensaje[], float flotante, float min, float max)
{
    if(mensaje != NULL)
    {
        printf("%s",mensaje);
        do
        {
            flotante=utn_setFlotante("",flotante);
            if(flotante < min || flotante > max)
            {
                printf("error. intenta de nuevo'n");
            }
        }
        while(flotante < min || flotante > max);
    }
    return flotante;
}


int utn_validarFlotante(char str[], int len)
{
    int flag=1;
    int i=0;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}


int utn_validarEntero(char str[], int len)
{
    int flag=1;
    int i=0;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }
            i++;
        }
    }
    return flag;
}



int utn_validarAlfabetico(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;

    if(str != NULL && len>0)
    {
        auxlen=strlen(str);

        while(str[i] != '\0' && i<= auxlen && str[i] != 10)
        {
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ' && str[i] != -61 &&
                    str[i] != -79 && str[i] != -111)
            {
                flag=0;
                break;
            }
            i++;
        }
    }
    return flag;
}


int utn_validarAlfanumerico(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen)
        {
            if( (str[i] != 10 ) && (str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}

int utn_validarCuit(char str[], int len)
{
    int i=0;
    int flag=1;
    int auxlen;

    if(str != NULL && len >0)
    {
        auxlen=strlen(str);
        while(str[i] != '\0' && i<= auxlen)
        {
            if( (str[i] != 10 ) && (str[i] < '0' || str[i] > '9') && str[i] != '-')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}
