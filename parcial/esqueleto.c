#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

int main()
{
    struct array[TAM];

    int opcion;

    // INICIALIZAR ARRAY
    // CARGAR REGISTROS

    do
    {
        printf("1.-Ingreso propietario\n2.-Modificacion propietario\n3.-Baja propietario\n4.-Listar propietarios\n5.-Alta coche\n15.-Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:
            break;

        case 5:

            break;

        case 15:
            printf("Programa finalizado");
            break;

        default:
            printf("Opcion invalida\n");
        }
    }
    while(opcion != 15);
    return 0;
}
