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
bool solve(int x)
{
  fstream file("input.txt", ios::in);
    string line;
    vector<vector<char>>grid(71,vector<char>(71,'.'));
    int num=0;
    while (getline(file, line))
    {
        int wds[2];
        int ii =0;
        string word;
        stringstream obj(line);
        while(getline(obj,word,','))
        {
            wds[ii++]=stoi(word);
        }
       if(num<x)grid[wds[0]][wds[1]]='#';
        num++;
    }
    int n= grid.size(),m= grid[0].size();
    vector<vector<ll>>dp(n,vector<ll>(m,LLONG_MAX));
    queue<pair<int,int>>q;
    q.push({0,0});
    dp[0][0]=0;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
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
    return dp[n-1][m-1]!=LLONG_MAX;
}
int main(){
  int l =0,r= 4900;
  while(l<r)
  {
    int m=(l+r+1)>>1;
    if(solve(m))l=m;
    else r=m-1;
  }
  fstream file("input.txt",ios::in);
  int x=0;
  string line;
  while(getline(file,line))
  {
    if(x==r)
    {
        cout<<line<<endl;
        break;
    }
    x++;
  }
}