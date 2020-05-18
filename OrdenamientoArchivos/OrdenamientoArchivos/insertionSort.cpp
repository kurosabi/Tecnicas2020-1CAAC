/* 
	Codigo tomado de GeeksForGeeks "https://www.geeksforgeeks.org/insertion-sort".
	Puesto que la inicitiva del trabajo es comparar el comportamiento de los distintos 
	algoritmos de ordenamiento, hago uso de los ya existentes en la web.
*/


#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 

using namespace std;


/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 

/*
// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
*/


/* Driver program to test insertion sort */
int main(){ 

	FILE *datos;
	FILE *archivo;

	char cadena[10];
	int arr[10000000];//cambiar
	int temp, i;
	int cont = 0;

	archivo = fopen("estadisticasDatosInsertion.txt", "a");//cambiar
	datos = fopen("datos10000000.txt", "r");//cambiar

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

	insertionSort(arr, n);

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