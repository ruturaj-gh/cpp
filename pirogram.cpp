#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int arr[N][N];
vector<pair<int,int>> graph2[N];

int main()
{
    int n,m;
    cin>>n>>m;
    
    for (int i = 0; i < n; i++)
    {
        /* code */
        int v1,v2,wt;
        cin>>v1>>v2;
        arr[v1][v2]=wt;
        arr[v2][v1]=wt;

        graph2[v1].push_back({v2,wt});
        graph2[v2].push_back({v1,wt});
    }
    
    
    
    
    



    return 0;
}