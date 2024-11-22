#include <stdio.h>
#include <string.h>

struct Invoice {
    char part_Number[50];
    char part_Description[100];
    int quantity;
    float price_PerItem;
};

float calculateInvoiceAmount(struct Invoice *invoice) {
    if (invoice->quantity < 0) invoice->quantity = 0;
    if (invoice->price_PerItem < 0) invoice->price_PerItem = 0.0;
    return invoice->quantity * invoice->price_PerItem;
}

int main() {
    struct Invoice invoice;

    printf("Enter part number: ");
    scanf(" %[^\n]", invoice.part_Number);
    printf("Enter part description: ");
    scanf(" %[^\n]", invoice.part_Description);
    printf("Enter quantity: ");
    scanf("%d", &invoice.quantity);
    printf("Enter price per item: ");
    scanf("%f", &invoice.price_PerItem);

    float invoiceAmount = calculateInvoiceAmount(&invoice);

    printf("\nInvoice Details:\n");
    printf("Part Number: %s\n", invoice.part_Number);
    printf("Part Description: %s\n", invoice.part_Description);
    printf("Quantity: %d\n", invoice.quantity);
    printf("Price per Item: %.2f\n", invoice.price_PerItem);
    printf("Invoice Amount: %.2f\n", invoiceAmount);

    return 0;
}

