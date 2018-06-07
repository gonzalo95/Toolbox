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
    return 0;
}
