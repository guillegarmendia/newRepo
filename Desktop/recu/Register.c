#include <stdio.h>
#include <string.h>
#include "Register.h"


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

    fprintf(fp, "%s;%s;%d;%s\n", shop.shop, shop.adress, shop.phone, shop.mail);

    fclose(fp);

}


void registerWorker() {

    Register r;
    FILE* fp = fopen("Workers.txt","a");

    if (fp == NULL) {
        printf("Error opening Workers.txt\n");
        return;
    }

    printf("Name: ");
    fgets(r.worker, sizeof(r.worker), stdin);
    r.worker[strlen(r.worker)-1] = '\0';


    printf("Mail: ");
    fgets(r.mail, sizeof(r.mail), stdin);
    r.mail[strlen(r.mail)-1] = '\0';

    printf("Password: ");
    fgets(r.password, sizeof(r.password), stdin);
    r.password[strlen(r.password)-1] = '\0';

    printf("Shop: ");
    fgets(r.shop, sizeof(r.shop), stdin);
    r.shop[strlen(r.shop)-1] = '\0';

    fprintf(fp, "%s;%s;%s;%s\n", r.worker, r.mail, r.password, r.shop);
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



}
