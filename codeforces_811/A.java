import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();

        while (t > 0) {
            countSleep(input);
            t--;
        }
    }
    public static void countSleep(Scanner input) {
        int n = input.nextInt();
        int H = input.nextInt();
        int M = input.nextInt();
        int minSleepTime = 24*60;
        int bedTime = H*60 + M;

        for (int i=0; i < n; i++) {
            int h = input.nextInt();
            int m = input.nextInt();

            int sleepTime = h*60 + m;
            int timeSlept;

            if ((sleepTime - bedTime) < 0) {
                timeSlept = 24*60 + (sleepTime - bedTime);
            }
            else {
                timeSlept = sleepTime - bedTime;
            }
            minSleepTime = Math.min(minSleepTime, timeSlept);
        }

        System.out.println(minSleepTime / 60 + " " + minSleepTime % 60);
    }
}
