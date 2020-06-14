#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{
    Employee* auxEmpleado;

    auxEmpleado = (Employee*)malloc(sizeof(Employee));

    if(auxEmpleado == NULL)
    {
        printf("No se pudo conseguir memoria ( funcion Employee* employee_new() )\n");
    }
    return auxEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
 {
      Employee* nuevoEmpleado;

    if((nuevoEmpleado=employee_new())!=NULL)
    {
        nuevoEmpleado->id=atoi(idStr);
        strcpy(nuevoEmpleado->nombre,nombreStr);
        nuevoEmpleado->horasTrabajadas=atoi(horasTrabajadasStr);
        nuevoEmpleado->sueldo=atoi(sueldoStr);

    }
    else
    {
        free(nuevoEmpleado);
        nuevoEmpleado=NULL;
    }

    return nuevoEmpleado;
}
int employee_setId(Employee* this,int id)
{
     int todoOk=0;

    if(this!=NULL )
    {
        this->id =id;
        todoOk=1;
    }
     return todoOk;
}
int employee_getId(Employee* this,int* id)
{
    int todoOk=0;
    if(this!=NULL && id!= NULL)
    {
        id=this->id;
        todoOk=1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* auxNombre)
{
    int todoOk=0;

    if(this!=NULL && auxNombre!= NULL)
    {
        strcpy(this->nombre,auxNombre);
        todoOk=1;
    }

    return todoOk;
}
int employee_getNombre(Employee* this,char* auxNombre)
{

    int todoOk=0;

    if(this!=NULL && auxNombre!= NULL)
    {
        strcpy(auxNombre,this->nombre);
        todoOk=1;
    }

    return todoOk;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;

    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk=1;
    }
     return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;
    if(this!=NULL && horasTrabajadas != NULL)
    {
        horasTrabajadas=this->horasTrabajadas;
        todoOk=1;
    }
    return todoOk;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk=0;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOk=1;
    }
     return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk=0;
    if(this!=NULL && sueldo!= NULL)
    {
        sueldo=this->sueldo;
        todoOk=1;
    }
    return todoOk;
}

