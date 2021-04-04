package Java;

import java.util.Arrays;
import java.util.Collections;

public class MinCoins {
    public static void main(String[] args) {
        System.out.println("### MinCoins ###");

        Integer coins[] = {10, 50, 100, 500};
        int N = 1260;

        Arrays.sort(coins, Collections.reverseOrder());

        System.out.println("MinCoins : " + Integer.toString(calcMinCoins(coins, N)));

    }

    private static int calcMinCoins(Integer coins[], int N) {

        int counter = 0;
        for(int coin : coins) {
            counter += (int)((double)N/(double)coin);
            N %= coin;
        }

        return counter;
    }
}