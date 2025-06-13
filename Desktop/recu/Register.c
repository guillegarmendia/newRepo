#include <stdio.h>
#include <string.h>
#include "Register.h"


void registerShop() {

    Shop shop;
    FILE* fp = fopen("Shops.txt","a");

    if (fp == NULL) {
        printf("Error opening Shops.txt\n");
        return;
    }

    printf("Shop's name: \n");
    fgets(shop.shop, sizeof(shop.shop), stdin);
    shop.shop[strlen(shop.shop)-1] = '\0';


    printf("Shop's address: \n");
    fgets(shop.adress, sizeof(shop.adress), stdin);
    shop.adress[strlen(shop.adress)-1] = '\0';

    printf("Shop's phone: \n");
    scanf("%d", &shop.phone);
    getchar();

    printf("Shop's mail: \n");
    fgets(shop.mail, sizeof(shop.mail), stdin);
    shop.mail[strlen(shop.mail)-1] = '\0';

    fprintf(fp, "%s;%s;%d;%s\n", shop.shop, shop.adress, shop.phone, shop.mail);

    fclose(fp);

}
