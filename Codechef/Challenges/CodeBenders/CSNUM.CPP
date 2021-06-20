#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        ll sum=0;
        int len = 0;
        while(n){
            sum += n%10;
            n /= 10;
            len++; 
        }

        if(sum%len == 0) cout<<"Good Work\n";
        else cout<<"Try Again\n";
    }
}
