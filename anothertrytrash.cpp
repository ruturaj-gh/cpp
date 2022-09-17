#include <bits/stdc++.h>
#include <map>
using namespace std;

vector<int>  fun(vector<int> &v,int target)
{
  vector<int> output;
  
  int start=0;
  int end=v.size();
  
  while (start<=end)
  {
    int mid=(start+end)/2;
    if (v[mid]==target)
    {
      output.push_back(mid-1);
      output.push_back(mid+1);
      output.pop_back()
      break;
    }
    else if (v[mid]>target)
    {
      start=mid+1;
      
    }
    else
    {
      end=mid-1;
      
    }
  }
  return output;
  
  
  

}
int main()
{
  vector<int> v = {5,7,7,8,9,10};
  vector<int> ans;
  ans=fun(v,8);
  cout<<ans.at(0)<<endl;
  cout<<ans.at(1)<<endl;
  


}