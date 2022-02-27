#include <bits/stdc++.h>
using namespace std;
class newclass{
    public:
void fun(int* arr,int n,int j,int k){
    
    if(j==n){
        return;
    }
    if(k==n){
        return;
    }
    
    
    if(arr[j]<arr[k]){
        swap(arr[j],arr[k]);
    }
    
    
    fun(arr,n,j+1,0);
    fun(arr,n,j,k+1);

    

    
    


}
void insertionsort(int *arr,int n){
    int i,key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while (j>=0 && arr[j]>key)
        {
            /* code */
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
}
void print(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}
};
int main(){
    int arr[]={10,8,15,7,9,3,45,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    newclass obj;
    cout<<"original array"<<endl;
    obj.print(arr,n);

    

    //obj.fun(arr,n,1,0);
    obj.insertionsort(arr,n);
    cout<<"after calling the function"<<endl;
    obj.print(arr,n);
    
    
    

    return 0;
}