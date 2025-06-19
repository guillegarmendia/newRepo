#include <stdio.h>
#include <string.h>

#include "Client.h"

#include <stdlib.h>

void clientSegmentation() {
    Client c;
    int numClients;
    int maxClients = 0;
    int i, j;
    char line[MAX];

    FILE *fp = fopen("Client.txt", "r");

    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        fgets(line, sizeof(line), fp);
        maxClients++;
    }

    fclose(fp);

    while(1) {
        printf("How many clients do you want to segmentate? ");
        scanf("%d", &numClients);
        getchar();

        if(numClients > maxClients) {
            printf("\nToo many clients, there are only %d clients registered\n\n", maxClients);
        } else {
            break;
        }
    }

    fp = fopen("Client.txt", "r");
    FILE *segFile = fopen("ClientSegmentation.txt", "a");

    for( i = 0; i < numClients; i++) {
        fgets(line, sizeof(line), fp);
        line[strlen(line)-1] = '\0';

        for( j = 0; line[j] != ';'; j++) {
            c.name[j] = line[j];
        }
        c.name[j] = '\0';

        printf("\n%d. Enter the product for %s: ", i+1, c.name);
        fgets(c.clientProduct, sizeof(c.clientProduct), stdin);
        c.clientProduct[strlen(c.clientProduct)-1] = '\0';

        fprintf(segFile, "%s;%s\n", line, c.clientProduct);
        printf("!%s saved!\n", c.clientProduct);


    }

}


void clientQuestionnaire() {
    char city[MAX];
    char lastProduct[MAX];
    char shop[MAX];
    char *age[MAX] = {"-18", "18-35", "36-50", "+60"};
    int ageOption;
    int cost;
    FILE * fp = fopen("Questionnaire.txt", "a");

    printf("Welcome to the questionnaire, answer the following questions. ");
    printf("\n\tEnter your city: ");
    fgets(city, sizeof(city), stdin);
    city[strlen(city)-1] = '\0';

    printf("\n\tEnter the last product you bought: ");
    fgets(lastProduct, sizeof(lastProduct), stdin);
    lastProduct[strlen(lastProduct)-1] = '\0';

    printf("\n\tEnter the shop you usually buy: ");
    fgets(shop, sizeof(shop), stdin);
    shop[strlen(shop)-1] = '\0';

    while(ageOption >= 5 || ageOption <= 0) {
        printf("\n\t\t1. (-18)\n\t\t2. (18-35)\n\t\t3. (35-59)\n\t\t4. (+60)");
        printf("\n\tEnter your age: ");
        scanf("%d", &ageOption);
        getchar();
    }

    printf("\n\tHow much do you usually spend on electric components? ");
    scanf("%d", &cost);
    getchar();

    fprintf(fp, "%s;%s;%s;%s;%d\n", city, lastProduct,shop,age[ageOption - 1], cost);
    fclose(fp);

    printf("\nAnswers saved!\n");
}


void analyzeQuestionnaire() {
    FILE *fp = fopen("Client.txt", "r");
    char line[MAX];
    int i, j = 0, k = 0;
    int numClients = 0;

    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        fgets(line, sizeof(line), fp);
        numClients++;
    }

    fclose(fp);

    fp = fopen("Questionnaire.txt", "r");

    float costs[4][numClients];
    int ageType;
    int a = 0, b = 0, c = 0, d = 0;
    char age[MAX], electricCost[MAX];

    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        line[strlen(line)-1] = '\0';
        int separation = 0;
        j = 0, k = 0;
        for( i = 0; line[i] != '\0'; i++) {
            if(line[i] == ';') {
                separation++;
                i++;
            }

            if(separation == 3) {
                age[j++] = line[i];
            }

            if(separation == 4) {
                age[j] = '\0';
                electricCost[k++] = line[i];
            }

        }

        electricCost[k] = '\0';


            if(strcmp(age,"-18") == 0 ) {
                costs[0][a++] = atof(electricCost);
            } if(strcmp(age,"18-35") == 0 ) {
                costs[1][b++] = atof(electricCost);
            } if(strcmp(age,"35-59") == 0 ) {
                costs[2][c++] = atof(electricCost);
            } if(strcmp(age,"+60") == 0 ) {
                costs[3][d++] = atof(electricCost);
            }

        fgets(line, sizeof(line), fp);
    }


        float mediaA = 0.0, mediaB = 0.0, mediaC = 0.0, mediaD = 0.0;
        float sumaA = 0.0, sumaB = 0.0, sumaC = 0.0, sumaD = 0.0;

    for(i = 0; i < a; i++) {
        sumaA += costs[0][i];
    }

    mediaA = sumaA/a;

    printf("\nAverage of (-18): %.2f€\n", mediaA);

    for(i = 0; i < b; i++) {
        sumaB += costs[1][i];
    }

    mediaB = sumaB/b;

    printf("Average of (18-35): %.2f€\n", mediaB);

    for(i = 0; i < c; i++) {
        sumaC += costs[2][i];
    }

    mediaC = sumaC/c;

    printf("Average of (35-59): %.2f€\n", mediaC);

    for(i = 0; i < d; i++) {
        sumaD += costs[3][i];
    }

    mediaD = sumaD/d;

    printf("Average of (+60): %.2f€\n", mediaD);


}


int isShopRepeated(char shops[][MAX], int count, char* newShop) {
    for (int i = 0; i < count; i++) {
        if (strcmp(shops[i], newShop) == 0)
            return 1;
    }
    return 0;
}


void rateShop() {
    FILE *fp = fopen("Shops.txt", "r");
    char line[MAX];
    char shops[20][MAX];
    int shopCount = 0;
    int i ,shopOption, shopRating;


    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        line[strlen(line)-1] = '\0';
        char shopName[MAX];

        for (i = 0; line[i] !=';'; i++) {
            shopName[i] = line[i];
        }

        shopName[i] = '\0';

        if (!isShopRepeated(shops, shopCount, shopName)) {
            strcpy(shops[shopCount], shopName);
            shopCount++;
        }

        fgets(line, sizeof(line), fp);
    }

    fclose(fp);

    printf("\nAvailable shops: ");
    for (i = 0; i < shopCount; i++) {
        printf("\n\t%d. %s ", i+1, shops[i]);
    }

    printf("\n\nWhich one do you want to rate? ");
    scanf("%d", &shopOption);
    getchar();

    shopOption = shopOption - 1;

    while(shopRating <= 0 || shopRating >= 6) {
        printf("Enter from 1 - 5 stars for %s: ", shops[shopOption]);
        scanf("%d", &shopRating);
        getchar();
    }

    fclose(fp);

    fp = fopen("Workers.txt", "r");

    printf("Available workers from %s: ", shops[shopOption]);

    int j = 0, count = 1;

    char worker[30][MAX], shopName[MAX];
    char emp[30][MAX];

    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        line[strlen(line)-1] = '\0';

        int separation = 0, k = 0;

        for( i = 0; line[i] !='\0'; i++) {
            if(line[i] == ';') {
                separation++;
                i++;
            }

            if(separation == 0) {
                worker[j][i] = line[i];
            }

            if(separation == 1) {
                worker[j][i] = '\0';
            }

            if(separation == 3) {
                shopName[k++] = line[i];
            }


        }

        shopName[k] = '\0';

        if(strcmp(shopName,shops[shopOption]) == 0) {

            printf("\n\t%d. %s",count,worker[j]);
            strcpy(emp[count],worker[j]);
            count++;
        }

        j++;

        fgets(line, sizeof(line), fp);
    }

    fclose(fp);

    int workerOption = 100;

     while(workerOption > count) {
        printf("\nWhich worker do you want to rate? ");
        scanf("%d", &workerOption);
        getchar();
   }

    int ratingWorker;

    while(ratingWorker <= 0 || ratingWorker >= 6) {
        printf("\nEnter from 1 - 5 stars for %s:  ", emp[workerOption]);
        scanf("%d", &ratingWorker);
        getchar();
    }

    fp = fopen("Ratings.txt", "a");
    fprintf(fp, "%s;%d;%s;%d\n", shops[shopOption], shopRating, emp[workerOption], ratingWorker);

    printf("\nAll ratings saved!\n");

    fclose(fp);
}


void checkRatings() {
    FILE *fp = fopen("Ratings.txt", "r");
    FILE *temp = fopen("Ratings_temp.txt", "w");


    char line[MAX];
    char shop[MAX], worker[MAX];
    char aux[10];
    int shopRating = 0, workerRating = 0;
    int numRating = 1;
    int exit = 0;
    char cont[MAX], option[MAX];


    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        line[strlen(line)-1] = '\0';
        int separation = 0, j = 0, g = 0, k = 0, p = 0;

        for(int i = 0; line[i] != '\0'; i++) {
            if(line[i] == ';') {
                separation++;
                i++;
            }

            if(separation == 0) {
                shop[p++] = line[i];
            }

            if(separation == 1) {
                shop[p] = '\0';
                aux[j++] = line[i];
            }

            if(separation == 2) {
                aux[j] = '\0';
                shopRating = atoi(aux);
                worker[g++] = line[i];
            }

            if(separation == 3) {
                worker[g] = '\0';
                aux[k++] = line[i];
            }
        }

        aux[k] = '\0';
        workerRating = atoi(aux);



        if(!exit) {
            printf("\nRating number %d: ",numRating);
            printf("\n\t %s's rating: %d stars - %s's rating: %d stars", shop, shopRating, worker, workerRating);

            while(1){

                printf("\nDo you want to delete this rating? Enter 'YES' or 'NO': ");
                fgets(option, sizeof(option), stdin);
                option[strlen(option)-1] = '\0';


                if(strcmp(option, "YES") == 0) {
                    printf("Rating number %d has been deleted\n", numRating);
                    break;
                }

                if(strcmp(option, "NO") == 0) {
                    printf("Rating number %d has NOT been deleted\n", numRating);
                    fprintf(temp, "%s\n", line);
                    break;
                }
            }


            while(1) {
                printf("Do you want to continue? Enter 'YES' or 'NO': ");
                fgets(cont, sizeof(cont), stdin);
                cont[strlen(cont)-1] = '\0';

                if(strcmp(cont, "YES") == 0) {
                    printf("Ok, next rating\n");
                    break;
                } if(strcmp(cont, "NO") == 0) {
                    printf("Ratings check is over");
                    exit = 1;
                    break;
                }
            }

            } else {
                fprintf(temp, "%s\n", line);
            }




        fgets(line, sizeof(line), fp);
        numRating++;
    }


    fclose(fp);
    fclose(temp);

    remove("Ratings.txt");
    rename("Ratings_temp.txt", "Ratings.txt");
}