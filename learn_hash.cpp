#include <iostream>
#include <math.h>
using namespace std;
#define MAX 1000
bool has[MAX+1][2];

bool search(int x){
    if(x>=0){
        if(has[x][0]==1){
            return true;

        }
        else{return false;}
    }
    else{
        x=abs(x);
        if(has[x][1]==1){
            return true;

        }
        else{return false;}

    }
}
void insert(int *arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i]<=0){
            has[arr[i]][0]=true;
        }
        else{
            has[abs(arr[i])][1]=true;
        }
    }
}
int main(){
    
    int arr[]={-1,9,2,-6,3,1}



    return 0
}