#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<long long int> dp(n, 0.0);
        dp[n-1] = 1;
        for(int i = n - 2; i >= 0 ; i--)
        {
            int jumpVal = nums[i];
            for(int j = 1; j <= jumpVal; j++)
            {
                if( i + j >= n)
                    break;
                dp[i] += dp[i+j];
            }  
        }
        
        for(int i = 0 ; i < n ; i++)
            cout << dp[i] << " ";
   
        return dp[0] > 0;
    }
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<endl;
    }
    cout<<canJump(v);
    
    
    return 0;
}    

