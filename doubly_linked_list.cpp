#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* previous;
    struct node* next;

}
int main(){
    struct node* p=new node();
    struct node* q=new node();
    struct node* r=new node();
    struct node* s=new node();
    p->data=50;
    p->next=q;
    q->data=51;

    q->next=r;
    r->data=52;
    r->data=s;
    s->data=53;
    s->next=NULL;

    




    return 0;
}