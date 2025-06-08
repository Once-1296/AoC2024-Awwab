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
bool chk(ll res, vector<ll>v)
{
    int n =v.size();
    vector<ll>pos={v[0]};
    for(int i =1;i<n;i++)
    {
        int sz = pos.size();
        vector<ll>v2;
        for(int j =0;j<sz;j++)
        {
            if(pos[j]+v[i]<=res)v2.push_back(pos[j]+v[i]);
            if(pos[j]*v[i]<=res)v2.push_back(pos[j]*v[i]);
            ll op3= stoll(to_string(pos[j])+to_string(v[i]));
            if(op3<=res)v2.push_back(op3);
        }
        pos=v2;
    }
    for(auto&e:pos)if (e==res)return true;
    return false;
}
int main()
{

    fstream file("input.txt", ios::in);
    string line;
    ll ans=0;
    vector<vector<char>>grid;
    while (getline(file, line))
    {
        vector<char>t(line.begin(),line.end());
        grid.push_back(t);
    }
    int m = grid.size(),n = grid[0].size();
    map<char,set<pair<int,int>>>mpst;
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(grid[i][j]!='.')mpst[grid[i][j]].insert({i,j});
        }
    }
    map<pair<int,int>,set<pair<int,int>>>mpp;
    for(auto&e:mpst)
    {
        auto it = e.second.begin();
        while(it!=e.second.end())
        {
            auto jit = it;
            jit++;
            while(jit!=e.second.end())
            {
                int ax = it->first,ay=it->second;
                int bx = jit->first,by=jit->second;
                int dx = bx-ax,dy= by-ay;
                    mpp[{dx,dy}].insert({ax,ay});
                jit++;
            }
            it++;
        }
    }
    set<pair<int,int>>pts;
    for(auto&e:mpp)
    {
        int dx = e.first.first,dy=e.first.second;
        for(auto&st:e.second)
        {
        int ax = st.first,ay=st.second;
        for(int i =ax,j=ay;((i>=0&&i<m)&&(j>=0&&j<n));i+=dx,j+=dy)
        {
         pts.insert({i,j});   
        }
        for(int i =ax,j=ay;((i>=0&&i<m)&&(j>=0&&j<n));i-=dx,j-=dy)
        {
         pts.insert({i,j});   
        }
    }
    }
    // for(auto&e:pts)if(grid[e.first][e.second]=='.')grid[e.first][e.second]='#';
    // for(auto&e:grid)
    // {
    //     for(auto&ee:e)cout<<ee;
    //     cout<<endl;
    // }
    cout<<pts.size()<<endl;  
}