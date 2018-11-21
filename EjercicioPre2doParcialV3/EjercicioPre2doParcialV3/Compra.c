#include "Compra.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Compra* Compra_new()
{
    Compra* this;
    this=malloc(sizeof(Compra));
    return this;
}

void Compra_delete(Compra* this)
{
    free(this);
}

Compra* Compra_newConParametros(char* nombreCliente,int idProducto,float precioUnitario,int unidades,float iva,float montoTotal)
{
    Compra* this;
    this=Compra_new();

    if(
    !Compra_setNombreCliente(this,nombreCliente)&&
    !Compra_setIdProducto(this,idProducto)&&
    !Compra_setPrecioUnitario(this,precioUnitario)&&
    !Compra_setUnidades(this,unidades)&&
    !Compra_setIva(this,iva)&&
    !Compra_setMontoTotal(this,montoTotal))
        return this;

    Compra_delete(this);
    return NULL;
}

int Compra_setNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL)
    {
        strcpy(this->nombreCliente,nombreCliente);
        retorno=0;
    }
    return retorno;
}

int Compra_getNombreCliente(Compra* this,char* nombreCliente)
{
    int retorno=-1;
    if(this!=NULL && nombreCliente!=NULL)
    {
        strcpy(nombreCliente,this->nombreCliente);
        retorno=0;
    }
    return retorno;
}

int Compra_setIdProducto(Compra* this,int idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idProducto=idProducto;
        retorno=0;
    }
    return retorno;
}

int Compra_getIdProducto(Compra* this,int* idProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idProducto=this->idProducto;
        retorno=0;
    }
    return retorno;
}

int Compra_setPrecioUnitario(Compra* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Compra_getPrecioUnitario(Compra* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Compra_setUnidades(Compra* this,int unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->unidades=unidades;
        retorno=0;
    }
    return retorno;
}

int Compra_getUnidades(Compra* this,int* unidades)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *unidades=this->unidades;
        retorno=0;
    }
    return retorno;
}

int Compra_setIva(Compra* this,float iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->iva=iva;
        retorno=0;
    }
    return retorno;
}

int Compra_getIva(Compra* this,float* iva)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *iva=this->iva;
        retorno=0;
    }
    return retorno;
}

int Compra_setMontoTotal(Compra* this,float montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->montoTotal=montoTotal;
        retorno=0;
    }
    return retorno;
}

int Compra_getMontoTotal(Compra* this,float* montoTotal)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *montoTotal=this->montoTotal;
        retorno=0;
    }
    return retorno;
}

int mostrarCompra(void* pElement)
{
    Compra* elemento;
    if(pElement != NULL)
    {
        elemento=(Compra*)pElement;
        printf("%10s--%3d--%5.2f--%3d--%7.2f--%9.2f\n",elemento->nombreCliente,elemento->idProducto,
                                                    elemento->precioUnitario,elemento->unidades,
                                                    elemento->iva,elemento->montoTotal);
    }
    return 0;
}

LinkedList* mostrarPorId(LinkedList* listaCompras, LinkedList* listaFiltrada)
{
    int id=0;
    if(listaCompras != NULL)
    {
        printf("elige un id como parametro de busqueda: ");
        scanf("%d",&id);
        listaFiltrada = ll_filterArgs(listaCompras,criterioParaLista,&id);
        ll_map(listaFiltrada,mostrarCompra);
    }
    return listaFiltrada;
}

int criterioParaLista(void* pElement, void* id)
{
    int* auxId=0;
    Compra* auxCompra=NULL;
    if(pElement != NULL)
    {
        auxId=(int*)id;
        auxCompra=(Compra*)pElement;
        if(auxCompra->idProducto==*(auxId))
        {
            return 1;
        }
    }
    return 0;
}

int com_calcularMonto(void* p)
{
    Compra* auxCompra=NULL;
    float montoTotal=0;
    float precioUnitario=0;
    float iva=0;
    if(p!= NULL)
    {
        auxCompra=(Compra*)p;
        Compra_getPrecioUnitario(auxCompra,&precioUnitario);
        Compra_getIva(auxCompra,&iva);
        montoTotal=precioUnitario+(precioUnitario*iva/100);
        Compra_setMontoTotal(auxCompra,montoTotal);
        return 0;
    }
    return 1;
}
