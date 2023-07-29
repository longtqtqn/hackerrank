/**
 * Code by longtqtqn
 */
import java.util.Scanner;
public class Main {
    public static final int MMOD = 1000000007;

    public static void main(String[] args)
    {
        int n, k, x;
        
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        k = s.nextInt();
        x = s.nextInt();
        long[][] dp = new long[2][n];

        if (x != 1) {
            dp[1][1] = 1;
            dp[0][1] = k - 2;
        } else {
            dp[1][1] = 0;
            dp[0][1] = k - 1;
        }

        for (int i = 2; i < n - 1; ++i) {
            dp[0][i] = (dp[0][i - 1] * (k - 2) % MMOD +  dp[1][i - 1] * (k - 1)) % MMOD;
            dp[1][i] = dp[0][i - 1];
        }

        System.out.println(dp[0][n - 2]);
    }
}