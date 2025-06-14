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
    for(int i =1;i<n-1;i++)
    {
        for(int j =1;j<m-1;j++)
        {
            if(grid[i][j]=='#')
            {
                bool chk=0;
                for(int k =0;k<4;k++)
                {
                    for(int l =0;l<4;l++)
                    {
                        if(l==k)continue;
                        int ai = i+dirs[l].first,aj=j+dirs[l].second;
                        int bi = i+ dirs[k].first,bj=j+dirs[k].second;
                        ll opt=dp[ai][aj]+d2[bi][bj]+2;
                        if(opt<=(dp[ei][ej]-100ll))
                        {
                            //cout<<dp[ei][ej]<<endl;
                            chk=1;
                            break;
                        }
                    }
                    if(chk)break;
                }
                if(chk)ans++;
            }
        }
    }
    cout<<ans<<endl;

}