#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int mn;
	int mx;
};

class stree{
public:
	vector<Node>tree;
	vector<int>arr;
	stree(vector<int>a){
		int n=a.size();
		int h=(int)ceil(log2(n));
		h=(int)2*pow(2,h)-1;
		tree.resize(h);
		arr.clear();
		arr=a;
		bulid();
	}
	int getmid(int s,int e){
		return s+(e-s)/2;
	}
	void bulid(){
		bulid(0,arr.size()-1,0);
	}
	void bulid(int start,int end,int node){
		if(start==end){
			tree[node].mn=arr[start];
			tree[node].mx=arr[start];
			return ;
		}
		int mid=getmid(start,end);
		bulid(start,mid,2*node+1);
		bulid(mid+1,end,2*node+2);

		tree[node].mn=min(tree[2*node+1].mn,tree[2*node+2].mn);
		tree[node].mx=max(tree[2*node+1].mx,tree[2*node+2].mx);
	}

	Node getminmax(int start,int end){
		return getminmax(0,0,arr.size()-1,start,end);
	}

	Node getminmax(int now,int sl,int sr,int l,int r){
		if(l>sr || r<sl)return {INT_MAX,INT_MIN};

		if(l<=sl && r>=sr)return {tree[now].mn,tree[now].mx};

		int mid=getmid(sl,sr);

		auto p=getminmax(2*now+1,sl,mid,l,r);

		auto q=getminmax(2*now+2,mid+1,sr,l,r);

		int mini=min(p.mn,q.mn);
		int maxi=max(p.mx,q.mx);

		return {mini,maxi};
	}


};

int main(){
	vector<int>arr = {1, 8, 5, 9, 6, 14, 2, 4, 3, 7}; 

	stree s(arr);

	int n=arr.size();

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			
			Node res=s.getminmax(i,j);

			cout<<res.mn<<" & "<<res.mx<<" for range "<<i<<" and "<<j<<endl;
		}
	}

	return 0;
}