#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        map<int, int> mp;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(A[i]) == mp.end()) mp[A[i]] = i;
            else {
                mini = min(mini, i - mp[A[i]]);
                mp[A[i]] = i;
            }
        }
        if(mini == INT_MAX) cout<<-1<<"\n";
        else cout<<n-mini<<"\n";
    }
}