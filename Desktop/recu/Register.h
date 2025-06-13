#ifndef REGISTER_H
#define REGISTER_H

typedef struct {
    char shop[100];
    char adress[100];
    int phone;
    char mail[100];
} Shop;

void registerShop();

#endif
