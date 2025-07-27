// Write a program to read two numbers and compare the numbers using function call by address
#include <stdio.h>

int compare(int *a, int *b) {
    if (*a > *b) {
        return 1; // a is greater
    } else if (*a < *b) {
        return -1; // b is greater
    } else {
        return 0; // both are equal
    }
}

int main() {
    int num1, num2;
    
    // Read two numbers from the user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    // Compare the numbers using the compare function
    int result = compare(&num1, &num2);
    
    // Output the result of the comparison
    if (result == 1) {
        printf("(%d) is greater than (%d)\n", num1, num2);
    } else if (result == -1) {
        printf("(%d) is greater than (%d).\n", num2, num1);
    } else {
        printf("Both numbers are same.\n");
    }
    
    return 0;
}

//Output
// Enter first number: 30
// Enter second number: 20
// (30) is greater than (20)

// Enter first number: 10
// Enter second number: 10
// Both numbers are same.