//Write a program to create a structure to store the information of n number of Employees. Employee’s
// information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%. Display the
// information of employees with gross salary. Use array of structure.

#include <stdio.h>
int main(){
typedef struct {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percentage;
    float da_percentage;
} Employee;

int n, i;
printf("Enter the number of employees: ");
scanf("%d", &n);
Employee employees[n];
for (i = 0; i < n; i++) {
    printf("\nEnter details for employee %d:\n", i + 1);
    printf("Employee ID: ");
    scanf("%d", &employees[i].emp_id);
    printf("Name: ");
    scanf(" %[^\n]", employees[i].name);
    printf("Designation: ");
    scanf(" %[^\n]", employees[i].designation);
    printf("Basic Salary: ");
    scanf("%f", &employees[i].basic_salary);
    printf("HRA %: ");
    scanf("%f%%", &employees[i].hra_percentage);
    printf("DA %: ");
    scanf("%f%%", &employees[i].da_percentage);
}
printf("-----------------------------------\n");
printf("\nEmployee Details:\n");
for (i = 0; i < n; i++) {
    float hra = (employees[i].hra_percentage / 100) * employees[i].basic_salary;
    float da = (employees[i].da_percentage / 100) * employees[i].basic_salary;
    float gross_salary = employees[i].basic_salary + hra + da;

    printf("\nEmployee ID: %d\n", employees[i].emp_id);
    printf("Name: %s\n", employees[i].name);
    printf("Designation: %s\n", employees[i].designation);
    printf("Basic Salary: %.2f\n", employees[i].basic_salary);
    printf("HRA: %.2f\n", hra);
    printf("DA: %.2f\n", da);
    printf("Gross Salary: %.2f\n", gross_salary);
}

return 0;
}

//Output
//Enter the number of employees: 2
// Enter details for employee 1:
// Employee ID: 1
// Name: Avneesh
// Designation: Professor
// Basic Salary: 10000
// HRA : 15%
// DA : 45%

// Enter details for employee 2:
// Employee ID: 2
// Name: Avantika
// Designation: Professor
// Basic Salary: 20000
// HRA : 10%
// DA : 35%
// -----------------------------------

// Employee Details:

// Employee ID: 1
// Name: Avneesh
// Designation: Professor
// Basic Salary: 10000.00
// HRA: 1500.00
// DA: 4500.00
// Gross Salary: 16000.00

// Employee ID: 2
// Name: Avantika
// Designation: Professor
// Basic Salary: 20000.00
// HRA: 2000.00
// DA: 7000.00
// Gross Salary: 29000.00