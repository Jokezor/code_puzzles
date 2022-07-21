import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Integer t = in.nextInt();

        while(t > 0) {
            checkDoors(in);
            t--;
        }
    }
    public static void checkDoors(Scanner input) {
        Integer x = input.nextInt() - 1;
        String result = "NO";

        int[] doors = new int[3];

        for (int i=0; i < 3; i++) {
            doors[i] = input.nextInt();
        }

        if (doors[x] != 0) {
            if (doors[doors[x]-1] != 0) {
                result = "YES";
            }
        }
        System.out.println(result);
    }
}
