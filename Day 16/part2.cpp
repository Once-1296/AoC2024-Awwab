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
map<char,int> oper={{'^',0},{'>',1},{'v',2},{'<',3}};
int main(){
    fstream file("input.txt", ios::in);
    string line;
    string ops="";
    ll ans=LLONG_MAX;
    vector<vector<char>>grid;
    while (getline(file, line))
    {
        vector<char>t(line.begin(),line.end());
        grid.push_back(t);
    }
    int n= grid.size(),m= grid[0].size();
    vector<vector<vector<ll>>>dp(4,vector<vector<ll>>(n,vector<ll>(m,LLONG_MAX)));
    queue<pair<int,pair<int,int>>>q;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]=='S')
            {

                q.push({1,{i,j}});
                dp[1][i][j]=0;
                break;
            }
        }
    }
    while(!q.empty())
    {
        int dptr=q.front().first,ui=q.front().second.first,uj=q.front().second.second;
        q.pop();
        int vi = ui+dirs[dptr].first,vj=uj+dirs[dptr].second;
           //cout<<vi<<""<<vj<<endl;
        if(vi>=0&&vi<n&&vj>=0&&vj<m)
        {
            if(grid[vi][vj]!='#')
            {
             
                if(dp[dptr][vi][vj]>=dp[dptr][ui][uj]+1)
                {
                    q.push({dptr,{vi,vj}});
                    dp[dptr][vi][vj]=dp[dptr][ui][uj]+1;
                }
            }
        }
        int rdptr = (dptr+1)%4,ldptr = dptr==0?3:dptr-1;
        if(dp[rdptr][ui][uj]>=dp[dptr][ui][uj]+1000)
        {
            q.push({rdptr,{ui,uj}});
            dp[rdptr][ui][uj]=dp[dptr][ui][uj]+1000;
        }
        if(dp[ldptr][ui][uj]>=dp[dptr][ui][uj]+1000)
        {
            q.push({ldptr,{ui,uj}});
            dp[ldptr][ui][uj]=dp[dptr][ui][uj]+1000;
        }
    }
    vector<vector<vector<ll>>>d2(4,vector<vector<ll>>(n,vector<ll>(m,LLONG_MAX)));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            // for(int k =0;k<4;k++)
            // {
            //     cout<<dp[k][i][j]<<" ";
            // }
            // cout<<endl;
            if(grid[i][j]=='E')
            {
                for(int k=0;k<4;k++)
                {
                    ans=min(ans,dp[k][i][j]);
                }
                for(int k =0;k<4;k++)
                {
                    if(dp[k][i][j]==ans)
                    {
                        int kk = (k+2)%4;
                        q.push({kk,{i,j}});
                        d2[kk][i][j]=0;
                    }
                }
                //break;
            }
        }
    }
    while(!q.empty())
    {
        int dptr=q.front().first,ui=q.front().second.first,uj=q.front().second.second;
        q.pop();
        int vi = ui+dirs[dptr].first,vj=uj+dirs[dptr].second;
           //cout<<vi<<""<<vj<<endl;
        if(vi>=0&&vi<n&&vj>=0&&vj<m)
        {
            if(grid[vi][vj]!='#')
            {
             
                if(d2[dptr][vi][vj]>=d2[dptr][ui][uj]+1)
                {
                    q.push({dptr,{vi,vj}});
                    d2[dptr][vi][vj]=d2[dptr][ui][uj]+1;
                }
            }
        }
        int rdptr = (dptr+1)%4,ldptr = dptr==0?3:dptr-1;
        if(d2[rdptr][ui][uj]>=d2[dptr][ui][uj]+1000)
        {
            q.push({rdptr,{ui,uj}});
            d2[rdptr][ui][uj]=d2[dptr][ui][uj]+1000;
        }
        if(d2[ldptr][ui][uj]>=d2[dptr][ui][uj]+1000)
        {
            q.push({ldptr,{ui,uj}});
            d2[ldptr][ui][uj]=d2[dptr][ui][uj]+1000;
        }
    }
    ll ct=0;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]!='#')
            {
                for(int k=0;k<4;k++)
                {
                    if(dp[k][i][j]+d2[(k+2)%4][i][j]==ans)
                    {
                        ct++;
                        break;
                    }
                }
            }
        }
    }
    cout<<ct<<endl;

}