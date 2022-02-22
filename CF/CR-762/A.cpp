#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        if(n%2==1) cout<<"NO\n";
        else {
            int i=0;
            int j=n/2;
            int f=1;
            while(j!=n){
                if(s[i] != s[j]) {f=0; break;}
                i++;j++;
            }
            if(f) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}