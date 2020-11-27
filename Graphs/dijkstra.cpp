#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int,int> ip;

class graph{
public:
	int v;
	list<ip>*m;
	graph(int v){
		this->v=v;
		m=new list<ip>[v];
	}
	void addEdge(int u,int v,int w){
		m[u].push_back({v,w});
		m[v].push_back({u,w});
	}

	void shortestpath(int src){
		priority_queue<ip,vector<ip>,greater<ip>>pq;
		vector<int>dist(v,INF);
		dist[src]=0;
		pq.push({0,src});
		vector<bool>vst(v,false);

		while(!pq.empty()){

			auto nd=pq.top().first;auto nv=pq.top().second;pq.pop();
				
			vst[nv]=true;

			for(auto i:m[nv]){

				auto v=i.first;
				auto w=i.second;

				if( !vst[v] && dist[v]>dist[nv]+w){

					dist[v]=dist[nv]+w;

					pq.push({dist[v],v});

				}
			}
		}

		for(int i=0;i<v;i++){
			cout<<i<<" "<<dist[i]<<" "<<endl;
		}
		cout<<endl;
	}
};


int main(){
	int V = 9;
	graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortestpath(0);

	return 0;
}