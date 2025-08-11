//2.1) WAP to create a 1-D array of n elements and perform the following menu based operations using function.
/*
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void insert(int arr[], int *n, int element, int position) {
    if (*n >= MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n\n");
        return;
    }
    if (position < 0 || position > *n) {
        printf("Invalid position.\n\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
    printf("Element inserted\n\n");
}
void delete_element(int arr[], int *n, int position) {
    if (*n == 0) {
        printf("Array is empty. Cannot delete element.\n\n");
        return;
    }
    if (position < 0 || position >= *n) {
        printf("Invalid position.\n\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted\n\n");
}
int linear_search(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}
void traverse(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n\n");
        return;
    }
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int arr[MAX_SIZE], n, option, element, position;
    
    printf("Enter size n: ");
    scanf("%d", &n);
    
    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid size. Size must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    
    printf("Enter Array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    do {
        printf("***MENU***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option:");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Element to insert: ");
                scanf("%d", &element);
                printf("Enter Position: ");
                scanf("%d", &position);
                insert(arr, &n, element, position);
                break;
            case 2:
                printf("Enter Position to delete: ");
                scanf("%d", &position);
                delete_element(arr, &n, position);
                break;
            case 3:
                printf("Element to search: ");
                scanf("%d", &element);
                position = linear_search(arr, n, element);
                if (position != -1) {
                    printf("Element found at index: %d\n\n", position);
                } else {
                    printf("Element not found\n\n");
                }
                break;
            case 4:
                traverse(arr, n);
                break;
            case 5:
                printf("Exiting...\n\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    } while (option != 5);
    
    return 0;
}

//Output
/*
Enter size n: 3
Enter Array elements: 1 2 3
***MENU***
1. Insert
2. Delete
3. Linear Search
4. Traverse
5. Exit
Enter option:4
Array Elements: 1 2 3 

***MENU***
1. Insert
2. Delete
3. Linear Search
4. Traverse
5. Exit
Enter option:1
Element to insert: 5
Enter Position: 1
Element inserted

***MENU***
1. Insert
2. Delete
3. Linear Search
4. Traverse
5. Exit
Enter option:2
Enter Position to delete: 0
Element deleted

***MENU***
1. Insert
2. Delete
3. Linear Search
4. Traverse
5. Exit
Enter option:3
Element to search: 3
Element found at index: 2
    
***MENU***
1. Insert
2. Delete
3. Linear Search
4. Traverse
5. Exit
Enter option:4
Array Elements: 5 2 3 

***MENU***
1. Insert
2. Delete
3. Linear Search
4. Traverse
5. Exit
Enter option:5
Exiting...
*/