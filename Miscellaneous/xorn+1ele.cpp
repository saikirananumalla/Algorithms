#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={1,2,3,4,5};
	int xo=2;
	int x=arr[0];
	for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++){
		x=x^arr[i];
	}
	cout<<(xo^x)<<endl;
	return 0;
}