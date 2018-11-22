#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"
int controller_loadFromText(char* path, LinkedList* pArrayListPersona);
int controller_loadFromBinary(char* path, LinkedList* pArrayListPersona);
int controller_verificarTexto(char* path);
int controller_verificarBinario(char* path);
int controller_saveAsBinary(char* path, LinkedList* pArrayListPersona);
int controller_saveAsText(char* path, LinkedList* pArrayListPersona);
#endif // CONTROLLER_H_INCLUDED
