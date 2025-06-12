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
void update(char c,vector<vector<char>>&gd,int &ri, int &rj)
{
    if(!oper.count(c))return;
    int dptr=oper[c];
    int ti = ri+dirs[dptr].first,tj=rj+dirs[dptr].second;
    int oi=-1,oj=-1;
    while(gd[ti][tj]!='.')
    {
        if(gd[ti][tj]=='#')return;
        if(oi==-1)
        {
            oi=ti,oj=tj;
        }
        ti+=dirs[dptr].first,tj+=dirs[dptr].second;
    }
    swap(gd[ti][tj],gd[ri][rj]);
    if(oi!=-1)
    {
        swap(gd[oi][oj],gd[ti][tj]);
        ri =oi;
        rj=oj;
        return;
    }
    ri=ti;
    rj=tj;
}
int main(){
    fstream file("input.txt", ios::in);
    string line;
    string ops="";
    ll ans=0;
    vector<vector<char>>grid;
    while (getline(file, line))
    {
        if(line[0]=='#')
        {
        vector<char>t(line.begin(),line.end());
        grid.push_back(t);
        }
        else ops+=line;
    }
    int n= grid.size(),m= grid[0].size();
    int ri=-1,rj;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]=='@')
            {
                ri=i;
                rj=j;
                break;
            }
        }
        if(ri!=-1)break;
    }
    for(auto&c:ops)update(c,grid,ri,rj);
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]=='O')
            {
                ans+=(100ll*i) + j;
            }
        }
    }
    cout<<ans<<endl;
}