#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"q0 is the intial state,q3 and q1 are final state,"<<endl;
    cout<<"q0 is even a final state as epsilon is a part of the language"<<endl;
    cout<<"Enter the string,alphabets are a,b and c:";
    
    string S;
    cin>>S;
    int state = 0;
    for(int i=0;i<S.size();i++)
    {
        
        cout<<S[i]<<" ----> ";
        
        if(i == 0)
        {
            if(S[i] == 'a')
            {
                if(S[i+1] =='a')
                {
                    state = 1;
                    cout<<"From q0 goes to q1"<<endl;
                }
                
                else
                {
                    if(S[i+1] =='b')
                    {
                        state = 2;
                        cout<<"From q0 goes to q2"<<endl;
                    }
                    
                    else
                    {
                        state == -1;
                        cout<<"Goes to trap state"<<endl;
                    }
                }
                
            }
            
            else
            {
                state = -1;
                cout<<"Goes to trap state"<<endl;
            }
            
        }
        
        else
        {
            if(state == 1)
            {
                if(S[i]=='a')
                cout<<"Remains in state q1"<<endl;
                
                else
                {
                    state = -1;
                    cout<<"Goes to trap state"<<endl;
                }
                
            }
            
            else{
                
            
            if(state == 2)
            {
                if(S[i] == 'b')
                {
                    state = 3;
                    cout<<"From q2 goes to q3"<<endl;
                }
                
                else
                {
                    state = -1;
                    cout<<"Goes to trap state"<<endl;
                }
            }
            
            else
            {
                if(state == 3)
                {
                    if(S[i]=='a')
                    {
                        state = 2;
                        cout<<"From q3 goes to q2"<<endl;
                    }
                    
                    else
                    {
                    state = -1;
                    cout<<"Goes to trap state"<<endl;
                    }
                }
                
                else
                {
                    if(state!=1)
                    cout<<"Remains in the trap state"<<endl;
                }
            }
            }
        }
    }
    
    if(state == 3||state == 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}