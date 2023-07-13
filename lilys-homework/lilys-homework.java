/**
 * Code by longtqtqn
 */
import java.util.Scanner;
import java.util.Vector;
import java.util.Map;
import java.util.TreeMap;
import java.util.Iterator;

public class Solution {

    public static int solveASC(Vector<Integer> arr, Map<Integer, Integer> m) {
        int count = 0;
        int posOfArr = 0;

        Iterator<Map.Entry<Integer, Integer>> it = m.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Integer, Integer> pair = it.next();
            int posOfNum = pair.getValue();
            int num = pair.getKey();
            int numInArr = arr.get(posOfArr);
            if (numInArr != num) {
                m.put(numInArr, posOfNum);
                arr.set(posOfNum, numInArr);
                ++count;
            }
            ++posOfArr;
        }
        return count;
    }
    public static int solveDESC(Vector<Integer> arr, Map<Integer, Integer> m) {
        int count = 0;
        int posOfArr = arr.size() - 1;

        Iterator<Map.Entry<Integer, Integer>> it = m.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Integer, Integer> pair = it.next();
            int posOfNum = pair.getValue();
            int num = pair.getKey();
            int numInArr = arr.get(posOfArr);
            if (numInArr != num) {
                m.put(numInArr, posOfNum);
                arr.set(posOfNum, numInArr);
                ++count;
            }
            --posOfArr;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Vector<Integer> arr = new Vector<Integer> ();
        Map<Integer, Integer> m = new TreeMap<>();

        for (int i = 0; i < n; ++i) {
            arr.add(scanner.nextInt());
            m.put(arr.get(i), i);
        }

        Vector<Integer> copyArr = new Vector<>(arr);
        Map<Integer, Integer> copyM = new TreeMap<>(m);
        int rsASC = solveASC(arr, m);
        int rsDESC = solveDESC(copyArr, copyM);

        System.out.println( (rsASC < rsDESC ? rsASC : rsDESC ) );

        scanner.close();
    }
}
