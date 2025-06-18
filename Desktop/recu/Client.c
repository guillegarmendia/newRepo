#include <stdio.h>
#include <string.h>

#include "Client.h"

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

    int costs[numClients][MAX];
    char age[MAX], electricCost[MAX];

    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        line[strlen(line)-1] = '\0';
        int separation = 0;

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

        fgets(line, sizeof(line), fp);
    }
}