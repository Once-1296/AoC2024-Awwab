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
int main()
{
    fstream file("input.txt",ios::in);
    ll ans=0;
    string line;
    map<string,ll>vals,indegs;
    set<vector<string>>ops,vis;
    map<string,int> mp= {{"AND",0},{"XOR",1},{"OR",2}};
    while(getline(file,line))
    {
        if(line.size()==0||line[0]==' ')break;
        string o=line.substr(0,3);
        int n=line[5]-'0';
        vals[o]=n;
        indegs[o]=0;
    }
    while(getline(file,line))
    {
        vector<string>parts;
        stringstream obj(line);
        string word;
        while(getline(obj,word,' '))
        {
            parts.push_back(word);
        }
        ops.insert({parts[0],parts[2],parts[4],parts[1]});
        indegs[parts[4]]=1;
    }
    queue<vector<string>>que;
    for(auto&e:ops)
    {
        if(indegs[e[0]]==0&&indegs[e[1]]==0)
        {
            que.push(e);
            vis.insert(e);
        }
    }
    while(!que.empty())
    {
        auto e = que.front();
        que.pop();
        string a = e[0],b=e[1],c=e[2],op=e[3];
        ll v;
        if(op=="XOR")v=vals[a]^vals[b];
        else if(op=="AND")v=vals[a]&vals[b];
        else v=vals[a]|vals[b];
        vals[c]=v;
        indegs[c]=0;
        for(auto&e:ops)
        {
        if(indegs[e[0]]==0&&indegs[e[1]]==0&&!vis.count(e))
        {
            que.push(e);
            vis.insert(e);
        }
        }
    }
    for(auto&e:vals)
    {
        if(e.first[0]=='z')
        {
           string ss = e.first.substr(1,2);
            int nn = stoi(ss);
            if(e.second==1ll)ans+=(1ll<<nn);
        }
    }
    cout<<ans<<endl;
}