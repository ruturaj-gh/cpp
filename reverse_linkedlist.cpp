#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(){
        this->data=0;
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
        struct node* Node=new node();
        
        Node->data=data;
        Node->next=head;
        head=Node;
              

    }
    void insertatlast(struct node* &head,int data){
        struct node* node3=new node();
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
        struct node* node4=new node();
        node4->data=data;
        struct node* temp=new node();
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
    struct node* reverse(struct node* &head){
        struct node* current;
        struct node* prev;
        struct node* next;
        current=head;
        prev=NULL;
        while (current!=NULL)       
        {
            /* code */
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;



        }
        head=prev;
        return head;
        

    }
    void recursivecall(struct node* &head){
        if(head==NULL){
            return;
        }
        recursivecall(head->next);
        cout<<head->data<<" ";
        
    }

    void del(struct node* &head,int key){
        struct node* temp=head;
        struct node* temp2=head;
        for(int i=0;i<key-1;i++){
            temp=temp->next;

        }
        
        temp2=temp->next->next;
        delete(temp->next);
        temp->next=temp2;

        
        
    
        
    }

    int printmiddle(struct node* head){
        
        cout<<"hello world how are doing "<<endl;
        int k=0;
        while (head!=NULL){
            head=head->next;
            k=k+1;
        }
        cout<<k<<endl;
        int middle=(k+1)/2;
        //cout<<middle<<endl;
        return middle;
        
        
        
        
        
        
        

    }

    
    

    




};


int main(){
    struct node* newnode=new node();
    linkedlist obj;
    
    
    
    obj.insertnodeat1(newnode,10);
    obj.insertnodeat1(newnode,20);
    obj.insertnodeat1(newnode,30);
    obj.insertnodeat1(newnode,40);
    obj.insertnodeat1(newnode,50);
    obj.insertnodeat1(newnode,60);
    obj.insertnodeat1(newnode,70);
    obj.insertnodeat1(newnode,80);
    obj.del(newnode,3);
    obj.printmiddle(newnode);
    
    


    
    obj.print(newnode);
    

    //obj.recursivecall(newnode);

    
    

    
    
    
    
    
    
    
   
    
    


  

    


    return 0;
}