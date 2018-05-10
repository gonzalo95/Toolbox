
// Me devuelve la siguiente id
int llamadas_findNextId(sLlamada* pLlamadas, int len)
{
    int i, maxId = -1;
    int retorno;
    for(i = 0; i < len; i++)
    {
        if(pLlamadas[i].flagEstado == LLAMADA_USED )
        {
            if(pLlamadas[i].idLlamada > maxId || maxId == -1)
                maxId = pLlamadas[i].idLlamada;
        }
    retorno = maxId+1;
    }
    return retorno;
}

// Me devuelve el indice de un espacio vacio
int llamadas_findEmptyPlace(sLlamada* pLlamadas, int len)
{
    int i;
    int retorno = -1;
    for(i = 0; i < len; i++)
    {
        if(pLlamadas[i].flagEstado == LLAMADA_EMPTY)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

// Me devuelve el indice del elemento con la id ingresada
int buscarIndexUsuario(eUsuario lista[], int id, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].id == id && lista[i].estado != 0)
        {
            index = i;
            break;
        }
    }
    return index;
}


// inicializa un vector con 0
void inicializar(int lista[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        lista[i] = 0;
    }
}

// Te pide un numero y lo valida
int pedirEnteroValido(char mensaje[])
{
    char input[50];
    int validacion;
    do
    {
        printf("%s\n", mensaje);
        scanf("%s", input);
        validacion = validarEntero(input)
    }
    while(validacion == -1)

    return atoid(input);
}

// Valida que la cadena sea un entero
int validarEntero(char input[])
{
   int i=0;
   while(input[i] != '\0')
   {
       if (i == 0 && input[i] == '-')
       {
           i++;
           continue;

       }
       if(input[i] < '0' || input[i] > '9')
       {
            printf("No es un numero\n");
            return -1;
       }

       i++;
   }
   return 1;
}

//Imprime todos los campos de todos los elementos de un array
void listarUsuarios(eUsuario lista[], int len)
{
    int i;
    float promedio;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%d -- %s -- %.2f\n", lista[i].id, lista[i].nombre, lista[i].promedio);
        }

    }
}

// Pide un pass y lo comprueba
int chequearPass(eUsuario lista[], int index)
{
    char pass[20];
    int respuesta = 1;
    printf("Pass: ");
    fflush(stdin);
    gets(pass);
    if(strcmp(lista[index].pass, pass) != 0)
        respuesta = -1;
    return respuesta;
}

//
int pedirFloatValido(char mensaje[],char input[])
{
    int validacion = -1;
    char aux[256];

    do
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(aux);
        validacion = esNumericoFlotante(aux);
    }
    while(validacion == -1)

    strcpy(input,aux);
    return 1;
}

// Comprueba que una cadena sea un float
int esNumericoFlotante(char str[])
{
   int i = 0;
   int cantidadPuntos = 0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0 && i != 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
       {
            printf("No es un numero de punto flotante\n");
            return -1;
       }

       i++;
   }
   return 1;
}

// Comprueba que la cadena sea solo letras
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
