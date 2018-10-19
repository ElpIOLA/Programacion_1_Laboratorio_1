#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[10];
    char apellido[10];
    int id;
}Cliente;

Cliente* cliente_new(void);

Cliente* cliente_clienteForzado(char* nombre, char* apellido, int id);

int cliente_setNombre(Cliente* this, char* nombre);

int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this, char* nombre);

int cliente_getApellido(Cliente* this,char* apellido);

int cliente_setId(Cliente* this, int id);

int cliente_GetId(Cliente* this,int id);

int cliente_deleteCliente(Cliente* this);

int cliente_buscarLugarVacio(Cliente* array[], int len);

int cliente_init(Cliente* array[], int len);

int cliente_buscarPorId(Cliente* array[], int len, int id);

#endif // CLIENTE_H_INCLUDED
