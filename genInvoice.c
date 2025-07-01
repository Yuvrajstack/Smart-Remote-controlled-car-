#include"lib.h"
void generateInvoice(struct Rental rental) {
    float total = rental.days * rental.rate;

    printf("\n--- Invoice ---\n");
    printf("Customer: %s\n", rental.customer_name);
    printf("Car ID: %d\n", rental.car_id);
    printf("Days: %d\n", rental.days);
    printf("Rate per day: %.2f\n", rental.rate);
    printf("Total: %.2f\n", total);
}