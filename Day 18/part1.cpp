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
int main(){
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
       if(num<1024)grid[wds[0]][wds[1]]='#';
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
        //if(vis[ui][uj])continue;
        //vis[ui][uj]=1;
        //cout<<q.size()<<endl;
        for(int i=0;i<4;i++)
        {
            int vi =ui+dirs[i].first,vj=uj+dirs[i].second;
            if(vi<0||vi>=n||vj<0||vj>=m)continue;
            if(grid[vi][vj]=='#')continue;
            if((dp[ui][uj]+1)<dp[vi][vj])
            {
                //vis[vi][vj]=0;
                q.push({vi,vj});
                dp[vi][vj]=dp[ui][uj]+1;
            }
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cout<<grid[i][j];

        }
        cout<<endl;
    }
    cout<<dp[n-1][m-1]<<endl;

}