#ifndef SHOP_H
#define SHOP_H

#define MAX 100

typedef struct {

char product[MAX];
    char category[MAX];
    float price;
    int quantity;
    char description[MAX];

} Shop;

void modifyShop(int modifyOption);

void addProduct();

#endif