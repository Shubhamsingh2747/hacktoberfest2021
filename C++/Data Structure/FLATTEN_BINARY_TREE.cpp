//FLATTEN A BINARY TREE

//store tails of both trees in a variable
//store right subtree in a temp variable
//make left subtree the right 
//add right subtree to left's tail
//return right tail
#include<iostream>
using namespace std;
struct node{    //structure of tree defined

    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void flatten(node* root){

    //base condition
    if(root==NULL || root->right==NULL && root->left==NULL){
        return;
    }

    //we are keeping everything under if condition as once the right subtree comes below the left one, this condition will help us traverse the 
    //new flattened right subtree until the non flat original right subtree is encountered.
    if(root->left != NULL){
        flatten(root->left);
    
        node*temp=root->right;
        root->right=root->left;
        root->left=NULL;

        node* tail = root->right;
        while(tail->right != NULL){
            tail=tail->right;
        }
        tail->right=temp;
    }
    flatten(root->right);
}


//printing the nodes by inorder traversal(recursive): left, root, right
void inorderPrint(node* root){

    if(root==NULL){
        return;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){

    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);

    flatten(root);
    inorderPrint(root);
    return 0;   
}