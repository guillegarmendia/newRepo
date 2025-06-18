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


}