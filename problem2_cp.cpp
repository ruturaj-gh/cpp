#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};
struct node *top=NULL;

void push(int n)
{
    struct node *temp= new node;
    temp->data=n;
    temp->next=top;
    top=temp;
}

void pop()
{
    struct node *temp;
    if(top!=NULL)
    {   temp=top;
        top=top->next;
        free(temp);
        cout<<"\nElement deleted";
    }
    else
    cout<<"\nStack is empty";
}

void display()
{
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        top=top->next;
    }
}

int main()
{
    int i,j,n;
    int r;
    cout<<"Enter the number of elements you want to insert : ";
    cin>>n;
    cout<<"Enter the elements : \n"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>j;
        push(j);
    }
    pop();
    
    cout<<"\nStack After Deletion of an element : "<<endl;

    display();
    cout<<endl;
    cout<<"enter the elements that you want to push"<<endl;
    cin>>r;
    push(r);
    cout<<"after pushing element in the stack"<<endl;
    display();
    
        
    
    return 0;
}
