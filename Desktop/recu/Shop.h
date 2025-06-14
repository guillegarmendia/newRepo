#ifndef SHOP_H
#define SHOP_H

#define MAX 100
#include <Llibreria Recuperació-20250406/operations.h>

typedef struct {

char product[MAX];
    int id;
    char category[MAX];
    float price;
    int quantity;
    char description[MAX];
    Coordinates coords;
} Shop;

void modifyShop(int modifyOption);

void addProduct();

void findNearestShops();

int loadShopsFromFile(const char *filename, ShopUbi *shops, int maxShops);

void find5NearestShops(ShopUbi *s, int numShops, Coordinates client, int *nearest_ids);

void proximityShops();

#endif