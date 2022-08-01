import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int q = input.nextInt();

        while (q > 0) {
            colorString(input);
            q--;
        }
    }
    public static void colorString(Scanner input) {
        input.nextLine();
        String t = input.nextLine();
        int n = Integer.parseInt(input.nextLine());

        String[] s = new String[n];
        HashMap<String, HashSet> map = new HashMap<String, HashSet>();
        HashSet<Integer> coverage = new HashSet();

        for (int i=0; i < n; i++) {
            s[i] = input.nextLine();
            map.put(s[i], new HashSet<Integer>());
        }

        for (int i=0; i < n; i++) {
            String key = s[i];
            int offset = 0;

            while (offset + key.length() < t.length()) {
                if (t.substring(offset, offset + key.length()).equals(key)) {
                    map.get(key).add(offset);
                }
                // Can jump longer like kmp etc
                offset++;
            }
        }

        // Need to merge all sets somehow or just map through them.
        Collection<HashSet> summedSets = map.values();
        if (summedSets.size() != t.length()) {
            System.out.println(-1);
        }
        else {
            // take the biggest set not already in coverage.
            System.out.println("Continue searching");
        }


    }
}
