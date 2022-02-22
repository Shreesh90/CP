#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        map<int, int> mp;
        for(int i=0;i<n;i++){
            int x; cin>>x;
            A.push_back(x);
            mp[x]++;
        }

        int ret = mp.size();
        for(auto it: mp){
            if(it.second>1 && mp.find(-1 * it.first) == mp.end() && it.first!=0) ret++;
        }
        // if(mp.find(0) != mp.end() && mp[0] > 1) ret--;
        cout<<ret<<"\n";
    }
}