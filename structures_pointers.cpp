#include<iostream>
using namespace std;
struct student
{
    int x;
    int y;
    string name;
};




void display(struct student * ptr){
    cout<<ptr->x<<endl;
    cout<<ptr->y<<endl;
    cout<<ptr->name<<endl;
    


}
struct student edit(struct student p){
    cout<<"after declaring a structure function and passing a variable to it"<<endl;

    (p.x)++;
    p.y=p.y+8;
    return p;
}

struct student *fun(int a,int b)
{
    struct student *ptr_fun=new struct student();
    ptr_fun->x=a;
    ptr_fun->y=b;
    return ptr_fun;

};

int main(){
    struct student var={0,3,"ruturaj"};
    struct student *o,*o2;
    
    cout<<var.x<<endl;

    cout<<var.y<<endl;
    display(&var);


    
    var=edit(var);
    display(&var);

    cout<<"New shit"<<endl;
    o=fun(202,203);
    o2=fun(98,89);
    display(o);
    display(o2);
//deallocating the pointer memory
    free(o);
    free(o2);


    return 0;

}
