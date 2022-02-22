#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> &A){
    ll ret = A.size();
    for(int i=0;i<A.size();i++){
        if(A[i] == 0) ret++;
    }
    return ret;
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> A(n);
        for(int i=0;i<n;i++) cin>>A[i];

        int ret = 0;
        for(int i=0;i<n;i++){
            vector<ll> temp;
            for(int j=i;j<n;j++){
                temp.push_back(A[j]);
                ret += solve(temp);
            }
        }
        cout<<ret<<endl;
    }
}