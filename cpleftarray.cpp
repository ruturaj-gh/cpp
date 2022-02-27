#include <iostream>
using namespace std;
void left(int n,int *arr){
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
        
    }
    arr[n-1]=temp;

}
void leftbyn(int *arr,int k,int n){
    for(int i=0;i<k;i++){
        left(n,arr);
    }
}
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }    

}
int main(){
    int n,r;
    cin>>n;
    cin>>r;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    leftbyn(arr,r,n);

    
    print(arr,n);
    




    return 0;
}
