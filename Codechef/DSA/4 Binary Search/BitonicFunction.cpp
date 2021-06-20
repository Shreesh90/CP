// QUESTION
// There is a point P on x axis with coordinates(x1,0) and (x1 < 1e16)
// You may ask a maximum of 150 queries. Each query is of the form !x2.
// The judge will return the distance between point P and point (x2,0).
// find the value of x1 

#include<iostream>
using namespace std;
// #define int long long
int main()
{
    int x;
    cin>>x;

    int lo = 0;
    int hi = 25; //1e16;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        int d1,d2;
        cout<<"! "<<mid<<endl;
        cin>>d1;
        cout<<"! "<<(mid+1)<<endl;
        cin>>d2;

        if(d1 > d2){
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
}