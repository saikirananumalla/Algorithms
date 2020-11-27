#include <iostream>
//REcursions hEre!
using namespace std;
template <class T>
class Recursions{
public:
    int sum(int key, int n);
    int isum(int key, int n);
    int fibo(int key);
    int fibomemo(int key);
    void hrc(int key);
    T taylor(T key,T n);
    T hornertaylor(T key,T n);
    void cbyref(int &x,int &y);
    void toh(int n,char from_rod,char to_rod,char aux_road);
};
template <class T>
int Recursions<T>::sum(int key,int n){
    static int count=n;
    if(key==n)
        return count;
    else{
        count+=key;
        sum(key+1,n);
    }
}
template <class T>
int Recursions<T>::isum(int key, int n){
    int count=n;
    while(key!=n){
        count+=key;
        key++;
    }

    return count;
}
template <class T>
int Recursions<T>::fibo(int key) {
    if(key<2)
        return key;
    return fibo(key-1)+fibo(key-2);
}
template <class T>
int Recursions<T>::fibomemo(int key) {
    int Fib[20]={};
    Fib[0]=0;Fib[1]=1;
    if (key<2)
        return key;
    if(Fib[key]!=0)
        return Fib[key];
    Fib[key]=fibomemo(key-1)+fibomemo(key-2);
    return Fib[key];

}
template <class T>
void Recursions<T>::hrc(int key) {
    if(key==10)
        cout<<10<<"|";
    if(key<10){
        hrc(key+1);
        cout<<key<<"|";
    }
}
template <class T>
T Recursions<T>::taylor(T key, T n) {
    static T num=1,den=1,pre;
    if(n==0)
        return 1;
    pre=taylor(key,n-1);
    num=num*key;
    den=den*n;
    return pre+num/den;
}

template<class T>
void Recursions<T>::cbyref(int &x, int &y) {
    int temp=x;
    x=y;
    y=temp;
}

template<class T>
T Recursions<T>::hornertaylor(T key, T n) {
    T sum=1;
    for(int i=n;i>0;i--)
        sum=1+key/i*sum;
    return sum;
}

template<class T>
void Recursions<T>::toh(int n, char from_rod, char to_rod, char aux_road) {
    if (n==1){
        cout<<"Move Disk From"<<from_rod<<"To"<<to_rod<<endl;
        return;
    }
    toh(n-1,from_rod,aux_road,to_rod);
    cout<<"Move Disk From"<<from_rod<<"To"<<to_rod<<endl;
    toh(n-1,aux_road,to_rod,from_rod);
}

int main() {
    int a=10,b=20;
    Recursions<float> r;
    //cout<<r.isum(1,100)<<endl;
    //cout<<r.fibomemo(6)<<endl;
    r.hrc(1);
    cout<<"\n";
    cout<<r.taylor(1,3)<<endl;
    cout<<r.hornertaylor(1,3)<<endl;
    r.cbyref(a,b);
    cout<<a<<"->"<<b<<endl;
    r.toh(3,'A','B','C');
}
