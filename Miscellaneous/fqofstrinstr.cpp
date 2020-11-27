#include<bits/stdc++.h>
using namespace std;

void calclps(vector<int>& lps,string pat){
	int len=0,i=1,n=pat.length();
	lps[0]=0;
	while(i<n){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len==0){
				lps[i]=0;
				i++;
			}
			else{
				len=lps[len-1];
			}
		}
	}
}

void show(vector<int>vec){
	for(auto i:vec)cout<<i<<" ";
	cout<<endl;
}

int magic(string pat,string str,vector<int>& lps){
	int i=0,j=0,m=pat.length(),n=str.length(),c=0;
	while(i<n){
		if(str[i]==pat[j]){
			i++;
			j++;
			if(j==m){
				c++;j=lps[j-1];
			}
		}
		else{
			if(j==0)i++;
			else{
				j=lps[j-1];
			}
		}
	}
	return c;
}

int main(){
	string pat="man";
	string str="man";
	vector<int>lps(pat.length());
	calclps(lps,pat);
	cout<<magic(pat,str,lps)<<endl;;
	// show(lps);
	return 0;
}