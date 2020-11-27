#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
unordered_map<string,int>m;
char dx[]={'a','e','i','o','u'};

bool isok(string x,char y){
    int n=x.length();
    if(x=="")return true;
    if(x[n-1]=='a' && y=='e')return true;
    if(x[n-1]=='e' && (y=='a' || y=='i'))return true;
    if(x[n-1]=='i' && y!='i')return true;
    if(x[n-1]=='o' && (y=='i' || y=='u' ))return true;
    if(x[n-1]=='u' && y=='a')return true;
    
    return false;
}

int solve(string a,int n,unordered_map<string,int>& m,int &res){
    if(n==0)return 0;
    if(m[a]!=0)return m[a];
    int ans=0;
    for(int i=0;i<5;i++){
        if(isok(a,dx[i])){
            // cout<<a+dx[i]<<endl;
            if(n==1)res++;
            int l=0;
            if(m[a+dx[i]]!=0)l=m[a+dx[i]];
            else l=solve(a+dx[i],n-1,m,res);
            ans+=(1+l);
        }
    }
    return m[a]=ans;
}


int countPerms(int n) {
    m.clear();
    string x="";
    int res=0;
    solve(x,n,m,res);
    return res;
}
int main()
{
    int n=10;

    int result = countPerms(n);

    cout << result << "\n";

    return 0;
}
