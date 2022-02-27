// C++ code to demonstrate star pattern

#include <bits/stdc++.h>
using namespace std;

class graph{
	public:
	int vertices;
	graph(int v);
	void addEdge(int v,int w);
	
	list<int> *adj;
	void show();
};
graph::graph(int v){
	this->vertices=v;
	adj = new list<int>[v];
}


void graph::addEdge(int v,int w){
	adj[v].push_back(w);

}
void graph::show(){
	for (auto it = adj->begin(); it != 
                            adj->end(); ++it)
        cout << ' ' << *it;
}
int main(){
	graph g1(5);       
g1.addEdge(1, 0);
g1.addEdge(0, 2);
g1.addEdge(2, 1);