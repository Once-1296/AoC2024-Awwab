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
const pair<int,int>dirs[4]={{1,0},{0,1},{-1,0},{0,-1}};
class dsu
{
    public:
    map<pair<int,int>,pair<int,int>>par;
    map<pair<int,int>,ull>s1,s2;
    int sz;
    dsu(vector<vector<char>>&gd)
    {
        int n = gd.size(),m =gd[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                par[{i,j}]={i,j};
                s2[{i,j}]=1;
                int ct=0;
                for(auto&e:dirs)
                {
                    int di = i+e.first,dj=j+e.second;
                    if(di<0||di>=n||dj<0||dj>=m)
                    {
                        ct++;
                        continue;
                    }
                    if(gd[i][j]!=gd[di][dj])ct++;
                }
                s1[{i,j}]=ct;
                //cout<<i<<" "<<j<<" ";
                //cout<<s1[{i,j}]<<" "<<s2[{i,j}]<<endl;
            }
        }
    }
    pair<int,int> find(pair<int,int>u)
    {
        if(u!=par[u])return par[u]=find(par[u]);
        return u;
    }
    void comb(pair<int,int> u, pair<int,int> v)
    {
        pair<int,int> ru = find(u),rv=find(v);
        if(ru!=rv)
        {
            par[rv]=ru;
            s1[ru]+=s1[rv];
            s2[ru]+=s2[rv];
        }
    }
};
int main(){
    fstream file("input.txt", ios::in);
    string line;
    ll ans=0;
    vector<vector<char>>grid;
    while (getline(file, line))
    {
        vector<char>t(line.begin(),line.end());
        grid.push_back(t);
    }
    dsu ds(grid);
    int n= grid.size(),m= grid[0].size();
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            for(auto&e:dirs)
                {
                    int di = i+e.first,dj=j+e.second;
                    if(di<0||di>=n||dj<0||dj>=m)
                    {
                        continue;
                    }
                    if(grid[i][j]==grid[di][dj])ds.comb({i,j},{di,dj});
                }
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            auto pr= ds.find({i,j});
            if(!vis[pr.first][pr.second])
            {
                vis[pr.first][pr.second]=1;
                //cout<<ds.s1[{pr.first,pr.second}]<<" "<<ds.s2[{pr.first,pr.second}]<<endl;
                ans+=ds.s1[{pr.first,pr.second}]*ds.s2[{pr.first,pr.second}];
            }
        }
    }
    cout<<ans<<endl;
}