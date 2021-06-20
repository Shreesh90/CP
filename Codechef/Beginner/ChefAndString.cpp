#include<bits/stdc++.h>
using namespace std;
#include<string>
#include<map>

int main()
{
    int t;

    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int f[2]={0};

        for(int i=0;i<s.size();i++){
            if(s[i] == 'x')
                f[0]++;
            else
                f[1]++;
        }
        int pair=0;
        while(f[0] && f[1]){
            f[0]--;
            f[1]--;
            pair++;
        }
        cout<<pair<<endl;
    }
}



