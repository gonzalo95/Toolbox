#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Employee.h"

#define REGISTROS 1000

int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char string[50];
    int i = 0;
    int flag = 0;
    Employee* pAux;

    if(pFile == NULL)
    {
        printf("Archivo inexistente\n");
        return 0;
    }


    while(i < REGISTROS) // !feof(pFile)
    {
        fgets(string, 50, pFile);
        if(!flag) // SALTEO EL 1º VALOR (TITULO)
        {
            flag = 1;
            continue;
        }

        //pAux = (Employee*)malloc(sizeof(Employee)); // ACA USAR NEWEMPLOYEE
        pAux = employee_new();
        if(pAux == NULL)
        {
            printf("Error al cargar el archivo\n");
            return 0;
        }


        employee_setId(pAux, atoi(strtok(string, ",")));
        employee_setName(pAux, strtok(NULL, ","));
        employee_setLastName(pAux, strtok(NULL, ","));
        if(strcmp(strtok(NULL, ","), "false\n") == 0)
            employee_setIsEmpty(pAux, 0);
        else
            employee_setIsEmpty(pAux, 1);

        /*
        pAux->id = atoi(strtok(string, ",")); //USAR SETTERS
        strcpy(pAux->name, strtok(NULL, ","));
        strcpy(pAux->lastName, strtok(NULL, ","));
        if(strcmp(strtok(NULL, ","), "false\n") == 0)
            pAux->isEmpty = 0;
        else
            pAux->isEmpty = 1;

        */

        if(al_add(pArrayListEmployee, pAux))
        {
            printf("Error al cargar el archivo\n");
            return 0;
        }
        i++;
    }
    printf("Archivo cargado exitosamente\n");
    return 1;
}
