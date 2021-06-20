#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int k=0;
        string ans = "";
        if(s.length() < 5){
            ans = s;
        }
        else {
            for(int i=0;i<=s.size()-1;i += k){
                string subs = s.substr(i,5);
                // cout<<subs<<endl;
                if(subs == "party"){
                    ans += "pawri";
                    k=5;
                }
                else{
                    ans += s[i];
                    k = 1;
                }
            }
        }
        cout<<ans<<endl;
    }
}