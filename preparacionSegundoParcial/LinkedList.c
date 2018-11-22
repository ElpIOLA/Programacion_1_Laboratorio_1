#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    if(this != NULL && ll_len(this)>0 && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++)
        {
            pNode=pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    Node* pAuxNodeUno = NULL;
    Node* pAuxNodeDos = NULL;
    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNode = malloc(sizeof(Node));
        if(nodeIndex == 0 && this->pFirstNode != NULL)
        {
            pNode->pNextNode = this->pFirstNode;
            this->pFirstNode = pNode;
        }
        else if(nodeIndex==0 && this->pFirstNode == NULL)
        {
            this->pFirstNode=pNode;
        }
        else if(nodeIndex > 0 && nodeIndex < ll_len(this))
        {
            pAuxNodeUno = getNode(this,(nodeIndex-1));
            pAuxNodeDos = getNode(this,nodeIndex);
            pAuxNodeUno->pNextNode=pNode;
            pNode->pNextNode=pAuxNodeDos;
        }
        else if(nodeIndex > 0 && nodeIndex == ll_len(this))
        {
            pAuxNodeUno=getNode(this,(nodeIndex-1));
            pAuxNodeUno->pNextNode=pNode;
        }
        this->size++;
        pNode->pElement=pElement;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        addNode(this,ll_len(this),pElement);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this)> 0)
    {
        pNode=getNode(this,index);
        returnAux=pNode->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode=NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this)> 0)
    {
        pNode=getNode(this,index);
        pNode->pElement=pElement;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode=NULL;
    Node* pAuxNode=NULL;
    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this)> 0)
    {
        if(index!=0 && index != (ll_len(this)-1))
        {
            pAuxNode=getNode(this,(index-1));
            pNode=getNode(this,index);
            pAuxNode->pNextNode=pNode->pNextNode;
            free(pNode);
        }
        else if(index==0)
        {
            pNode=getNode(this,index);
            this->pFirstNode=pNode->pNextNode;
            free(pNode);
        }
        else if(index!=0 && index == (ll_len(this)-1))
        {
            free(pNode);
        }
        this->size--;
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    if(this != NULL)
    {
        for(i=(ll_len(this)-1); i>=0; i--)
        {
            ll_remove(this,i);
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pAux=NULL;
    int i;
    if(this != NULL && ll_len(this)>0)
    {
        i=0;
        startIterator(this,i);
        while(i<ll_len(this))
        {
            pAux=ll_getNext(this);
            if(pAux==pElement)
            {
                returnAux=i;
                break;
            }
            i++;
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(ll_len(this)>0)
        {
            returnAux=0;
        }
        else if(ll_len(this)==0)
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        if(!addNode(this,index,pElement))
        {
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux=ll_get(this,index);
        if((returnAux!=NULL))
        {
            ll_remove(this,index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux=0;
        if(ll_indexOf(this,pElement)!=-1)
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pAux=NULL;
    int i;
    if(this != NULL && this2 != NULL)
    {
        returnAux=1;
        i=0;
        startIterator(this2,i);
        while(i<ll_len(this2))
        {
            pAux=ll_getNext(this2);
            if(!ll_contains(this,pAux))
            {
                returnAux=0;
                break;
            }
            i++;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pAux;
    int i;
    if(this != NULL && from >= 0 && to>from && from < ll_len(this) && to <= ll_len(this) && !ll_isEmpty(this))
    {
        cloneArray=ll_newLinkedList();
        i=from;
        startIterator(this,i);
        while(i<to)
        {
            pAux=ll_getNext(this);
            ll_add(cloneArray,pAux);
            i++;
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL && !ll_isEmpty(this))
    {
        cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pElement1=NULL;
    void* pElement2=NULL;
    void* aux=NULL;
    int i;
    int j;
    if(this != NULL && pFunc != NULL && !ll_isEmpty(this) && order < 2 && order >= 0)
    {
        for(i=0; i<(ll_len(this)-1); i++)
        {
            pElement1=ll_get(this,i);
            j=i+1;
            startIterator(this,j);
            while(j<ll_len(this))
            {

                pElement2=ll_getNext(this);
                if(order==1)
                {
                    if(pFunc(pElement1,pElement2)>0)
                    {
                        aux=pElement1;
                        pElement1=pElement2;
                        pElement2=aux;
                    }
                }
                else if(order==0)
                {
                    if(pFunc(pElement1,pElement2)<0)
                    {
                        aux=pElement2;
                        pElement2=pElement1;
                        pElement1=aux;
                    }
                }
                ll_set(this,i,pElement1);
                ll_set(this,j,pElement2);
                j++;
            }

        }
        returnAux=0;
    }
    return returnAux;
}

/** \brief  guarda el nodo indicado con un indice en el campo pNext de la LInkedList
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Indice del nodo a obtener
 * \return Node* Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                          (0) Si funciono correctamente
 *
 */
int startIterator(LinkedList* this, int nodeIndex)
{
    int returnAux=-1;

    if(this != NULL && ll_len(this)>0 && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        this->pNext=getNode(this,nodeIndex);
        returnAux=0;
    }
    return returnAux;
}

/** \brief obtiene el elemento del nodo apuntado en pNext y luego reemplaza ese nodo por el siguiente
 *
 * \param this LinkedList* Puntero a la lista
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                          (puntero al elemento) Si funciono correctamente
 *
 */
void* ll_getNext(LinkedList* this)
{
    void* returnAux=NULL;
    Node* nextNode;
    if(this != NULL)
    {
        nextNode=this->pNext;
	    returnAux=nextNode->pElement;
        this->pNext=nextNode->pNextNode;
    }
    return returnAux;
}

/** \brief filtra los elementos de la lista utilizando la funcion criterio recibida como parametro
            y los agrega a otra lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la lista es NULL, el puntero a la funcion criterio es NULL o
                                si la lista esta vacia.
                                (puntero a nueva lista) Si ok
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* this2=NULL;
    void* pElement=NULL;
    int i;

    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        this2= ll_newLinkedList();
        i=0;
        startIterator(this,i);
        while(i<ll_len(this))
        {
            pElement=ll_getNext(this);
            if(pFunc(pElement))
            {
                ll_add(this2,pElement);
            }
            i++;
        }
    }
    return this2;
}

/** \brief filtra los elementos de la lista utilizando un argumento y la funcion criterio recibidos como parametros
            y los agrega a otra lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param args void* el argumento que recibe la funcion filter
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la lista es NULL, el puntero a la funcion criterio es NULL o
                                si la lista esta vacia.
                                (puntero a nueva lista) Si ok
 */
LinkedList* ll_filterArgs(LinkedList* this, int (*pFunc)(void*,void*), void* args)
{
    LinkedList* this2=NULL;
    void* pElement=NULL;
    int i;

    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        this2= ll_newLinkedList();
        i=0;
        startIterator(this,i);
        while(i<ll_len(this))
        {
            pElement=ll_getNext(this);
            if(pFunc(pElement,args))
            {
                ll_add(this2,pElement);
            }
            i++;
        }
    }
    return this2;
}


/** \brief rrecorre la lista y realiza una funcion utilizando un elemento de esta
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion
 * \return LinkedList* Retorna  (-1) Error: si el puntero a la lista es NULL, el puntero a la funcion criterio es NULL o
                                si la lista esta vacia.
                                (0) si no se pudo realizar siempre la funcion con exito
                                (1) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux=-1;
    void* pElement=NULL;
    int i;

    if(this != NULL && pFunc != NULL && !ll_isEmpty(this))
    {
        returnAux=1;
        i=0;
        startIterator(this,i);
        while(i<ll_len(this))
        {
            pElement=ll_getNext(this);
            if(pFunc(pElement)!=0)
            {
                returnAux=0;
                break;
            }
            i++;
        }
    }
    return returnAux;
}
