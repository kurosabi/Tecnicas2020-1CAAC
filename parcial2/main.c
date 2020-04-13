#include "FuncionesCC.h"
#include <stdio.h>


int menu()
{

    int opcion = 0;

    printf(" Opciones  \n\n");
    printf("1. Crear un centro Comercial\n");
    printf("2. Crear un nuevo local en el centro Comercial\n");
    printf("3. Consultar informacion del centro comercial\n");
    printf("4. Modificar la informacion de un local\n");
    printf("5. Eliminar un Local (este local pasará a estar disponible)\n");
    printf("6. Salir\n");
    printf("\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}


int main(){

	local_t **centroComercial;
	int i, j, numPisos, numLocales, option;

    do
    {
        option = menu();
        switch (option){

            case 1:

        		printf("Ingrese el numero de pisos para el centro comercial:");
				scanf("%d", &numPisos);
				printf("\n");
				printf("Ingrese el numero de locales para el centro comercial:");
				scanf("%d", &numLocales);
				printf("\n");

                centroComercial = reservaCC(numPisos, numLocales);
                inicializacionMatriz(centroComercial, numPisos, numLocales);
                break;

            case 2:

            	crearNuevoLocal(centroComercial);		
            	break;

            case 3:

            	infoCC(centroComercial, numPisos, numLocales);
            	break;

            case 4:

            	modificarInfoLocal(centroComercial);
            	break;

            case 5:

            	eliminarLocales(centroComercial);
            	break;

            case 6:
                break;
            
            default:
                printf("Opcion invalida\n");
                break;
        }

    } while (option != 6);
	
	return 0;
}