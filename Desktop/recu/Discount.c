#include <stdio.h>
#include <string.h>
#include <TDD.h>

#include <Discount.h>

void manageDisc(int option) {
    Discount d;
    FILE *fp;

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


                fprintf(fp,"%d;%s;%s;%s;%s", d.code, d.startDate, d.endDate, d.shop, d.applicableProducts);

                printf("\nCode created!\n");
                fclose(fp);
            }
            break;

        default:
            printf("Invalid option.\n");
        break;

    }

}