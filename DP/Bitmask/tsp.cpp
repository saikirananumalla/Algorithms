#include<bits/stdc++.h>
using namespace std;

int dp[21][21];
vector<vector<int>>cost;

int solve(int v,int mask,int& src,int& n){
	if(mask==0)return cost[v][src];
	if(dp[v][mask]!=-1)return dp[v][mask];

	int ans=INT_MAX;

	for(int j=0;j<n;j++){
		if(mask & (1<<j)){
			ans=min(ans,cost[v][j]+ solve(j,mask^(1<<j),src,n));
		}
	}
	return dp[v][mask]=ans;
}


int main(){
	int n=4;
	vector<vector<int>>vec={ {0,2,7,8},{6,0,3,7},{5,8,0,8},{7,6,9,0} };

	cost=vec;

	memset(dp,-1,sizeof(dp));

	int src=0;

	cout<<solve(0,(1<<n)-1-((int)pow(2,src)),src,n)<< " is the least cost\n";

	return 0;

}