#include<bits/stdc++.h>
using namespace std;


void display(int set,int n){
	for(int i=0;i<n;i++){
		if(set & (1<<i)){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}


void remove(int& set,int v){

	set = set ^ (1<<(v));
}

void add(int& set,int v ){
	set = set | (1<<(v));
}


int main(){
	int n=10;

	int set=(int)pow(2,n)-1;

	display(set,n);

	remove(set,3);

	display(set,n);

	add(set,3);

	display(set,n);

	return 0;

}