#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseCompras(char* fileName, LinkedList* lista);
int verificarInt(char* idProducto,int* auxIdProducto,char* unidades,int* auxUnidades);
int verificarFloat(char* precioUnitario,float* auxPrecioUnitario,char* iva,float* auxIva);


#endif // PARSER_H_INCLUDED
