/**
 * Code by longtqtqn
 */
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String args[]) {
        //Just code for fun :))
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int it = 0; it < t; ++it) {
            int n = sc.nextInt();
            List<Integer> prices = new ArrayList<>(Arrays.asList(new Integer[n]));

            prices.forEach(number -> {
                int price = sc.nextInt();
                prices.set(prices.indexOf(number), price);
            });

            long curMax = prices.get(n - 1);
            long rs = 0;

            for (int i = n - 2; i >= 0; --i) {
                if (prices.get(i) < curMax) {
                    rs += curMax - prices.get(i);
                } else {
                    curMax = prices.get(i);
                }
            }
        
            System.out.println(rs);
        }
    }
}