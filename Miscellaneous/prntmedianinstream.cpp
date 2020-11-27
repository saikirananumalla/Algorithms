#include<bits/stdc++.h>
using namespace std;

void printMedians(double arr[],int n){
	priority_queue<double>sml;
	priority_queue<double,vector<double>,greater<double>>grt;

	double median=arr[0];
	cout<<median<<" ";
	sml.push(arr[0]);
	for(int i=1;i<n;i++){
		double x=arr[i];

		if(sml.size()>grt.size()){
			if(x<median){
				grt.push(sml.top());
				sml.pop();
				sml.push(x);
			}
			else{
				grt.push(x);
			}
			median=(sml.top()+grt.top())/2.0;

		}

		else if(sml.size()==grt.size()){
			if(x<median){
				sml.push(x);
				median=sml.top();
			}
			else{
				grt.push(x);
				median=grt.top();
			}

		}
		else{
			if(x>median){
				sml.push(grt.top());
				grt.pop();
				grt.push(x);
			}
			else{
				sml.push(x);
			}
			median=(sml.top()+grt.top())/2.0;
		}

		cout<<median<<" ";
	}
	cout<<endl;
}

int main(){
    double arr[] = {1,2,3,4}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMedians(arr, n); 
    return 0; 

}