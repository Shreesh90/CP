#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A = {0,1,2,3,4,5,6,7,8,-9};
    vector<int> B = {0,1,2,3,4,5,6,7,8,-9};
    
    int dx[] = {1,1,0,-1,-1,-1,0,1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    int n = A.size();

    int ans = 0;
    for(int ptr=0;ptr<n-1;ptr++){
        int sx = A[ptr];
        int sy = B[ptr];
        
        queue<pair<int,int> > q;
        q.push({sx, sy});
        int temp=0;
        while(!q.empty()){

            int k = q.size();
            temp++;
            
            while(k--){
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();

                int di = pow((A[ptr+1] - cx), 2) + pow((B[ptr+1] - cy), 2);

                int f = di;
                int fx=-1;
                int fy=-1;
                for(int i=0;i<8;i++){
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
    
                    if(nx == A[ptr+1] and ny == B[ptr+1]){
                        ans += temp;
                        k=0;
                        while(!q.empty()) q.pop();
                        f = di;
                        break;
                    }
                    else {
                        int dn = pow((A[ptr+1] - nx), 2) + pow((B[ptr+1] - ny), 2);
                        if(dn < f){
                            f = dn;
                            fx = nx;
                            fy = ny;
                        }
                    }
                }
                if(f!=di) q.push({fx, fy});
            }
            
        }    
    }
    cout<<ans;
    // return ans;
}