#include<bits/stdc++.h>
using namespace std;

class graph{
public:
	int v;
	unordered_map<int,set<int>>m;
	graph(int v){
		this->v=v;
		m.clear();
	}
	void addedge(int u,int v){
		m[u].insert(v);
		m[v].insert(u);
	}

	bool bfspath(int source,int dest,vector<int>& pred,vector<int>& dist){
		dist.resize(v,INT_MAX);
		pred.resize(v,-1);
		vector<bool>vst(v,false);

		dist[source]=0;
		vst[source]=true;

		deque<int>q;
		q.push_back(source);

		while(!q.empty()){
			int u=q.front();
			q.pop_front();

			for(auto i:m[u]){
				if(!vst[i]){
					vst[i]=true;
					pred[i]=u;
					dist[i]=dist[u]+1;
					q.push_back(i);

					if(i==dest){
						return true;
					}
				}
			}
		}

		return false;			
	}

	void printspath(int source,int dest){
		vector<int>pred,dist;

		bool k=bfspath(source,dest,pred,dist);
		if(!k){
			cout<<source<<" and "<<dest<<" aren't connected "<<endl;
			return;
		}
		vector<int>path;
		int now=dest;
		while(now!=-1){
			path.push_back(now);
			now=pred[now];
		}

		cout<<" The shortest path length is : "<<dist[dest]<<endl;

		cout<<" The path is : ";

		for(int i=path.size()-1;i>=0;i--){
			cout<<path[i]<<" ";
		}
		cout<<endl;

	}
};

int main(){

	graph g(8);
	g.addedge(0,1);
	g.addedge(0,3);
	g.addedge(1,2);
	g.addedge(3,4);
	g.addedge(3,7);
	g.addedge(4,5);
	g.addedge(4,6);
	g.addedge(4,7);
	g.addedge(5,6);
	g.addedge(6,7);
	
	int s=2,d=6;

	g.printspath(s,d);

	return 0;
}