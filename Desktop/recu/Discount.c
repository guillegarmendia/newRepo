#include <stdio.h>
#include <string.h>
#include <TDD.h>

#include <Discount.h>
#include <stdlib.h>

void manageDisc(int option) {
    Discount d;
    char discCode[MAX];
    FILE *fp;
    FILE *temp;
    int found = 0;

    switch(option) {
        case 1:
            fp = fopen("Discount.txt", "a");

            if(fp == NULL) {
                printf("Error opening file Discount.txt\n");
            } else {
                printf("Enter a new discount/promotion code: ");
                scanf("%d", &d.code);
                getchar();

                printf("Enter the start day (DAY-MONTH-YEAR): ");
                fgets(d.startDate, sizeof(d.startDate), stdin);
                d.startDate[strlen(d.startDate) - 1] = '\0';

                printf("Enter the end day (DAY-MONTH-YEAR): ");
                fgets(d.endDate, sizeof(d.endDate), stdin);
                d.endDate[strlen(d.endDate) - 1] = '\0';

                printf("Enter the shop's name: ");
                fgets(d.shop, sizeof(d.shop), stdin);
                d.shop[strlen(d.shop) - 1] = '\0';

                printf("Enter the products (category) where this discount is applicable: ");
                fgets(d.applicableProducts, sizeof(d.applicableProducts), stdin);
                d.applicableProducts[strlen(d.applicableProducts) - 1] = '\0';

-
                fprintf(fp,"%d;%s;%s;%s;%s\n", d.code, d.startDate, d.endDate, d.shop, d.applicableProducts);

                printf("\nCode created!\n");
                fclose(fp);
            }
            break;

        case 2:
            found = 0;
            char newDate[MAX];
            char line[200];
            char rest[MAX];
            int codeChange;

            printf("Enter the code to change: ");
            scanf("%d", &codeChange);
            getchar();

            printf("Enter the new end time (DAY-MONTH-YEAR): ");
            fgets(newDate, sizeof(newDate), stdin);
            newDate[strlen(newDate) - 1] = '\0';

            fp = fopen("Discount.txt", "r");
            temp = fopen("Discount_temp.txt", "w");

            fgets(line, sizeof(line), fp);

            while(!feof(fp)) {
                line[strlen(line) - 1] = '\0';

                int separation = 0;
                int i = 0;
                int j = 0;
                int k = 0;
                int l = 0;
                int p = 0;

                for( i = 0; line[i] != '\0'; i++) {
                    if(line[i] == ';') {
                        separation++;
                        i++;
                    }

                    if(separation == 0) {
                        discCode[p] = line[i];
                        p++;
                    }

                    if(separation == 1) {
                        discCode[p] = '\0';
                        d.startDate[j] = line[i];
                        j++;
                    }

                    if(separation == 2) {
                        d.startDate[j] = '\0';
                        d.endDate[k] = line[i];
                        k++;
                    }

                    if(separation >= 3) {
                        d.endDate[k] = '\0';
                        rest[l++] = line[i];
                    }

                }

                rest[l] = '\0';

                if(codeChange == atoi(discCode)) {
                    fprintf(temp,"%d;%s;%s;%s\n", codeChange, d.startDate, newDate, rest);
                    found = 1;
                } else {
                    fprintf(temp,"%s\n", line);
                }

                fgets(line, sizeof(line), fp);
            }

        fclose(fp);
        fclose(temp);

        remove("Discount.txt");
        rename("Discount_temp.txt", "Discount.txt");

        if(found) {
            printf("%s is the new end date for this code: %d\n", newDate, codeChange);
        } else {
            printf("%d has not been found.\n", codeChange);
        }


            break;



        default:
            printf("Invalid option.\n");
        break;

    }

}
