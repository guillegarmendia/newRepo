#include <stdio.h>
#include <string.h>
#include "Register.h"

#include <stdlib.h>


void registerShop() {

    Register shop;
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

    float latitud = -90.0f + ((float)rand() / RAND_MAX) * 180.0f;
    float longitud = -180.0f + ((float)rand() / RAND_MAX) * 360.0f;

    fprintf(fp, "%s;%s;%d;%s;%.6f;%.6f\n", shop.shop, shop.adress, shop.phone, shop.mail, latitud, longitud);


    fclose(fp);

}


void registerWorker() {

    Register shop;
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

void registerClient() {
    Register r;
    FILE* fp = fopen("Client.txt","a");

    if (fp == NULL) {
        printf("Error opening Client.txt\n");
        return;
    }

    printf("Name: ");
    fgets(r.client, sizeof(r.client), stdin);
    r.client[strlen(r.client)-1] = '\0';


    printf("Mail: ");
    fgets(r.mail, sizeof(r.mail), stdin);
    r.mail[strlen(r.mail)-1] = '\0';

    printf("Password: ");
    fgets(r.password, sizeof(r.password), stdin);
    r.password[strlen(r.password)-1] = '\0';

    printf("Card number: ");
    scanf("%d", &r.numCard);
    getchar();

    printf("Balance: ");
    scanf("%f", &r.balance);
    getchar();

    fprintf(fp, "%s;%s;%s;%d;%.2f\n", r.client, r.mail, r.password, r.numCard, r.balance);

}
