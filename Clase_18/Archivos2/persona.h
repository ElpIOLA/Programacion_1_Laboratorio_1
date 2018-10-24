#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#define LIMITE_PERSONA 1010
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int isEmpty;
}Persona;

Persona* persona_new(void);

Persona* persona_nuevoConParametros(Persona* arrayPersona, char* id, char* nombre, char* apellido, char* isEmpty);

Persona* persona_PersonaForzado(char* nombre, char* apellido, int id);

int persona_setNombre(Persona* this, char* nombre);

int persona_getNombre(Persona* this,char* nombre);

int persona_setApellido(Persona* this, char* nombre);

int persona_getApellido(Persona* this,char* apellido);

int persona_setId(Persona* this, int id);

int persona_GetId(Persona* this, int id);

int persona_setIsEmpty(Persona* this, int isEmpty);

int persona_GetIsEmpty(Persona* this, int isEmpty);

int persona_deletePersona(Persona* this);

int persona_buscarLugarVacio(Persona* array[], int len);

int persona_init(Persona* array[], int len);

int persona_buscarPorId(Persona* array[], int len, int id);

int persona_listarArray(Persona* array[], int len);

#endif
