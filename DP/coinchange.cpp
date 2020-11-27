#include<bits/stdc++.h>
using namespace std;

void show(vector<int>vec){
	for(int i:vec)cout<<i<<" ";
	cout<<endl;
}

int count(vector<int>&vec,int n){
	int m=vec.size();
	vector<int>table(n+1,0);
	table[0]=1;

	for(int i=0;i<m;i++){
		for(int j=vec[i];j<=n;j++){
			table[j]+=table[j-vec[i]];
		}
	}
	show(table);
	return table[n];
}

int main(){
	vector<int>vec={1,2,5,8};
	int n=10;
	cout<<count(vec,n)<<endl;

}