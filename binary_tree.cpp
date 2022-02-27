#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;

};
node* newnode(int data){
    node* temp=new node();
    temp.data=data;
    temp.left=temp.right=NULL;
    return temp;

}
node* constructTreeUtil(int pre[],int* preindex,int low,int high,int size){


    if(*preindex>=size ||  low>high){
        return NULL;

    }

    //synchronizing node
    node* root=newnode(pre[*preindex]);
    *preindex=*preindex+1;

    if(low==high)
    return root;

    int i;
    for(i=low;i<=high;i++){
        if(pre[i]>root.data){
            break;
        }
    }
    root.left=constructTreeUtil(pre,preindex,*preindex,i-1,size);
    root.right=constructTreeUtil(pre,preindex,i,high,size);
    return root;

    void printorder(node* node){
        if(node==NULL){
            return;

        }
        printinorder(node.left);
        cout<<node.data<<" ";
        printinorder(node.right);

    }



}
int main(){
    int pre[]={10,34,1,7,40,50};
    int size=sizeof(pre)/sizeof(pre[0]);
    node* root=constructTreeUtil(pre,size);


    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);



    return 0;

}



