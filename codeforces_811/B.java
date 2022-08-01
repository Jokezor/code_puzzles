import java.util.Scanner;
import java.util.HashSet;

public class B {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        while (t > 0) {
            numMoves(input);
            t--;
        }
    }
    public static void numMoves(Scanner input) {
        int n = input.nextInt();
        int[] a = new int[n];
        HashSet<Integer> set = new HashSet<>();
        int result = 0;

        for (int i=0; i < n; i++) {
            a[i] = input.nextInt();
        }

        for (int i=n-1; i >= 0; i--) {
            if (set.contains(a[i])) {
                result = i+1;
                break;
            }
            set.add(a[i]);
        }
        System.out.println(result);
    }
}
