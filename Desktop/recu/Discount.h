#ifndef DISCOUNT_H
#define DISCOUNT_H

#define MAX 100


typedef struct {
    int code;
    char codeString[MAX];
    char startDate[MAX];
    char endDate[MAX];
    char shop[MAX];
    char applicableProducts[MAX];
} Discount;

void manageDisc(int option);

int isActive(char* start, char* end);
int findShopIndex(char shops[][20], int count, char* shop);
void showPromotions();


#endif