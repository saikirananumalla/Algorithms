#include <bits/stdc++.h>
using namespace std;

int scatterPalindrom(string s)
{
    int n = s.size();
    int ans = 0;
    vector<int>A(n+1,0);

    for(int i=1;i<=n;i++)
    {
        A[i] = A[i-1] ^ (1<<(s[i-1]-'a'));
    }
    int x;
    unordered_set<string>st;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            x = A[j]^A[i-1];
            if((x &(x-1) )==0)
            {
                if(st.count(s.substr(i-1,j-i+1))==0)
                {
                    cout<<s.substr(i-1,j-i+1)<<endl;
                     st.insert(s.substr(i-1,j-i+1));
                    ans++;
                }
               
                
            }
        }
    }
    return ans;
}
int main()
{
    cout<<scatterPalindrom("aabb")<<endl;
    
    return 0;
}