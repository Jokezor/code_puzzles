import java.util.Scanner;

public class Solution {
    public static void main(String[] args)
    {
        Scanner inMain = new Scanner(System.in);
        int t = inMain.nextInt();

        while (t > 0) {
            differenceOperation(inMain);
            t--;
        }
    }
    public static void differenceOperation(Scanner input) {
        int n = input.nextInt();
        int start = input.nextInt();
        int next;
        String result = "YES";

        for (int i=0; i < n-1; i++) {
            next = input.nextInt();
            if (!(next % start == 0)) {
                result = "NO";
            }
        }

        System.out.println(result);
    }
}
