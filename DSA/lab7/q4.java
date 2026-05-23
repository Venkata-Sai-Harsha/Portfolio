package lab7;

public class q4 {
    static class Node {
        int data;
        Node left, right;
        Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    Node root;
    q4() {
        root = null;
    }

    public static int getlevel(Node root, int value){
        if(root == null){
            return -1;
        }
        if(root.data == value) {
            return 0;
        }
        else {
            int leftLevel = getlevel(root.left, value);
            int rightLevel = getlevel(root.right, value);
            return 1 + Math.max(leftLevel, rightLevel);
        }
    }

    public static void main(String[] args) {
        q4 tree = new q4();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.left.right.left = new Node(7);
        tree.root.right.left = new Node(2);
        tree.root.right.right = new Node(6);

        int nodeValue = 2;
        int level = getlevel(tree.root, nodeValue);
        System.out.println("Level of " + nodeValue + " is: " + level);
    }
}
