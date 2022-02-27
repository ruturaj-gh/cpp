#include <iostream>
using namespace std;
struct node{
    int data;
     node* next;
    node(){
        this->data=data;
        this->next=next;

    }
};
struct node* head;
static void fun(int * arr,int size,struct node* Node){
    //struct node * Node=new node();
    struct node* temp=Node;
    for(int i=0;i<size;i++){
        if(i==size){
            Node->next=NULL;
            return;
        }
        Node->data=arr[i];
        Node=Node->next;
        
    }

}
static void print(struct node* Node){
    //struct node* Node=new node();
    while (Node->next!=NULL)
    {
        /* code */
        cout<<Node->data<<" ";
        Node=Node->next;
    }
    
}
int main(){
    struct node * newnode=head;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

        
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    

    fun(arr,size,newnode);
    print(newnode);
    



    return 0;
}

