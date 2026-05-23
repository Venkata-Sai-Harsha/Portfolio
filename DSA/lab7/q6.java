package lab7;

public class q6 {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    Node root;

    q6() {
        root = null;
    }

    public static int countLeaves(Node root) {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 1;
        return countLeaves(root.left) + countLeaves(root.right);
    }

    public static int singlechild(Node root) {
        if (root == null)
            return 0;
        if (root.left == null && root.right != null)
            return 1 + singlechild(root.right);
        if (root.left != null && root.right == null)
            return 1 + singlechild(root.left);
        return singlechild(root.left) + singlechild(root.right);
    }

    public static int twochild(Node root) {
        if (root == null)
            return 0;
        if (root.left != null && root.right != null)
            return 1 + twochild(root.left) + twochild(root.right);
        return twochild(root.left) + twochild(root.right);
    }

    public static void main(String[] args) {
        q6 tree = new q6();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(7);
        tree.root.right.left = new Node(2);
        tree.root.right.right = new Node(6);

        int leafCount = countLeaves(tree.root);
        System.out.println("Number of leaves in the tree: " + leafCount);
    }
}