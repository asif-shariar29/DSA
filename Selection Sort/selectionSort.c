#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n) {
    int min_idx;
    for (int i = 0; i < n-1; i++) {
        min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int *arr, int size) {

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    
   int n;
   printf("Enter the size of array: ");
   scanf("%d",&n);
   printf("Insert an element: ");
   int arr[n];
   for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d",&tmp);
    arr[i] = tmp;
   }

    printf("Original array: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}