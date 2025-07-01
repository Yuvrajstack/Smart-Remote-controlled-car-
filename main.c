// Compile- gcc main.c genInvoice.c returnCar.c rentCar.c availCars.c addCars.c 
// Run    - ./a

#include"lib.h"

int main() {
    int choice;

    while (1) {
        printf("\n=== Car Rental Management System ===\n");
        printf("1. Add Cars\n");
        printf("2. Show Available Cars\n");
        printf("3. Rent a Car\n");
        printf("4. Return a Car\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                addCars();
                break;
            case 2:
                showAvailableCars();
                break;
            case 3:
                rentCar();
                break;
            case 4:
                returnCar();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}