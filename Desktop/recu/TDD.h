#ifndef TDD_H
#define TDD_H
#define MAX 100

char *readProduct();
void TEST_shouldReturnProduct();

char *readShop();
void TEST_shouldReturnShop();

float getLowestDist();
void TEST_findDistante();

int checkIsActive(char* start, char* end);
void TEST_shouldReturnIfIsActive();

float calculateAverage(float a, float b);
void TEST_returnAverage();



#endif