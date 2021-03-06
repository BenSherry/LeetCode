package generateTrees;

import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<TreeNode> generateTrees(int n) {
        return generateTrees(1, n);
    }

    public List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> allTrees = new LinkedList<>();
        if (start > end) {
            allTrees.add(null);
            return allTrees;
        }
        for (int i = start; i <= end; i++) {
            List<TreeNode> left = generateTrees(start, i - 1);
            List<TreeNode> right = generateTrees(i + 1, end);
            for (TreeNode nodeLeft : left) {
                for (TreeNode nodeRight : right) {
                    TreeNode root = new TreeNode(i);
                    root.left = nodeLeft;
                    root.right = nodeRight;
                    allTrees.add(root);
                }
            }
        }
        return allTrees;
    }
}
