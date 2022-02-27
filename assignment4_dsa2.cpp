//non recursive code for tree travesal

#include<iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
 

void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
      
            s.push(curr);
            curr = curr->left;
        }
 
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
 

        curr = curr->right;
 
    } 
}

void preorder(struct Node *root) {
   if (root == NULL)
   return;
   stack<Node *> NodeStack;
   NodeStack.push(root);
   while (NodeStack.empty() == false) {
      struct Node *temp_Node = NodeStack.top();
      cout<< temp_Node->data <<" ";
      NodeStack.pop();
      if (temp_Node->right)
      NodeStack.push(temp_Node->right);
      if (temp_Node->left)
      NodeStack.push(temp_Node->left);
   }
}
 
int main()
{
 

    struct Node *root = new Node(1);
    root->left= new Node(32);
    root->right= new Node(43);
    root->left->left= new Node(54);
    root->left->right= new Node(65);
    cout<<"inorder traversal"<<endl;
 
    inOrder(root);
    cout<<endl;

    cout<<"preorder traversal"<<endl;
    preorder(root);

    return 0;
}