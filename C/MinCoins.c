#include <stdio.h>

void bubbleSort(int coins[], int arrSize);
int calcMinCoins(int coins[], int arrSize, int N);

int main(void) {
    printf("Get Min Coins\n");

    int coins[] = {10, 50, 100, 500};
    int N = 1260;

    int arrSize = sizeof(coins)/sizeof(int);

    bubbleSort(coins, arrSize);

    printf("Min Coins : %d coins.\n", calcMinCoins(coins, arrSize, N));

    return 0;
}

int calcMinCoins(int coins[], int arrSize, int N) {
    int coinCounter = 0;

    for(int i = 0; i < arrSize; i++) {
        coinCounter += (int) ((float) N / (float) coins[i]);
        N %= coins[i];
    }

    return coinCounter;
}

void bubbleSort(int coins[], int arrSize) {

    for(int i = 0; i < arrSize-1; i++) {
        for(int j = i+1; j < arrSize; j++) {

            if(j > i) {
                int tmp = coins[i];
                coins[i] = coins[j];
                coins[j] = tmp;
            }

        }
    }
}