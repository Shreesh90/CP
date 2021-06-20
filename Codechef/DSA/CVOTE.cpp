#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int isSmaller(string a, string b){
    int n = a.length();
    int m = b.length();
    int mi = min(a.length(), b.length());
    
    int counter=0;
    for(int i=0;i<mi;i++){
        counter++;
        if(a[i] == b[i]){ 
            if(counter == mi && mi == n) return 1;
            else if(counter == mi && mi == m) return 0;
            continue;
        }
        else if(a[i] < b[i]){
            return 1;
        } else {
            return 0;
        }
    }
}

string winner(map<string, int> point){
    string final;
    string prev;
    int max_point= 0;
    map<string, int> ::iterator it1;

    for(it1 = point.end() ; it1 != point.begin(); ){
        it1--;
        if(max_point <= it1->second) max_point = it1->second;
        prev = it1->first;
        if(it1->second >= max_point && isSmaller(it1->first, prev)){
            final = it1->first;
        }
    }

    return final;
}

int main()
{
    int N,M;
    cin>>N>>M;

    string name, country;
    map<string, string> entry;
    map<string, int> chef_point;
    map<string, int> country_point;

    for(int i=0;i<N;i++){
        cin>>name>>country;
        entry[name] = country;
    }

    for(int i=0;i<M;i++){
        string x;
        cin>>x;
        chef_point[x]++;
        country_point[entry[x]]++;
    }
    cout<<winner(country_point)<<endl;
    cout<<winner(chef_point);

    return 0;
}