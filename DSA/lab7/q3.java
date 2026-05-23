package lab7;

public class q3 {
    class TreeNode {
        char data;
        TreeNode left, right;

        TreeNode(char data) {
            this.data = data;
            left = right = null;
        }
    }

    TreeNode root;

    q3() {
        root = null;
    }

    public void traverseAndPrint(TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.data == '+' || root.data == '-' || root.data == '*' || root.data == '/') {
            System.out.print("(");
        }
        traverseAndPrint(root.left);
        System.out.print(root.data + " ");
        traverseAndPrint(root.right);
        if (root.data == '+' || root.data == '-' || root.data == '*' || root.data == '/') {
            System.out.print(")");
        }
    }

    public static void main(String[] args) {
        q3 tree = new q3();
        tree.root = tree.new TreeNode('+');
        tree.root.left = tree.new TreeNode('-');
        tree.root.left.right = tree.new TreeNode('6');
        tree.root.left.left = tree.new TreeNode('+');
        tree.root.left.left.left = tree.new TreeNode('3');
        tree.root.left.left.right = tree.new TreeNode('*');
        tree.root.left.left.right.left = tree.new TreeNode('2');
        tree.root.left.left.right.right = tree.new TreeNode('1');
        tree.root.right = tree.new TreeNode('-');
        tree.root.right.left = tree.new TreeNode('5');
        tree.root.right.right = tree.new TreeNode('4');
        tree.traverseAndPrint(tree.root);
    }
}