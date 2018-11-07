#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/** \brief reserva memoria en el heap para la entidad
 * \param
 * \param
 * \return Employee* puntero de tipo entidad
 *
 */
Employee* Employee_new();

/** \brief libera memoria del heap para la entidad
 * \param
 * \param
 * \return void no devuelve nada
 *
 */
void Employee_delete();

/** \brief reserva memoria y agrega parametros de una entidad en el heap
 * \param id int el id de la entidad
 * \param nombre char* puntero al nombre de la entidad
 * \param horasTrabajadas int las horas trabajadas de la entidad
 * \param sueldo int el sueldo de la entidad
 * \return Employee* devuelve el puntero a la entidad
 *
 */
Employee* Employee_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo);


/** \brief agrega el id de la entidad en el heap
 * \param this Employee* puntero a la entidad
 * \param id int el id a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Employee_setId(Employee* this,int id);

/** \brief carga el id de la entidad desde el heap
 * \param this Employee* puntero a la entidad
 * \param id int el id donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Employee_getId(Employee* this,int* id);


/** \brief agrega el nombre de la entidad en el heap
 * \param this Employee* puntero a la entidad
 * \param nombre char*  puntero al nombre a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Employee_setNombre(Employee* this,char* nombre);


/** \brief carga el nombre de la entidad desde el heap
 * \param this Employee* puntero a la entidad
 * \param nombre char* puntero a la variable donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Employee_getNombre(Employee* this,char* nombre);


/** \brief agrega las horas trabajadas de la entidad en el heap
 * \param this Employee* puntero a la entidad
 * \param horasTrabajadas int las horas trabajadas a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief carga el las horas trabajadas de la entidad desde el heap
 * \param this Employee* puntero a la entidad
 * \param horasTrabajadas int el puntero a donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief agrega el sueldo de la entidad en el heap
 * \param this Employee* puntero a la entidad
 * \param sueldo int el sueldo a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Employee_setSueldo(Employee* this,int sueldo);

/** \brief carga el sueldo de la entidad desde el heap
 * \param this Employee* puntero a la entidad
 * \param sueldo int el puntero a donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Employee_getSueldo(Employee* this,int* sueldo);

/** \brief agrega datos a la entidad para luego guardarla en la linkedList
 * \param this Employee* puntero a la entidad
 * \param nuevoId int el nuevo id a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Employee_addDesdeLinkedList(Employee* this, int nuevoId);

/** \brief modifica los datos de la entidad guardada en el linkedList
 * \param this Employee* puntero a la entidad
 * \param
 * \return -1 si error. 0 si ok
 *
 */
int Employee_editDesdeLinkedList(Employee* this);

/** \brief compara dos elementos de la entidad por sus nombres
 * \param void* elementoUno el primer elemento a comparar
 * \param void* elementoDos el segundo elementoa comparar
 * \return -1 si error. 0 si ok
 *
 */
int Employee_sortComparacion(void* elementoUno, void* elementoDos);

#endif // EMPLOYEE_H_INCLUDED
