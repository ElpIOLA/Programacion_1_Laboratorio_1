#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

/** \brief sets a float
 * \param flt float the float number
 * \return float Return the float number
 *
 */
float utn_setFlotante(char mensaje[], float flotante);

/** \brief sets an integer
 * \param intg int the integer
 * \return int Return the integer
 *
 */
int utn_setEntero(char mensaje[], int entero);

/** \brief sets a name
 * \param str char a string
 * \param len int string lenght
 * \return int (0) if error - (1) if ok
 *
 */
int set_nombre(char mensaje[], char texto[], int len);


/** \brief sets an alphanumeric string
 * \param str char a string
 * \param len int string lenght
 * \return int (0) if error - (1) if ok
 *
 */
int set_texto(char mensaje[], char texto[], int len);

int set_cuit(char mensaje[], char cuit[], int len);

/** \brief sets a float in a margin
 * \param flt float the float number
 * \param minimun float the minimun float number posible
 * \param maximun float the maximun float number posible
 * \return float Return the float number
 *
 */
float set_margenFlotante(char mensaje[], float flotante, float min, float max);

/** \brief sets a integer in a margin
 * \param intg int the integer
 * \param minimun int the minimun integer posible
 * \param maximun int the maximun integer posible
 * \return int Return the integer
 *
 */
int set_margenEntero(char mensaje[], int entero, int min, int max);


/** \brief validates that a string has a flotant number
 * \param str char a string
 * \param len int string lenght
 * \return int (0) if error - (1) if ok
 *
 */
int validar_flotante(char str[], int len);

/** \brief validates that a string has an integer
 * \param str char a string
 * \param len int string lenght
 * \return int (0) if error - (1) if ok
 *
 */
int validar_entero(char str[],int len);

/** \brief validates than a string has alphabetic characters
 * \param str char a string
 * \param len int string lenght
 * \return int (0) if error - (1) if ok
 *
 */
int validar_alfabetico(char str[], int len);

/** \brief validates than a string has alphanumeric characters
 * \param str char a string
 * \param len int string lenght
 * \return int (0) if error - (1) if ok
 *
 */
int validar_alfanumerico(char str[], int len);

int validar_cuit(char str[], int len);

#endif
