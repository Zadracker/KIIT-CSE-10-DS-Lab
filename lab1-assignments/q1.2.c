// Write a program to create an array of n elements using dynamic memory allocation. Calculate sum of
// all the prime elements of the array using function and de-allocate the memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
int sum_of_primes(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of prime elements
    int sum = sum_of_primes(arr, n);
    printf("Sum of prime elements: %d\n", sum);

    // De-allocate the memory
    free(arr);
    
    return 0;
}

//Output
// Enter the number of elements in the array: 5
// Enter 5 elements:
// 2 5 6 7 11
// Sum of prime elements: 25