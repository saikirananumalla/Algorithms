#include<bits/stdc++.h>
using namespace std;

void lps(string s,vector<int>&vec){
	int len=0,i=1;
	vec[0]=0;
	while(i<s.length()){
		if(s[i]==s[len]){
			len++;
			vec[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=vec[len-1];
			}
			else{
				vec[i]=0;
				i++;
			}
		}
	}
}

void show(vector<int> v){
	for(int i:v)cout<<i<<" ";
	cout<<endl;
}
int main(){
	string text="aaaaa";
	string pat="aa";
	vector<int>vec(pat.length(),0);
	lps(pat,vec);
	show(vec);
	int m=pat.length();
	pat.insert(0,"#");
	cout<<pat<<endl;
	int count=0,n=text.length();
	int i=0,j=0,start=0;
	while(i<n){
		cout<<text[i]<<" "<<pat[j+1]<<" "<<endl;
		if(text[i]==pat[j+1]){
			i++;
			j++;
		}
		if(j==m){
			j=vec[j-1];
			count++;
		}
		else if(i<n && text[i]!=pat[j+1]){
			if(j!=0)j=vec[j-1];
			else i++;
		}
	}
	cout<<count<<" is the freq"<<endl;


}