#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 10

struct Course {
    char courseID[];
    char courseName[100];
    int credits;
};

struct Department {
    char departmentName[100];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

struct University {
    struct Department departments[MAX_DEPARTMENTS];
    int departmentCount;
};

void addDepartment(struct University *uni) {
    if (uni->departmentCount >= MAX_DEPARTMENTS) {
        printf("No space for more departments.\n");
        return;
    }
    printf("Enter department name: ");
    scanf(" %[^\n]", uni->departments[uni->departmentCount].departmentName);
    uni->departments[uni->departmentCount].courseCount = 0;
    uni->departmentCount++;
    printf("Department added.\n");
}

void addCourse(struct University *uni) {
    char deptName[50];
    printf("Enter department name to add a course: ");
    scanf(" %[^\n]", deptName);

    for (int i = 0; i < uni->departmentCount; i++) {
   if (strcmp(uni->departments[i].departmentName, deptName) == 0) {
   if (uni->departments[i].courseCount >= MAX_COURSES) {
    printf("No space for more courses in this department.\n");
    return;
}
    struct Course *course = &uni->departments[i].courses[uni->departments[i].courseCount];
    printf("Enter course ID: ");
    scanf(" %[^\n]", course->courseID);
    printf("Enter course name: ");
    scanf(" %[^\n]", course->courseName);
   printf("Enter credits: ");
   scanf("%d", &course->credits);
   uni->departments[i].courseCount++;
   printf("Course added.\n");
    return;
}
    }
    printf("Department not found.\n");
}

void displayDetails(struct University *uni) {
    for (int i = 0; i < uni->departmentCount; i++) {
    printf("\nDepartment: %s\n", uni->departments[i].departmentName);
    for (int j = 0; j < uni->departments[i].courseCount; j++) {
   struct Course *course = &uni->departments[i].courses[j];
    printf("  Course ID: %s\n", course->courseID);
    printf("  Course Name: %s\n", course->courseName);
    printf("  Credits: %d\n", course->credits);
  }
    }
}

void calculateTotalCredits(struct University *uni) {
    for (int i = 0; i < uni->departmentCount; i++) {
int totalCredits = 0;
for (int j = 0; j < uni->departments[i].courseCount; j++) {
    totalCredits += uni->departments[i].courses[j].credits;
}
 printf("Total credits for '%s': %d\n", uni->departments[i].departmentName, totalCredits);
    }
}

int main() {
    struct University uni = {0};
    int choice;

    do {
   printf("\n1. Add Department\n2. Add Course\n3. Display Details\n4. Calculate Total Credits\n5. Exit\n");
   printf("Enter choice: ");
   scanf("%d", &choice);

    switch (choice) {
    case 1: addDepartment(&uni); break;
    case 2: addCourse(&uni); break;
   case 3: displayDetails(&uni); break;
    case 4: calculateTotalCredits(&uni); break;
   case 5: printf("Exiting.\n"); break;
  default: printf("Invalid choice.\n");
   }
    } while (choice != 5);

    return 0;
}

