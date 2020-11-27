#include<bits/stdc++.h>
using namespace std;

void permute(string s,int l,int r){
	if(l==r){
		cout<<s<<endl;
		return ;
	}
	for(int i=l;i<=r;i++){
		swap(s[i],s[l]);
		permute(s,l+1,r);
		swap(s[i],s[l]);
	}
}

void permute(string s){
	cout<<s<<endl;
	while(next_permutation(s.begin(),s.end())){
		cout<<s<<endl;
	}
}

int main(){
	string s="ABC";
	int n=s.length();
	// permute(s,0,n-1);
	permute(s);
	return 0;
}