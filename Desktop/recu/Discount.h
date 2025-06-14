#ifndef DISCOUNT_H
#define DISCOUNT_H

#define MAX 100


typedef struct {
    int code;
    char startDate[MAX];
    char endDate[MAX];
    char shop[MAX];
    char applicableProducts[MAX];
} Discount;

void manageDisc(int option);

#endif