#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,x;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>x;

        int rev[100000]; //= {-1};
        for(int i=0;i<100000;i++)
            rev[i] = -1;
        int j=0;
        while(x != 0){
            int units = x%10;
            rev[j++] = units;
            x = (x - units)/10;
        }

        j=0;
        while(rev[j] == 0){
            j++;
        }

        while(rev[j] != -1){
            cout<<rev[j++];
        }

        cout<<endl;
    }

    return 0;
}
