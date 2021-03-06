/* C implementation QuickSort algorithm*/
#include<stdio.h>
 
/*A utility function to swap two elements*/
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
 
/* This function takes last element as pivot, places
	the pivot element at its correct position in sorted
	array, and places all element smaller than pivot
	to left of pivot and all greater elements to right
	of pivot */
int partition (int arr[], int low, int high) {
	int pivot = arr[high];    /* pivot*/
	int i = (low - 1);  /*Index of smaller element*/
 
	for (int j = low; j <= high- 1; j++)
	{
		/* If current element is smaller than or equal to pivot*/
		if (arr[j] <= pivot)
		{
			i++;	/* increment index of smaller element*/
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
 
/* The main function that implements QuickSort
	arr[] --> Array to be sorted,
	low  --> Starting index,
	high  --> Ending index */
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
			at right place */
		int pi = partition(arr, low, high);
 
		/* Separately sort elements before*/
		/* partition and after partition*/
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
 
/* Function to print the array */
void printArray(int arr[], int size) {
	int x;
	for (x=0; x < size; x++)
		printf("%d ", arr[x]);
	printf("\n");
}
 
/* Ask the user to input the number of the element and value of each element
 * we then sort the array using quicksort algorithm and print the sorted array to the user*/
int main() {
	int x,num;
	printf("Please enter the number of element: ");
	scanf("%i",&num);
	int arr[num];
	for (x=0;x<num;x++) {
		printf("Please enter the value for element %i: ",x+1);
		scanf("%i",&arr[x]);
	}
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

