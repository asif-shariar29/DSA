#include <stdio.h>

void insertionSort (int *arr, int size) {

    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i-1;
        while (arr[j] > current && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
       arr[j+1] = current;
    }
}

void print_arr(int *arr, int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
}

int main () {

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

    printf("Given array: \n");
    print_arr(arr,n);
    insertionSort(arr,n);
    printf("\nSorted array: \n");
    print_arr(arr,n);

}