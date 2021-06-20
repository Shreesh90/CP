#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define oset tree < pair<int,int> ,  null_type ,  less<pair<int,int> > ,  rb_tree_tag ,  tree_order_statistics_node_update >

int main()
{
    oset s;

    // s.insert({2,1});
    // s.insert({3,2});
    // s.insert({4,3});
    // s.insert({5,4});
    // s.insert({6,5});
    // s.insert({7,5});
    // s.insert({4,6});
    // cout<<s.order_of_key({4,6})<<s.size();

    int n;
    cin>>n;

    int x;
    ll sum=0;

    for(int i=0;i<n;i++){
        cin>>x;
        s.insert({x,i});
        ll less_than = s.order_of_key({x, i});
        ll less_than_equal_to = less_than + 1;
        sum += ( s.size()-1 ) - less_than;
    } 

    cout<<sum;
  
}

