#include <stdio.h>

void binary_search(int *arr, int size, int key);
void bubble_sort(int *arr, int size);

int main()
{
    int size;
    printf("Input array size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Insert Elements: ");
    for (int i = 0; i < size; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
	bubble_sort(arr, size);

	printf("After sorting the array: ");
	for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter the value you want to search: ");
    int usr_input;
    scanf("%d", &usr_input);
	binary_search(arr, size, usr_input);

	return 0;
}

void binary_search(int *arr, int size, int key)
{
	int low = 0;
	int high = size;
	int mid = (low + high)/2;

	while (low <= high) {
		if (arr[mid] == key) {
			printf("Found at position %d\n", mid);
			return;
		}
		if (arr[mid] < key) {
			low = mid + 1;
		}
		if (arr[mid] > key) {
			high = mid - 1;
		}
		mid = (low + high)/2;
	}

	printf("Not found\n");
}

void bubble_sort(int *arr, int size)
{
	for (int i = 0; i < size; i++) {
    	for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}