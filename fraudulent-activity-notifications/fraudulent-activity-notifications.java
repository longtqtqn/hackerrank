import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

/*
Code by longtqtqn

Using default template read/write console of hackerrank :p
*/
class Result {

    static Map<Integer, Integer> map = new TreeMap<>();
    static {
        for (int i = 0; i <= 200; ++i) {
            map.put(i, 0);
        }
    }
    
    private static double getMedian(int d) {
        Integer count = 0;
        int remember = -1;
        int mid = d / 2;

        Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Integer, Integer> pair = it.next();
            count += pair.getValue();
            if (count > mid) {    
                if (d % 2 == 1 || remember == -1) {
                    return pair.getKey();
                }            
                return (remember + pair.getKey()) / 2.0;
            }
            if (count == mid && d % 2 == 0) {         
                remember = pair.getKey();
            }
        }
        return 0;
    }

    private static void incMap(int key) {
        int value = map.get(key);
        map.put(key, value + 1);
    }
    
    private static void decMap(int key) {
        int value = map.get(key);
        map.put(key, value - 1);
    }
    
    public static int activityNotifications(List<Integer> expenditure, int d) {
        int rs = 0;
        for (int i = 0; i < d; ++i) {
            incMap(expenditure.get(i));
        }
        
        for (int i = d; i < expenditure.size(); ++i) {
            double median = getMedian(d);       
            int exp = expenditure.get(i);
            if (exp >= median * 2) {
                ++rs;
            } 
            decMap(expenditure.get(i - d));
            incMap(expenditure.get(i)); 
        }
        
        return rs;
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int d = Integer.parseInt(firstMultipleInput[1]);

        List<Integer> expenditure = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.activityNotifications(expenditure, d);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
