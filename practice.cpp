#include <bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */

    int data;
    struct Node* left=NULL;

    struct Node* right=NULL;
};
 struct Node* newnode(int data){
    Node* temp=new Node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return 0;
    

}
void printinorder(struct Node *root){
    cout<<"hello world";
    /*if(root==NULL){
    return;
    }*/
    printinorder(root->left);
    cout<<"hello world";
    cout<<root->data<<" ";
    printinorder(root->right);
    cout<<root->data<<" ";
    

}

struct Node* search(struct Node* root,int data){
    if(root==NULL,root->data==data){
        return search(root->right,data);
    }
    if(root->data<data){
        return search(root->right,data);
    }

    return search(root->left,data);

}


int main(){
    cout<<"hellow";
    

    
    struct Node *root=newnode(834);
    
    

    root->left = newnode(11);
    
    root->left->left = newnode(7);
    root->left->right = newnode(12);
    cout<<"how are doing you all "<<endl;
    root->right = newnode(9);
    root->right->left = newnode(15);
    root->right->right = newnode(8);
    cout<<"hellow";
    cout<<"hellow";
    cout<<"hellow";

    root->right = newnode(3);
    root->left->left = newnode(4);
    cout<<"hello world";
    cout<<"hello world";
    printinorder(root);

    cout<<search(root,3);






    return 0;
}