#include <iostream>
using namespace std;
class animal{
    public:

    void fun(){
        cout<<"the class animal is created"<<endl;

    }

};
class rabbit:public animal{
    public:
    void fun2(){
        cout<<"The class rabbit is inherited from derived class animal"<<endl;

    }

};
class kangaroo:public rabbit{
    public:
    void fun3(){
        cout<<"the class kangaroo is inherited from already inherited class rabbit"<<endl;

    }

};



int main(){
    kangaroo obj;
    obj.fun();
    obj.fun2();
    obj.fun3();




    return 0;
}
