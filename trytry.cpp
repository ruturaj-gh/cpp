#include <bits/stdc++.h>
using namespace std;
class graph{
    int v;
    list<int> *adj;


    public:
    void bfs(int s);
    void addEdge(int v,int w);
    graph(int v);


};
graph::graph(int v){
    this->v=v;
    adj=new list<int>[v];


}
void graph::addEdge(int v,int w){
    adj[v].push_back(w);
}
void graph::bfs(int s){
    bool *visited=new bool[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;

    }
    visited[s]=true;

    list<int> queue;
    queue.push_back(s);


    list<int>::iterator i;


    while (!queue.empty())
    {
        /* code */
        int d=queue.front();
        cout << d << " ";
        queue.pop_front();
         

        for(i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        } 

    }
    
}
int main(void){
    graph g(8);
    g.addEdge(1,4);
    g.addEdge(3,4);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    
    g.bfs(4);

}
