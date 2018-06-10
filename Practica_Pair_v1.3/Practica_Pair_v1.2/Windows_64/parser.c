#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Employee.h"

int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char string[50];
    int i = 0;
    int flag = 0;
    Employee* pAux;
    //Employee* pAux = (Employee*)malloc(sizeof(Employee));  // ACA USAR NEWEMPLOYEE
    //if(pFile == NULL || pAux == NULL)
    //return 0;

    while(i <1000) // !feof(pFile)
    {
        fgets(string,100, pFile);
        if(!flag) // SALTEO EL 1º VALOR (TITULO)
        {
            flag = 1;
            continue;
        }

        pAux = (Employee*)malloc(sizeof(Employee)); // ACA USAR NEWEMPLOYEE

        pAux->id = atoi(strtok(string, ","));
        strcpy(pAux->name, strtok(NULL, ","));
        strcpy(pAux->lastName, strtok(NULL, ","));
        if(strcmp(strtok(NULL, ","), "false\n") == 0)
            pAux->isEmpty = 0;
        else
            pAux->isEmpty = 1;

        if(al_add(pArrayListEmployee, pAux))
            return 0;
        i++;
    }


    return 1;
}
