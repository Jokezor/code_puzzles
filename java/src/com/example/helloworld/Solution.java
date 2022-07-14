package src.com.example.helloworld;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;


class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levels = new LinkedList<List<Integer>>();

        if (root == null) {
            return levels;
        }

        Queue<Tuple> q = new LinkedList<Tuple>();
        levels.add(new LinkedList<Integer>(List.of(root.val)));

        Integer highestLevel = 1;

        List<Integer> level = new LinkedList<Integer>();

        if (root.left != null) {
            q.add(new Tuple(1, root.left));
        }

        if (root.right != null) {
            q.add(new Tuple(1, root.right));
        }


        while (q.peek() != null) {
            // How to know if we are on the same level as the neighbour?
            // Add a level + 1 always when adding it to the Queue.
            Tuple pair = q.remove();
            Integer currentLevel = pair.x;
            TreeNode head = pair.y;

            if (currentLevel > highestLevel) {
                levels.add(level);
                highestLevel = currentLevel;
                level = new LinkedList<Integer>();
            }

            level.add(head.val);

            if (head.left != null) {
                q.add(new Tuple(currentLevel + 1, head.left));
            }

            if (head.right != null) {
                q.add(new Tuple(currentLevel + 1, head.right));
            }
        }

        if (!level.isEmpty()) {
            levels.add(level);
        }

        return levels;
    }
    public static void main(String[] args) {
        TreeNode t1 = new TreeNode(3);
        t1.left = new TreeNode(9);
        t1.right = new TreeNode(20);
        t1.right.left = new TreeNode(15);
        t1.right.right = new TreeNode(7);

        List<List<Integer>> solution = new Solution().levelOrder(t1);

        for (List<Integer> node: solution) {
            for (Integer val: node) {
                System.out.println(val);
            }
        }
    }
}
