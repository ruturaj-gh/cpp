#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
class BST
{
    Node* root;
    
    public:
    BST();
    Node* getroot();

    void insert();

    void del(int);
    Node* delete_Node(Node *, int);
    void display(Node *);


    void search(int);
    void deletes(int);


};
BST::BST()
{
    root = NULL;
    
}
Node* BST::getroot()
{
    return root;
}

void BST::insert()
{
    Node* temp, *newNode;
    char ch = 'y';
    while(ch == 'y' || ch == 'Y')
    {
    newNode = new Node();
    cout<<"\nEnter data for new Node: ";
    cin>>newNode->data;
    newNode->left = newNode->right = NULL;

    if(root == NULL)
    root = newNode;
    else
    {
        temp = root;
    check:
    if(newNode->data < temp->data)
    {
    if(temp->left != NULL)
    {
        temp = temp->left;
        goto check;
    }
    else
    {
        temp->left = newNode;
    }
    }
    else if(newNode->data > temp->data)
    {
    if(temp->right != NULL)
    {
        temp = temp->right;
        goto check;
    }
    else
    {
        temp->right = newNode;
    }
    }
    }
    
    cout<<"\nEnter y to add more Nodes and press any key to back to main menu: ";
    cin>>ch;
    }
}



void BST::del(int x)
{
    root = delete_Node(root, x);
}
Node* BST::delete_Node(Node *t, int x)
{
    Node *temp;
    if(t == NULL)
    {
        cout<<"\nElement not found!";
        return t;
    }
    if(x < t->data)
    {
        t->left = delete_Node(t->left, x);
        return t;
    }
    else if(x > t->data)
    {
        t->right = delete_Node(t->right, x);
        return t;
    }
    else
    {
        if(t->left == NULL && t->right == NULL)
    {
        temp = t;
        delete temp;
        return NULL;
    }
    if(t->left == NULL)
    {
        temp = t;
        t = t->right;
        delete temp;
        return t;
    }
    if(t->right == NULL)
    {
        temp = t;
        t = t->left;
        delete temp;
        return t;
    }
        temp = t->right;
        while(temp->left != NULL)
        temp = temp->left;
        t->data = temp->data;
        t->right = delete_Node(t->right, temp->data);
        return t;
    }
    return NULL;
}
//this is for trial and practice of delete function in binary search tree
void BST::deletes(int n){
    
}
void BST::search(int no)
{
    Node *temp;
    temp = root;
    check:
    if(no == temp->data)
    {
        cout<<"\nData found!";
        return;
    }
    if(no < temp->data)
    {
    if(temp->left != NULL)
    {
    temp = temp->left;
    goto check;
    }
    else
    {
        cout<<"\nData doesnt exist.";
        return;
    }
    }
    else if(no > temp->data)
    {
        if(temp->right != NULL)
        {
        temp = temp->right;
        goto check;
        }
        else
        {
        cout<<"\nData doesnt exist.";
        return;
        }
    }
}


void BST::display(Node *root)
{
    if(root == NULL)
    return;
    else
    {
        display(root->left);
        cout<<" "<<root->data<<" ";
        display(root->right);
    }
}


int main()
{

    BST tree;
    
    int x, choice;
    char ch = 'y';

while(1)
{
    cout<<"\n\nBinary Search Tree Operations ";
    cout<<"\n1. Insert.";
    cout<<"\n2. Delete.";
    cout<<"\n3. Search.";
    cout<<"\n4. display.";


cin>>choice;
switch(choice)
{
    case 1:
        tree.insert();
    break;

    case 2:
        cout<<"\nEnter data to delete: ";
        cin>>x;
        tree.del(x);
        break;

    case 3:
        cout<<"\nEnter number to search: ";
        cin>>x;
        tree.search(x);
        break;

    case 4:
        tree.display(tree.getroot());
        break;

        return 0;
}
}
return 0;
}