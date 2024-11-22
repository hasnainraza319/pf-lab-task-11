#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50], dob[15], department[30];
    int id;
    float salary;
};

void addEmployee(struct Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
  printf("Cannot add more employees.\n");
 return;
    }
    printf("Enter Name: "); scanf(" %[^\n]", employees[*count].name);
    printf("Enter DOB: "); scanf(" %[^\n]", employees[*count].dob);
    printf("Enter ID: "); scanf("%d", &employees[*count].id);
    printf("Enter Department: "); scanf(" %[^\n]", employees[*count].department);
    printf("Enter Salary: "); scanf("%f", &employees[*count].salary);
    (*count)++;
    printf("Employee added.\n");
}

void deleteEmployee(struct Employee employees[], int *count) {
    int id, i, found = 0;
    printf("Enter Employee ID to delete: "); scanf("%d", &id);
    for (i = 0; i < *count; i++) {
   if (employees[i].id == id) {
   found = 1;
    break;
        }
    }
    if (found) {
   for (; i < *count - 1; i++) employees[i] = employees[i + 1];
   (*count)--;
    printf("Employee deleted.\n");
    } else printf("Employee not found.\n");
}

void displayEmployees(struct Employee employees[], int count) {
    if (count == 0) {
 printf("No employees to display.\n");
    return;
    }
    for (int i = 0; i < count; i++) {
   printf("\nName: %s, DOB: %s, ID: %d, Dept: %s, Salary: %.2f\n", 
  employees[i].name, employees[i].dob, employees[i].id, 
   employees[i].department, employees[i].salary);
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int count = 0, choice;
    do {
   printf("\n1. Add Employee  2. Delete Employee  3. Display Employees  4. Exit\n");
    printf("Enter choice: "); scanf("%d", &choice);
    switch (choice) {
    case 1: addEmployee(employees, &count); break;
   case 2: deleteEmployee(employees, &count); break;
    case 3: displayEmployees(employees, count); break;
     case 4: printf("Exiting.\n"); break;
     default: printf("Invalid choice.\n");
    }
    } while (choice != 4);
    return 0;
}

