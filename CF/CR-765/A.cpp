#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;

        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        int ret = 0;
        for(int i=0;i<32;i++){
            int zeros=0, ones=0;
            for(int j=0;j<n;j++){
                if(v[j] & (1<<i)) ones++;
                else zeros++;
            }
            if(ones>=zeros){
                ret |= 1<<i;
            }
        }
        cout<<ret<<"\n";
    }
}
