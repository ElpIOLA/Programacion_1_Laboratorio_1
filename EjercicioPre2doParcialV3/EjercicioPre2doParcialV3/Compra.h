#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
  char nombreCliente[128];
  int idProducto;
  float precioUnitario;
  int unidades;
  float iva;
  float montoTotal;
}Compra;


Compra* Compra_new();
void Compra_delete();
Compra* Compra_newConParametros(char* nombreCliente,int idProducto,float precioUnitario,int unidades,float iva,float montoTotal);

int Compra_setNombreCliente(Compra* this,char* nombreCliente);
int Compra_getNombreCliente(Compra* this,char* nombreCliente);

int Compra_setIdProducto(Compra* this,int idProducto);
int Compra_getIdProducto(Compra* this,int* idProducto);

int Compra_setPrecioUnitario(Compra* this,float precioUnitario);
int Compra_getPrecioUnitario(Compra* this,float* precioUnitario);

int Compra_setUnidades(Compra* this,int unidades);
int Compra_getUnidades(Compra* this,int* unidades);

int Compra_setIva(Compra* this,float iva);
int Compra_getIva(Compra* this,float* iva);

int Compra_setMontoTotal(Compra* this,float montoTotal);
int Compra_getMontoTotal(Compra* this,float* montoTotal);

int mostrarCompra(void* pElement);
int criterioParaLista(void* pElement, void* id);
LinkedList* mostrarPorId(LinkedList* listaCompras, LinkedList* listaFiltrada);
int com_calcularMonto(void* p);

#endif // COMPRA_H_INCLUDED
