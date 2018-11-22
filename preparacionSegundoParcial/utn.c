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
            if((flag=utn_validarFlotante(auxFlt)))
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
            if((flag=utn_validarEntero(auxIntg)))
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
            if(!(flag=utn_validarAlfabetico(texto)))
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
            if(!(flag=utn_validarAlfanumerico(texto)))
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
            if(!(flag=utn_validarCuit(cuit)))
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


int utn_validarFlotante(char str[])
{
    int flag=1;
    int i=0;

    if(str != NULL)
    {
        while(str[i] != '\0' && str[i] != 10)
        {
            if((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '.')
            {
                flag= 0;
                break;
            }

            i++;
        }
    }
    return flag;
}


int utn_validarEntero(char str[])
{
    int flag=1;
    int i=0;

    if(str != NULL )
    {
        while(str[i] != '\0' && str[i] != 10)
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



int utn_validarAlfabetico(char str[])
{
    int i=0;
    int flag=1;

    if(str != NULL )
    {

        while(str[i] != '\0' && str[i] != 10)
        {
            if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != ' ' && str[i] != '-')
            {
                flag=0;
                break;
            }
            i++;
        }
    }
    return flag;
}


int utn_validarAlfanumerico(char str[])
{
    int i=0;
    int flag=1;

    if(str != NULL)
    {
        while(str[i] != '\0' && str[i] != 10)
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

int utn_validarCuit(char str[])
{
    int i=0;
    int flag=1;

    if(str != NULL)
    {
        while(str[i] != '\0' && str[i] != 10)
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

int utn_isValidEntero(char* auxEntero, int* entero)
{
    int retorno=-1;
    if(auxEntero!= NULL && utn_validarEntero(auxEntero))
    {
        *entero=atoi(auxEntero);
        retorno=0;
    }
    return retorno;
}

int utn_isValidFlotante(char* auxFlotante, float* flotante)
{
    int retorno=-1;
    if(auxFlotante!= NULL && utn_validarFlotante(auxFlotante))
    {
        *flotante=atof(auxFlotante);
        retorno=0;
    }
    return retorno;
}

int utn_isValidNombre(char* bufferNombre)
{
    int retorno=-1;
    int i=0;

    if(bufferNombre != NULL && utn_validarAlfabetico(bufferNombre))
    {
        while(*(bufferNombre+i)!='\0')
        {
            if(i==0 && *(bufferNombre+i)>='A' && *(bufferNombre+i)<='Z')
            {
                retorno=0;
            }
            if(i!=0 && *(bufferNombre+i)==' ' && (*(bufferNombre+i+1)<'A' || *(bufferNombre+i+1)>'Z'))
            {
                retorno=-1;
                break;
            }
            else if(i!=0 && *(bufferNombre+i)=='-' && (*(bufferNombre+i+1)<'A' || *(bufferNombre+i+1)>'Z'))
            {
                retorno=-1;
                break;
            }
            i++;
        }

    }
    return retorno;
}

int utn_isValidEstado(char* bufferEstado)
{
    int retorno=-1;
    if(bufferEstado!= NULL &&
            (strcmp(bufferEstado,"1")==0 ||
             strcmp(bufferEstado,"TRUE")==0 ||
             strcmp(bufferEstado,"true")==0 ||
             strcmp(bufferEstado,"VERDADERO")==0 ||
             strcmp(bufferEstado,"verdadero")==0 ||
             strcmp(bufferEstado,"ocupado")==0 ||
             strcmp(bufferEstado,"OCUPADO")==0))
    {
        retorno=0;
    }
    else if(bufferEstado!= NULL &&
            (strcmp(bufferEstado,"0")==0 ||
             strcmp(bufferEstado,"FALSE")==0 ||
             strcmp(bufferEstado,"false")==0 ||
             strcmp(bufferEstado,"FALSO")==0 ||
             strcmp(bufferEstado,"falso")==0 ||
             strcmp(bufferEstado,"libre")==0 ||
             strcmp(bufferEstado,"LIBRE")==0))
    {
        retorno=0;
    }
    return retorno;
}

int utn_isValidTelefono(char* bufferTelefono)
{
    int retorno=-1;
    int i=0;
    int contador=0;
    if(bufferTelefono != NULL)
    {
        while(*(bufferTelefono+i)!='\0')
        {
            if(i==0 && *(bufferTelefono+i)>='0' && *(bufferTelefono+i)<='9')
            {
                retorno=0;
            }

            if(*(bufferTelefono+i)==' ' || *(bufferTelefono+i)=='-')
            {
                contador++;
            }

            if(i!=0 && *(bufferTelefono+i)==' ' && (*(bufferTelefono+i+1)<'0' || *(bufferTelefono+i+1)>'9'))
            {
                retorno=-1;
                break;
            }
            else if(i!=0 && *(bufferTelefono+i)=='-' && (*(bufferTelefono+i+1)<'0' || *(bufferTelefono+i+1)>'9'))
            {
                retorno=-1;
                break;
            }
            i++;
        }
        if(contador!=1)
        {
            retorno=-1;
        }
    }
    return retorno;
}
