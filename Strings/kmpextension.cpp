#include<bits/stdc++.h>
using namespace std;

void calculatelps(string s,vector<int>&lps){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<s.length()){
		if(s[i]==s[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0)len=lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}
void show(vector<int>lps){
	for(int i:lps)cout<<i<<" ";
		cout<<endl;
}
int main(){
	string str1="geekgeek";
	string str2="geek";
	int n=str1.length();
	vector<int>lps(n,0);
	str2=str2+str2;
	int m=str2.length();
	calculatelps(str1,lps);
	show(lps);
	str1.insert(0,"#");
	int i=0,j=0;
	int maxlen=0,pos;

	while(i<m){
		while(j>0 && str1[j+1]!=str2[i]) j = lps[j-1];
		if(str2[i]==str1[j+1])j++;

		if(j>maxlen){
			maxlen=j;
			pos=i-j+1;
		}
		i++;
	}
	cout<<maxlen<<endl;
	cout<<pos<<endl;
	return 0;
}