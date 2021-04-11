#include <stdio.h>
#include <string.h>

int main(void) {
    char info[5] = "5 8 3";
    char *input = "2 4 5 4 6";

    /* 입력값 검증 */
    
    int N = info[0] - '0';
    if ( 2 > N || 1000 < N ) {
        return 1;
    } 

    int M = info[2] - '0';
    if ( 1 > M || 10000 < M ) {
        return 1;
    }

    int K = info[4] - '0';
    if ( 1 > K || 10000 < K ) {
        return 1;
    }
    
    int inputLen = strlen(input);

    int inputArr[N];
    int number;

    inputArr[0] = input[0] - '0';
    int inx = 1;

    for (int i = 1; i < inputLen; i++) {
        if (i%2 == 0) {
            number = input[i] - '0';

            // 내림차순 정렬
            for(int j = 0; j < inx; j++) {
                if(number > inputArr[j]) {
                    int tmp = inputArr[j];
                    inputArr[j] = number;
                    number = tmp;
                } 
            }
            inputArr[inx] = number;
            inx++;
        }
    }

    int biggestNumber = inputArr[0];
    int secondBiggestNumber = inputArr[1];

    int count = 0;
    int sum = 0;
    for (int i = 0; i < M; i++) {
        if (count < K) {
            sum += biggestNumber;
            count++;
        }
        else {
            sum += secondBiggestNumber;
            count = 0;
        }
    }

    printf("Result : %d\n", sum);

    return 0;
}