#include<bits/stdc++.h>
using namespace std;

bool solve(string &s){
    int i=0, j=s.length()-1;
    
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;

        int flag = solve(s);

        if(flag){
            cout<<1<<"\n";
        }
        else {
            if(k==0){
                cout<<1<<"\n";
            }
            else cout<<2<<"\n";
        }
    }
}