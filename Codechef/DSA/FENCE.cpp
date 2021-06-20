#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll  long long
int main()
{
    int T;
    cin>>T;
    while(T--){
         int N,M,K;
        cin>>N>>M>>K;
        
        map<pair<int,int>,  int > ground;
        for(int i=0;i<K;i++){
             int x,y;
            cin>>x>>y;
            ground[make_pair(x, y)] = 1;
        }

         int len=0;

        map<pair< int,  int>,  int > :: iterator it;
        for(it=ground.begin(); it != ground.end(); it++){
             int x = it->first.first;
             int y = it->first.second;
            
            if(ground.find(make_pair(x, y+1)) == ground.end()) len++;
            if(ground.find(make_pair(x+1, y)) == ground.end()) len++;
            if(ground.find(make_pair(x, y-1)) == ground.end()) len++;
            if(ground.find(make_pair(x-1, y)) == ground.end()) len++;
        }
        cout<<len<<endl;
    }
}