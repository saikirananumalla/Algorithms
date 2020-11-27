#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ip;

int minLinesToCoverPoints(int points[][2],int n,int x0,int y0){
	set<ip>st;
	ip temp;
	int c=0;
	for(int i=0;i<n;i++){
		int x=points[i][0],y=points[i][1];
		int dx=(x-x0),dy=(y-y0);
		int g=__gcd(dx,dy);
		temp={dx/g,dy/g};
		if(st.find(temp)==st.end()){
			st.insert(temp);
			c++;
		}
	}
	return c;
}

int main(){
	int x0,y0;
	x0=1,y0=0;
	int points[][2]={
		{-1, 3}, 
        {4, 3}, 
        {2, 1}, 
        {-1, -2}, 
        {3, -3}
	};
    int N = sizeof(points) / sizeof(points[0]); 
    cout << minLinesToCoverPoints(points, N, x0, y0); 
    return 0; 
}