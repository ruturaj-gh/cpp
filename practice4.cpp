#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int *arr,int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={3,4,323,44,32,78};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    print(arr,n);

    return 0;
}