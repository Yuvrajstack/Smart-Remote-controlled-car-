#include"lib.h"
void showAvailableCars() {
    FILE *fp = fopen("cars.txt", "rb");
    struct Car car;
    int found = 0;

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nAvailable Cars:\n");
    while (fread(&car, sizeof(car), 1, fp)) {
        if (car.available == 1) {
            printf("ID: %d, Model: %s\n", car.id, car.model);
            found = 1;
        }
    }

    if (!found) {
        printf("No cars available.\n");
    }

    fclose(fp);
}