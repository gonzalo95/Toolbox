#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* lista = al_newArrayList();

    int i;
    int len;
    Employee* pAux;

    if(lista == NULL)
    {
        printf("Error al crear ArrayList\n");
        return -1;
    }
    FILE* pData = fopen("data.csv", "r");
    int opcion;

    do
    {
        printf("\nMENU:\n");
        printf("1. Parse del archivo data.csv\n");
        printf("2. Listar Empleados\n");
        printf("3. Ordenar por nombre\n");
        printf("4. Agregar un elemento\n");
        printf("5. Elimina un elemento\n");
        printf("6. Listar Empleados (Desde/Hasta)\n");
        printf("7. Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(pData != NULL)
            {
                parserEmployee(pData, lista);
                printf("Archivo cargado satisfactoriamente\n");
            }
            else
                printf("Archivo inexistente\n");

            break;

        case 2:
            //int i;
            //int len = al_len(lista);
            //Employee* pAux;
            len = al_len(lista);
            for(i = 0; i < len; i++)
            {
                pAux = al_get(lista, i);
                employee_print(pAux);
            }

            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            printf("Programa finalizado\n");
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
    }
    while(opcion != 7);



    /*
    int i;
    Employee* auxE;
    ArrayList* lista;
    lista = al_newArrayList();
    Employee* e1;
    e1 = (Employee*)malloc(sizeof(Employee));
    Employee* e2;
    e2 = (Employee*)malloc(sizeof(Employee));

    if(lista != NULL)
    {
        e1->id = 666;
        strcpy(e1->name, "Juan");
        strcpy(e1->lastName, "Gomes");
        e1->isEmpty = 1;
    }
    al_add(lista, e1);

    if(lista != NULL)
    {
        e2->id = 1;
        strcpy(e2->name, "Alfredo");
        strcpy(e2->lastName, "Arias");
        e2->isEmpty = 1;
    }
    al_add(lista, e2);

    printf("Len: %d\n", al_len(lista));

    al_sort(lista, employee_compare, 1);

    for(i = 0; i < al_len(lista); i++)
    {
        printf("\n");
        auxE = (Employee*)al_get(lista, i);
        employee_print(auxE);
    }
    */

    return 0;
}
