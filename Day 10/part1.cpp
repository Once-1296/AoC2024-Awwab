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
pair<int,int>dirs[4]={{1,0},{0,1},{-1,0},{0,-1}};
int bfs(int x, int y,vector<vector<char>>gd,int m,int n)
{
    queue<pair<int,int>>q;
    q.push({x,y});
    set<pair<int,int>>stp;
    while(!q.empty())
    {
        int cx = q.front().first,cy=q.front().second;
        q.pop();
        //cout<<gd[cy][cx]<<endl;
        if(gd[cy][cx]=='9')
        {
            stp.insert({cx,cy});
            continue;
        }
        for(int i =0;i<4;i++)
        {
            int dx = cx+dirs[i].first,dy=cy+dirs[i].second;
            if(dx<0||dx>=n||dy<0||dy>=m)
            {
                continue;
            }
            //cout<<gd[cy][cx]<<" "<<gd[dy][dx]<<endl;
            if(int(gd[dy][dx]-gd[cy][cx])==1)
            {
                //cout<<gd[dy][dx]<<"\n";
                q.push({dx,dy});
            }
        }
    }
   // cout<<stp.size()<<"\n";
    return stp.size();
}
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
    int m = grid.size(),n = grid[0].size();
    for(int i =0;i<m;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(grid[i][j]=='0')
            {
                ans+=bfs(j,i,grid,m,n);
            }
        }
    }
    cout<<ans<<endl;
}