#include <iostream>
using namespace std;
struct node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data=data;
        left=right=NULL;


    }

};

void preorder(struct node *root){
    if(root==NULL){
        return;

    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);





}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);

}
void preorder_recursive(node *root)
{
if (root != NULL)
{
cout << root->data<<endl;
preorder_recursive(root->left);
preorder_recursive(root->right);
}
}

void inorder_recursive(node *root)
{
if (root != NULL)
{
inorder_recursive(root->left);
cout << root->data<<endl;
inorder_recursive(root->right);
}
}

void postorder_recursive(node *root)
{
if (root != NULL)
{
postorder_recursive(root->left);
postorder_recursive(root->right);
cout << root->data<<endl;
}
}

void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;

}

int main(){
    struct node* root = new node(1);
    root->left = new node(12);
    root->right = new node(23);
    root->left->left = new node(34);
    root->left->right = new node(45);

    cout << "\nPreorder traversal of binary tree is \n";
    preorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    inorder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    postorder(root);

    cout<<"\nPreorder recursive traversal of binary tree is \n";
    preorder_recursive(root);

    cout << "\nInorder recursive traversal of binary tree is \n";
    inorder_recursive(root);    
 
    cout << "\nPostorder recursive traversal of binary tree is \n";
    postorder_recursive(root);


    return 0;
}

