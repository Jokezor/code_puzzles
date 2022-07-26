import java.util.Scanner;
import java.util.Arrays;

public class A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();

        while (t > 0) {
            getMinimalStringLength(input);
            t--;
        }
    }
    public static void getMinimalStringLength(Scanner input) {
        int n = input.nextInt();
        int m = input.nextInt();
        StringBuffer sb = new StringBuffer();
        String[] s = new String[m];
        Arrays.fill(s, "B");

        for (int i=0; i < n; i++) {
            int firstChoice = input.nextInt() - 1;
            int secondChoice = (m - firstChoice) - 1;

            int tmp;

            if (secondChoice < firstChoice) {
                tmp = secondChoice;
                secondChoice = firstChoice;
                firstChoice = tmp;
            }

            if (s[firstChoice].equals("B")) {
                s[firstChoice] = "A";
            }
            else if (s[secondChoice].equals("B")) {
                s[secondChoice] = "A";
            }
        }

        for (int i=0; i < m; i++) {
            sb.append(s[i]);
        }

        System.out.println(sb);
    }
}
