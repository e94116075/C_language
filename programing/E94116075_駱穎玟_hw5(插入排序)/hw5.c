#include <stdio.h>
/* Print an array */
void print_arr(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
		printf("\n");
}
/* selection sort */
void selection_sort(int arr[], int n) {
	int temp;
	int min;
	for(int i=0;i<n-1;i++){
		min=i;//i is the minimun 
		for(int j=i+1;j<n;j++){//if there's any number smaller than the ith number after it in the array,
			if(arr[min]>arr[j]){
				min=j;//set the order of the number be the minmun
			}
		} 
		temp=arr[i];//change the ith number and the minimun number after it
		arr[i]=arr[min];
		arr[min]=temp;
	}
}
int main(void) {
	int n = 8; // Array size
	int arr[] = {16, 25, 39, 27, 12, 8, 45, 63}; // Array
	printf("Origin: ");
	print_arr (arr, n);
	selection_sort(arr, n); // Call the function of selection sort
	printf("Result: ");
	print_arr (arr, n);
return 0;
}
