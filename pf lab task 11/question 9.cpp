#include <stdio.h>
#include <string.h>

#define MAX_COURSES 3
#define MAX_STUDENTS 5
#define MAX_DEPARTMENTS 2

struct Student {
    int id;
    char name[50];
};

struct Instructor {
    int id;
    char name[50];
};

struct Course {
    int id;
    char name[50];
    struct Instructor instructor;
    struct Student students[MAX_STUDENTS];
    int studentCount;
};

struct Department {
    int id;
    char name[50];
    struct Course courses[MAX_COURSES];
    int courseCount;
};

struct University {
    struct Department departments[MAX_DEPARTMENTS];
    int departmentCount;
};

void addStudent(struct Department* department) {
    int courseId;
    printf("Enter Course ID (0 to %d): ", department->courseCount - 1);
    scanf("%d", &courseId);
    getchar();
    if (courseId >= 0 && courseId < department->courseCount) {
        struct Course* course = &department->courses[courseId];
        if (course->studentCount < MAX_STUDENTS) {
            struct Student student;
            printf("Enter Student ID: ");
            scanf("%d", &student.id);
            getchar();
            printf("Enter Student Name: ");
            fgets(student.name, 50, stdin);
            student.name[strcspn(student.name, "\n")] = 0;  // Remove newline
            course->students[course->studentCount++] = student;
            printf("Student added to course %s.\n", course->name);
        } else {
            printf("Course is full.\n");
        }
    } else {
        printf("Invalid Course ID.\n");
    }
}

void addCourse(struct Department* department) {
    if (department->courseCount < MAX_COURSES) {
        struct Course course;
        printf("Enter Course ID: ");
        scanf("%d", &course.id);
        getchar();
        printf("Enter Course Name: ");
        fgets(course.name, 50, stdin);
        course.name[strcspn(course.name, "\n")] = 0;  // Remove newline
        printf("Enter Instructor ID: ");
        scanf("%d", &course.instructor.id);
        getchar();
        printf("Enter Instructor Name: ");
        fgets(course.instructor.name, 50, stdin);
        course.instructor.name[strcspn(course.instructor.name, "\n")] = 0;  // Remove newline
        course.studentCount = 0;
        department->courses[department->courseCount++] = course;
        printf("Course added.\n");
    } else {
        printf("Department is full.\n");
    }
}

void addDepartment(struct University* university) {
    if (university->departmentCount < MAX_DEPARTMENTS) {
        struct Department department;
        printf("Enter Department ID: ");
        scanf("%d", &department.id);
        getchar();
        printf("Enter Department Name: ");
        fgets(department.name, 50, stdin);
        department.name[strcspn(department.name, "\n")] = 0;  // Remove newline
        department.courseCount = 0;
        university->departments[university->departmentCount++] = department;
        printf("Department added.\n");
    } else {
        printf("University is full.\n");
    }
}

void displayUniversity(struct University university) {
    printf("\nUniversity Details:\n");
    for (int i = 0; i < university.departmentCount; i++) {
        printf("\nDepartment: %s\n", university.departments[i].name);
        for (int j = 0; j < university.departments[i].courseCount; j++) {
            printf("  Course: %s, Instructor: %s\n", university.departments[i].courses[j].name, university.departments[i].courses[j].instructor.name);
            for (int k = 0; k < university.departments[i].courses[j].studentCount; k++) {
                printf("    Student: %s\n", university.departments[i].courses[j].students[k].name);
            }
        }
    }
}

int main() {
    struct University university;
    university.departmentCount = 0;
    int choice;
    
    do {
        printf("\n1. Add Department\n2. Add Course\n3. Add Student\n4. Display University\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                addDepartment(&university);
                break;
            case 2:
                if (university.departmentCount > 0) {
                    int depId;
                    printf("Enter Department ID (0 to %d): ", university.departmentCount - 1);
                    scanf("%d", &depId);
                    getchar();
                    if (depId >= 0 && depId < university.departmentCount) {
                        addCourse(&university.departments[depId]);
                    } else {
                        printf("Invalid Department ID.\n");
                    }
                } else {
                    printf("No departments available.\n");
                }
                break;
            case 3:
                if (university.departmentCount > 0) {
                    int depId;
                    printf("Enter Department ID (0 to %d): ", university.departmentCount - 1);
                    scanf("%d", &depId);
                    getchar();
                    if (depId >= 0 && depId < university.departmentCount) {
                        addStudent(&university.departments[depId]);
                    } else {
                        printf("Invalid Department ID.\n");
                    }
                } else {
                    printf("No departments available.\n");
                }
                break;
            case 4:
                displayUniversity(university);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

