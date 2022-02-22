#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t; cin>>t;
    while(t--){
        string temp;
        cin>>temp;

        int idx = 0;
        for(int i=0;i<temp.length()-1;i++){
            int a = temp[i] - '0';
            int b = temp[i+1] - '0';
            if(a+b>9) idx = i;
        }

        string ans;
        for(int i=0;i<idx;i++){
            ans += temp[i];
        }
        int a = temp[idx] - '0';
        int b = temp[idx+1] - '0';

        ans += to_string(a+b);
        for(int i=idx+2;i<temp.length();i++) ans += temp[i];
        cout<<ans<<"\n";

    }
}