import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        solution(input);
    }
    public static void solution(Scanner input) {
        int n = input.nextInt();
        String result = "Yes";

        input.nextLine();
        String s = input.nextLine();

        if (s.equals("BA") || s.equals("AB") || !(s.substring(0, 1).equals("B") || s.substring(n-1, n).equals("A"))) {
            result = "No";
        }

        System.out.println(result);
    }
}
