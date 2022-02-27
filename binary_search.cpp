#include <iostream>
using namespace std;
int binarysearch(int arr[],int  size,int num){
    int i,k,j;
    i=0;j=size;
    while (i<=j)
    {
        /* code */
        k=(i+j)/2;
        if(arr[k]==num){
            return  k;
        }
        else if(arr[k]<num){
            i=k+1;
            
        }
        else{
            j=k-1;
        }
    }
    
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    cout<<binarysearch(arr,10,5);


    return 0;
}