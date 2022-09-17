#include <bits/stdc++.h>
using namespace std;
int reverse(int num){
    int remainder;
    int rev=0;
    int number;
    while (num!=0)
    {
        remainder=num%10;
        rev=rev*10+remainder;
        number=num/10;
    }
    return rev;
    


}
int main()
{
    int num;
cin>>num;

cout<<reverse(num)<<endl;
    
    
}
