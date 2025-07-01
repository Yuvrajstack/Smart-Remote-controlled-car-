#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_CARS = 100;

struct Car {
    int id;
    char model[50];
    int available;
};

struct Rental {
    int car_id;
    char customer_name[50];
    int days;
    float rate;
};

void addCars();
void rentCar();
void returnCar();
void showAvailableCars();
void generateInvoice(struct Rental rental);