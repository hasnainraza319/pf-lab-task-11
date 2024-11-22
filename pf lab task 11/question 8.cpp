#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "books.txt"

struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void addBook() {
    struct Book book;
    FILE *file = fopen(FILE_NAME, "a+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &book.id);
    printf("Enter Title: ");
    getchar();
    fgets(book.title, sizeof(book.title), stdin);
    book.title[strcspn(book.title, "\n")] = '\0';
    printf("Enter Author: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = '\0';
    printf("Enter Quantity: ");
    scanf("%d", &book.quantity);
    printf("Enter Price: ");
    scanf("%f", &book.price);
    fwrite(&book, sizeof(struct Book), 1, file);
    fclose(file);
    printf("Book added successfully.\n");
}

void viewBooks() {
    struct Book book;
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }
    printf("\nBooks in Library:\n");
    while (fread(&book, sizeof(struct Book), 1, file)) {
        printf("ID: %d\n", book.id);
        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Quantity: %d\n", book.quantity);
        printf("Price: %.2f\n", book.price);
        printf("---------------------------------------\n");
    }
    fclose(file);
}

void searchBook() {
    struct Book book;
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }
    int id;
    char title[100];
    int choice;
    printf("Search by 1. ID  2. Title: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (book.id == id) {
                printf("Book found: %s by %s, Quantity: %d, Price: %.2f\n", 
                       book.title, book.author, book.quantity, book.price);
                fclose(file);
                return;
            }
        }
    } else if (choice == 2) {
        printf("Enter Book Title: ");
        getchar();
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';
        while (fread(&book, sizeof(struct Book), 1, file)) {
            if (strcmp(book.title, title) == 0) {
                printf("Book found: %s by %s, Quantity: %d, Price: %.2f\n", 
                       book.title, book.author, book.quantity, book.price);
                fclose(file);
                return;
            }
        }
    } else {
        printf("Invalid choice.\n");
    }
    printf("Book not found.\n");
    fclose(file);
}

void deleteBook() {
    struct Book book;
    FILE *file = fopen(FILE_NAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        printf("Error opening file.\n");
        return;
    }
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    int found = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        if (book.id == id) {
            found = 1;
        } else {
            fwrite(&book, sizeof(struct Book), 1, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Book deleted.\n");
    } else {
        printf("Book not found.\n");
    }
}

void calculateInventoryValue() {
    struct Book book;
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }
    float totalValue = 0;
    while (fread(&book, sizeof(struct Book), 1, file)) {
        totalValue += book.quantity * book.price;
    }
    printf("Total Inventory Value: %.2f\n", totalValue);
    fclose(file);
}

int main() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. View Books\n3. Search Book\n4. Delete Book\n5. Calculate Inventory Value\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: calculateInventoryValue(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
    return 0;
}


