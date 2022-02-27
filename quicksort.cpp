#include <iostream>
using namespace std;

void quicksort(int arr[],int size,int low,int high){
    if(low>=high){
        return;
    }
    int s=low;
    int e=high;
    int mid=(s+e)/2;
    int pivot=arr[mid];
    while(s<=e)
    {
        /* code */
        //also a  reason why if its alreasdy sorted it will not swap
        while (arr[s]<pivot)
        {
            /* code */
            s++;
            
        }
        while (arr[e]>pivot)
        {
            /* code */
            e--;
            
        }
        if(s<=e){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
        
        
    }
    //now pivot is at correct position please sort  two halves
    quicksort(arr,size,low,e);
    quicksort(arr,size,s,high);
    
}
int main(){
    int arr[]={63,54,78,43,67,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,n,0,n-1);
    cout<<"sorted array is as follows"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}