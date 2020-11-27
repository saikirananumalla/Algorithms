#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class activity{
public:
    int start;
    int finish;
    bool operator<(activity & a){
        return finish<a.finish;
    }
};
void nextperm(int A[]){
    cout<<"The 3! possible permutations are: \n";
    do{
        cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<"\n";
    }
    while (prev_permutation(A,A+3));
    cout<<"After Loop\n";
    cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<"\n";
}
int main() {
    vector<activity> act={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    sort(act.begin(),act.end());
    int j=0;
    cout<<act[j].start<<" "<<act[j].finish<<endl;
    for(int i=1;i<act.size();i++){
        if(act[j].finish<=act[i].start) {
            cout << act[i].start << " " << act[i].finish<<endl;
            j=i;
        }
    }
    int A[]={1,2,3};
    nextperm(A);
    return 0;
}
