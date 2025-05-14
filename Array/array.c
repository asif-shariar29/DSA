#include <stdio.h>

#define SIZE 10

void array_traverse(int *arr, int size);
int array_insert(int *arr, int size, int position, int data);
int array_delete(int *arr, int size, int position, int count);
int array_lsearch(int *arr, int size, int key);

int main()
{
    int arr[SIZE];
    int count = 0;
    int position = 0;

    while (1) {

        printf("1. Traverse\n2. Insert\n3. Delete\n4. Search\n5. Exit\n");
        printf("[*] Select your option: ");
        int user_input;
        scanf("%d", &user_input);

        if (user_input ==  1) {
            printf("[");
            array_traverse(arr, count);
            printf("\b\b]");
            printf("\n");
        }

        if (user_input ==  2) {
            int data;
            printf("Insert an element: ");
            scanf("%d", &data);
            if (!array_insert(arr, SIZE, position, data))
                continue;
            count++;
            position++;
        }

        if (user_input ==  3) {
            int p;
            printf("Input the index value: ");
            scanf("%d", &p);
            if (!array_delete(arr, SIZE, p, count))
                continue;
            count--;
        }
        
        if (user_input ==  4) {
            int key;
            printf("Input key: ");
            scanf("%d", &key);
            if (array_lsearch(arr, SIZE, key))
                printf("[*] Found\n");
            else
                printf("[!] Not found\n");
        }

        if (user_input ==  5)
            break;
    }

    return 0;
}

void array_traverse(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);

    }
}

int array_insert(int *arr, int size, int position, int data)
{
    if (position > size - 1) {
        printf("[!] error: overflow\n");
        return 0;
    }
    arr[position] = data;
    return 1;
}

int array_delete(int *arr, int size, int position, int count)
{
    if (count == 0) {
        printf("[!] error: underflow\n");
        return 0;
    }
    for (int i = position; i < size; i++) {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int array_lsearch(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return 1;
    }
    return 0;
}