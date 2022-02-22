#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;i++) cin>>A[i];

        int cnt=0;
        int idx=n-1;

        while(idx!=0){
            while(idx > 0 && A[idx]==A[idx-1]) idx--;
            int len = n-idx;
            if(len==n) break;
            cnt++;
            int i=max(0, idx-len);
            int j=n-len;
            int d = len;
            while(d--){
                A[i++] = A[j++];
            }
        }
        cout<<cnt<<"\n";
    }
}