#include"lib.h"
void returnCar() {
    FILE *fp = fopen("cars.txt", "rb+");
    struct Car car;
    int car_id, found = 0;

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Car ID to return: ");
    scanf("%d", &car_id);

    long pos;
    while (fread(&car, sizeof(car), 1, fp)) {
        if (car.id == car_id && car.available == 0) {
            car.available = 1;
            pos = ftell(fp) - sizeof(car);
            fseek(fp, pos, SEEK_SET);
            fwrite(&car, sizeof(car), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("Car returned successfully.\n");
    else
        printf("Car ID not found or already returned.\n");
}