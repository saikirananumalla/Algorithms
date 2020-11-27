#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];
int c;

int solve(int arr[],int i,int j){
	c++;
	if(i>j)return 0;
	if(t[i][j]!=-1)return t[i][j];
	if(__gcd(arr[i],arr[j]) > 1 ) return 0;
	int ans=INT_MAX;
	for(int k=i;k<j;k++){
		int temp=1+solve(arr,i,k)+solve(arr,k+1,j);
		ans=min(ans,temp);
	}
	return t[i][j]=ans;
	// return ans;
}

int main(){
	// int arr[]={2,3,4,4,4,3};
	// int arr[]={1,2,3};
	// int arr[]={2,3,4,4,3,3};
	// int arr[]={2,3,2,3,3};
	// int arr[]={3,5,7,11,2};
	// int arr[]={10,13,17,9,23,6,6,29,3};
	int arr[]={3,29,6,6,23,9,17,13,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	memset(t,-1,sizeof(t));
	c=0;
	cout<<max(0,solve(arr,0,n-1)+1);
	cout<<"\nfunction is called is: "<<c<<" times"<<endl;
	return 0;
}