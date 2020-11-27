//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int partition(int A[],int l,int  h){
    int pivot=A[l];
    int i=l;
    int j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        while (A[j]>pivot)
            j--;
        if(i<j)swap(A[i],A[j]);
    }
    while(i<j);
    swap(A[l],A[j]);
    return j;
}
void merge(int A[],int l,int mid,int h){
    int i=l,j=mid+1,k=1;
    int *B=new int[h+1];
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    for(;i<mid;i++)
        B[k++]=A[i++];
    for(;j<h;j++)
        B[k++]=A[j++];
}
void Quicksort(int A[],int l,int h){
    if(l<h){
       int j=partition(A,l,h);
        Quicksort(A,l,j-1);
        Quicksort(A,j+1,h);
    }
}
void iQuicksort(int A[],int l,int h){
//    stack<int> stk;
    queue<int> stk;
    stk.push(h);
    stk.push(l);
    while(!stk.empty()){
        h=stk.front();
        stk.pop();
        l=stk.front();
        stk.pop();
        int p=partition(A,l,h);
        if(p-1>l){
            stk.push(p-1);
            stk.push(l);
        }
        if (p+1<h){
            stk.push(h);
            stk.push(p+1);
        }
    }
}
void imergesort(int A[],int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p*=2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        merge(A,0,p/2-1,n-1);
}
void mergesort(int A[],int l, int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(A,l,mid);
        mergesort(A,mid+1,h);
        merge(A,l,mid,h);
    }
}
int main() {
//    int key,j;
//    int A[]={10,5,12,9,7,5};
//    int n=sizeof(A)/sizeof(A[0]);
//    iQuicksort(A,0,5);
//    for(int i:A)
//        cout<<i<<" ";
//    cout<<endl;
//    imergesort(A,6);
//    for(int i:A)
//        cout<<i<<" ";
//    cout<<endl;
//    mergesort(A,0,5);
//    for(int i:A)
//        cout<<i<<" ";
//bubble
//    for(int i=0;i<n;i++)
//        for(int j=i+1;j<n;j++){
//            if(A[i]>A[j])
//                swap(A[i],A[j]);
//        }
//insertion
//    for(int i=1;i<n;i++){
//        key=A[i];
//        j=i-1;
//        while (j>=0 && A[j]>key){
//            A[j+1]=A[j];
//            j--;
//        }
//        A[j+1]=key;
//    }
//count
//    int max=0;
//    for(int i=0;i<n;i++) {
//        if (A[i] > max)
//            max = A[i];
//    }
//    int *count;
//    count=new int[max+1];
//    for(int i=0;i<n;i++)
//        count[A[i]]++;
//    int i=0;
//    int k=0;
//    while(k<max+1){
//        if(count[k]>0){
//            A[i++]=k;
//            count[k]--;
//        }
//        else{
//            k++;
//        }
//    }
//    for(int i:A)
//        cout<<i<<" ";
    vector<int> A = {0,8,8,1,7,2,1,3,5,9};
    if (A.back() != 9) {
        int temp = A.back();
        A.pop_back();
        A.push_back(temp + 1);
        int i=0;
        while(A[i]==0){
            cout<<i<<A[i]<<endl;
            A.erase(A.begin());
        }
    } else {
        int sz = A.size();
        int i = sz - 1;
        while (A[i] == 9 && i >= 0) {
            A[i] = 0;
            i--;
        }
        cout<<i<<" i"<<endl;
        if (i != -1 && A[i] < 9)
            A[i]++;
        else if (i == -1) {
            A.resize(sz + 1);
            A[0] = 1;
            for (int k = 1; k < A.size() - 1; k++)
                A[k] = 0;
        }
    }
    for(int i:A)
        cout<<i<<" ";
    return 0;
}
