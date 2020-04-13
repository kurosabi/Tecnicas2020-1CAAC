#include "FuncionesCC.h"
/* Funcion de ejemplo que imprimiria la informacion de un local */
/*
void mostrarLocal(local_t ** centroComercial, int numPiso,
		int numLocalxPiso, int numPisos, int numLocalesxPiso) {
	
	//Se valida si el numero ingresado esta en el rango
	if(numPiso<=numLocalxPiso && numLocalxPiso <= numLocalesxPiso)
	{
		printf("Nombre local : %s", centroComercial[numPiso][numLocalxPiso].nombreLocal);
		printf("Numero local : %d ", centroComercial[numPiso][numLocalxPiso].numeroLocal);
	}
	//TODO completarlo con los datos que le sirvan en su caso
}
*/



/*
	Esta funcion reserva memoria dinamicamente para la matriz
	que representa el centro comercial, los tamaños son 
	de acuerdo al gusto del usuario.
*/
local_t **reservaCC(int numPisos, int numLocales){

	int i;

	local_t **centroComercial = malloc(sizeof(local_t*)*numPisos);

	if(centroComercial != NULL){

		for(i = 0; i < numPisos; i++){

			centroComercial[i] = malloc(sizeof(local_t)*numLocales);

			if(centroComercial[i] == NULL){

				printf("error al crear el centro comercial\n");
				break;
			}
		}

		printf("Se ha creado satisfactoriamente el centro comercial\n\n");
	}
	else{

		printf("error al crear el centro comercial\n");
	}

	return centroComercial;
}


/*
	Esta funcion inicializa la matriz con todos los locales en 1, esto
	quiere decir que todos los locales en un principio estan disponibles.
	En este escenario el 1 significa que el local esta disponible y el
	0 por lo contrario significa que no esta disponible.
*/
void inicializacionMatriz(local_t **centroComercial, int numPisos, int numLocales){

	int i, j;

	for(i = 0; i < numPisos; i++){
		for(j = 0; j < numLocales; j++){

			centroComercial[i][j].disponible = 1;
		}
	}
}


/*
	Esta funcion crea un nuevo local en el centro comercial pero solo
	si el local se encuentra disponible, en caso de que no este disponible
	la funcion le va a pedir al usuario que intente con otro local.	
*/
void crearNuevoLocal(local_t **centroComercial){

	int i, j, piso, local, id;

	srand(time(NULL));

	while(1){


		printf("Ingrese el piso del local: ");
		scanf("%d", &piso);
		printf("\n");
		printf("Ingrese el numero del local: ");
		scanf("%d", &local);
		printf("\n");

		piso = piso - 1;
		local = local - 1;

		if(centroComercial[piso][local].disponible == 1){

			id = rand()%101;
			centroComercial[piso][local].idLocal = id;

			printf("Ingrese un nombre para el local: ");
			scanf("%35s", &centroComercial[piso][local].nombreLocal);
			printf("\n");
			printf("Ingrese un tipo de mercado del local: ");
			scanf("%35s", &centroComercial[piso][local].tipoLocal);
			printf("\n\n");

			centroComercial[piso][local].pisoLocal = piso + 1;
			centroComercial[piso][local].numLocalxPiso = local + 1;	
			centroComercial[piso][local].disponible = 0;

			break;		
		}

		else{
			printf("Este local no se encuentra disponible, intente con un local diferente.\n\n");
		}
	}

	printf("Se ha creado el local satisfactoriamente con los siguentes datos:\n\n");
	printf("Nombre del local: %s\n", centroComercial[piso][local].nombreLocal);
	printf("ID del local: %d\n", centroComercial[piso][local].idLocal);
	printf("Piso: %d\n", piso + 1);
	printf("Numero del local: %d\n", local + 1);
}


/*
	Esta funcion modifica alguna informacion del local que el usuario
	desee, a exepcion del id, puesto que este identificador es unico.	
*/
void modificarInfoLocal(local_t **centroComercial){

	int temp, piso, local;

	printf("Ingrese el piso del local que quiere modificar: ");
	scanf("%d", &piso);
	printf("\n");
	printf("Ingrese el numero del local que quiere modificar: ");
	scanf("%d", &local);
	printf("\n");

	piso = piso - 1;
	local = local - 1;

	do{

		printf("1. Modificar el nombre del local\n");
		printf("2. Modificar el tipo de mercado del local\n");
		printf("3. Terminar\n");
		printf("\n");
    	printf("Opcion: ");
		scanf("%d", &temp);
		printf("\n");

		switch(temp){

			case 1:

				printf("Nombre actual del local: %s\n", centroComercial[piso][local].nombreLocal);
				printf("Ingrese el nuevo nombre del local: ");
				scanf("%35s", &centroComercial[piso][local].nombreLocal);
				printf("\n");
				printf("Nuevo nombre del local: %s\n", centroComercial[piso][local].nombreLocal);
				break;

			case 2:

				printf("Tipo de mercado actual del local: %s\n", centroComercial[piso][local].tipoLocal);
				printf("Ingrese el nuevo tipo de mercado del local: ");
				scanf("%35s", &centroComercial[piso][local].tipoLocal);
				printf("\n");
				printf("Nuevo tipo de mercado del local: %s\n", centroComercial[piso][local].tipoLocal);
				break;

			case 3:

				break;

			default:

                printf("Opcion invalida\n");
                break;
		}
	} while (temp != 3);
}


/*
	Esta funcion elimina un local del centro comercial, es decir, que 
	el local pasa a estar disponible.		
*/
void eliminarLocales(local_t **centroComercial){

	int temp, piso, local;

	printf("Ingrese el piso del local que quiere eliminar: ");
	scanf("%d", &piso);
	printf("\n");
	printf("Ingrese el numero del local que quiere eliminar: ");
	scanf("%d", &local);
	printf("\n");

	piso = piso - 1;
	local = local - 1;

	centroComercial[piso][local].disponible = 1;
}


/*
	Esta funcion brinda informacion de algun local en especifico
	que el usuario desee conocer.	
*/
void infoLocal(local_t **centroComercial){

	int temp, piso, local;

	printf("Ingrese el piso del local del que quiera informacion: ");
	scanf("%d", &piso);
	printf("\n");
	printf("Ingrese el numero del local del que quiera informacion: ");
	scanf("%d", &local);
	printf("\n");

	piso = piso - 1;
	local = local - 1;

	do{

		printf("1. Nombre del local\n");
		printf("2. ID del local\n");
		printf("3. Tipo de mercado del local\n");
		printf("4. Terminar\n");
		printf("\n");
    	printf("Opcion: ");
		scanf("%d", &temp);
		printf("\n");

		switch(temp){

			case 1:

				printf("El nombre del local es: %s\n", centroComercial[piso][local].nombreLocal);
				break;

			case 2:

				printf("El ID del local es: %d\n", centroComercial[piso][local].idLocal);
				break;

			case 3:

				printf("El tipo de mercado del local es: %s\n", centroComercial[piso][local].tipoLocal);
				break;

			case 4:

				break;

			default:

                printf("Opcion invalida\n");
                break;
		}
	} while (temp != 4);

}


/*
	Esta funcion brinda informacion del centro comercial que este
	disponible al usuario.	
*/
void infoCC(local_t **centroComercial, int numPisos, int numLocales){

	int temp;

	do{

		printf("1. Saber el numero de pisos que hay en el centro comercial\n");
		printf("2. Saber el numero de locales que hay por piso en el centro comercial\n");
		printf("3. Informacion de algun local en especifico\n");
		printf("4. Terminar\n");
		printf("\n");
    	printf("Opcion: ");
		scanf("%d", &temp);
		printf("\n");

		switch(temp){

			case 1:

				printf("Numero de pisos totales que hay en el centro comercial: %d\n", numPisos);
				break;

			case 2:

				printf("Numero de locales totales que hay por piso en el centro comercial: %d\n", numLocales);
				break;

			case 3:

				infoLocal(centroComercial);
				break;

			case 4:

				break;

			default:

                printf("Opcion invalida\n");
                break;
		}
	} while (temp != 4);
}

