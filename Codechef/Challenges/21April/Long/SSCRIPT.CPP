#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<char> a(n);
        int count=INT_MIN;
        int temp=0;
        for(char &c: a){
            cin>>c;
            if(c == '*') temp++;
            if(c != '*'){
                count = max(count, temp);
                temp=0;
                
            }
        }
        count = max(count, temp);

        if(count >= k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}