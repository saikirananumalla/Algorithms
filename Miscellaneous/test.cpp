#include<bits/stdc++.h>
using namespace std;

// class xyz{

// };

int main(){
	// xyz x;
	// cout<<sizeof(x);
	int n=2;
	int sum=5;
	switch(n){
		case 2:sum=sum-2;
		case 3:sum*=5; break;
		default: sum=0;
	}
	cout<<sum<<endl;
	return 0;
}