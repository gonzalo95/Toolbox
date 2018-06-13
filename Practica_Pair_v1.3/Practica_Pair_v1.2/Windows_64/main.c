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


void listar(ArrayList*);
void ordenar(ArrayList*);
void listarRango(ArrayList*);
void agregar(ArrayList*);
void eliminar(ArrayList*);

int main()
{
    ArrayList* lista = al_newArrayList();

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
            parserEmployee(pData, lista);
            break;

        case 2:
            listar(lista);
            break;

        case 3:
            ordenar(lista);
            break;

        case 4:
            agregar(lista);
            break;

        case 5:
            eliminar(lista);
            break;

        case 6:
            listarRango(lista);
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


void listar(ArrayList* lista)
{
    int i;
    int len = al_len(lista);
    Employee* pAux;
    len = al_len(lista);
    for(i = 0; i < len; i++)
    {
        pAux = al_get(lista, i);
        employee_print(pAux);
    }
}

void ordenar(ArrayList* lista)
{
    int orden;
    printf("Ordenar de forma ascendente(1) o descendente(0)?: \n"); //VALIDAR INGRESO
    scanf("%d", &orden);
    if(orden < 0 || orden > 1)
    {
        printf("Opcion invalida\n");
        return;
    }
    al_sort(lista, employee_compare, orden);
    listar(lista);
}

void listarRango(ArrayList* lista)
{
    int desde;
    int hasta;
    printf("Desde: \n"); //VALIDAR INGRESOS
    scanf("%d", &desde);
    printf("Hasta: \n");
    scanf("%d", &hasta);
    if((desde < 0 || desde >= al_len(lista))|| (hasta < 0 || hasta >= al_len(lista)))
    {
        printf("Fuera de rango\n");
        return;
    }
    ArrayList* pSublista;
    pSublista = al_subList(lista, desde, hasta);
    listar(pSublista);
}

void agregar(ArrayList* lista)
{
    Employee* pNuevo;
    Employee* aux;
    pNuevo = employee_new();
    int id;
    int index;
    char nombre[20];
    char apellido[20];
    index = (lista->size == 0) ? 0 : lista->size-1;

    aux = al_get(lista, index);
    if(aux == NULL || pNuevo == NULL)
    {
        printf("No se puede agregar un nuevo elemento\n");
        return;
    }
    id = (aux->id)+1;
    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese el apellido: \n");
    fflush(stdin);
    gets(apellido);
    employee_setId(pNuevo, id);
    employee_setIsEmpty(pNuevo, 0);
    employee_setName(pNuevo, nombre);
    employee_setLastName(pNuevo, apellido);

    /*
    pNuevo->id = id;
    strcpy(pNuevo->name, nombre);
    strcpy(pNuevo->lastName, apellido);
    pNuevo->isEmpty = 0;
    */

    al_add(lista, pNuevo);
}

void eliminar(ArrayList* lista)
{
    int id;
    char confirmacion;
    int i;
    int index = -1;
    Employee* aux;
    listar(lista);
    printf("Ingrese el id: \n");
    scanf("%d", &id);
    if(id < 0)
    {
        printf("Id Invalida\n");
        return;
    }

    for(i = 0; i < al_len(lista); i++)
    {
        aux = al_get(lista, i);
        if(aux != NULL)
        {
            if(employee_getId(aux) == id)
            {
                index = i;
                break;
            }
        }
    }

    if(index == -1)
    {
        printf("Id inexistente\n");
        return;
    }

    printf("Seguro desea continuar: s/n\n");
    fflush(stdin);
    scanf("%c", &confirmacion);
    if(confirmacion == 's')
    {
        al_remove(lista, index);
    }
}
