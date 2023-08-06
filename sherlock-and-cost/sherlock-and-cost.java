/**
 * Code by longtqtqn
 */
import java.util.Scanner;
public class Main {
    public static Scanner sc = new Scanner(System.in);
    public static int[] b = new int[100005];
    public static int[][] dp = new int[2][100005];

    public static void solve() {
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            b[i] = sc.nextInt();
        }
        dp[0][0] = 0;
        dp[1][0] = 0;

        for (int i = 1; i < n; ++i) {
            dp[0][i] = Math.max(Math.abs(b[i] - b[i - 1]) + dp[0][i - 1], (b[i] - 1) + dp[1][i - 1]);
            dp[1][i] = b[i - 1] - 1 + dp[0][i - 1];
        }

        System.out.println(Math.max(dp[0][n - 1], dp[1][n - 1]));
    }

    public static void main(String[] args)
    {
        int t = sc.nextInt();
        while(t-- > 0) {
            solve();
        }
    }
}