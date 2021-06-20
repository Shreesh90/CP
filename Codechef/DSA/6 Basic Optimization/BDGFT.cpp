#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int t; cin>>t;

    while(t--){
        string s;
        cin>>s;
        // cout<<s.length();
        vector<int> fone;
        vector<int> fzero;

        fone.pb(0);
        fzero.pb(0);

        if(s[0] == '0') {fzero.pb(1); fone.pb(0);}
        else { fone.pb(1); fzero.pb(0); }

        for(int i=1;i<s.size(); i++){
            if(s[i] == '0'){
                fzero.pb(fzero[i] + 1);
                fone.pb(fone[i]);
            }
            else{
                fone.pb(fone[i] + 1);
                fzero.pb(fzero[i]);
            }
        }

        for(int i=0;i<s.length() + 1; i++){
            cout<<fzero[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<s.length() + 1; i++){
            cout<<fone[i]<<" ";
        }
        
        
        int ans = 0;
        int j=1, k=2;
        while(j <= k && k<=s.length() && j<=s.length()){
            int zero = fzero[k] - fzero[j-1];
            int one = fone[k] - fone[j-1];
            if(zero == one*one) {
                ans++;
                k++;
            }
            else if(zero > one*one){
                if(one == 0){
                    j++; k++;
                }
                else j++;
            }
            else if(zero < one*one){
                if(zero = 0){
                    j++; k++;
                }
                else k++;
            }
        }

        // cout<<ans<<endl;

    }

}

