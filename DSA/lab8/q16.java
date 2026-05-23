

import java.util.*;

import org.w3c.dom.Node;

public class q16 {
    class Node{
        int data;
        Node left, right;
        Node(int data){
            this.data = data;
            left = right = null;
        }
    }

    Node root;
    q16(){
        root = null;
    }

    void convertBTtoBST(Node root) {
        List<Integer> values = new ArrayList<>();
        extractValues(root, values);
        Collections.sort(values);
        constructBST(root, values);
    }

    void extractValues(Node root, List<Integer> values) {
        if (root == null) {
            return;
        }
        extractValues(root.left, values);
        values.add(root.data);
        extractValues(root.right, values);
    }

    Node constructBST(Node root, List<Integer> values) {
        if (root == null) {
            return null;
        }
        root.left = constructBST(root.left, values);
        root.data = values.remove(0);
        root.right = constructBST(root.right, values);
        return root;
    }

    void inorder(Node root){
        if(root == null){
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    void preorder(Node root){
        if(root == null){
            return;
        }
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    void postorder(Node root){
        if(root == null){
            return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    public static void main(String[] args) {
        q16 tree = new q16();
        tree.root = tree.new Node(10);
        tree.root.left = tree.new Node(2);
        tree.root.right = tree.new Node(7);
        tree.root.left.left = tree.new Node(8);
        tree.root.left.right = tree.new Node(4);
        tree.root.right.left = tree.new Node(6);
        tree.root.right.right = tree.new Node(5);
        System.out.println("Inorder traversal of binary tree is :");
        tree.inorder(tree.root);
        System.out.println();
        System.out.println("Preorder traversal of binary tree is :");
        tree.preorder(tree.root);
        System.out.println();
        System.out.println("Postorder traversal of binary tree is :");
        tree.postorder(tree.root);
        tree.convertBTtoBST(tree.root);
        System.out.println();
        System.out.println("Inorder traversal of binary search tree is :");
        tree.inorder(tree.root);
        System.out.println();
        System.out.println("Preorder traversal of binary search tree is :");
        tree.preorder(tree.root);
        System.out.println();
        System.out.println("Postorder traversal of binary search tree is :");
        tree.postorder(tree.root);
    }
}
