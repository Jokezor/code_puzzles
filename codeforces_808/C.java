import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.Collectors;


public class C {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();

        while (t > 0) {
            checkContests(input);
            t--;
        }

    }
    public static void checkContests(Scanner input) {
        int n = input.nextInt();
        int q = input.nextInt();
        int[] a = new int[n];

        for (int i=0; i < n; i++) {
            a[i] = input.nextInt();
        }

        String[] contestOrder = getContestsReverseOrder(a, q, n);
        System.out.println(Arrays.stream(contestOrder).collect(Collectors.joining("")));
    }
    public static String[] getContestsReverseOrder(int[] a, int q, int n) {
        int Q = 0;
        String[] contestOrder = new String[n];
        Arrays.fill(contestOrder, "0");

        for (int i=n; i > 0 ; i--) {
            if (a[i-1] <= Q) {
                contestOrder[i-1] = "1";
            }
            if (Q < q && a[i-1] > Q) {
                contestOrder[i-1] = "1";
                Q++;
            }
        }

        return contestOrder;
    }
    public static String[] getContestsBinarySearch(int[] a, int q, int n) {
        String[] contestOrder = new String[n];
        Arrays.fill(contestOrder, "0");

        return contestOrder;
    }
}
