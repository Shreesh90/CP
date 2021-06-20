#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int x1,y1,x2,y2,x3,y3;

    int lo = 0;
    int hi = 1000;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        cout<<"? "<<mid<<" "<<0<<endl;
        string ans;
        cin>>ans;
        if(ans == "YES"){
            lo = mid + 1;
            x1 = mid;y1=0;
        } else {
            hi = mid-1;
        }
        fflush(stdin);
    }

    lo=0; hi=1000;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        cout<<"? "<<mid<<" "<<2*x1<<endl;
        string ans;
        cin>>ans;
        if(ans == "YES"){
            lo = mid+1;
            x2=mid; y2=2*x1;
        } else {
            hi = mid-1;
        }
        fflush(stdin);
    }

    lo=0; hi=1000;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        cout<<"? "<<0<<" "<<mid<<endl;
        string ans;
        cin>>ans;
        if(ans == "YES"){
            lo = mid+1;
            x3=0; y3=mid;
        } else {
            hi = mid-1;
        }
        fflush(stdin);
    }

    int square = 4*x1*x1;
    int triangle = 0.5*(2*x2)*(y3-y2);

    int area = square+triangle;
    cout<<"! "<<area;
}