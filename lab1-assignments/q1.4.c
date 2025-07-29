// Write a menu driven program to create a structure to represent complex number and perform the
// following operation using function :
// 1. addition of two complex number (call by value)
// 2. multiplication of two complex number (call by address)

#include <stdio.h>
int main() {
    typedef struct {
        int real;
        int img;
    } Complex;

    Complex c1, c2, sum;
    int choice;

    printf("Enter complex number 1 (real and imaginary parts): ");
    scanf("%d %d", &c1.real, &c1.img);
    printf("Enter complex number 2 (real and imaginary parts): ");
    scanf("%d %d", &c2.real, &c2.img);

    do {
        printf("\nMENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sum.real = c1.real + c2.real;
                sum.img = c1.img + c2.img;
                printf("Sum = %d + %di\n", sum.real, sum.img);
                break;

            case 2:
                sum.real = (c1.real * c2.real) - (c1.img * c2.img);
                sum.img = (c1.real * c2.img) + (c1.img * c2.real);
                printf("Product = %d + %di\n", sum.real, sum.img);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
                break;    
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice == 1 || choice == 2);

    return 0;
}


//Output
/*

Enter complex number 1 (real and imaginary parts): 2 5
Enter complex number 2 (real and imaginary parts): 6 1

MENU
1. Addition
2. Multiplication
3. Exit
Enter your choice: 1
Sum = 8 + 6i

MENU
1. Addition
2. Multiplication
3. Exit
Enter your choice: 2
Product = 7 + 32i

MENU
1. Addition
2. Multiplication
3. Exit
Enter your choice: 3
Exiting the program.


*/