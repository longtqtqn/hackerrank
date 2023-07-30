/**
 * Code by longtqtqn
 */
import java.util.Scanner;
public class Main {
    public static final int MMOD = 1000000007;
    public static long[] dp = new long[200005];

    public static void main(String[] args)  
    {
        String s;        
        Scanner sc = new Scanner(System.in);
        s = sc.nextLine();

        long rs = 0;
        s = " " + s;
        for (int i = 1; i < s.length(); ++i) {
            dp[i] =(dp[i - 1] * 10 % MMOD + i * (s.charAt(i) - '0') % MMOD);
            rs = (rs + dp[i]) % MMOD; 
        }
        System.out.println(rs);
    }
}