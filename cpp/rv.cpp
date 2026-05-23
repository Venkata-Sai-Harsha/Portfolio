#include <bits/stdc++.h>
using namespace std;
// bool isvowel(char c){
//     if(c=='a'|| c=='e'|| c=='i'|| c=='o'||c=='u'){
//         return true;
//     }
//     return false;
// }
// string check(string s){
//     int n=s.length();
//     string c="";
//     for(int i=0;i<n;i++){
//         if(i==0 || i==n-1){
//             c+=s[i];
//             continue;
//         }
//         if(!isvowel(s[i-1]) && isvowel(s[i]) && !isvowel(s[i+1])){
//             continue;
//         }
//         c+=s[i];
//     }
//     return c;
// }
// int main(){
//     string s;
//     cin>>s;
//     cout<<check(s);
//     return 0;
// }


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
Node* findmin(Node* root){
    root=root->right;
    while(root->left!=NULL && root!=NULL){
        root=root->left;
    }
    return root;
}
Node* deletenode(Node* root, int x){
    if(root==NULL) return root;
    if(root->data<x){
        root->right=deletenode(root->right,x);
    }
    else if(root->data>x){
        root->left=deletenode(root->left,x);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* temp=findmin(root);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}
int kths(Node* root,int k,int& c,int& ks){
    if(root==NULL) return -1;
    int left = kths(root->left, k, c, ks);
    if (left != -1) return left;
    c++;
    if(c==k){
        ks=root->data;
        return ks;
    }
    kths(root->right,k,c,ks);
}
int kthsmallest(Node* root, int k){
    int c=0;
    int ks=0;
    return kths(root,k,c,ks);
}
int kthl(Node* root,int k,int& c,int& ks){
    if(root==NULL) return -1;
    int right = kthl(root->right, k, c, ks);
    if (right != -1) return right;
    c++;
    if(c==k){
        ks=root->data;
        return ks;
    }
    kthl(root->left,k,c,ks);
}
int kthlargest(Node* root,int k){
    int c=0;
    int ks=0;
    return kths(root,k,c,ks);
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->right->left=new Node(12);
    root->right->right=new Node(18);
    inorder(root);
    cout<<endl;
    cout<<kthsmallest(root,3);
    cout << endl;
    cout<<kthlargest(root,3);
    cout<<endl;
    root=deletenode(root,15);
    inorder(root);
    return 0;
}