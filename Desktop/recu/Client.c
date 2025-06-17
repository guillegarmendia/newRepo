#include <stdio.h>
#include <string.h>

#include "Client.h"

void clientSegmentation() {
    Client c[20];
    int numClients;
    int maxClients = 0;
    char line[MAX];

    FILE *fp = fopen("Client.txt", "r");

    fgets(line, sizeof(line), fp);
    while(!feof(fp)) {
        fgets(line, sizeof(line), fp);
        maxClients++;
    }

    while(1) {
        printf("How many clients do you want to segmentate? ");
        scanf("%d", &numClients);
        getchar();

        if(numClients > maxClients) {
            printf("\nToo many clients, there are %d clients\n\n", maxClients);
        } else {
            break;
        }

    }


}