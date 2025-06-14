#include <stdio.h>
#include <string.h>
#include "Shop.h"
#include "Register.h"
#include "TDD.h"


void modifyShop(int modifyOption) {
    Shop s;
    Register r;

    FILE *shopFile;
    FILE *productFile;
    FILE *tempFile;

    char line[MAX];
    char productName[MAX];
    char price[MAX];
    char shopName[MAX];
    char newName[MAX];
    char newAddress[MAX];
    char phone[MAX];
    int newPhone;
    int i;
    int found = 0;


    switch(modifyOption) {
        case 1:
            printf("Introduce the name of the product to change its price: ");
            fgets(s.product, MAX, stdin);
            s.product[strlen(s.product) - 1] = '\0';

            float newPrice;

            printf("Introduce the new price for %s: ", s.product);
            scanf("%f", &newPrice);
            getchar();

        productFile = fopen("Products.txt", "r");
        tempFile = fopen("Products_temp.txt", "w");   //Fichero temporal para hacer modificaciones

            fgets(line, sizeof(line),productFile);

            while(!feof(productFile)) {

                line[strlen(line) - 1] = '\0';
                int j = 0;
                int g = 0;
                int k = 0;
                char quantity[MAX];

                int separation = 0;
                for(i = 0; line[i] != '\0'; i++) {
                    if(line[i] == ';') {
                        separation++;
                        i++;
                    }

                    if(separation == 0) {
                        productName[i] = line[i];
                    }

                    if(separation == 1) {
                        productName[i] = '\0';
                        s.category[j] = line[i];
                        j++;
                    }

                    if(separation == 2) {
                        s.category[j] = '\0';
                        //No hay que hacer nada, ya que se escribe nuevo precio
                    }

                    if(separation == 3) {
                        quantity[g] = line[i];
                        g++;
                    }

                    if(separation == 4) {
                        quantity[g] = '\0';
                        s.description[k] = line[i];
                        k++;
                    }

                }

                s.description[k] = '\0';


                if(strcmp(s.product, productName) == 0) {
                    fprintf(tempFile, "%s;%s;%.2f;%s;%s\n", s.product, s.category, newPrice, quantity, s.description);
                    found = 1;
                } else {
                    fprintf(tempFile, "%s\n", line);
                }

                fgets(line, sizeof(line),productFile);

            }

        fclose(productFile);
        fclose(tempFile);

        remove("Products.txt");
        rename("Products_temp.txt", "Products.txt");

            if(found) {
                printf("%s price has been changed.\n", s.product);
            } else {
                printf("%s has not been found.\n", s.product);
            }

            break;

        case 2:

            printf("Introduce the name of the product to change its stock: ");
            fgets(s.product, MAX, stdin);
            s.product[strlen(s.product) - 1] = '\0';

            int newStock;

            printf("Introduce the new stock for %s: ", s.product);
            scanf("%d", &newStock);
            getchar();

        productFile = fopen("Products.txt", "r");
        tempFile = fopen("Products_temp.txt", "w");   //Fichero temporal para hacer modificaciones

            fgets(line, sizeof(line),productFile);

            while(!feof(productFile)) {

                line[strlen(line) - 1] = '\0';
                int j = 0;
                int g = 0;
                int k = 0;

                int separation = 0;
                for(i = 0; line[i] != '\0'; i++) {
                    if(line[i] == ';') {
                        separation++;
                        i++;
                    }

                    if(separation == 0) {
                        productName[i] = line[i];
                    }

                    if(separation == 1) {
                        productName[i] = '\0';
                        s.category[j] = line[i];
                        j++;
                    }

                    if(separation == 2) {
                        s.category[j] = '\0';
                        price[g] = line[i];
                        g++;
                    }

                    if(separation == 3) {
                        price[g] = '\0';
                        //No hay que hacer nada, ya que se escribe nuevo stock
                    }

                    if(separation == 4) {
                        s.description[k] = line[i];
                        k++;
                    }

                }

                s.description[k] = '\0';


                if(strcmp(s.product, productName) == 0) {
                    fprintf(tempFile, "%s;%s;%s;%d;%s\n", s.product, s.category, price, newStock, s.description);
                    found = 1;
                } else {
                    fprintf(tempFile, "%s\n", line);
                }

                fgets(line, sizeof(line),productFile);

            }

        fclose(productFile);
        fclose(tempFile);

        remove("Products.txt");
        rename("Products_temp.txt", "Products.txt");

            if(found) {
                printf("%s stock has been changed.\n", s.product);
            } else {
                printf("%s has not been found.\n", s.product);
            }

            break;

        case 3:

            printf("Introduce the name of the shop to change its name: ");
            fgets(r.shop, MAX, stdin);
            r.shop[strlen(r.shop) - 1] = '\0';

            printf("Introduce the new shop name for %s: ", r.shop);
            fgets(newName, sizeof(newName), stdin);
            newName[strlen(newName) - 1] = '\0';


            shopFile = fopen("Shops.txt", "r");
            tempFile = fopen("Shop_temp.txt", "w");

        fgets(line, sizeof(line), shopFile);

        while(!feof(shopFile)) {

            line[strlen(line) - 1] = '\0';
            int j = 0;
            int g = 0;
            int k = 0;

            int separation = 0;
            for(i = 0; line[i] != '\0'; i++) {
                if(line[i] == ';') {
                    separation++;
                    i++;
                }

                if(separation == 0) {
                    shopName[i] = line[i];
                }

                if(separation == 1) {
                    i--;
                   shopName[i] = '\0';
                    i++;
                    r.adress[j] = line[i];
                    j++;
                }

                if(separation == 2) {
                    r.adress[j] = '\0';
                    phone[g] = line[i];
                    g++;
                }

                if(separation == 3) {
                    phone[g] = '\0';
                    r.mail[k] = line[i];
                    k++;
                }

            }

            r.mail[k] = '\0';


            if(strcmp(r.shop, shopName) == 0) {
                fprintf(tempFile, "%s;%s;%s;%s\n", newName,r.adress, phone, r.mail);
                found = 1;
            } else {
                fprintf(tempFile, "%s\n", line);
            }

            fgets(line, sizeof(line),shopFile);

        }

        fclose(shopFile);
        fclose(tempFile);

        remove("Shops.txt");
        rename("Shop_temp.txt", "Shops.txt");

        if(found) {
            printf("%s is the new shop name\n", newName);
        } else {
            printf("%s has not been found.\n", r.shop);
        }
            break;

        case 4:

            printf("Introduce the name of the shop to change its address: ");
            fgets(r.shop, MAX, stdin);
            r.shop[strlen(r.shop) - 1] = '\0';

            printf("Introduce the new shop address for %s: ", r.shop);
            fgets(newAddress, sizeof(newAddress), stdin);
            newAddress[strlen(newAddress) - 1] = '\0';


            shopFile = fopen("Shops.txt", "r");
            tempFile = fopen("Shop_temp.txt", "w");

        fgets(line, sizeof(line), shopFile);

        while(!feof(shopFile)) {

            line[strlen(line) - 1] = '\0';
            int j = 0;
            int g = 0;
            int k = 0;

            int separation = 0;
            for(i = 0; line[i] != '\0'; i++) {
                if(line[i] == ';') {
                    separation++;
                    i++;
                }

                if(separation == 0) {
                    shopName[i] = line[i];
                }

                if(separation == 1) {
                    i--;
                   shopName[i] = '\0';
                    i++;
                    r.adress[j] = line[i];
                    j++;
                }

                if(separation == 2) {
                    r.adress[j] = '\0';
                    phone[g] = line[i];
                    g++;
                }

                if(separation == 3) {
                    phone[g] = '\0';
                    r.mail[k] = line[i];
                    k++;
                }

            }

            r.mail[k] = '\0';


            if(strcmp(r.shop, shopName) == 0) {
                fprintf(tempFile, "%s;%s;%s;%s\n", r.shop,newAddress, phone, r.mail);
                found = 1;
            } else {
                fprintf(tempFile, "%s\n", line);
            }

            fgets(line, sizeof(line),shopFile);

        }

        fclose(shopFile);
        fclose(tempFile);

        remove("Shops.txt");
        rename("Shop_temp.txt", "Shops.txt");

        if(found) {
            printf("%s is the new shop address of %s\n", newAddress, r.shop);
        } else {
            printf("%s has not been found.\n", r.shop);
        }
            break;

        case 5:


            printf("Introduce the name of the shop to change its phone contact: ");
            fgets(r.shop, MAX, stdin);
            r.shop[strlen(r.shop) - 1] = '\0';

            printf("Introduce the new shop phone contact for %s: ", r.shop);
            scanf("%d", &newPhone);
            getchar();

            shopFile = fopen("Shops.txt", "r");
            tempFile = fopen("Shop_temp.txt", "w");

        fgets(line, sizeof(line), shopFile);

        while(!feof(shopFile)) {

            line[strlen(line) - 1] = '\0';
            int j = 0;
            int g = 0;
            int k = 0;

            int separation = 0;
            for(i = 0; line[i] != '\0'; i++) {
                if(line[i] == ';') {
                    separation++;
                    i++;
                }

                if(separation == 0) {
                    shopName[i] = line[i];
                }

                if(separation == 1) {
                    i--;
                   shopName[i] = '\0';
                    i++;
                    r.adress[j] = line[i];
                    j++;
                }

                if(separation == 2) {
                    r.adress[j] = '\0';
                    phone[g] = line[i];
                    g++;
                }

                if(separation == 3) {
                    phone[g] = '\0';
                    r.mail[k] = line[i];
                    k++;
                }

            }

            r.mail[k] = '\0';


            if(strcmp(r.shop, shopName) == 0) {
                fprintf(tempFile, "%s;%s;%d;%s\n", r.shop,r.adress, newPhone, r.mail);
                found = 1;
            } else {
                fprintf(tempFile, "%s\n", line);
            }

            fgets(line, sizeof(line),shopFile);

        }

        fclose(shopFile);
        fclose(tempFile);

        remove("Shops.txt");
        rename("Shop_temp.txt", "Shops.txt");

        if(found) {
            printf("%d is the new shop contact of %s\n", newPhone, r.shop);
        } else {
            printf("%s has not been found.\n", r.shop);
        }
            break;

        default:
            printf("Invalid option\n");
        break;
    }

}

void addProduct() {
    Shop s;
    FILE* fp = fopen("Products.txt", "a");

    printf("Enter the product's name: ");
    fgets(s.product, MAX, stdin);
    s.product[strlen(s.product) - 1] = '\0';

    printf("Enter the category: ");
    fgets(s.category, MAX, stdin);
    s.category[strlen(s.category) - 1] = '\0';

    printf("Enter the price: ");
    scanf("%f", &s.price);
    getchar();

    printf("Enter the number of stocks: ");
    scanf("%d", &s.quantity);
    getchar();

    printf("Enter the descripction: ");
    fgets(s.description, MAX, stdin);
    s.description[strlen(s.description) - 1] = '\0';

    fprintf(fp, "%s;%s;%.2f;%d;%s", s.product, s.category, s.price, s.quantity, s.description);
    fclose(fp);
}