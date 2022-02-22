#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        int f=1;
        if((a+b)%2 != 0) f=0;

        if(f){
            int sum = (a+b)/2;
            if(sum==0){
                cout<<"0 0\n";
            } else {
                cout<<sum-1<<" "<<1<<endl;
            }
        } else {
            cout<<"-1 -1\n";
        }
    }
}