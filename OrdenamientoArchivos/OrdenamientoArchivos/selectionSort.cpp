/* 
	Codigo tomado de GeeksForGeeks "https://www.geeksforgeeks.org/selection-sort".
	Puesto que la inicitiva del trabajo es comparar el comportamiento de los distintos 
	algoritmos de ordenamiento, hago uso de los ya existentes en la web.
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

using namespace std;


void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

/*
//Function to print an array
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
*/


// Driver program to test above functions 
int main(){

	FILE *datos;
	FILE *archivo;

	char cadena[10];
	int arr[10000000];//cambiar
	int temp, i;
	int cont = 0;

	archivo = fopen("estadisticasDatosOrdenadosSelection.txt", "a");//cambiar
	datos = fopen("datosOrdenados10000000.txt", "r");//cambiar

	while(!feof(datos)){
		fgets(cadena, 10, datos);
		temp = atoi(cadena);
		arr[cont] = temp;
		cont = cont + 1;
	}

	int n = sizeof(arr) / sizeof(arr[0]); 

	//Calcula el tiempo de ejecucion con fecha y hora
	clock_t tiempoInicio, tiempoFinal;
	double seg;

	time_t fechaHora;
	time(&fechaHora);

	fprintf(archivo, "10000000 datos\n\n");//cambiar

	fprintf(archivo, "Fecha y hora de cuando inicio el programa\n");
	fprintf(archivo, "%s\n", ctime(&fechaHora));

	tiempoInicio = clock();
	//operaciones incio

	selectionSort(arr, n);

	//operaciones final
	tiempoFinal = clock();

	seg = (double)(tiempoFinal - tiempoInicio) / CLOCKS_PER_SEC;
	
	time(&fechaHora);

	fprintf(archivo, "Fecha y hora de cuando termino el programa\n");
	fprintf(archivo, "%s\n", ctime(&fechaHora));

	fprintf(archivo, "Tiempo de ejecucion\n");
	fprintf(archivo, "%f\n\n", seg);

	fclose(archivo);
	fclose(datos);

	return 0; 
}