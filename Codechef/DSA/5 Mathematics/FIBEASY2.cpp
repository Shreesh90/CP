#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> fibs;
const long long N = 10000005;

void fib(ll n){
    fibs.pb(0);
    fibs.pb(1);

    ll f0 = 0;
    ll f1 = 1; 

    for(ll i=0; i<n-2; i++){
        ll temp= (f0%10 + f1%10)%10;
        fibs.pb(temp);
        f0 = f1%10;
        f1 = temp;
    }
}

ll power(int x, int n){
    
    // x %= N;
    int ans=1;
    while(n!=0){
        if(n%2 == 1) ans = (ans * x);
        x = (x * x);
        n >>= 1;
    }
    return ans;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    fib(N);
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll k = (long long)log2(n);

        // ll k=0;
        // while(n > 0){
        //     n >>= 1;
        //     ++k;
        // }

        ll index = (ll)power(2, k);
        index = index%N;
        cout<<fibs[index-1]<<"\n";

    }    
}