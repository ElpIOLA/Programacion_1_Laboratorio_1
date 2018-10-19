#include <stdio.h>
#include <stdlib.h>

int funcion(void)
{
    return 7;
}

void funcionRecibeFuncion(int (*pepe)(void))
{
    pepe();
    printf("devolvio %d\n", pepe());
}

int main()
{
    printf("%p\n",funcion);
    funcionRecibeFuncion(funcion);
    return 0;
}
