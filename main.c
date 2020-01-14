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


int BubbleSort(int *arr, int arrayCount){
	for(int i = 0; i < (arrayCount-1); i++){
		for(int j = 0; j < (arrayCount - i-1); j++){
			if(*(arr + j) > *(arr + j + 1)){
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}

	return 0;
}

int MergeSort(int *arr, int arrayCount){
	if(arrayCount > 1){
		int middle = arrayCount / 2;
		int *left = malloc(middle * sizeof(int));
		int leftCount = middle;
		int *right = malloc((arrayCount - middle) * sizeof(int));
		int rightCount = arrayCount - middle;

		memcpy(left, arr, sizeof(int) * leftCount);
		memcpy(right, (arr + middle), sizeof(int) * rightCount);

		MergeSort(left, middle);
		MergeSort(right, arrayCount - middle);

		int i = 0, j = 0, k = 0;

		//If both sides still have data in them
		while(i < leftCount && j < rightCount){
			if(left[i] < right[j]){
				arr[k] = left[i];
				i++;
			}
			else{
				arr[k] = right[j];
				j++;
			}

			k++;
		}

		//If only left side has data left
		while(i < leftCount){
			arr[k] = left[i];
			i++;
			k++;
		}

		//If only right side has data left
		while(j < rightCount){
			arr[k] = right[j];
			j++;
			k++;
		}

		free(left);
		free(right);
	}

	return 0;
}

int QuickSort(int *arr, int arrayCount){
	int pivot = *arr;
	int i = 1, j = arrayCount - 1;

	if(arrayCount > 1){
		int done = 0;
		while(!done){
			while(*(arr + i) <= pivot && i <= j){
				i++;
			}

			while(*(arr + j) >= pivot && i <= j){
				j--;
			}

			if(i > j){
				done = 1;
			}
			else{
				int temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}

		int tempPivot = *(arr);
		*arr = *(arr + j);
		*(arr + j) = tempPivot;

		QuickSort( arr, j);		//Quick sort on left half
		QuickSort( (arr + i), arrayCount - i);		//Quick sort on right half
	}

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
	free(array);

	array = (int*)malloc(ListCount * sizeof(int));
	memcpy(array, items, sizeof(items));

	printf("Un-sorted list:\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	MergeSort(array, ListCount);

	printf("Merge-sorted list:\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);

	array = (int*)malloc(ListCount * sizeof(int));
	memcpy(array, items, sizeof(items));

	printf("Un-sorted list:\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	QuickSort(array, ListCount);

	printf("Quick-sorted list:\n");
	for(int i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);


	return 0;
}


