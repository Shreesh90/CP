#include<bits/stdc++.h>
using namespace std;
#include<string>
#include<map>

int main()
{
    int t;
    cin>>t;

    for(int j=0;j<t;j++){
        string s;
        cin>>s;

        int size = s.size();
        int mid = s.size() / 2;
        
        int s1[200]={0},s2[200]={0};
        
        for(int i=0;i<=mid-1;i++){
            s1[(int)s[i]]++;
        }

    if(size%2 == 0){
        for(int i=mid;i<size;i++){
            s2[(int)s[i]]++;
        }
    }
    else{
         for(int i=mid+1;i<size;i++){
            s2[(int)s[i]]++;
        }
    }

        int check=0;
        for(int i=60;i<200;i++){
            if(s1[i] != s2[i]){
                cout<<"NO"<<endl;
                check=1;
                break;
            }
        }
        if(check==0)
            cout<<"YES"<<endl;

    }
}



