#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cant;
    char buffer[4][100];

    Employee* auxEmpleado;

    cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    printf("%s %s %s %s\n",buffer[0],buffer[1],buffer[2],buffer[3]);

      while( !feof(pFile))
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(cant == 4 )
        {
            auxEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

            ll_add(pArrayListEmployee,auxEmpleado);// Los datos del archivo los cargo en la linkedList

            printf("%d %s %d %d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        }
        else
        {
            break;
        }
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int cant;
    int limite = ll_len(pArrayListEmployee);

    Employee auxEmpleado;

      while(!feof(pFile))
    {
        fread(&auxEmpleado,sizeof(Employee),limite,pFile);

        ll_add(pArrayListEmployee,&auxEmpleado);

        fprintf(pFile,"%d %s %d %d\n",auxEmpleado.id,auxEmpleado.nombre,auxEmpleado.horasTrabajadas,auxEmpleado.sueldo);

        todoOk=1;
    }
    return todoOk;
}
