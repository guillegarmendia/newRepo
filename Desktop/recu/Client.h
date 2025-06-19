
#define MAX 100

typedef struct {
    char name[MAX];
    char mail[MAX];
    char password[MAX];
    char shop[MAX];
    char clientProduct[MAX];
} Client;


void clientSegmentation();

void clientQuestionnaire();

void analyzeQuestionnaire();

void rateShop();

int isShopRepeated(char shops[][MAX], int count, char* newShop);

void checkRatings();