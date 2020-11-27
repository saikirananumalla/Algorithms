#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void showvector(vector<int>& vec){
    cout<<"Max Heap is: [";
    for(int i=0;i<vec.size();i++)
        cout<<"|"<<vec[i];
    cout<<"]";
    cout<<endl;
}
void heapify(vector<int>& vec){
    int n=vec.size(),j;
    for(int i=(n/2)-1;i>=0;i--){
        j=2*i+1;
        while(j<n-1){
            if(vec[j]<vec[j+1])
                j=j+1;
            if(vec[i]<vec[j]){
                swap(vec[i],vec[j]);
                i=j;
                j=2*i+1;
            }
            else
                break;
        }
    }
}
void Insert(vector<int>& vec,int key){
    auto i=vec.size();
    vec.push_back(key);
    while(i>0 && key>vec[i%2==0?(i/2)-1:(i/2)]){
        swap(vec[i],vec[i%2==0?(i/2)-1:(i/2)]);
        i=i%2==0?(i/2)-1:(i/2);
    }
}
void createHeap(vector<int>&vec,int A[],int n){
    for(int i=0;i<n;i++)
        Insert(vec,A[i]);
}
void del(vector<int>& vec,int n){
    swap(vec.front(),vec[n-1]);
    int i=0,j=1;
    while(j<n-1) {
        if(j!=n-2)
            if (vec[j] < vec[j + 1])
            j = j + 1;
        if (vec[i] < vec[j]) {
            swap(vec[i], vec[j]);
            i = j;
            j = 2 * i + 1;
        } else
            break;
    }
}
int main() {
//    vector<int> v={20,25,30,10,12,16,19};
//    vector<int>::iterator it;
//    make_heap(v.begin(),v.end());
//    sort_heap(v.end(),v.begin());
//    for(auto x:v)
//        cout<<x<<"|";
//    pop_heap(v.begin(),v.end());
//    v.pop_back();
//    cout<<endl;
//    for(auto x:v)
//        cout<<x<<"|";
//    v.push_back(40);
//    is_heap(v.begin(),v.end())?cout<<"\nyes":cout<<"\nno";
//    auto it1 = is_heap_until(v.begin(),v.end());
//    cout<<endl;
//    for(it=v.begin();it<it1;it++)
//        cout<<*it<<"|";
//    auto f=find(v.begin(),v.end(),12);
//    int index=distance(v.begin(),f);
//    cout<<"\n"<<index<<"is index of 12";
//      vector<int> v={30,20,25,10,12,16,19};
//      showvector(v);
//      Insert(v,40);
//      showvector(v);
//      cout<<endl;
//      cout<<"Creating Heap\n";
//      vector<int>v1;
//      int A[]={10,12,16,19,20,25,30};
//      int n=sizeof(A)/sizeof(A[0]);
//      createHeap(v1,A,n);
//      showvector(v1);
      vector<int> v2;
      v2={10,11,12,13,14,15,16,17,18};
      heapify(v2);
      showvector(v2);
    for (int (i) = v2.size(); (i) >0 ; i--) {
        del(v2,i);
    }
      showvector(v2);
    vector<int>vector;
    vector={20,16,19,10,11,12,13,14,15};
    make_heap(vector.begin(),vector.end(),greater<int>());
    showvector(vector);
      return 0;
}
