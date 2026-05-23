package practise;

public class e5{
    class Node {
        int data;
        Node left, right;
        Node(int data){
            this.data = data;
            left = right = null;
        }
    }
    Node root;
    e5(){
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
    void printDescendants(Node root, int target){
        if(root == null){
            return;
        }
        if(root.data == target){
            printSubtree(root);
            return;
        }
        if(root.data > target){
            printDescendants(root.left, target);
        }
        else{
            printDescendants(root.right, target);
        }   
    }

    void printSubtree(Node root){
        if(root == null){
            return;
        }
        System.out.print(root.data + " ");
        printSubtree(root.left);
        printSubtree(root.right);
    }

     void printAncestors(Node root, int node) {
        // Check if the root is null.
        if (root == null) {
          return;
        }
    
        // Check if the root is the node we are looking for.
        if (root.data == node) {
          System.out.println(root.data);
          return;
        }
    
        // Check if the node is less than the root.
        if (node < root.data) {
          printAncestors(root.left, node);
        } 
        else {
          printAncestors(root.right, node);
        }
      }
    public static void main(String[] args) {
        e5 obj = new e5();
        obj.root = obj.insert(obj.root, 8);
        obj.root = obj.insert(obj.root, 3);
        obj.root = obj.insert(obj.root, 1);
        obj.root = obj.insert(obj.root, 6);
        obj.root = obj.insert(obj.root, 4);
        obj.root = obj.insert(obj.root, 7);
        obj.root = obj.insert(obj.root, 10);
        obj.root = obj.insert(obj.root, 14);
        obj.root = obj.insert(obj.root, 13);
        obj.printAncestors(obj.root, 3);
        System.out.println();
        obj.printDescendants(obj.root, 3);
    }
}