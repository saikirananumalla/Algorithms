#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr,int* tree,int start,int end,int tN){
	if(start==end){
		tree[tN]=arr[start];
		return ;
	}
	int mid=(start+end)/2;
	buildTree(arr,tree,start,mid,2*tN+1);
	buildTree(arr,tree,mid+1,end,2*tN+2);

	tree[tN]=tree[2*tN+1]+tree[2*tN+2];
}

int query(int *tree,int now,int sl,int sr,int l, int r){

	if(l>sr || r<sl)return 0;

	if(l<=sl && r>=sr) return tree[now];

	int mid=(sl+sr)/2;

	return query(tree,2*now+1,sl,mid,l,r)+query(tree,2*now+2,mid+1,sr,l,r);


}

void update(int* tree,int now,int sl,int sr,int dif,int pos){
	if(pos<sl || pos>sr)return ;
	tree[now]+=dif;
	if(sl!=sr){
		int mid=(sl+sr)/2;
		update(tree,2*now+1,sl,mid,dif,pos);
		update(tree,2*now+2,mid+1,sr,dif,pos);
	}
}

int main(){
	int arr[]={1,2,5,6,7,9};
	int h=(int)ceil(log2(6));
	// cout<<h<<" is the height"<<endl;
	h=(int)pow(2,h+1)-1;
	// cout<<h<<endl;
	int* tree=new int[h];

	buildTree(arr,tree,0,5,0);

	for(int i=0;i<h;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	cout<<query(tree,0,0,5,2,4);
	// cout<<endl;
	//update
	arr[2]+=7;
	arr[4]+=1;
	update(tree,0,0,5,7,2);
	update(tree,0,0,5,1,4);
	cout<<endl;
	cout<<query(tree,0,0,5,2,4);
	cout<<endl;
}