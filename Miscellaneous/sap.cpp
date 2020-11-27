#include<bits/stdc++.h>
using namespace std;

int main(){
	unordered_map<int,set<int>>m;
	m[1]={2,3};
	m[2]={1,2};
	m[3]={1,2,3};
	m[4]={2,4};

	int arr[]={1,2,3,4};
	int maxi=0;
	unordered_map<int,pair<int,int>>mp;
	for(int i=0;i<3;i++){
		for(int j=i+1;j<4;j++){
			// set<int>temp;
			vector<int>temp;
			set_intersection(m[arr[i]].begin(),m[arr[i]].end(),m[arr[j]].begin(),m[arr[j]].end(),back_inserter(temp));

			cout<<"for "<<arr[i]<<" and "<<arr[j]<<" the set is : ";
			for(auto i:temp)cout<<i<<" ";
			cout<<endl;

			mp[temp.size()]={arr[i],arr[j]};

			if(temp.size()>maxi){
				maxi=temp.size();
			}
		}
	}

	int res=0;
	for(auto i:mp){

		if(i.first==maxi){
			res=max(res,i.second.first*i.second.second);
		}
	}
	cout<<res<<endl;

	return 0;
}