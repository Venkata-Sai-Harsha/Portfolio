package lab7;

public class q5 {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    Node root;

    q5() {
        root = null;
    }

    public static int findNodeHeight(Node root, int value) {
        if (root == null)
            return 0;
        if (root.data == value)
            return 1;
        int leftHeight = findNodeHeight(root.left, value);
        int rightHeight = findNodeHeight(root.right, value);
        if (leftHeight != 0)
            return leftHeight + 1;
        if (rightHeight != 0)
            return rightHeight + 1;
        return 0;
    }

    public static int height(Node root) {
        if (root == null) {
            return 0;
        } 
        else {
            int leftHeight = height(root.left);
            int rightHeight = height(root.right);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }

    public static int diameter(Node root){
        if(root == null){
            return 0;
        }
        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
        int leftDiameter = diameter(root.left);
        int rightDiameter = diameter(root.right);
        return Math.max(leftHeight + rightHeight + 1, Math.max(leftDiameter, rightDiameter));
    }

    public static void main(String[] args) {
        q5 tree = new q5();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.left.right.left = new Node(7);
        tree.root.right.left = new Node(2);
        tree.root.right.right = new Node(6);

        int nodeValue = 3;
        int height = findNodeHeight(tree.root, nodeValue);
        System.out.println("Height of " + nodeValue + " is: " + height);
        System.out.println("Height of tree is: " + height(tree.root));
        System.out.println("Diameter of tree is: " + diameter(tree.root));
    }
}