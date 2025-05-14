#include <stdio.h>

void bubble_sort(int *arr, int size);

int main () {

    int size;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Insert an element: ");

    int arr[size];
    for (int i = 0; i < size; i++) {
    int tmp;
    scanf("%d",&tmp);
    arr[i] = tmp;
    }

    for (int i = 0; i < size; i++) {
    printf("%d, ",arr[i]);
    }

    printf("\n");
    printf("After sorting the array is: ");
    bubble_sort(arr, size);
    for (int i = 0; i < size; i++) {
    printf("%d, ",arr[i]);
    }
    printf("\n");

    return 0;

}

void bubble_sort(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

}