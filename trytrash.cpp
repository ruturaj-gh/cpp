#include <bits/stdc++.h>

using namespace std;
int binary_search(int *arr,int start,int end,int target)
{
    int mid=(start+end)/2;
    if (arr[mid]==target)
    {
        /* code */
        
        return mid;
    }
    
    if(target<arr[mid])
    {
        end=mid;
        binary_search(arr,start,end,target);
    }
    else
    {
        start=mid;
        binary_search(arr,start,end,target);
    }
    

}
int * reverse(int arr[])
{
    for(int i=8;i>=0;i--)
    {
    int temp=arr[i];
    arr[i]=arr[9-(i+1)];
    arr[9-(i+1)]=temp;
    }
    return arr;
}


int main()
{
int arr[]={2,3,5,5,11,15,16,19,24};
int start=0;
    int end=9;
    int mid=(start+end)/2;
    int target=5;
//cout<<binary_search(arr,start,end,target);
int *p=reverse(arr);
for (int i = 0; i < 9; i++)
{
    /* code */
    cout<<*(p+i)<<endl;
}

}
