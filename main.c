#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();



int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    Employee* auxEmpleado;

    char id[20];
    char nombre[20];
    char horasDT[20];
    char sueldo[20];
// -----case 5-----
    int auxId;
    int idBucar;
    int indice;
    char confirmar;
    Employee* backup;
    int tam;
//-----------------
    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv",listaEmpleados)==1)//cargo los dato en Texto
            {
                printf("Se logro cargar los datos Formato texto\n");
            }
            else
            {
                printf("Se produjo un eRror al cargar los datos en Formato Texto\n");
            }
            getch();
            break;

        case 2:
            if(controller_loadFromBinary("datab.csv",listaEmpleados)==1)//Cargo los datos en binario
            {
                printf("Se logro cargar datos Formato binario\n");

            }
            else
            {
                printf("Se produjo un eRror al cargar los datos en Formato Binario\n");
            }
            getch();
            break;
        case 3:

            printf("Ingrese Id\n");
            fflush(stdin);
            gets(id);
            printf("Ingrese Nombre\n");
            fflush(stdin);
            gets(nombre);
            printf("Ingrese Horas de trabajo\n");
            fflush(stdin);
            gets(horasDT);
            printf("Ingrese sueldo\n");
            fflush(stdin);
            gets(sueldo);

            auxEmpleado=employee_newParametros(id,nombre,horasDT,sueldo);

            ll_add(listaEmpleados,auxEmpleado);

            break;
        case 4:
            if(controller_editEmployee(listaEmpleados))
            {
                printf("Se realizo con exito la modificacion\n");
            }
            else
            {
                printf("Ocurrio un eRror con la modificacion\n");
            }
            getch();
            break;

        case 5:

            tam=ll_len(listaEmpleados);
            controller_ListEmployee(listaEmpleados);

            printf("Ingrese ID deseado\n");
            scanf("%d",&auxId);

            for(int i=0; i < tam; i++)
            {
                backup=ll_get(listaEmpleados,i);

                if(backup->id==auxId)
                {
                    indice=i;
                    break;
                }
            }
            listarUnEmpleado(backup);
            printf("Confirma la baja= S=Si N=No\n");
            fflush(stdin);
            scanf("%c",&confirmar);

            if('s'== tolower(confirmar) && ll_remove(listaEmpleados,indice)==0)
            {
                printf("Se realizo la baja con exito\n");

            }
            else
            {
                printf("Se produjo un eRror al realizar la baja\n");
            }
            getch();
            break;

        case 6:
            if(controller_ListEmployee(listaEmpleados))
            {
                printf("Se listo los empleados correctamente\n");
            }
            else
            {
                printf("Se produjo un error al litar empleados\n");
            }
            getch();
            break;
        case 7:

            break;
        case 8:
            controller_saveAsText("data.csv",listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("datab.csv",listaEmpleados);
            break;
        case 10:

            break;
        }
    }
    while(option != 10);

    return 0;
}

int menu()
{
    int indice;

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n\n");

    printf("Ingrese opcion\n");
    scanf("%d",&indice);

    return indice;
}
