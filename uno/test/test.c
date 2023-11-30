#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <bsd/stdlib.h>

void printTabInt(int *tab, int size) {
    if  (!tab) exit(EXIT_FAILURE);
    printf("size : %d\n", size);
    int side = sqrt(size);
    int leftover = size / side + size % side;
    for (int i = 0; i < side - 1; i++) {
        for (int j = 0; j < side; j++) {
            printf("%d ",tab[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < leftover; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void printTabFloat(float *tab, int size) {
    if  (!tab) exit(EXIT_FAILURE);
    printf("size : %d\n", size);
    int side = sqrt(size);
    int leftover = size / side + size % side;
    for (int i = 0; i < side - 1; i++) {
        for (int j = 0; j < side; j++) {
            printf("%f ",tab[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < leftover; i++) {
        printf("%f ",tab[i]);
    }
    printf("\n");
}

int getRandomInt(int limit) {
    return rand()%limit;
}
/*
int getMinimumInt(int *tab, int size) {
    int min = tab[0];
    for (int i = 0; i < size; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
    }
    return min;
}

int getTabDiff(int *tab, int size) {
    int min = getMinimumInt(tab, size);
    for (int i = 0; i < size; i++) {
        tab[i] = tab[i] - min;
    }
    return *tab;
}*/

float getTabPercentages(int *tab, int size, int nbOccurence) {
    float tabPerc[size];
    for (int i = 0; i < size; i++) {
        tabPerc[i] = ((float)tab[i] / nbOccurence) *100;
    }
    return *tabPerc;
}

int main(void) {
    srand(time(NULL));

    int tab[100] = {0};
    int nbOccurence = 10000000;
    for (int i = 0; i < nbOccurence; i++) {
        tab[getRandomInt(100)]++;
    }
    float tabPerc = getTabPercentages(tab, 100, nbOccurence);
    printTabInt(tab, 100);
    printf("\n");
    printTabFloat(&tabPerc, 100);
    return EXIT_SUCCESS;
}