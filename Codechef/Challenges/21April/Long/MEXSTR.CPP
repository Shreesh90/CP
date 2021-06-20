#include<bits/stdc++.h>
using namespace std;
#define ll long long
string cnt = "";
int ret = 0;

// ll lcs(string s, string ans, vector<vector<int> > &dp, ll n, ll m){
//     if(n==0 || m==0) return 0;

//     if(dp[n][m] != -1) return dp[n][m];

//     if(ans[n-1] == s[m-1]){
//         return dp[n][m] = 1 + lcs(s, ans, dp, n-1, m-1);
//     }
//     else
//         return dp[n][m] = max(lcs(s, ans, dp, n, m-1), lcs(s, ans, dp, n-1, m));
// }  

bool subs(string s, string ans){
    int j=0;
    for(int i=0;i<s.length();i++){
        if(ans[j] == s[i]) j++;
        if(j == ans.length()) return true;
    }
    return false;
}

void binstrs(ll n, vector<char> &temp, int i, string s){
    if(ret == 1) return;
    if(i == n){
        string ans = "";
        int flag=0;
        
        for(char c:temp){
            if(c != '0') flag=1;
            if(flag) ans += c;
        }

        if(ans == "") ans = "0";
        
        // vector<vector<int> > dp(ans.length()+1, vector<int> (s.length()+1, -1) ) ;
        // ll t = lcs(s, ans, dp,  ans.length(), s.length() );
        // vector<vector<int> > f;
        // if(dp[ans.length()][s.length()] != ans.length() && ret == 0){ cnt = ans; ret = 1;}

        if(!subs(s, ans) && ret==0) { cnt = ans; ret = 1;}
        return;
    }
    
    temp[i] = '0';
    binstrs(n, temp, i+1, s);

    temp[i] = '1';
    binstrs(n, temp, i+1, s);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll t; cin>>t;
    while(t--){
        string s; cin>>s;
    
        ll n = s.length();
        vector<char> temp(n);
        ret = 0;

        binstrs(n, temp, 0, s);
        
        cout<<cnt<<endl;
    }
    return 0;
}