#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "persona.h"

int parser_LoadText(FILE* pfile, LinkedList* lista)
{
    int returnAux=-1;
    FILE* listaNegra=fopen("listaNegra.csv","w");
    Persona* auxiliar=NULL;
    char string[1080];
    char* bufferId;
    char* bufferNombre;
    char* bufferApellido;
    char* bufferEstado;
    char* bufferSalario;
    int auxId=0;
    int auxSalario=0;
    int flag=0;
    if(lista != NULL)
    {
        fscanf(pfile,"%[^\n]\n",string);
        while(!feof(pfile))
        {
            fscanf(pfile,"%[^\n]\n",string);
            bufferId=strtok(string,",");
            bufferNombre=strtok(NULL,",");
            bufferApellido=strtok(NULL,",");
            bufferEstado=strtok(NULL,",");
            bufferSalario=strtok(NULL,"\n");

            if(!utn_isValidEntero(bufferId,&auxId) &&
                    !utn_isValidNombre(bufferNombre) &&
                    !utn_isValidNombre(bufferApellido) &&
                    !utn_isValidEstado(bufferEstado) &&
                    !utn_isValidEntero(bufferSalario,&auxSalario))
            {
                auxiliar=persona_new();
                persona_setId(auxiliar,auxId);
                persona_setNombre(auxiliar,bufferNombre);
                persona_setApellido(auxiliar,bufferApellido);
                persona_setEstado(auxiliar,bufferEstado);
                persona_setSalario(auxiliar,auxSalario);
                ll_add(lista,auxiliar);
            }
            else
            {
                flag=1;
                fprintf(listaNegra,"%s,%s,%s,%s,%s\n",bufferId,bufferNombre,bufferApellido,bufferEstado,bufferSalario);
            }
        }
        fclose(listaNegra);
        if(flag==0)
        {
            free(listaNegra);
        }
        returnAux=0;
    }
    return returnAux;
}

int parser_loadTextSinVerificar(FILE* pfile, LinkedList* lista)
{
    int returnAux=-1;
    Persona* auxiliar=NULL;
    char string[1080];
    char* bufferId;
    char* bufferNombre;
    char* bufferApellido;
    char* bufferEstado;
    char* bufferSalario;
    int auxId=0;
    int auxSalario=0;
    if(lista != NULL && pfile != NULL)
    {
        while(!feof(pfile))
        {
            fscanf(pfile,"%[^\n]\n",string);
            bufferId=strtok(string,",");
            bufferNombre=strtok(NULL,",");
            bufferApellido=strtok(NULL,",");
            bufferEstado=strtok(NULL,",");
            bufferSalario=strtok(NULL,"\n");

            if(!utn_isValidEntero(bufferId,&auxId) &&
                    !utn_isValidEntero(bufferSalario,&auxSalario))
            {
                auxiliar=persona_new();
                persona_setId(auxiliar,auxId);
                persona_setNombre(auxiliar,bufferNombre);
                persona_setApellido(auxiliar,bufferApellido);
                persona_setEstado(auxiliar,bufferEstado);
                persona_setSalario(auxiliar,auxSalario);
                ll_add(lista,auxiliar);
            }
        }
        returnAux=0;
    }
    return returnAux;
}

int parser_loadBinary(FILE* pfile, LinkedList* lista)
{
    int returnAux=-1;
    Persona* auxiliar=NULL;
    if(lista != NULL && pfile != NULL)
    {
        while(!feof(pfile))
        {
            auxiliar=persona_new();
            fread(auxiliar,sizeof(Persona),1,pfile);
            ll_add(lista,auxiliar);
        }
        returnAux=0;
    }
    return returnAux;
}

int parser_saveText(FILE* pfile, LinkedList* lista)
{
    int returnAux=-1;
    Persona* pPersona=NULL;
    int id=0;
    char nombre[50];
    char apellido[50];
    char estado[15];
    int salario=0;
    int i=0;

    if(lista != NULL && pfile != NULL)
    {
        fprintf(pfile,"id,nombre,horasTrabajadas,estado,sueldo\n");
        startIterator(lista,i);
        while(i<ll_len(lista))
        {
            pPersona=(Persona*)ll_getNext(lista);
            persona_getId(pPersona,&id);
            persona_getNombre(pPersona,nombre);
            persona_getApellido(pPersona,apellido);
            persona_getEstado(pPersona,estado);
            persona_getSalario(pPersona,&salario);
            fprintf(pfile,"%d,%s,%s,%s,%d\n",id,nombre,apellido,estado,salario);
            i++;
        }
        returnAux=0;
    }
    return returnAux;
}


int parser_saveBinary(FILE* pfile, LinkedList* lista)
{
    int returnAux=-1;
    int i;
    Persona* pPersona=NULL;
    if(lista != NULL && pfile != NULL)
    {
        i=0;
        startIterator(lista,i);
        while(i<ll_len(lista))
        {
            pPersona=(Persona*)ll_getNext(lista);
            fwrite(pPersona,sizeof(Persona),1,pfile);
            i++;
        }
        returnAux=0;
    }
    return returnAux;
}
