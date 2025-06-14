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
void solve(vector<vector<char>>&grid,vector<vector<ll>>&dp,int si,int sj,int &n,int &m)
{
    queue<pair<int,int>>q;
    q.push({si,sj});
    dp[si][sj]=0;
    while(!q.empty())
    {
        int ui=q.front().first,uj=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int vi =ui+dirs[i].first,vj=uj+dirs[i].second;
            if(vi<0||vi>=n||vj<0||vj>=m)continue;
            if(grid[vi][vj]=='#')continue;
            if((dp[ui][uj]+1)<dp[vi][vj])
            {
                q.push({vi,vj});
                dp[vi][vj]=dp[ui][uj]+1;
            }
        }
    }
}
int main(){
    fstream file("input.txt", ios::in);
    string line;
    vector<vector<char>>grid;
    while (getline(file, line))
    {
        vector<char>t(line.begin(),line.end());
        grid.push_back(t);
    }
    int n= grid.size(),m= grid[0].size();
    vector<vector<ll>>dp(n,vector<ll>(m,INT_MAX)),d2=dp;
    int si,sj,ei,ej;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]=='S')
            {
                si=i,sj=j;
                solve(grid,dp,i,j,n,m);
            }
            if(grid[i][j]=='E')
            {
                ei=i,ej=j;
                solve(grid,d2,i,j,n,m);
            }
        }
    }
    ll ans=0;
    set<vector<int>>sv;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
                ll op1=INT_MAX,op2=op1;
                for(int o =0;o<4;o++)
                {
                    int di = i+dirs[o].first,dj=j+dirs[o].second;
                    if(di<0||di>=n||dj<0||dj>=m)continue;
                    if(grid[di][dj]=='#')continue;
                    op2=dp[di][dj];
                
                for(int l =-19;l<20;l++)
                {
                    for(int k = -(19 - abs(l));k<=19-abs(l);k++)
                    {
                        int ddi = i +l,ddj=j+k;
                        if(ddi<0||ddi>=n||ddj<0||ddj>=m)continue;
                        if(grid[ddi][ddj]=='#')continue;
                        if(op2+d2[ddi][ddj]+abs(l)+abs(k)+1<=dp[ei][ej]-100)sv.insert({di,dj,ddi,ddj});
                    }
                }
            }
                //if(op1+op2<=dp[ei][ej]-100ll)ans++;
        }
    }
    // for(auto&e:sv)
    // {
    //     for(auto&ee:e)cout<<ee<<" ";
    //     cout<<endl;
    // }
    cout<<sv.size()<<endl;

}