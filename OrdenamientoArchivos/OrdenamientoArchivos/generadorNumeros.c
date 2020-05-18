/*
	Programa que genera los numero aleatorios en un archivo de texto.
	Inicialmente se uso para generar los numeros aleatorios desorganizados
	y despues se hizo uso de la funcion qsort para generar los datos de manera
	ordenada.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int compare(const int *num1, const int *num2)
{
  if (*num1 == *num2){
  	return  0;
  }
  else if (*num1 <  *num2){
  	return -1;
  }	
  else if (*num1 >  *num2){
  	return  1;
  }
  else
  return 0;
}


int *randArray(int n){
	int *array;
	int i;

	array = malloc(n * sizeof(int));
	srand(time(NULL));
	for(i = 0 ; i < n ; i++){
		array[i] = rand()%10000;
	}

	qsort(array, n, sizeof(int), (void *)compare);

	return array;
}

int main(){

	int *arrayAux = randArray(10000000);
	int i;

	FILE *archivo;

	archivo = fopen("datos10000000.txt", "w");

	for(i = 0; i < 10000000; i++){
		fprintf(archivo, "%d\n", arrayAux[i]);
	}
	
	fclose(archivo);

	return 0;
}