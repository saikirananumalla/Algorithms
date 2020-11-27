#include<bits/stdc++.h>
using namespace std;

class stree{
public:
	vector<int>tree;
	vector<int>arr;
	stree(){
		tree.clear();
		arr.clear();
	}
	int getmid(int s, int e){return s+(e-s)/2;}
	void build(vector<int>arr){
		int n=arr.size();
		int h=(int)ceil(log2(n));
		h=(int)(pow(2,h+1))-1;
		tree.resize(h);
		this->arr=arr;
		buildutil(0,n-1,0);
	}
	void buildutil(int start,int end,int node){
		if(start==end){
			tree[node]=arr[start];
			return ;
		}
		int mid=getmid(start,end);
		buildutil(start,mid,2*node+1);
		buildutil(mid+1,end,2*node+2);
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
	void printtree(){
		for(int i:tree)cout<<i<<" ";
		cout<<endl;
	}

	int query(int l,int r){
		// cout<<endl;
		return queryutil(0,0,arr.size()-1,l,r);
	}
	int queryutil(int now,int sl,int sr,int l,int r){
		if(l>sr || r<sl)return 0;

		if(l<=sl && r>=sr) return tree[now];

		int mid=getmid(sl,sr);

		return queryutil(2*now+1,sl,mid,l,r)+queryutil(2*now+2,mid+1,sr,l,r);
	}

	void update(int pos,int val){
		cout<<endl;
		if(pos<0 || pos>=arr.size())return ;
		updateutil(0,0,arr.size()-1,val-arr[pos],pos);
	}

	void updateutil(int now,int sl,int sr,int dif,int pos){

		if(pos<sl || pos>sr) return ;

		int mid=getmid(sl,sr);
		tree[now]+=dif;
		if(sl!=sr){
			updateutil(2*now+1,sl,mid,dif,pos);
			updateutil(2*now+2,mid+1,sr,dif,pos);
		}

	}
};

int main(){
	vector<int>arr={1,2,5,6,7,9};
	stree s;
	s.build(arr);
	s.printtree();
	cout<<s.query(2,4);
	s.update(2,-1);
	cout<<s.query(2,4);
	return 0;
}