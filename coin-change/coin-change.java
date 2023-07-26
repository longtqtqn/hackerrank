import java.util.Scanner;
import java.util.Vector;
import java.util.Collections;

public class Main {
    public static void main(String[] args)
    {
        long[][] dp = new long[51][251];
        int n, m;
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        m = s.nextInt();
        Vector<Integer> c = new Vector<>();
        for (int i = 0; i < m; ++i) {
            int tmp = s.nextInt();
            c.add(tmp);
            dp[tmp][tmp] = 1;
        }
        Collections.sort(c);
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < c.size(); ++j) {
                for (int jj = j; jj < c.size(); ++jj) {
                    if (i + c.get(jj) <= n) {
                        dp[c.get(jj)][i + c.get(jj)] += dp[c.get(j)][i];
                    }
                }
            }
        }

        long rs = 0;
        for (int x : c) {
            rs += dp[x][n];
        }

        System.out.println(rs);
    }
}