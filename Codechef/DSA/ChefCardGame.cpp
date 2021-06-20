#include <bits/stdc++.h>
using namespace std;

int power(string q){
    long sum=0;
    for(int i=0;i<q.size();i++){
        sum += q[i]; 
    }
    return sum;
}

int main() {
	int t,n;
	int A=0,B=0;
	string x,y;
	cin>>t;
	while(t--){
	    cin>>n;
	    A=0;B=0;
	    while(n--1){
    	    cin>>x>>y;
    	    long int powerA = power(x);
    	    long int powerB = power(y);
    	    cout<<powerA<<" "<<powerB;
            // if(powerA > powerB)
    	    //     A++;
    	    // else if(powerA < powerB)
    	    //     B++;
    	    // else{
    	    //     A++;B++;
    	    // }
	    }
	    // if(A > B){
	    //     cout<<0<<" "<<A<<endl;
	    // }
	    // else if(A < B){
	    //     cout<<1<<" "<<B<<endl;
	    // }
	    // else{
	    //     cout<<2<<" "<<A<<endl;
	    // }
	}
}
