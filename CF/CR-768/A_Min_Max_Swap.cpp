#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n),b(n);

        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        // int ai=0,bi=0;
        // int maxa,maxb;
        // for(int i=0;i<n;i++){
        //     if(a[i] > maxa){
        //         maxa = a[i];
        //         ai = i;
        //     }
        //     if(b[i] > maxb){
        //         maxb = b[i];
        //         bi = i;
        //     }
        // }
        // int ai = max_element(a, a+n) - a;
        // int bi = max_element(b, b+n) - b;


        // if(ai == bi){
        //     cout<<a[ai]*b[bi]<<"\n";
        // }
        // else if(a[ai]==b[bi] || a[bi] == b[bi]){
        //     cout<<a[ai]*b[bi]<<"\n";
        // }
        // else {
            for(int i=0;i<n;i++){
                if(a[i] < b[i]) swap(a[i], b[i]);
            }
            int maxa=0,maxb=0;
            for(int i=0;i<n;i++){
                if(a[i] > maxa){
                    maxa = a[i];
                }
                if(b[i] > maxb){
                    maxb = b[i];
                }
            }
            cout<< maxa*maxb<<"\n";
        // }
    }
}