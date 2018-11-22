#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"
int parser_LoadText(FILE* pfile, LinkedList* lista);
int parser_loadTextSinVerificar(FILE* pfile, LinkedList* lista);
int parser_loadBinary(FILE* pfile, LinkedList* lista);
int parser_saveBinary(FILE* pfile, LinkedList* lista);
int parser_saveText(FILE* pfile, LinkedList* lista);
#endif // PARSER_H_INCLUDED
