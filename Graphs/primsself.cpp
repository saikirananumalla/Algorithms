#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ip;

class graph{
public:
	int v;
	unordered_map<int,vector<pair<int,int>>>m;
	graph(int n){
		v=n;
		m.clear();
	}
	void addedgedge(int u,int v,int w){
		m[u].push_back({v,w});
		m[v].push_back({u,w});
	}

	int givemin(vector<int>& val,vector<bool>& vst){
		int mini=INT_MAX,vert;

		for(int i=0;i<v;i++){
			if(!vst[i] && val[i]<mini){
				vert=i;
				mini=val[i];
			}
		}
		return vert;
	}
	void prims(int src){
		vector<int>parent(v,-1);
		vector<int>val(v,INT_MAX);
		vector<bool>vst(v,false);

		val[src]=0;
		parent[src]=-1;

		priority_queue<ip,vector<ip>,greater<ip>>pq;

		pq.push({0,src});

		// for(int i=0;i<v-1;i++){
		// 	int u=givemin(val,vst);
		// 	vst[u]=true;
		// 	for(auto v:m[u]){
		// 		int pr=v.second;
		// 		int nv=v.first;

		// 		if(!vst[nv] && pr<val[nv]){
		// 			val[nv]=pr;
		// 			parent[nv]=u;
		// 		}
		// 	}
		// }

		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();

			vst[u]=true;

			for(auto pv:m[u]){
				int v=pv.first;
				int w=pv.second;

				if(!vst[v] && val[v]>w){
					val[v]=w;
					parent[v]=u;
					pq.push({val[v],v});
				}
			}
		}
		int sum=0;
		for(int i=1;i<v;i++){
			sum+=val[i];
			cout<<parent[i]<<"->"<<i<<" with value: "<<val[i]<<" "<<endl;
		}
		cout<<"The min cost tree is : "<<sum<<endl;
	}	
};

int main(){
	// graph g(4);
	// g.addedge(0,1,3);
	// g.addedge(0,2,1);
	// g.addedge(1,2,2);
	// g.addedge(1,3,4);
	// g.addedge(2,3,5);

	int V = 9; 
    graph g(V); 
  
    //  making above shown graph 
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


	g.prims(0);

	return 0;
}