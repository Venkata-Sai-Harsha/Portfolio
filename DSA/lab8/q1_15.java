//package DSA.lab8;

import java.util.*;

import org.w3c.dom.Node;

public class q1_15{
    static class Node{
        int data;
        Node left, right;
        Node(int data){
            this.data = data;
            left = right = null;
        }
    }

    Node root;
    q1_15(){
        root = null;
    }

    Node insert(Node root, int data){
        if(root == null){
            root = new Node(data);
            return root;
        }
        if(root.data > data){
            root.left = insert(root.left, data);
        }
        else if(root.data < data){
            root.right = insert(root.right, data);
        }
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

    Node delete(Node root, int data){
        if(root == null){
            return root;
        }
        if(root.data > data){
            root.left = delete(root.left, data);
        }
        else if(root.data < data){
            root.right = delete(root.right, data);
        }
        else{
            if(root.left == null){
                return root.right;
            }
            else if(root.right == null){
                return root.left;
            }
            root.data = min(root.right).data;
            root.right = delete(root.right, root.data);          
        }
        return root;
    }

    Node search(Node root, int data){
        if(root == null || root.data == data){
            return root;
        }
        if(root.data > data){
            return search(root.left, data);
        }
        return search(root.right, data);
    }

    Node min(Node root){
        if(root == null){
            return root;
        }
        if(root.left == null){
            return root;
        }
        return min(root.left);
    }

    Node max(Node root){
        if(root == null){
            return root;
        }
        if(root.right == null){
            return root;
        }
        return max(root.right);
    }

    int getHeight(Node node) {
        if (node == null) {
            return 0;
        } 
        else {
            int leftHeight = getHeight(node.left);
            int rightHeight = getHeight(node.right);
            return Math.max(leftHeight, rightHeight) + 1;
        }
    }
    

    public static void main(String[] args) {
        q1_15 tree = new q1_15();
        Scanner sc = new Scanner(System.in);
        tree.root = tree.insert(tree.root, 30);
        tree.root = tree.insert(tree.root, 35);
        tree.root = tree.insert(tree.root, 40);
        tree.root = tree.insert(tree.root, 50);
        tree.root = tree.insert(tree.root, 12);
        tree.root = tree.insert(tree.root, 17);
        tree.root = tree.insert(tree.root, 45);
        tree.root = tree.insert(tree.root, 90);
        tree.root = tree.insert(tree.root, 23);
        tree.root = tree.insert(tree.root, 56);
        System.out.print("Inorder: ");
        tree.inorder(tree.root);
        System.out.println();
        System.out.print("Preorder: ");
        tree.preorder(tree.root);
        System.out.println();
        System.out.print("Postorder: ");
        tree.postorder(tree.root);
        System.out.println();
        System.out.print("Enter the value to be deleted: ");
        int value = sc.nextInt();
        tree.root = tree.delete(tree.root, value);
        System.out.print("Inorder after deletion: ");
        tree.inorder(tree.root);
        System.out.println();
        System.out.print("Inorder for searching 40: ");
        tree.inorder(tree.search(tree.root, 40));
        System.out.println();
        System.out.print("Inorder for searching 90: ");
        tree.inorder(tree.search(tree.root, 90));
        System.out.println();
        System.out.print("Inorder for searching 32: ");
        tree.inorder(tree.search(tree.root, 32));
        System.out.println();
        System.out.print("Inorder for searching 92: ");
        tree.inorder(tree.search(tree.root, 92));
        System.out.println();
        System.out.print("Inorder for searching 56: ");
        tree.inorder(tree.search(tree.root, 56));
        System.out.println();
        System.out.println("Minimum element: " + tree.min(tree.root).data);
        System.out.println("Maximum element: " + tree.max(tree.root).data);
        System.out.println("Height of the tree: " + tree.getHeight(tree.root));
        int k;
        System.out.print("Enter the value of k: ");
        k = sc.nextInt();
        //System.out.println("Kth largest element: " + tree.Klargest(tree.root, k));
        sc.close();
    }
}