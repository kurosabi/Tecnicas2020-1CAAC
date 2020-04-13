#ifndef FUNCIONESCC_H_
#define FUNCIONESCC_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum tipoDeLocales tipo;

enum tipo{Restaurante, Ropa, Calzado, Joyeria, Variedades};

//Local 
typedef struct Local{
	char nombreLocal[35];
	char tipoLocal[35]; 
	int idLocal; // Calculado automaticamente por su programa
	int pisoLocal;
	int numLocalxPiso;
	int disponible;
	// Completelo con lo que quiera
} local_t;

local_t **reservaCC(int numPisos, int numLocales);

void inicializacionMatriz(local_t **centroComercial, int numPisos, int numLocales);

void crearNuevoLocal(local_t **centroComercial);

void modificarInfoLocal(local_t **centroComercial);

void eliminarLocales(local_t **centroComercial);

void infoCC(local_t **centroComercial, int numPisos, int numLocales);

void infoLocal(local_t **centroComercial);

/*Agregar las funciones que necesite para satisfacer los requerimientos */
//void mostrarLocal(local_t ** centroComercial, int numPiso, int numLocalxPiso, int numPisos, int numLocalesxPiso);


#endif /* FUNCIONESCC_H_ */