#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        int i=1;
        while(i<n && s[i]<s[0] && s[i] <= s[i-1]) i++;
        // while(i<n && s[i] == s[i-1]) i++;
        string temp = s.substr(0, i);
        string ret = temp;
        reverse(temp.begin(), temp.end());
        ret += temp;
        cout<<ret<<"\n";

    }
}