#include <bits/stdc++.h>
using namespace std;
void yettwoint(vector<vector<int>>& vec){
    vector<int> v1;
    int a=vec.size();
    for(int i=0;i<a;i++){
        int x,y,z,k=0;
        v1=vec[i];
        x=v1[0];
        y=v1[1];
        if(x==y)
            cout<<0<<endl;
        else {
            if (y > x)
                swap(x, y);
            z=x-y;
            if(z%10==z)
                cout<<1<<endl;
            if (z % 10 != z){
                k=(z-z%10)/10;
                z=z%10;
                z>0?cout<<k+1<<endl:cout<<k<<endl;
            }
        }
    }
}

int main() {
    int x,y;
    vector<vector<int>>vec;
    cin>>x;
    for(int i=0;i<x;i++){
        vector<int> v1;
        for(int j=0;j<2;j++){
            cin>>y;
            v1.push_back(y);
        }
        vec.push_back(v1);
    }
    yettwoint(vec);
    return 0;
}
