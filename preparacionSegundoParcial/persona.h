#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    char estado[15];
    int salario;
}Persona;

Persona* persona_new();
void persona_delete();
Persona* persona_newConParametros(int id,char* nombre,char* apellido,char* estado,int salario);
Persona* persona_newDesdeArchivoConParametros(char* id,char* nombre,char* apellido,char* estado,char* salario);

int persona_setId(Persona* this,int id);
int persona_getId(Persona* this,int* id);

int persona_setNombre(Persona* this,char* nombre);
int persona_getNombre(Persona* this,char* nombre);

int persona_setApellido(Persona* this,char* apellido);
int persona_getApellido(Persona* this,char* apellido);

int persona_setEstado(Persona* this,char* estado);
int persona_getEstado(Persona* this,char* estado);

int persona_setSalario(Persona* this,int salario);
int persona_getSalario(Persona* this,int* salario);

int persona_mostrarUno(void* pElement);
int persona_calcularId(void* pElement);
int Persona_sortComparacion(void* elementoUno, void* elementoDos);
#endif // PERSONA_H_INCLUDED
