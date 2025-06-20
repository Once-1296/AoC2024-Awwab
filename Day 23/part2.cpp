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
    while(getline(file,line))
    {
        string a=line.substr(0,2),b=line.substr(3,2);
        mp[a].insert(b);
        mp[b].insert(a);
    }
    ll mxsz=0;
    set<string>st;
    for(auto&e:mp)
    {
        string a = e.first;
        if(mp[a].size()+1<mxsz)
        {
            continue;        
        }
        set<string>tm={a};
        for(auto&ee:e.second)
        {
            bool b=1;
            for(auto&eee:tm)
            {
                if(mp[ee].find(eee)==mp[ee].end())
                {
                    b=0;
                    break;
                }
            }
            if(b)tm.insert(ee);
        }
        if(tm.size()>mxsz)
        {
            st=tm;
            mxsz=tm.size();
        }
    }
    for(auto&e:st)
    {
        cout<<e<<",";
    }
}