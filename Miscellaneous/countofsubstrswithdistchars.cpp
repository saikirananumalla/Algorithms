#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int magic(string s){
    int n=s.length();
    int i=0,j=0;
    int *cnt=new int[26];
    int c=0;
    while(i<n){
        if(j<n && cnt[s[j]-'a']==0){
            c+=(j-i+1);
            cnt[s[j++]-'a']++;
        }
        else{
            cnt[s[i++]-'a']--;
        }
    }
    return c;
}

int main(){
    string s="gfg";
    cout<<"res is : "<<magic(s)<<endl;
    return 0;
}