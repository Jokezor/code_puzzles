import java.util.HashSet;
import java.util.Scanner;

public class E {
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
        int[] a = new int[n];
        String result = "Yes";
        boolean odds = false;
        boolean evens = false;
        boolean fives = false;

        HashSet<Integer> evenSet = new HashSet<>();
        HashSet<Integer> oddSet = new HashSet<>();

        for (int i = 0; i < n; i++) {
            a[i] = input.nextInt();
        }

        // 1. Generate even sets: {1,2,4,8} etc. A member or the member + member % 10 counts.
        int firstEven = 1;
        while (firstEven < 100) {
            evenSet.add(firstEven);
            firstEven += firstEven % 10;
        }

        int firstOdd = 3;
        while (firstOdd < 100) {
            oddSet.add(firstOdd);
            firstOdd += firstOdd % 10;
        }

        // 2. Check if multiple of 5.
        int target = 0;
        for (int e : a) {
            if (e % 10 == 5) {
                if (fives && (e + 5) != target) {
                    result = "No";
                    break;
                }

                if (target == 0) {
                    target = e + 5;
                }
                fives = true;
            }

            if (e % 10 == 0) {
                if (fives && e != target) {
                    result = "No";
                    break;
                }

                if (target == 0) {
                    target = e;
                }
                fives = true;
            }
        }

        // 3. Check in odd and even sets if there are no fives.
        if (!fives) {
            for (int e : a) {
                String numStr = String.valueOf(e);
                int num;

                if (numStr.length() > 2) {
                    num = Integer.parseInt(numStr.substring(numStr.length() - 2));
                } else {
                    num = Integer.parseInt(numStr);
                }

                String nextNumStr = String.valueOf(num + num % 10);
                int nextNum;

                if (nextNumStr.length() > 2) {
                    nextNum = Integer.parseInt(nextNumStr.substring(nextNumStr.length() - 2));
                } else {
                    nextNum = Integer.parseInt(nextNumStr);
                }

                if (evenSet.contains(num) || evenSet.contains(nextNum)) {
                    if (odds) {
                        result = "No";
                        break;
                    }
                    evens = true;
                }

                if (oddSet.contains(num) || oddSet.contains(nextNum)) {
                    if (evens) {
                        result = "No";
                        break;
                    }
                    odds = true;
                }

            }
        }

        System.out.println(result);

    }
}
