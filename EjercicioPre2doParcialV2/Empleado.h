#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Empleado;

/** \brief reserva memoria en el heap para la entidad
 * \param
 * \param
 * \return Empleado* puntero de tipo entidad
 *
 */
Empleado* Empleado_new();

/** \brief libera memoria del heap para la entidad
 * \param
 * \param
 * \return void no devuelve nada
 *
 */
void Empleado_delete();

/** \brief reserva memoria y agrega parametros de una entidad en el heap
 * \param id int el id de la entidad
 * \param nombre char* puntero al nombre de la entidad
 * \param horasTrabajadas int las horas trabajadas de la entidad
 * \param sueldo int el sueldo de la entidad
 * \return Empleado* devuelve el puntero a la entidad
 *
 */
Empleado* Empleado_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo);


/** \brief agrega el id de la entidad en el heap
 * \param this Empleado* puntero a la entidad
 * \param id int el id a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_setId(Empleado* this,int id);

/** \brief carga el id de la entidad desde el heap
 * \param this Empleado* puntero a la entidad
 * \param id int el id donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_getId(Empleado* this,int* id);


/** \brief agrega el nombre de la entidad en el heap
 * \param this Empleado* puntero a la entidad
 * \param nombre char*  puntero al nombre a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_setNombre(Empleado* this,char* nombre);


/** \brief carga el nombre de la entidad desde el heap
 * \param this Empleado* puntero a la entidad
 * \param nombre char* puntero a la variable donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_getNombre(Empleado* this,char* nombre);


/** \brief agrega las horas trabajadas de la entidad en el heap
 * \param this Empleado* puntero a la entidad
 * \param horasTrabajadas int las horas trabajadas a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);

/** \brief carga el las horas trabajadas de la entidad desde el heap
 * \param this Empleado* puntero a la entidad
 * \param horasTrabajadas int el puntero a donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);


/** \brief agrega el sueldo de la entidad en el heap
 * \param this Empleado* puntero a la entidad
 * \param sueldo int el sueldo a guardar
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_setSueldo(Empleado* this,int sueldo);

/** \brief carga el sueldo de la entidad desde el heap
 * \param this Empleado* puntero a la entidad
 * \param sueldo int el puntero a donde guardar el dato desde el heap
 * \return -1 si error. 0 si ok
 *
 */
int Empleado_getSueldo(Empleado* this,int* sueldo);
int mostrarEmpleados(void* pElement);
int em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
