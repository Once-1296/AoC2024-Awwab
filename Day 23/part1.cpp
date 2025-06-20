#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include<set>
#include<map>
#include<queue>
#include <string>
typedef long long ll;
using namespace std;
typedef unsigned long long ull;
const pair<int,int>dirs[4]={{-1,0},{0,1},{1,0},{0,-1}};
int main()
{
    fstream file("input.txt",ios::in);
    ll ans=0;
    string line;
    map<string,set<string>>mp;
    set<tuple<string,string,string>>stp;
    while(getline(file,line))
    {
        string a=line.substr(0,2),b=line.substr(3,2);
        for(auto&e:mp[a])
        {
            if(mp[b].find(e)!=mp[b].end())
            {
                string c= e;
                if(a[0]=='t'||b[0]=='t'||c[0]=='t')
                {
                    stp.insert({a,b,c});
                }
            }
        }
        mp[a].insert(b);
        mp[b].insert(a);
    }
    cout<<stp.size()<<endl;
}