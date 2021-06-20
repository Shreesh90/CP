#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        stack<char> ch;
        ll count=0;
        int freq = 0 ;
        for(int i=0;i<s.size(); i++){
            if(s[i] == 60){
                // ch.push('<');
                freq++;
            } 
            else if(s[i] == 62) {
                freq--;
                // if(ch.empty() || ch.top() == 62){
                //     freq--;
                // }
                // else if(ch.top() == 60){
                //     count++;
                //     ch.pop();
                //     freq--;
                // } 
            }
            if(freq < 0)
                break;
            if(freq == 0){
                count = i+1;
            }
        }
        cout<<count<<"\n";
    }
}