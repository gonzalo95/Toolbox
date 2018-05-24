#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define OCUPADO 1
#define LIBRE 0

void inicializarArray(struct lista[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void cargarRegistros(struct lista[])
{
    // REGISTROS

    int i;
    for(i = 0; i < REGISTROS; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].estado = OCUPADO;
    }
}

int obtenerId(struct lista[], int len)
{
    int retorno;
    int mayorId = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if((lista[i].id > mayorId || mayorId == -1) && lista[i].estado == OCUPADO)
            mayorId = lista[i].id;
    }
    retorno = mayorId + 1;
    return retorno;
}

int buscarEspacioLibre(struct lista[], int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarPorId(struct lista[], int len, int id)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void imprimir(struct lista[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == OCUPADO)
            printf("%d -- %s -- %d\n", lista[i].id, lista[i].nombre, lista[i].estado);
    }
}

void ordenar(struct lista[], int len)
{
    int i;
    int j;
    struct aux;
    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                   aux = lista[i];
                   lista[i] = lista[j];
                   lista[j] = aux;
            }
        }
    }
}

int esSoloLetras(char cadena[])
{
   int i = 0;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

void pedirNombre(char mensaje[],char input[])
{
    int validacion = 0;
    char aux[20];
    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        get(aux);
        validacion = esSoloLetras(aux);
        if(validacion == 0)
            printf("Dato invalido\n");
    }
    while(validacion == 0);
    strcpy(input, aux);
}

int chequearPass(char pass[])
{
    int retorno = -1;
    char aux[20];
    printf("Pass: ");
    scanf("%s", aux);
    if(strcmp(pass, aux) == 0)
        retorno = 1;
    else
        printf("Pass incorrecto\n");
    return retorno;
}

int pedirId()
{
    int id;
    int retorno;
    printf("Ingrese el id: ");
    scanf("%d", &id);
    retorno = buscarPorId(lista, len, id);
    if(retorno == -1)
        printf("Id inexistente\n");
    return retorno
}

int pedirStock(char mensaje[])
{
    int retorno;
    int validacion = -1;
    char aux[256];
    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(aux);
        if(esEnteroPositivo(aux))
        {
            validacion = 1;
            retorno = atoi(aux);
        }
        else
            printf("Dato invalido\n");
    }
    while(validacion == -1);
    return retorno;
}

int esEnteroPositivo(char str[])
{
    int i = 0;
    while(str[i] != '\0')
   {
       if(!isdigit(str[i])) return 0;
       i++;
   }
   return 1;
}

char confirmar(char mensaje[])
{
    char aux;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &aux);
    return aux;
}
