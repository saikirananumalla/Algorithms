#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll magic(ll x){
    ll prev=x%2;
    x=x/2;
    while(x){
        ll now=x%2;
        if((now==0 && prev==0) || (now==1 && prev==1))return 0;
        prev=now;
        x=x/2;
    }
    return 1;
}

int main(){
    while(true){
        ll x;
        cin>>x;
        if(x==0)break;
        (magic(x)==0)?cout<<"No No"<<endl : cout<<"Yes Yes"<<endl;
    }
    return 0;
}