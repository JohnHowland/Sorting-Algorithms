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

/* The bubble sort works by comparing the 2 leftmost indices with each other and swapping
 * the data in the indices if the value on the left is larger than the right. The comparison
 * indexes are incremented by one, and the process continues until the end of the array is
 * reached. This process has moved through the array, and moved the largest value to the
 * end of the array. Repeat this process again starting at the beginning of the array end
 * minus 1. Repeat again, minus 1 etc etc etc.
 */
int BubbleSort(int *arr, int arrayCount){
	for(int i = 0; i < (arrayCount-1); i++){
		//Go to end of the array, minus the number of times gone through the array thus far
		for(int j = 0; j < (arrayCount - i - 1); j++){
			//Comparing 2 adjacent indices in an array. If the left is larger, swap data
			if(*(arr + j) > *(arr + j + 1)){
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}

	return 0;
}

/*
 * Merge sort is a divide and conquer method through the way of recursion. The original array
 * is cut into array halves until it s just 1 indices. It is then re-constructed by sorting
 * left and right halves in order.
 */
int MergeSort(int *arr, int arrayCount){
	//Only enter into if there is more than 1 value in the array
	if(arrayCount > 1){
		int middle = arrayCount / 2;	//Find middle index of the array (floored being that data is an int)
		int *left = malloc(middle * sizeof(int));
		int leftCount = middle;					//Number of the array indices in the left array
		int *right = malloc((arrayCount - middle) * sizeof(int));
		int rightCount = arrayCount - middle;	//Number of the array indices in the right array

		//Copy the data to the left and right arrays
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

/*
 *
 *
 *
 */
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
/*
 * A function that prints out the contents of an array.
 */
int PrintArray(char *title, int *arr, int arrayCount){
	if(strlen(title)){
		printf("%s\n", title);
	}

	for(int i = 0; i < arrayCount; i++){
		printf("%d ", *(arr + i));
	}
	printf("\n");

	return 0;
}
/*
 * Function to search sorted array for specifica value in the array
 */
int BinarySearch(int *arr, int arrayCount, int questValue){
	int leftIndex = 0; //Beginning of the
	int rightIndex = arrayCount - 1;

	while(leftIndex <= rightIndex){
		int middleIndex = ((rightIndex-leftIndex) / 2) + leftIndex;

		if(*(arr + middleIndex) == questValue){
			return middleIndex;
		}
		else{
			if( questValue > *(arr + middleIndex)){
				leftIndex = middleIndex + 1;
			}
			else{
				rightIndex = middleIndex - 1;
			}
		}
	}

	return -1;
}


//---------------------------- MAIN PROGROM ------------------------------------
int main(void){
	char *title;
	title = (char*)malloc(sizeof(char) * 25);

//-------------------------------------------------------- Bubble Sort
	int *array = (int*)malloc(ListCount * sizeof(int));
	memcpy(array, items, sizeof(items));
	strcpy(title, "Unsorted Array");
	PrintArray(title, array, ListCount);

	BubbleSort(array, ListCount);

	strcpy(title, "Bubble-sorted list");
	PrintArray(title, array, ListCount);
	free(array);
//-------------------------------------------------------- Merge Sort
	array = (int*)malloc(ListCount * sizeof(int));
	memcpy(array, items, sizeof(items));

	strcpy(title, "Unsorted list");
	PrintArray(title, array, ListCount);

	MergeSort(array, ListCount);

	strcpy(title, "Merge-sorted list");
	PrintArray(title, array, ListCount);
	free(array);
//-------------------------------------------------------- Quick Sort
	array = (int*)malloc(ListCount * sizeof(int));
	memcpy(array, items, sizeof(items));

	strcpy(title, "Unsorted list");
	PrintArray(title, array, ListCount);

	QuickSort(array, ListCount);

	strcpy(title, "Quick-sorted list");
	PrintArray(title, array, ListCount);


	int val = BinarySearch(array, ListCount, 53);
	printf("Val = %d\n", val);

	free(array);
	free(title);
	return 0;
}


