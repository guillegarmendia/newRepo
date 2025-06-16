#include <float.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Discount.h"
#include "Shop.h"


char *readProduct() {

    FILE *productFile = fopen("Products.txt", "r");
    char productName[MAX];
    char line[MAX];
    int i;
    fscanf(productFile,"%s",line);

    for(i = 0; line[i] != ';'; i++) {
        productName[i] = line[i];
    }
    productName[i] = '\0';

    return productName;

}

void TEST_shouldReturnProduct() {
    char *product = readProduct();

    printf("Product: %s\n", product);
}

char *readShop() {
    FILE *shopFile = fopen("Shops.txt", "r");
    char shopsName[MAX];
    char line[MAX];
    int i;
    fscanf(shopFile,"%s",line);

    for(i = 0; line[i] != ';'; i++) {
        shopsName[i] = line[i];
    }
    shopsName[i] = '\0';

    return shopsName;
}

void TEST_shouldReturnShop() {
    char *shop = readShop();

    printf("Shop's name: %s\n", shop);
}

float getLowestDist() {
    float dist[5] =  {99.6, 23.98, 45.76,95.07,78.99};
    float minDist = FLT_MAX;

    for (int i = 0; i < 5; i++) {
        if(minDist > dist[i]) {
            minDist = dist[i];
        }
    }

    return minDist;
}


void TEST_findDistante() {
    float dist = getLowestDist();

    printf("Lowest dis: %.2f", dist);
}

int checkIsActive(char* start, char* end) {
    struct tm tStart = {0}, tEnd = {0};
    time_t now = time(NULL);

    strptime(start, "%d-%m-%Y", &tStart);
    strptime(end, "%d-%m-%Y", &tEnd);

    time_t startTime = mktime(&tStart);
    time_t endTime = mktime(&tEnd);

    return now >= startTime && now <= endTime;
}

void TEST_shouldReturnIfIsActive() {
    int result = checkIsActive("15-06-2020", "01-01-2080");

    if (result != 1)
        printf("Test failed: expected 1, got %d\n", result);
    else
        printf("Test passed\n");
}

