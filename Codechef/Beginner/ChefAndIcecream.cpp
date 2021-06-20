#include<bits/stdc++.h>
using namespace std;
#include<map>

int main()
{
    int t,n;
    cin>>t;
    
    while(t--){
        cin>>n;
        int p[n];
        for(int i=0;i<n;i++)
            cin>>p[i];
        int m[20]={0};
        int check=0,counter=0;
        for(int i=0;i<n;i++){
            check = 0;
            
            if( p[i]==5 ){
                m[5]++;
                counter++;
                check=1;;
            }

            else if( p[i]==10 && (m[5] >= (p[i] - 5)/5) ){
                m[10]++;
                m[5] -= (p[i] - 5)/5;
                counter++;
                check=1;
            }


            else if( p[i]==15 ){
                if(m[10]>=1){
                    m[15]++;
                    m[10]--;
                    counter++;
                    check=1;
                }
                else if(m[5]>=2){
                    m[15]++;
                    m[5] -= 2;
                    counter++;
                    check=1;
                }    
            }
            
            if(check==0){
                cout<<"NO"<<endl;
                break;
            }
        }
        
        if(counter==n && check=1)
            cout<<"YES"<<endl;
    }
}
