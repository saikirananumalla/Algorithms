#include <bits/stdc++.h>
using namespace std;
void yettwoint(vector<vector<long int>>& vec){
    vector<long int> v1;
    int a=vec.size();
    int times;
    for(int i=0;i<a;i++){
        v1=vec[i];
        times=v1[4];
        if(v1[1]>v1[0]) {
            if(v1[2]==2) {
                swap(v1[1], v1[0]);
                swap(v1[3], v1[2]);
            }
        }
        while (v1[1] > v1[3] && times > 0){
            v1[1]--;
            times--;
        }
        while(v1[0]>v1[2] && times>0){
            v1[0]--;
            times--;
        }
        cout<<v1[0]<<endl;
        cout<<v1[1]<<endl;
        cout<<v1[0]*v1[1]<<endl;
    }
}

int main() {
    int x,y;
    vector<vector<long int>>vec;
    cin>>x;
    for(int i=0;i<x;i++){
        vector<long int> v1;
        for(int j=0;j<5;j++){
            cin>>y;
            v1.push_back(y);
        }
        vec.push_back(v1);
    }
    yettwoint(vec);
    return 0;
}
