#include<bits/stdc++.h>
using namespace std;


int jos(int n,int k){
	if(n==1)
		return 1;
	return ((jos(n-1,k)+k-1)%n)+1;
}


int main(){
	cout<<jos(14,2)<<" is the prince that was promised"<<endl;
	return 0;
}