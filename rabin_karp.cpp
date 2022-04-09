#include <bits/stdc++.h>
using namespace std;
#define d 256
static void search(char pattern[], char txt[],int q){
    int m=strlen(pattern);
    int n=strlen(txt);
    int i,j;
    int p=0;
    int t=0;
    int h=1;
    int something = 4;

    //the value of h would be pow(d,M-1)%q
    for(i=0;i<m-1;i++){
        h=(h*d)%q;

    }

    //calculate the hash value of pattern and first window of text
    for(i=0;i<m;i++){
        p=(d*p +pattern[i])%q;
        t=(t*d + txt[i])%q;
    }

    //silding txt one by one

    for(i=0;i<=n-m;i++){

        if(p==t){
            bool flag=true;
            for(j=0;j<m;j++){
                if(txt[i+j]!=pattern[j]){
                    break;

                }
            }
            if(flag){
                cout<<i;
            }
            if(j==m){
                cout<<"pattern found at index "<<i;
            }
        }
        if(i<n-m){
            t=(d*(t-txt[i]*h) + txt[i+m])%q;
            if(t<0){
                t=(t+q);
            }
        }
        
    }





}
int main(){
    char txt[]="abdcb";
    char pattern[]="dc";

    int q=11;
    search(pattern,txt,q);





    return 0;
}