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

    printf("Shop's name: ");
    fgets(shop.shop, sizeof(shop.shop), stdin);
    shop.shop[strlen(shop.shop)-1] = '\0';


    printf("Shop's address: ");
    fgets(shop.adress, sizeof(shop.adress), stdin);
    shop.adress[strlen(shop.adress)-1] = '\0';

    printf("Shop's phone: ");
    scanf("%d", &shop.phone);
    getchar();

    printf("Shop's mail: ");
    fgets(shop.mail, sizeof(shop.mail), stdin);
    shop.mail[strlen(shop.mail)-1] = '\0';

    fprintf(fp, "%s;%s;%d;%s\n", shop.shop, shop.adress, shop.phone, shop.mail);

    fclose(fp);

}


void registerWorker() {

    Shop shop;
    FILE* fp = fopen("Workers.txt","a");

    if (fp == NULL) {
        printf("Error opening Workers.txt\n");
        return;
    }

    printf("Name: ");
    fgets(shop.worker, sizeof(shop.worker), stdin);
    shop.worker[strlen(shop.worker)-1] = '\0';


    printf("Mail: ");
    fgets(shop.mail, sizeof(shop.mail), stdin);
    shop.mail[strlen(shop.mail)-1] = '\0';

    printf("Password: ");
    fgets(shop.password, sizeof(shop.password), stdin);
    shop.password[strlen(shop.password)-1] = '\0';

    printf("Shop: ");
    fgets(shop.shop, sizeof(shop.shop), stdin);
    shop.shop[strlen(shop.shop)-1] = '\0';

    fprintf(fp, "%s;%s;%s;%s\n", shop.worker, shop.mail, shop.password, shop.shop);
    fclose(fp);

}
