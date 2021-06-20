#include<bits/stdc++.h>
using namespace std;
#include<queue>

void StepNum(int value, int n, int m, int *visited){
    
    queue<int> Q;
    Q.push(value);

    while(!Q.empty()){
        int u = Q.front();
        if(visited[u] == 0)
            cout<<u<<" ";
        visited[u] = 1;
        Q.pop();

        int lastDigit = u%10;
        int sn1 = (u*10) + lastDigit + 1;
        int sn2 = (u*10) + lastDigit - 1; 
        if(lastDigit == 0 && sn1 <= m)
            Q.push(sn1);
        if(lastDigit == 9 && sn2 <= m)
            Q.push(sn2);
        if(lastDigit != 0 && lastDigit != 9 && n <= sn2 && sn2 <= m)
            Q.push(sn2);
        if(lastDigit != 0 && lastDigit != 9 && n <= sn1 && sn1 <= m)
            Q.push(sn1);
        
    }
}

int main()
{
    int n,m;
    cout<<"Enter Lower Bound and Upper Bound to find all Stepping Numbers between them: ";
    cin>>n>>m;

    int visited[m+1] = {0};
    for(int i=0; i<10; i++)
        StepNum(i, n, m, visited);
}