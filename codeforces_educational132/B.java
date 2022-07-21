import java.lang.Math;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Integer n = in.nextInt();
        Integer m = in.nextInt();
        int[] a = new int[n];
        long [] fallLeft = new long[n];
        long[] fallRight = new long[n];
        int[][] quests = new int[m][2];

        for (int i=0; i < n; i++) {
            a[i] = Integer.parseInt(in.next());
        }

        for (int i=0; i < m; i++) {
            quests[i][0] = Integer.parseInt(in.next());
            quests[i][1] = Integer.parseInt(in.next());
        }

        for (int i=1; i < n; i++) {
            Integer leftDiff = a[i] - a[i-1];
            fallLeft[i] = leftDiff > 0 ? leftDiff : 0;
            fallLeft[i] += fallLeft[i-1];
        }

        for (int i=n-2; i >= 0; i--) {
            Integer rightDiff = a[i] - a[i+1];
            fallRight[i] = rightDiff > 0 ? rightDiff : 0;
            fallRight[i] += fallRight[i+1];
        }

        for (int i=0; i < m; i++) {
            tryQuest(quests[i][0], quests[i][1], fallLeft, fallRight);
        }

    }
    public static void tryQuest(int s, int t, long[] fallLeft, long[] fallRight) {
        long result = 0;
        long fall = 0;

        if (s > t) {
            fall = fallLeft[s-1] - fallLeft[t-1];
        }
        else {
            fall = fallRight[s-1] - fallRight[t-1];
        }
        result = fall > 0 ? fall : 0;

        System.out.println(result);

    }
}
