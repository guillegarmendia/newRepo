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