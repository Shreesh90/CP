#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n),b(n);

        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        int ai = max_element(a, a+n) - a;
        int bi = max_element(b, b+n) - b;


        if(ai == bi){
            cout<<a[ai]*b[bi];
        }
        else if(a[ai]==b[bi] || a[bi] == b[bi]){
            cout<<a[ai]*b[bi];
        }
        else {
            for(int i=0;i<n;i++){
                if(a[i] < b[i]) swap(a[i], b[i]);
            }
            int maxa = *max_element(a,a+n);
            int maxb = *max_element(b,b+n);
            cout<<maxa*maxb;
        }
    }
}