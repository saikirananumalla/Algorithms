#include<bits/stdc++.h>
using namespace std;

int fact(int n){
	int s=1;
	for(int i=1;i<=n;i++){
		s*=i;
	}
	return s;
}

int convert(int x,int y){
	string res="";
	while(x>0){
		int n=x%y;
		res+=to_string(n);
		x/=y;
	}
	return stoi(res);
}

int main(){
	int n;
	n=6;
	cout<<fact(6)<<endl;

	map<int,int>m;
	for(int k=4;k<10;k++){
		// m[k]=convert(fact(k)+1,k-1);
		m[k]=fact(k)+1;
	}
	for(auto& i:m){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}