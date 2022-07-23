import java.util.Scanner;
import java.util.Arrays;
import java.util.stream.Collectors;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class B {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();

        while (t > 0) {
            solution(input);
            t--;
        }
    }
    public static void solution(Scanner input) {
        int n = input.nextInt();
        int l = input.nextInt();
        int r = input.nextInt();

        String[] a = new String[n];
        String result = "YES";

        for (int i=n; i > 0; i--) {
            int temp = ((l - 1) / i + 1) * i;
            if (temp > r) {
                result = "NO";
            }
            a[i-1] = String.valueOf(temp);
        }

        System.out.println(result);

        if (result.equals("YES")) {
            System.out.println(Arrays.stream(a).collect(Collectors.joining(" ")));
        }
    }
    public static int gcd(int a, int b) {
        int d = max(a, b);
        int c = min(a, b);

        if (c == 0) {
            return d;
        }
        if (d == 0) {
            return c;
        }

        return gcd(c, d % c);
    }
}
