#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;

        bool ret = false;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1' && !ret){
                ret = true;
                count++;
            }
            else if(s[i] == '0') ret = false;
        }
        
        cout<<count<<"\n";
    }
}
