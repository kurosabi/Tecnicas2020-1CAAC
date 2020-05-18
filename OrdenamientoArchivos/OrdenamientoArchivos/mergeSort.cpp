/* 
	Codigo tomado de GeeksForGeeks "https://www.geeksforgeeks.org/c-program-for-merge-sort".
	Puesto que la inicitiva del trabajo es comparar el comportamiento de los distintos 
	algoritmos de ordenamiento, hago uso de los ya existentes en la web.
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 


/*
//UTILITY FUNCTIONS 
//Function to print an array
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
}
*/ 


/* Driver program to test above functions */
int main(){ 

	FILE *datos;
	FILE *archivo;

	char cadena[10];
	int arr[10000000];//cambiar
	int temp, i;
	int cont = 0;

	archivo = fopen("estadisticasDatosMerge2.txt", "w");//cambiar
	datos = fopen("datos10000000.txt", "r");//cambiar

	while(!feof(datos)){
		fgets(cadena, 10, datos);
		temp = atoi(cadena);
		arr[cont] = temp;
		cont = cont + 1;
	}

	int arr_size = sizeof(arr)/sizeof(arr[0]);

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

	mergeSort(arr, 0, arr_size - 1);

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