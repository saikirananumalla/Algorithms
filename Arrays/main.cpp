#include <iostream>
using namespace std;
class Array{
private:
    int* A;
    int size;
    int len;
public:
    Array(){
        size=10;
        A=new int(size);
        len=0;
    }
    Array(int siz){
        size=siz;
        A=new int(size);
        len=0;
    }
    ~Array(){
        delete [] A;
    }
    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index,int x);
    int* MaxMin();
    //int Sum();
    //float Avg();
    void Reverse();
    //void Reverse2();
    //void InsertSort(int x);
    bool isSorted();
//    void Rearrange();
//    Array* Merge(Array arr2);
//    Array* Union(Array arr2);
//    Array* Diff(Array arr2);
//    Array* Inter(Array arr2);
//    void missele();
    int mlsub(int sum);
};

void Array::Display() {
    cout<<"Display result:";
    for(int i=0;i<len;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void Array::Append(int x) {
    if(len<size)
        A[len++]=x;
}

void Array::Insert(int index, int x) {
    if(index>=0 && index<=len){
        for(int i=len;i>index;i--)
            A[i]=A[i-1];
        A[index]=x;
        len++;
    }
}

int Array::Delete(int index) {
    if(index>=0 && index<=len){
        int x = A[index];
        for(int i=index;i<len-1;i++)
            A[i]=A[i+1];
        len--;
        return x;
    }
}

int Array::LinearSearch(int key) {
    for(int i=0;i<len;i++){
        if(A[i]==key){
            //swap(A[i],A[0]);
            return i;
        }

    }
    return -1;
}

int Array::BinarySearch(int key) {
    int l=0;
    int h=len-1;
    int mid=0;
    while (l<=h){
        mid=(l+h)/2;
        if(A[mid]==key) {
            return mid;
        }
        if(A[mid]>key){
            h=mid-1;
        }
        if(A[mid]<key)
            l=mid+1;
    }
    for(int i=0;i<len;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return -1;
}

int Array::Get(int index) {
    if (index>=0 && index<len)
        return A[index];
    return -1;
}

void Array::Set(int index, int x) {
    if(index>=0 && index< len)
        A[index]=x;
}

int* Array::MaxMin() {
    int *B = new int(2);
    int max=A[0],min=A[0];
    for(int i=0;i<len;i++){
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
    }
    B[0]=max;B[1]=min;
    return B;
}

void Array::Reverse() {
    int i,j;
    for(i=0,j=len-1;i<j;i++,j--)
        swap(A[i],A[j]);
}
bool Array::isSorted()
{
    int i;
    for(i=0;i<len-1;i++)
    {
        if(A[i]>A[i+1])
            return false;
    }
    return true;
}

int Array::mlsub(int sum) {
    int s=0;
    int cs=A[0];
    int min=len;
    for(int i=1;i<=len;i++){
        while(cs>sum && s<len-1){
            cs-=A[s];
            s++;
        }
        if(cs==sum){
            cout<<"Elements found between "<<s<<" and "<<i-1<<endl;
            min=i-s;
            cs-=A[s];
            s++;
        }
        if(i<len)
            cs+=A[i];

    }
    return min;
}
//
//void Array::missele() {
//    int i=0;
//    while((A[i]-10)%10 == i)
//        i++;
//    if(i!=len)
//        Insert(i,i*10+10);
//
//}

int main() {
    Array a(20);
    a.Append(10);
    a.Append(20);
    a.Append(30);
    a.Append(40);
    a.Append(50);
    a.Display();
    a.Insert(5,70);
    a.Display();
    a.Insert(5,60);
    a.Display();
    a.Append(80);
    a.Display();
    if(a.Delete(7)>=0)
        cout<<"index 7 element is deleted\n";
    a.Display();
    cout<<a.LinearSearch(40)<<" LS is the location of 40\n";
    a.Display();
    if(a.isSorted())
        cout<<a.BinarySearch(10)<<" BS is the location of 10\n";
    int *b;
    b=a.MaxMin();
    cout<<*b<<","<<*(b+1)<<" are the MAX and MIN respectively\n";
    a.Reverse();
    a.Reverse();
    a.Display();

    a.Display();
    cout<<a.mlsub(60);
    return 0;
}
