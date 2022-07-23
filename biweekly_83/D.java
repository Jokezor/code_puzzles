import java.util.HashSet;
import java.util.Set;

public class D {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] rolls = {1,1,3,2,2,2,3,3};
        int k = 4;

        System.out.println(solution.shortestSequence(rolls, k));
    }
}

class Solution {
    public int shortestSequence(int[] rolls, int k) {
        // For each subset with all k elements there is a posibility
        // for getting a longer length.
        int maxSequenceLength = 1;
        Set<Integer> uniqueRolls = new HashSet<>();

        for (int roll : rolls) {
            uniqueRolls.add(roll);
            if (uniqueRolls.size() == k) {
                maxSequenceLength++;
                uniqueRolls.clear();
            }
        }

        return maxSequenceLength;
    }
}