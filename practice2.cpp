#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(){
        this->data=data;
        this->next=NULL;
    }

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class linkedlist{
    struct node* head=NULL;
    public:
    linkedlist(){
    head=NULL;
    }

    void insertnodeat1(struct node* &head,int data){
        struct node* Node=head;
        
        Node->data=data;
        Node->next=head;
        head=Node;
              

    }
    void insertatlast(struct node* &head,int data){
        struct node* node3=head;
        node3->data=data;
        node3->next=NULL;
        struct node* temp=head;
        while (temp->next!=NULL)
        {
            /* code */
            temp=temp->next;
        }
        temp->next=node3;
        
        
    }
    void insertafter(struct node* &head,int data,int index){
        struct node* node4=head;
        node4->data=data;
        struct node* temp=head;
        for(int i=0;i<index;i++){
            head=head->next;
            

        }
        temp=head->next->next;
        head->next->next=node4;
        node4->next=temp;
        




    }
    void print(struct node* &head){
        while (head!=NULL)
        {
            /* code */
            cout<<head->data<<" ";
            head=head->next;
        }
        
    }
    

    




};


int main(){
    struct node* newnode=&head;
    linkedlist obj;
    
    obj.insertatlast(newnode,90);
    obj.insertatlast(newnode,100);
    obj.insertnodeat1(newnode,40);
    obj.insertnodeat1(newnode,50);
    obj.insertnodeat1(newnode,60);
    obj.insertnodeat1(newnode,70);
    obj.insertnodeat1(newnode,80);
    obj.insertafter(newnode,120,3);
    obj.print(newnode);
    cout<<"after"<<endl;
    
    
   
    
    


  

    


    return 0;
}