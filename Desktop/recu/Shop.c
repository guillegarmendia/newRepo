#include <stdio.h>
#include <string.h>
#include "Shop.h"
#include <float.h>
#include <math.h>
#include <Llibreria Recuperació-20250406/operations.h>
#include "Register.h"
#include "TDD.h"

#define EARTH_RADIUS_KM 6371.0f


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
    float latitude = 0.0f, longitude = 0.0f;
    char latStr[20], lonStr[20];
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
            int l = 0;
            int p = 0;

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

                if(separation == 4) {
                    r.mail[k] = '\0';
                    latStr[l] = line[i];
                    l++;
                }

                if(separation == 5) {
                    latStr[l] = '\0';
                    lonStr[p] = line[i];
                    p++;
                }

            }

            lonStr[j] = '\0';
            latitude = atof(latStr);
            longitude = atof(lonStr);

            if(strcmp(r.shop, shopName) == 0) {
                fprintf(tempFile, "%s;%s;%s;%s;%.6f;%.6f\n", newName, r.adress, phone, r.mail, latitude, longitude);
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
            int l = 0;
            int p = 0;

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

                if(separation == 4) {
                    r.mail[k] = '\0';
                    latStr[l] = line[i];
                    l++;
                }

                if(separation == 5) {
                    latStr[l] = '\0';
                    lonStr[p] = line[i];
                    p++;
                }

            }

            lonStr[j] = '\0';
            latitude = atof(latStr);
            longitude = atof(lonStr);

            if(strcmp(r.shop, shopName) == 0) {
                fprintf(tempFile, "%s;%s;%s;%s;%.6f;%.6f\n", r.shop, newAddress, phone, r.mail, latitude, longitude);
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
            int l = 0;
            int p = 0;

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

                if(separation == 4) {
                    r.mail[k] = '\0';
                    latStr[l] = line[i];
                    l++;
                }

                if(separation == 5) {
                    latStr[l] = '\0';
                    lonStr[p] = line[i];
                    p++;
                }

            }

            lonStr[j] = '\0';
            latitude = atof(latStr);
            longitude = atof(lonStr);

            if(strcmp(r.shop, shopName) == 0) {
                fprintf(tempFile, "%s;%s;%d;%s;%.6f;%.6f\n", r.shop,r.adress, newPhone, r.mail,latitude,longitude);
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

float deg2rad(float deg) {
    return deg * (M_PI / 180.0f);
}

float calculateDist(Coordinates a, Coordinates b) {
    float lat1 = deg2rad(a.latitude);
    float lon1 = deg2rad(a.longitude);
    float lat2 = deg2rad(b.latitude);
    float lon2 = deg2rad(b.longitude);

    float dlat = lat2 - lat1;
    float dlon = lon2 - lon1;

    float haversine = sinf(dlat/2) * sinf(dlat/2) +
                      cosf(lat1) * cosf(lat2) * sinf(dlon/2) * sinf(dlon/2);

    float c = 2 * atan2f(sqrtf(haversine), sqrtf(1 - haversine));

    return EARTH_RADIUS_KM * c;
}

int loadShopsFromFile(const char *filename, ShopUbi *shops, int maxShops) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    char line[256];
    int count = 0;

    while (fgets(line, sizeof(line), fp) && count < maxShops) {
        // Eliminar salto de línea final
        line[strcspn(line, "\n")] = 0;

        // Parsear usando sscanf o strtok
        char phoneStr[20];
        float lat, lon;

        int n = sscanf(line, "%49[^;];%99[^;];%19[^;];%49[^;];%f;%f",
                       shops[count].name, shops[count].address, phoneStr, shops[count].email, &lat, &lon);
        if (n == 6) {
            shops[count].phone = atoi(phoneStr);
            shops[count].coords.latitude = lat;
            shops[count].coords.longitude = lon;
            count++;
        }
    }

    fclose(fp);
    return count;
}



void find5NearestShops(ShopUbi *s, int numShops, Coordinates client, int *nearest_ids) {

    float min_dist[5];
    int min_id[5];
    for (int i = 0; i < 5; i++) {
        min_dist[i] = FLT_MAX;
        min_id[i] = -1;
    }

    for (int i = 0; i < numShops; i++) {
        float dist = calculateDist(s[i].coords, client);
        for (int j = 0; j < 5; j++) {
            if (dist < min_dist[j]) {
                for (int k = 4; k > j; k--) {
                    min_dist[k] = min_dist[k-1];
                    min_id[k] = min_id[k-1];
                }
                min_dist[j] = dist;
                min_id[j] = i;
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        nearest_ids[i] = min_id[i];
    }
}



