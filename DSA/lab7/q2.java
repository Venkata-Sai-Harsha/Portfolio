package lab7;
//import java.util.*;

public class q2{
    class Node{
        char data;
        Node left, right;
        Node(char data){
            this.data = data;
            left = right = null;
        }
    }

    Node root;
    q2(){
        root = null;
    }

    Node insert(Node root, char data){
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

    public static void main(String[] args){
        q2 tree = new q2();
        tree.root = tree.insert(tree.root, '+');
        tree.root.left = tree.insert(tree.root.left, '-');
        tree.root.left.left = tree.insert(tree.root.left.left, '+');
        tree.root.left.right = tree.insert(tree.root.left.right, '6');
        tree.root.left.left.left = tree.insert(tree.root.left.left.left, '3');
        tree.root.left.left.right = tree.insert(tree.root.left.left.right, '*');
        tree.root.left.left.right.left = tree.insert(tree.root.left.left.right.left, '2');
        tree.root.left.left.right.right = tree.insert(tree.root.left.left.right.right, '1');
        tree.root.right = tree.insert(tree.root.right, '-');
        tree.root.right.left = tree.insert(tree.root.right.left, '5');
        tree.root.right.right = tree.insert(tree.root.right.right, '4');
      
        System.out.println("Inorder traversal: ");
        tree.inorder(tree.root);
        System.out.println("\nPreorder traversal: ");
        tree.preorder(tree.root);
        System.out.println("\nPostorder traversal: ");
        tree.postorder(tree.root);
    }
}