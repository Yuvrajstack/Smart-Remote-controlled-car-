#include"lib.h"
void rentCar() {
    FILE *fp = fopen("cars.txt", "rb+");
    struct Car car;
    struct Rental rental;
    int found = 0;

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Car ID to rent: ");
    scanf("%d", &rental.car_id);
    getchar();

    long pos;
    while (fread(&car, sizeof(car), 1, fp)) {
        if (car.id == rental.car_id && car.available == 1) {
            car.available = 0;
            pos = ftell(fp) - sizeof(car);
            fseek(fp, pos, SEEK_SET);
            fwrite(&car, sizeof(car), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Car not available.\n");
        return;
    }

    printf("Enter your name: ");
    fgets(rental.customer_name, 50, stdin);
    rental.customer_name[strcspn(rental.customer_name, "\n")] = 0;

    printf("Enter number of days: ");
    scanf("%d", &rental.days);

    printf("Enter rate per day: ");
    scanf("%f", &rental.rate);

    generateInvoice(rental);

    FILE *rf = fopen("rentals.txt", "ab");
    if (rf) {
        fwrite(&rental, sizeof(rental), 1, rf);
        fclose(rf);
    }

    printf("Car rented successfully.\n");
}