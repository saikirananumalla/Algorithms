#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ip;

int main(){
	vector<int>arr={1,5,4,3,2};
	unordered_map<int,int>mp1,mp2;
	int n=arr.size();
	for(int i=0;i<n;i++){
		mp1[arr[i]]=i;
		// cout<<arr[i]<<" "<<i<<endl;
	}
	sort(arr.begin(),arr.end());
	set<ip>st;
	ip temp;
	int c=0;
	for(int i=0;i<n;i++){
		int nowp=i;
		int prevp=mp1[arr[i]];
		if(nowp==prevp)continue;
		if(nowp>prevp)swap(nowp,prevp);
		cout<<nowp<<" "<<prevp<<endl;
		temp={nowp,prevp};
		if(st.find(temp)==st.end()){
			c++;
			st.insert(temp);
		}
	}
	cout<<c<<" is the # of swaps required\n";
	return 0;

}