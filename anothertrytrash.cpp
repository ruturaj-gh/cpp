#include <iostream>
using namespace std;
static int fib(int n){
  if(n==1 || n==2){
    return 1;

  }
  else{
    return fib(n-1)+fib(n-2);
  }

}

static int anotherfib(int n,int memo[]){
  int result=0;
  if(memo[n]!='\0'){
    return memo[n];
  }
  else if(n==1 || n==2){
  result=1;
    
  }
  else{
    result=fib(n-1)+fib(n-2);
    memo[n]=result;
    return result;
  }
}
static int feb_bottom_up(int n){
  if(n==1 || n==2){
    return 1;
  }
  int bottom_up[n]={};
  bottom_up[0]=0;
  bottom_up[1]=1;
  for(int i=2;i<n;i++){
    bottom_up[i]=bottom_up[i-1]+bottom_up[i-2];
    
  }
  return bottom_up[n];
}
int main(){
  int n=3;
  int memo[n+1]={};
  cout<<anotherfib(n,memo)<<endl;
  cout<<fib(n)<<endl;
  cout<<feb_bottom_up(n)<<endl;



  return 0;
}