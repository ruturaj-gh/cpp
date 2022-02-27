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

void preorder(struct node *root) {
   if (root == NULL)
   return;
   stack<node *> nodeStack;
   nodeStack.push(root);
   while (nodeStack.empty() == false) {
      struct node *temp_node = nodeStack.top();
      cout<< temp_node->data <<" ";
      nodeStack.pop();
      if (temp_node->right)
      nodeStack.push(temp_node->right);
      if (temp_node->left)
      nodeStack.push(temp_node->left);
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
    cout<<"preorder traversal"<<endl;

    return 0;
}