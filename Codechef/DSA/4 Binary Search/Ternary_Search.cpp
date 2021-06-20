// Ternary Search
// CODECHEF QUESTION
// AMCS03

#include<bits/stdc++.h>
using namespace std;

int s[100011],d[100011];
long long n;
double k;

double f(double t){
    double max = -1;
    double min = INT_MAX;

    for(int i=0;i<n;i++){
        double pi = s[i]*t + d[i];

        if(max < pi) max = pi;
        if(min > pi) min = pi;
    }

    return (max-min);

}

double search(double l, double r){
    double eps = 1e-9;

    while(r-l > eps){
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double f1 = f(m1);
        double f2 = f(m2);

        if(f1 < f2){
            r = m2;
        } else {
            l = m1;
        }
    }
    return f(l);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    cin>>n>>k;
    cout<<fixed<<setprecision(6);
    for(int i=0;i<n;i++) cin>>s[i]>>d[i];

    double ans = search(0.000, k);
    cout<<ans<<endl;
    
}