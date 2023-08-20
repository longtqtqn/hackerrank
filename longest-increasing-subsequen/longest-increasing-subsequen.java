/**
 * Code by longtqtqn
 */
import java.util.Scanner;
import java.util.Arrays;
public class Main {

    public static int lower_bound(int[] list, int value) {
        int l = 0, r = list.length;
        while(l <= r) {
            int m = (l + r) / 2;
            if (list[m] < value) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    public static void main(String[] args)  
    {
        int n, rs = 0;        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] arr = new int[n];
        int[] F = new int[n];
        Arrays.fill(F, Integer.MAX_VALUE);

        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextInt();
        }
        F[0] = arr[0];

        for (int i = 1; i < n; ++i) {
            int index = lower_bound(F, arr[i]);
            rs = Math.max(rs, index + 1);
            F[index] = arr[i];
        }
        
        System.out.println(rs);
    }
}