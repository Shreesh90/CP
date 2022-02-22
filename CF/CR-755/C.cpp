#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int f=1;
        for(int i=0;i<n;i++){
            if(a[i]==b[i]) continue;
            else if(a[i]+1 != b[i]) {f=0; break;}
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
}