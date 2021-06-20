// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
#include<vector>
#include<algorithm>

// lower_bound(x) - We have a monotonic function f(x). We have to find the first point x such that f(X) >= k
// upper_bound(x) - We have a monotonic function f(x). We have to find the first point x such that f(X) > k

// Using 0 based indexing
vector<int> v = {1,2,2,3};

int f(int x){
    return v[x];
}

int lower_bound(int k ,int lo, int hi){
    int return_x = INF;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        int fmid = f(mid);

        if(fmid >= k){
            return_x = min(mid, return_x);
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return return_x;
}

int upper_bound(int k, int lo, int hi){
    int return_x = INF;
    while(lo <= hi){
        int mid = (lo+hi)/2;
        int fmid = f(mid);

        if(fmid > k){
            return_x = min(mid, return_x);
            hi = mid-1;
        }
        else lo=mid+1;
    }

    return return_x;
}

int main()
{
    int lo = 0;
    int hi = v.size();
    int k;
    cin>>k;
    cout<<"Upper Bound: "<<upper_bound(k, lo, hi)<<endl;
    cout<<"Lower Bound: "<<lower_bound(k, lo, hi)<<endl;
}

