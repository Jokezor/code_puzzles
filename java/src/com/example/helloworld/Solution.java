package src.com.example.helloworld;
import java.util.List;
import java.util.ArrayList;


public class Solution {
    public List levelOrder(TreeNode root) {
        ArrayList<Integer> levels = new ArrayList<Integer>();
        levels.add(root.val);
        return levels;
    }
    public static void main(String[] args) {
        TreeNode t1 = new TreeNode(10);
        List solution = new Solution().levelOrder(t1);

        for (Object node: solution) {
            System.out.println(node);
        }
    }
}
