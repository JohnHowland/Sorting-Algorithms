/*
 * main.c
 *
 *  Created on: Jan 13, 2020
 *      Author: JohnC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define	ListCount			10

int items[10] = {6, 9, 3, 7, 23, 20, 2, 1, 53, 4};


int BubbleSort(int *arr, int count){

	for(int i = 0; i < (count-1); i++){
		for(int j = 0; j < (count - i-1); j++){
			if(*(arr + j) > *(arr + j + 1)){
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}

	return 0;
}

int MergeSort(){

	return 0;
}

int QuickSort(){

	return 0;
}

int main(void){
	printf("Hello World\n\n");

	int *array = (int*)malloc(ListCount * sizeof(int));
	memcpy(array, items, sizeof(items));
	printf("Un-sorted list:\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	BubbleSort(array, ListCount);

	printf("Bubble-sorted list:\n");
		for(int i = 0; i < 10; i++){
			printf("%d ", array[i]);
		}
		printf("\n");


	return 0;
}


