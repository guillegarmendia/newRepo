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
