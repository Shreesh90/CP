#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;
        string s; cin>>s;

        vector<int> midgrp;
        vector<int> sides;
        vector<int> cut;

        int count=0;
        int flag=0;

        for(int i=0;i<s.size(); i++){
            if(s[i]=='0'){
                count++;
                if(i==0 || i==(s.size()-1)) flag=1;
            }
            if(s[i] == '1' || i==(s.size()-1)){
                if(flag==1){
                    sides.push_back(count);
                } else {
                    if(count > 0) midgrp.push_back(count);
                }
                count=0;
                flag=0;
            }
        }

        if(midgrp.empty()) midgrp.push_back(0);
        if(sides.empty()) sides.push_back(0);

        if(midgrp.empty() && sides.empty()){
            cout<<0<<endl;
            continue;
        }

        else if(sides[0] == s.size()){
            cout<<0<<endl;
            continue;
        }

        sort(midgrp.begin(), midgrp.end(), greater<int>());
        sort(sides.begin(), sides.end(), greater<int>());

        
        int bulbs_mid = accumulate(midgrp.begin(), midgrp.end(), 0);
        int bulbs_side = accumulate(sides.begin(), sides.end(), 0); 
        int bulbs = bulbs_mid + bulbs_side;
       
        vector<int> ::iterator it1 = midgrp.begin();
        vector<int> ::iterator it2 = sides.begin();

        while(k!=0){
        
            if(k%2 != 0){
                cut.push_back(*it2);
                *it2 = 0;
                if(it2 != sides.end()-1) it2++;
                k--;
            } else {
                int curr_side_bulbs = accumulate(sides.begin(), sides.end(), 0);
                if(*it1 > curr_side_bulbs){
                    cut.push_back(*it1);
                    *it1 = 0;
                    if(it1 != midgrp.end()-1) it1++;
                    k -=2;
                } else {
                    cut.push_back(*it2);
                    *it2 = 0;
                    if(it2 != sides.end()-1) it2++;
                    k--;
                }
            }
        }
        
        int maxi = accumulate(cut.begin(), cut.end(), 0);
        int ans;
        ans = bulbs - maxi;

        cout<<ans<<endl;
    }
}

