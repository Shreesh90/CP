#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n);

        for(int i=0;i<n;i++) cin>>A[i];
        
        int maxi = 0;
        int ret = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, A[i]);
            if(maxi == i+1) ret++;
        }
        cout<<ret<<"\n";
    }
}