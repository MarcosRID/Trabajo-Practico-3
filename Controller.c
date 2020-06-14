#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    FILE* punteroFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {

     punteroFile = fopen(path,"r");

        if(parser_EmployeeFromText(punteroFile,pArrayListEmployee))
        {
            todoOk=1;
        }
    }

    fclose(punteroFile);

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    FILE* punteroFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {

     punteroFile = fopen(path,"rb");

        if(parser_EmployeeFromText(punteroFile,pArrayListEmployee))
        {
            todoOk = 1;
        }
    }

    fclose(punteroFile);

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int id;
    int idBucar;
    int indice;
    char auxNombre[20];
    int auxHoras;
    int auxSueldo;
    Employee* aux;
    int tam=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese ID deseado\n");
        scanf("%d",&id);

        for(int i=0; i < tam;i++)
        {
                aux=(Employee*)ll_get(pArrayListEmployee,i);

            if(aux->id==id)
               {
                    indice=i;
                    break;
               }
        }

        switch(menuEdit())
        {
            case 1:
                    printf("Ingrese nuevo nombre\n");
                    fflush(stdin);
                    gets(auxNombre);
                    employee_setNombre(aux,auxNombre);
            break;

            case 2:
                    printf("Ingrese nuevo dato (HORAS)\n");
                    scanf("%d",&auxHoras);
                    employee_setHorasTrabajadas(aux,auxHoras);
            break;

            case 3:
                    printf("Ingrese nuevo Sueldo\n");
                    scanf("%d",&auxSueldo);
                    employee_setSueldo(aux,auxSueldo);
            break;

            case 4:
            break;

        }
        todoOk=1;
    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int tam=ll_len(pArrayListEmployee);

        for(int i=0; i< tam;i++)
        {
            listarUnEmpleado((Employee*)ll_get(pArrayListEmployee,i));
        }
        todoOk=1;

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    FILE* pFile;
    Employee* auxEmp;
    char auxNombre[20];
    char pasajeIdString[20];
    char pasajeHorasString[20];
    char pasajeSueldoString[20];
    int tam=ll_len(pArrayListEmployee);

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
         pFile=fopen(path,"w");

        for(int i=0; i < tam ;i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);

            employee_getNombre(auxEmp,auxNombre);

            itoa(auxEmp->id,pasajeIdString,10);
            itoa(auxEmp->horasTrabajadas,pasajeHorasString,10);
            itoa(auxEmp->sueldo,pasajeSueldoString,10);

            fprintf(pFile,"%s,%s,%s,%s\n",pasajeIdString,auxNombre,pasajeHorasString,pasajeSueldoString);
        }
        todoOk=1;
    }

    fclose(pFile);

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk=0;

    FILE* pFile;
    Employee* auxEmp;
    int tam=ll_len(pArrayListEmployee);

    if( pFile!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"wb");

        for(int i=0; i < 1 ;i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);

            fwrite(auxEmp,sizeof(Employee),1,pFile);
        }
        todoOk=1;
    }

    fclose(pFile);

    return todoOk;
}
int menuEdit()
{
    int indice;

    printf("1. Editar Nombre\n");
    printf("2. Editar Horas\n");
    printf("3. EditarSueldo\n");
    printf("10. Salir\n\n");

    printf("Ingrese opcion\n");
    scanf("%d",&indice);

    return indice;
}
int listarUnEmpleado(Employee* elemento)
{
    int todoOk=0;

    if(elemento != NULL)
    {
        printf("%d %9s %d %d\n",elemento->id,elemento->nombre,elemento->horasTrabajadas,elemento->sueldo);

        todoOk=1;
    }

    return todoOk;
}
