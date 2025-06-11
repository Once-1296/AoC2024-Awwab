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
map<pair<int,int>,map<int,set<int>>>cmap;
map<pair<int,int>,map<int,set<int>>>rmap;
class dsu
{
    public:
    map<pair<int,int>,pair<int,int>>par;
    map<pair<int,int>,ull>s2;
    int sz;
    dsu(vector<vector<char>>&gd)
    {
        int n = gd.size(),m =gd[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                rmap[{i,j}][i].insert(j);
                cmap[{i,j}][j].insert(i);
                par[{i,j}]={i,j};
                s2[{i,j}]=1;
                
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
            for(auto&e:rmap[rv])
            {
                for(auto&ee:e.second)
                {
                rmap[ru][e.first].insert(ee);
                }
            }
            for(auto&e:cmap[rv])
            {
                for(auto&ee:e.second)
                {
                cmap[ru][e.first].insert(ee);
                }
            }
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
                ll peri=0;
                for(auto&e:rmap[pr])
                {
                    int rn = e.first;
                    int ct=0;
                    bool b=0;
                    vector<int>up,down;
                    for(auto&ee:e.second)
                    {
                       int cn = ee;
                       if(rn==0)
                       {
                        up.push_back(cn);
                       }
                       else if(grid[rn-1][cn]!=grid[rn][cn])up.push_back(cn);

                       if(rn==(n-1))down.push_back(cn);
                       else if(grid[rn+1][cn]!=grid[rn][cn])down.push_back(cn); 
                    }
                    int us=0,ds=0;
                    int prev=-1;
                    for(int i =0;i<up.size();i++)
                    {
                        if(prev==-1)
                        {
                           
                            us=1;
                        }
                        else
                        {
                            if(up[i]-prev>1)
                            {
                                us++;
                            }
                        }
                         prev = up[i];
                    }
                    prev=-1;
                     for(int i =0;i<down.size();i++)
                    {
                        if(prev==-1)
                        {
                           
                            ds=1;
                        }
                        else
                        {
                            if(down[i]-prev>1)
                            {
                                ds++;
                            }
                        }
                         prev = down[i];
                    }
                    //cout<<rn<<" "<<us<<" "<<ds<<endl;
                    peri+=us+ds;
                }
                for(auto&e:cmap[pr])
                {
                    int cn = e.first;
                    vector<int>left,right;
                    for(auto&ee:e.second)
                    {
                       int rn = ee;
                       if(cn==0)
                       {
                        left.push_back(rn);
                       }
                       else if(grid[rn][cn-1]!=grid[rn][cn])left.push_back(rn);
                       if(cn==(m-1))right.push_back(rn);
                       else if(grid[rn][cn+1]!=grid[rn][cn])right.push_back(rn); 
                    }
                    int ls=0,rs=0;
                    int prev=-1;
                    for(int i =0;i<left.size();i++)
                    {
                        if(prev==-1)
                        {
                           
                            ls=1;
                        }
                        else
                        {
                            if(left[i]-prev>1)
                            {
                                ls++;
                            }
                        }
                         prev = left[i];
                    }
                    prev=-1;
                     for(int i =0;i<right.size();i++)
                    {
                        if(prev==-1)
                        {
                           
                            rs=1;
                        }
                        else
                        {
                            if(right[i]-prev>1)
                            {
                                rs++;
                            }
                        }
                         prev = right[i];
                    }
                    peri+=ls+rs;
                    //cout<<cn<<" "<<ls<<" "<<rs<<endl;
                }
                ans+=peri*ds.s2[pr];
                //cout<<ans<<endl;
            }
        }
    }
    cout<<ans<<endl;
}