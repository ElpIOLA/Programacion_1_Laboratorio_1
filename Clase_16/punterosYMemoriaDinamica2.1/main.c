#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define   CLIENTES  100
int main()
{
    Cliente* arrayClientes[CLIENTES];
    Cliente* auxArrayClientes;
    int indexVacio=-1;
    cliente_init(arrayClientes,CLIENTES);
    auxArrayClientes=cliente_new();
    if(auxArrayClientes != NULL)
    {
        indexVacio= cliente_buscarLugarVacio(arrayClientes,CLIENTES);
        if(auxArrayClientes!= NULL && indexVacio > -1)
        {
            if(cliente_setNombre(auxArrayClientes,"nombre"))
            {
                char nombreV[10];
                cliente_getNombre(auxArrayClientes,nombreV);
                printf("nombre: %s\n",nombreV);
            }
            if(cliente_setApellido(auxArrayClientes,"apellido"))
            {
                char apellidoV[10];
                cliente_getApellido(auxArrayClientes,apellidoV);
                printf("apellido: %s\n",apellidoV);
            }
            if(cliente_setId(auxArrayClientes,3))
            {
                int idV=-1;
                idV=cliente_GetId(auxArrayClientes,idV);
                printf("id: %d\n", idV);
            }
            arrayClientes[indexVacio]=auxArrayClientes;
        }
    }
    return 0;
}

