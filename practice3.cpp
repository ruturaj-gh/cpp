#include <iostream>
using namespace std;
class selection_sort{
    public:
    
    void sort(int* arr,int size)
    {
        int min;
        for(int i=0;i<size-1;i++){
            
            for(int j=i+1;j<size;j++){
                if(arr[j]<arr[i]){
                    
                    swap(arr[j],arr[i]);
                }
            }
        }
        
    }
    void print(int * arr,int size){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" "<<endl;
        }
    }

};
int main(){
    int arr[]={23,1,45,6,45,87};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection_sort obj;
    obj.sort(arr,n);
    obj.print(arr,n);


    return 0;
}