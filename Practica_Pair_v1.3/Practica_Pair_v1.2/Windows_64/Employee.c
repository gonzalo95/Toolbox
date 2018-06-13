#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno;
    Employee* e1 = (Employee*)pEmployeeA;
    Employee* e2 = (Employee*)pEmployeeB;

    retorno = strcmp(e1->name, e2->name);

    return retorno;
}


void employee_print(Employee* this)
{
    printf("Id: %d -- Nya: %s, %s -- Vacio: %d\n", this->id, this->name, this->lastName, this->isEmpty);
}


Employee* employee_new(void)
{
    Employee* newE;
    newE = (Employee*)malloc(sizeof(Employee));

    return newE;

}

void employee_delete(Employee* this)
{
    if(this != NULL)
        this->isEmpty = 0;
}

int employee_setId(Employee* this, int id)
{
    if(this != NULL)
    {
        this->id = id;
        return 1;
    }
    return 0;
}

int employee_getId(Employee* this)
{
    if(this != NULL)
        return this->id;

    return 0;
}

int employee_setName(Employee* this, char* name)
{
    if(this != NULL)
    {
        strcpy(this->name, name);
        return 1;
    }
    return 0;
}

char* employee_getName(Employee* this)
{
    if(this != NULL)
        return this->name;

    return NULL;
}

int employee_setLastName(Employee* this, char* name)
{
    if(this != NULL)
    {
        strcpy(this->lastName, name);
        return 1;
    }
    return 0;
}

char* employee_getLastName(Employee* this)
{
    if(this != NULL)
        return this->lastName;

    return NULL;
}

int employee_setIsEmpty(Employee* this, int status)
{
    if(this != NULL)
    {
        this->isEmpty = status;
        return 1;
    }
    return 0;
}

int employee_getIsEmpty(Employee* this)
{
    if(this != NULL)
        return this->isEmpty;

    return 0;
}

