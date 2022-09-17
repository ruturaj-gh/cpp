#include <bits/stdc++.h>
using namespace std;
vector<int> g[100000];
int visited[100000];
void dfs(int vertex)
{
    // if(visited[vertex]==1)
    // {
    //     return;
    // }
    if(!visited[vertex])
    {
        visited[vertex]=1;
        for(int i=0;i<g[vertex].size();i++)
        {
            if(!visited[g[vertex][i]]){
                dfs(g[vertex][i]);
            }
        }
        
    }

}
int main()
{
    int n;
    cout<<"enter the no of edges"<<endl;
    cin>>n;

    
    while(n--)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        //g[v2].push_back(v1);
    }
    dfs(0);
    cout<<0<<":"<<visited[0]<<" ";
    cout<<1<<":"<<visited[1]<<" ";
    cout<<2<<":"<<visited[2]<<" ";
   cout<<3<<":"<<visited[3]<<" ";
    
}