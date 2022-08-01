import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();
        while (t > 0) {
            t--;
            minVariedNumber(t, input);
        }
    }
    public static void minVariedNumber(int t, Scanner input) {
        int s = input.nextInt();
        int[] result = new int[9];
        int res = s;
        int candidate = 9;

        HashSet<Integer> used = new HashSet<>();


        while (res > 0) {
            int num = candidate;
            if (!used.contains(res)) {
                num = Math.min(res, candidate);
            }

            res -= num;
            used.add(num);
            result[candidate-1] = num;
            candidate--;
        }

        for (int i=0; i < 9; i++) {
            if (result[i] != 0) {
                System.out.print(result[i]);
            }
        }

        if (t > 0) {
            System.out.print("\n");
        }

        // Map out all nonzero elements from result

    }
}
