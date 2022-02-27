#include <iostream>
using namespace std;
class stack{
    private:
    int top;
    int arr[5];
    
    public:
    stack(){
        top=-1;
        for (int i=0;i<5;i++){
            arr[i]=0;
        }
        
        
    }
    bool isempty(){
        if (top==-1){
            return true;
            
        }
        else{
            return false;
            
        }
    }
    bool isfull(){
        if(top==4){
            return true;
            
        }
        else{
            return false;
            
        }
    }
    void push(int val){
        if(isfull()){
            cout<<"stack overflow"<<endl;
        }
        else{
            top++;
            arr[top]=val;
            
            
        }
        
    }
    
    int pop(){
        if(isempty()){
            cout<<"the stack is empty"<<endl;
            return 0;
        }
        
        else{
            int popval=arr[top];
            arr[top]=0;
            top--;
            return popval;
            
            
            
        }
    }
    
    int count(){
        return(top+1);
        
    }
    int peek(int pos){
        if(isempty()){
            cout<<"stack underflow"<<endl;
            return 0;
            
            
        }
        else{
            return arr[pos];
            
        }
        
    }
    void change(int pos,int val){
        cout<<"value change at location"<<pos<<endl;
        
        
    }
    void display(){
        cout<<"all values in the stack are"<<endl;
        for (int i=4;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
        
    
};

int main(){
    stack s1;
    int option,position,value;
    
    do{
        cout<<"what do you want to perform. 0 for exit"<<endl;
        cout<<"1.push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.isempty"<<endl;
        cout<<"4.isfull" <<endl;
        cout<<"5.peek"<<endl;
        cout<<"6.count"<<endl;
        cout<<"7.change"<<endl;
        cout<<"8.display" <<endl;
        cout<<"9.clear screen" <<endl;
        
        cin>>option;
        switch(option){
            case 1:
            cout<<"enter a number";
            cin>>value;
            s1.push(value);
            break;
            
            
            case 2:
            cout<<"pop function called-popped value"<<s1.pop()<<endl;
            break;
            
            case 3:
            if(s1.isempty()){
                cout<<"stack is empty"<<endl;
                
            }
            else{
                cout<<"stack is not emppty";
                break;
            }
            
            case 4:
            if(s1.isfull()){
                cout<<"stack is full"<<endl;
                
            }
            else{
                cout<<"stack is not full"<<endl;
                break;
                
            }
            case 5:
            cout<<"enter the position you want to peek"<<endl;
            cin>>position;
            cout<<"peekfunctioncalled"<<endl;
            cout<<s1.peek(position);
            break;
            
            case 6:
            cout<<"the number of items in stack are"<<s1.count()<<endl;
            break;
            
            
            case 7:
            cout<<"enter the position you want to change"<<endl;
            cin>>position;
            cout<<endl;
            cout<<"enter the value item you want to change"<<endl;
            cin>>value;
            s1.change(position,value);
            break;
            
            case 8:
            cout<<"display function called"<<endl;
            s1.display();
            break;
            
            case 9:
            system("cls");
            cout<<"enter the proper option number"<<endl;
            
            default:
            cout<<"enter proper number"<<endl;
            
            
            
            
            
            
        }
        
        
    }while(option!=0);
    
    
    
    return 0;
    
}
