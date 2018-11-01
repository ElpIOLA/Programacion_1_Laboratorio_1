#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* Employee_new();
void Employee_delete();
Employee* Employee_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo);

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);

int Employee_setNombre(Employee* this,char* nombre);
int Employee_getNombre(Employee* this,char* nombre);

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);

int Employee_add(Employee* this, int nuevoId);

int verificarId(char* stringId, int enteroConvertido);
int verificarNombre(char* stringNombre);
int verificarHorasTrabajadas(char* stringHorasTrabajadas, int enteroConvertido);
int verificarSalario(char* stringSalario, int enteroConvertido);

#endif // EMPLOYEE_H_INCLUDED