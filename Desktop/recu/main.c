#include <stdio.h>
#include "Register.h"
#include "Shop.h"
#include "TDD.h"

void showRegisterMenu() {
    printf("\n\t\t1.1 Register Shop");
    printf("\n\t\t1.2 Register Staff Member");
    printf("\n\t\t1.3 Register Customer");
    printf("\n\t\t1.4 Back");
    printf("\nOption: ");
}

void showStaffMenu() {
    printf("\n\t\t1.1 Modify shop's configuration");
    printf("\n\t\t1.2 Add product");
    printf("\n\t\t1.4 Back");
    printf("\nOption: ");
}

void showMainMenu() {
    printf("\n\t\t1. Register\n\t\t2. Staff Access\n\t\t3. Client Login\n\t\t4. Exit");
    printf("\nOption: ");
}

int main() {

    printf("\n----------------------\n");
    printf("--LS ELECTRONICS HUB--\n");
    printf("----------------------\n");

    int option = 0;
    int registerOption = 0;
    int staffOption = 0;
    int modifyOption = 0;

    do {
        showMainMenu();
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                do {
                    showRegisterMenu();
                    scanf("%d", &registerOption);
                    getchar();

                    switch (registerOption) {
                        case 1:
                            registerShop();
                            break;
                        case 2:
                            registerWorker();
                            break;
                        case 3:
                            registerClient();
                            break;
                        case 4:
                            printf("Returning to Menu\n");
                            break;
                        default:
                            printf("Invalid option\n");
                            break;
                    }
                } while (registerOption != 4);
                break;

            case 2:
                showStaffMenu();
                scanf("%d", &staffOption);
                getchar();

            switch (staffOption) {
                case 1:
                    printf("\n\t1.Update product price\n\t2.Adjust stock\n\t3.Change shop's name\n\t4.Change adress\n\t5.Change phone number");
                    printf("\nOption: ");
                    scanf("%d", &modifyOption);
                    getchar();
                    modifyShop(modifyOption);
                    break;

                case 2:
                    addProduct();
                break;


                default:
                    printf("Invalid option\n");
                break;
            }
                break;

            case 3:

                break;

            case 4:
                printf("End of program!\n");
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != 4);

    return 0;
}
