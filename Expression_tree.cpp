#include<bits/stdc++.h>
#include <stack>
using namespace std;
struct expressionTree{
    char value;
    expressionTree *left;
    expressionTree *right;

};
bool isoperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
        return true;
    }
    else{
        return false;
    }
}

void inorder( struct expressionTree *node){
    if(node){
        inorder(node->left);
        cout<<"the value of leaf node is " + node->value;

        inorder(node->right);

    }
}

struct expressionTree *newnode(char value){
    struct expressionTree *temp=new expressionTree;
    temp->left=temp->right=NULL;
    temp->value=value;
    return temp;


};

struct expressionTree *constructTree(char postfix[]){
    stack<expressionTree *> st;
    struct expressionTree *t;
    struct expressionTree *t1;
    struct expressionTree *t2;
    
    for (int i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (!isoperator(postfix[i]))
        {
            t = newnode(postfix[i]);
            st.push(t);
        }
        else // operator
        {
            t = newnode(postfix[i]);
 
            // Pop two top nodes
            t1 = st.top(); // Store top
            st.pop();      // Remove top
            t2 = st.top();
            st.pop();
 
            //  make them children
            t->right = t1;
            t->left = t2;
 
            // Add this subexpression to stack
            st.push(t);
        }
    }
 
    //  only element will be root of expression
    // tree
    t = st.top();
    st.pop();
 
    return t;    

}
int main(){
    char postfix[] = "ab+ef*g*-";
    int size=sizeof(postfix[9])/sizeof(postfix[0]);
    struct expressionTree *r = constructTree(postfix);
    cout<<"infix expression is \n";
    inorder(r);
    return 0;

    
}