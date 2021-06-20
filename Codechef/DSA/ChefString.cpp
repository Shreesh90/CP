#include <bits/stdc++.h>
using namespace std;
#include<string>
#include<sstream>

int main() {
	int t,n;
	cin>>t;
	
	while(t--){
	    cin>>n;
	    string c[n];
	    for(int i=0;i<n;i++){
	        cin>>c[i];
	    }
	    long int sum=0;
	    
	    for(int i=0;i<n-1;i++){
	        stringstream one(c[i+1]);
	        stringstream two(c[i]);
	        int x=0,y=0;
	        one >> x;
	        two >> y;
	        sum += abs(x - y)-1;
	    }
	    cout<<sum<<endl;
	}
}
