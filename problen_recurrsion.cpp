#include <bits/stdc++.h>
using namespace std;
static int fun(string name,int i){
    if(i==name.length()){
        return 0;
    }
    
    if(isupper(name[i])){
        cout<<name[i]<<endl;
        cout<<i<<endl;
    }
    i++;
    fun(name,i);
    

}
int main(){
    string name="ruTUraj";
    int i=0;




    fun(name,i);
    

    return 0; 
}