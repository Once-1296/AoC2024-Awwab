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
void solve(vector<vector<int>>&locks,vector<vector<int>>&keys,vector<vector<char>>&gd)
{
    int n = gd.size(),m=gd[0].size();
    string s(gd[0].begin(),gd[0].end());
    vector<int>v;
    if(s.find('.')==string::npos)
    {
        for(int i =0;i<m;i++)
        {
            int t=0;
            for(int j =1;j<n-1;j++)
            {
                if(gd[j][i]=='#')t++;
            }
            v.push_back(t);
        }
        locks.push_back(v);
    }
    else
    {
        for(int i =0;i<m;i++)
        {
            int t=0;
            for(int j =n-2;j>0;j--)
            {
                if(gd[j][i]=='#')t++;
            }
            v.push_back(t);
        }
        keys.push_back(v);
    }
}
int main()
{
    fstream file("input.txt",ios::in);
    ll ans=0;
    string line;
    vector<vector<int>>locks,keys;
    int n=-1;
    while(!file.eof())
    {
        vector<vector<char>>gd;
        while(getline(file,line))
        {
            if(line==""||line==" ")break;;
            vector<char>t(line.begin(),line.end());
            gd.push_back(t);
        }
        if(n==-1)
        {
            n=gd.size()-2;
        }

        solve(locks,keys,gd);
    }
    //return 0;
    for(auto&e:locks)
    {
        for(auto&f:keys)
        {
            int sz=e.size();
            bool b=1;
            for(int i =0;i<sz;i++)
            {
                if(e[i]+f[i]>n)
                {
                    b=0;
                    break;
                }
            }
            if(b)ans++;
        }
    }
    // cout<<"Locks\n";
    // for(auto&e:locks)
    // {
    //     for(auto&ee:e)cout<<ee<<" ";
    //     cout<<endl;
    // }
    // cout<<"Keys\n";
    // for(auto&e:keys)
    // {
    //     for(auto&ee:e)cout<<ee<<" ";
    //     cout<<endl;
    // }
    cout<<ans<<endl;
}