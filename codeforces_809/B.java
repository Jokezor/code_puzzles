import java.util.Arrays;
import java.util.Scanner;
import java.lang.Math;
import java.util.stream.Collectors;

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
        int[] tower = new int[n];
        String[] optimalTower = new String[n];

        for (int i=0; i < n; i++) {
            tower[i] = input.nextInt();
        }

        for (int i=0; i < n; i++) {
            int[] block = new int[2];

            for (int j=0; j < n; j++) {
                if (tower[j] == i+1) {
                    block[j % 2] = 1 + block[(j+1) % 2];
                }
            }
            optimalTower[i] = String.valueOf(Math.max(block[0], block[1]));
        }
        System.out.println(Arrays.stream(optimalTower).collect(Collectors.joining(" ")));
    }
}
