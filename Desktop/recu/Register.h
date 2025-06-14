#ifndef REGISTER_H
#define REGISTER_H

#define MAX 100

typedef struct {
    char shop[MAX];
    char adress[MAX];
    int phone;
    char mail[MAX];
    char worker[MAX];
    char password[MAX];

} Shop;

void registerShop();

void registerWorker();

#endif
