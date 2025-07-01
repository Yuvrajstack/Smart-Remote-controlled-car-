#include"lib.h"
void addCars() {
    FILE *fp = fopen("cars.txt", "ab+");  // Open in append mode, binary
    struct Car car;
    int n;

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("How many cars do you want to add? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        int duplicate = 0;
        printf("\nEnter Car ID: ");
        scanf("%d", &car.id);
        getchar();

        // Check for duplicate ID
        fseek(fp, 0, SEEK_SET);
        struct Car temp;
        while (fread(&temp, sizeof(temp), 1, fp)) {
            if (temp.id == car.id) {
                printf("Car ID already exists. Skipping...\n");
                duplicate = 1;
                break;
            }
        }

        if (duplicate) continue;

        printf("Enter Model: ");
        fgets(car.model, 50, stdin);
        car.model[strcspn(car.model, "\n")] = 0; // remove newline
        car.available = 1;

        fwrite(&car, sizeof(car), 1, fp);
    }

    fclose(fp);
    printf("Cars added successfully.\n");
}