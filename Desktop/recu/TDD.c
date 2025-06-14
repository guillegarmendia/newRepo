#include <float.h>
#include <stdio.h>
#include <string.h>

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
