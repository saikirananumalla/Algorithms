#include<bits/stdc++.h>
using namespace std;


class Node{
public:
	int v;int w;
	Node(int x,int y){v=x;w=y;}
};

class Graph{
public:
	int v;
	unordered_map<int,vector<Node>>m;
	Graph(int x){v=x;m.clear();}

	void addEdge(int u,int v,int w){
		Node n(v,w);
		m[u].push_back(n);
	}

	void topsort(int s,vector<bool>& vst,stack<int>& stk){

		vst[s]=true;

		for(auto i:m[s]){
			if(!vst[i.v])topsort(i.v,vst,stk);
		}
		stk.push(s);

	}

	void longestPath(int s){
		vector<bool>vst(v,false);
		stack<int>stk;

		vector<int>dist(v,INT_MIN);

		for(int i=0;i<v;i++){
			if(!vst[i])topsort(i,vst,stk);
		}

		dist[s]=0;

		while(!stk.empty()){
			int u=stk.top(); stk.pop();
			for(auto i:m[u]){
				int nv=i.v;
				int w=i.w;

				if(dist[nv]<dist[u]+w)dist[nv]=dist[u]+w;
			}
		}

		for(int i=0;i<v;i++){
			(dist[i]==INT_MIN)?cout<<"INF"<<" " : cout<<dist[i]<<" ";
		}

	}
};


int main(){
	Graph g(6);  
    g.addEdge(0, 1, 5);  
    g.addEdge(0, 2, 3);  
    g.addEdge(1, 3, 6);  
    g.addEdge(1, 2, 2);  
    g.addEdge(2, 4, 4);  
    g.addEdge(2, 5, 2);  
    g.addEdge(2, 3, 7);  
    g.addEdge(3, 5, 1);  
    g.addEdge(3, 4, -1);  
    g.addEdge(4, 5, -2);  
    
    int s = 1;  
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";  
    g.longestPath(s);  
    
    return 0;
}