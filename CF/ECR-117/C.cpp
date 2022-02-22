#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        ll k, x;
        cin>>k>>x;
        ll count=0;
        ll sum=0;
        ll adder=1;
        ll dir=1;
        while(sum < x){
            count++;
            sum += adder;
            if(adder < k && dir==1) adder++;
            else if(adder == k && dir==1) {adder--; dir=0;}
            else if(adder < k && dir==0) adder--;
            if(adder==0) break;
        }
        cout<<count<<endl;
    }
}