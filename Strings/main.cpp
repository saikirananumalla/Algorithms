#include <iostream>
#include<cstring>
#include<vector>
using namespace std;
class str{
    char *A;
    int len;
    int size;

public:
    str(){
        A= new char(15);
        len=0;
        size=15;
    }
    void take_input(int mlen){
        if(mlen<size) {
            int i;
            cout << "Enter the string here: ";
            for (i = 0; i < mlen; i++)
                cin >> A[i];
            A[i]='\0';
            len=mlen;
            cout<<"\n";
        }

    }
    void changecase(char key){
        if(key == 'l'){
            int i=0;
            while(A[i]!='\0'){
                if((int)A[i]<(int)'a')
                    A[i]=(A[i]-'A'+'a');
                cout<<A[i];
                i++;
            }
        }
    }
    void reverse(){
        for(int i=0,j=len-1;i<j;i++,j--)
            swap(A[i],A[j]);
    }
    void Display(){
        cout<<"The string is: ";
        for(int j=0;j<len;j++)
            cout<<A[j]<<" ";
        cout<<"\n";
    }
    int palindrome(char *s){
        int i=0;
        int j=strlen(s)-1;
        //cout<<strlen(s)<<endl;
        while(i!=j){
            if(s[i]!=s[j])
                return 0;
            i++;
            j--;
        }

        return 1;
    }
    void checkdupli(){
        int h[26]={};
        //h[26]={0};
        int i;
        for(i=0;i<len;i++)
            h[A[i]-'a']++;
        for(int j=0;j<26;j++)
            if(h[j]>1)
                cout<<(char)(j+'a')<<" is repeating "<<h[j]<<" times \n";
    }
    void bitwise(){
        int h=0;int x;
        int i=0;
        while(A[i]!=0){
            x=1;
            x=x<<(A[i]-'a');
            if((x & h) >0)
                cout<<A[i]<<" is duplicate at index "<<i<<endl;
            else
                h=x|h;
            i++;
        }
    }
    int anagram(char *a,char *b){
        if(strlen(a)!=strlen(b))
            return 0;
        int h[26]={};
        int i;
        for(i=0;i<strlen(a);i++)
            h[a[i]-'a']++;
        for(i=0;i<strlen(a);i++)
            h[b[i]-'a']--;
        for(i=0;i<26;i++){
            if(h[i]!=0)
                return 0;
        }
        return 1;

    }
};
void lps(string &exp, int n,vector<int>&a) {
    int len=0;
    a[0]=0;
    int i=1;
    while(i<n){
        cout<<"in while\n";
        if(exp[i]==exp[len]) {
            len++;
            a[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=a[len-1];
            }
            else{
                a[i]=0;
                i++;
            }
        }
    }
}
string lp(string A) {
    int n=A.length(),i,j,d;
    string res;
    if(n==1)return A;
    if(n==2){
        if(A[0]!=A[1]){
            res+=A[0];
            return res;
        }
        else return A;
    }
    int maxi=INT32_MIN,start,end;
    bool l[n][n];
    for(i=0;i<n;i++)
        l[i][i]=true;
    for(i=0;i<n-1;i++){
        if (A[i] == A[i + 1]){
            l[i][i + 1] = true;
            start = i;
            maxi = 2;
            end=i+1;
            cout<<" IF Two chars "<<start<<" "<<maxi<<endl;
        }
        else {
            l[i][i + 1] = false;
            cout<<"ELSe of two chars"<<endl;
        }
    }
    for(d=3;d<=n;d++){
        for(i=0;i<n-d+1;i++){
            j=i+d-1;
            if(A[i]==A[j] && l[i+1][j-1]){
                l[i][j]=true;
                if(d>maxi){
                    start =i;
                    maxi=d;
                    end=j;
                    cout<<"maxlen="<<d<<" "<<start<<" "<<maxi<<"j is "<<j<<endl;
                }
            }
            else l[i][j]=false;
        }
    }
    for(i=start;i<=end;i++){
//        cout<<A[i];
        res+=A[i];
    }
    return res;
}
void showvector(vector<unsigned long long int> v){
    int i=0;
    for(i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int compareVersion(string A, string B) {
    vector<unsigned long long int> av;
    unsigned long long int a=A.length(),b=B.length();
    vector<unsigned long long int>bv;
    if(a==0 && b>0) return -1;

    for(unsigned long long int i=0;i<a;i++){
        string res;
        while(isalnum(A[i])){
            if(res.length()<=16)res+=A[i];
            i++;
        }
//        cout<<1<<endl;
        av.push_back(stoull(res));
    }
    for(unsigned long long int i=0;i<b;i++){
        string res;
        while(isalnum(B[i])){
            if(res.length()<=16)res+=B[i];
            i++;
        }
        bv.push_back(stoull(res));
    }
    showvector(av);
    showvector(bv);
    unsigned long long int p=av.size(),q=bv.size();
    unsigned long long int i=0,j=0;
    while(i<p && j<q){
        if(av[i]==bv[j]){
            i++;
            j++;
        }
        else if(av[i]>bv[j])return 1;
        else return -1;
    }

    if(p-i)return 1;
    if(q-j)return -1;
    if(i==p && j==q) return 0;
}


int main() {
    str str;
//  str.take_input(7);
//  str.bitwise();
//    str.changecase('l');
//    str.Display();
//    str.reverse();
//    str.Display();
//    char *name="saias";
//    if(str.palindrome(name)==1)
//        cout<<"This string is a plaindrome\n";
//    if(str.palindrome(name)==0)
//        cout<<"This string isn't a plaindrome\n";
//    str.checkdupli();
//    char *a="sai";
//    char *b="ias";
//   if( str.anagram(a,b)==1)
//       cout<<"The strings are anagram\n";
//    if( str.anagram(a,b)==0)
//        cout<<"The strings aren't anagram\n";
////    string pat="abacdfgdcaba";
//    string pat="abbcccbbbcaaccbababcbcabca";
//    vector<int>c(pat.length());
//    lps(pat,pat.length(),c);
//    string c=lp(pat);
//    cout<<c<<endl;
//    string hq="Word1  ";
//    int i=0,index=0;
//    int n=hq.length();
//    string polis;
//    int k=0,p;
//    if(hq[0]==' ') {
//        k++;
//        while (hq[k] == ' ')
//            k++;
//    }
//    while(k<n){
//        if(hq[k]==' ' && k!=n-1){
//            polis+=hq[k];
//            k++;
//            while(hq[k]==' ')
//                k++;
//        }
//        else{
//            polis+=hq[k];
//            k++;
//        }
//    }
//    cout<<polis<<endl;
//    p=polis.length();
//    cout<<p<<endl;
//    while(i<p){
//        if(polis[i]==' '&& i!=p-1){
//                index=i;
//        }
//        i++;
//    }
//    cout<<index<<endl;
////    cout<<hq.length()<<endl;
//    int count=0;
//    if(index==0 && polis[p-1]!=' ')cout<< p;
//    else if(index==0) cout<< p-1;
//    else{
//        do{
//            count++;
//            index++;
//        }
//        while(index!=p && polis[index]!=' ');
//        cout<<count-1;
//    }
//    string ver="1.3.24";
//    cout<<"1"<<endl;
//    for(int l=0;l<ver.length();l++)cout<<ver[l]<<" "<<endl;
//    cout<<"\n"<<compareVersion("8.88888888888888888888888888888","8.888888888888888")<<endl;
cout<<"\n"<<compareVersion("01","1");
return 0;
}
