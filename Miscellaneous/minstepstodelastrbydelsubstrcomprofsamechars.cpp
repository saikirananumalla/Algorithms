/*Given a string str. You are allowed to delete only some contiguous characters if all the characters are same in a single operation. The task is to find the minimum number of operations required to completely delete the string.*/


#include <bits/stdc++.h> 
using namespace std; 
// Driver code 

int dp[10][10];

int solve(int i,int j,string s){
	if(i>j)return 0;
	if(i==j)return 1;
	if(dp[i][j]!=-1)return dp[i][j];
	int res = 1+solve(i+1,j,s);

	for(int k=i+1;k<=j;k++){
		if(s[i]==s[k]){
			res=min(res,solve(i+1,k,s)+solve(k+1,j,s));
		}
	}
	return dp[i][j]=res;
}

int main() 
{ 
	string s = "abcddef"; 
	int n = s.length(); 
	memset(dp, -1, sizeof dp); 
	cout << solve(0, n - 1,s); 

	return 0; 
} 
