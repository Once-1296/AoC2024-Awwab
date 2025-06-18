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
    ll ans=0ll;
    while (getline(file, line))
    {
        ll num=stoll(line);
        for(int i =0;i<2000;i++)
        {
            ll m=num<<6ll;
            num^=m;
            num%=16777216ll;
            m=num>>5ll;
            num^=m;
            num%=16777216ll;
            m=num<<11ll;
            num^=m;
            num%=16777216ll;
        }
        ans+=num;
    }
    cout<<ans<<endl;
}