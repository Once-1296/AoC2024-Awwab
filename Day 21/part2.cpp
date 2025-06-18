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
typedef pair<int,int> i2;
ll dfs(int ii,string s,map<string,map<int,ll>>&bdp,map<char,i2>&m,map<pair<i2,i2>,set<string>>&mm)
{
    if(ii==0)
    {
        return bdp[s][0]=s.length();
    }
    if(bdp.count(s)&&bdp[s].count(ii))return bdp[s][ii];
    ll ans=0;
    vector<vector<string>>s1;
    char co='A';
    for(char ci:s)
    {
        auto u = m[co],v=m[ci];
        vector<string>st;
            for(auto&sss:mm[{u,v}])
            {
                st.push_back({sss});
            }
        s1.push_back(st);
        co=ci;
    }
    for(auto&e:s1)
    {
        ll mn = LLONG_MAX;
        for(auto&ee:e)
        {
            mn=min(mn,dfs(ii-1,ee,bdp,m,mm));
        }
        ans+=mn;
    }
    return bdp[s][ii]=ans;
}
void qry(i2 a, i2 b, map<pair<i2,i2>,set<string>>&m,set<i2>&s)
{
    int ui = a.first,uj=a.second,vi=b.first,vj=b.second;
    for(int i=0;i<2;i++)
    {
        string v="";
        int ti=ui,tj=uj;
        if(i==1)
        {
            bool ok = 1;
            while(ti<vi)
            {
                v+="v";
                ti++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(ti>vi)
            {
                v+="^";
                ti--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(tj<vj)
            {
                v+=">";
                tj++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(tj>vj)
            {
                v+="<";
                tj--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            m[{a,b}].insert(v+"A");
        }
        else
        {
            bool ok = 1;
            while(tj<vj)
            {
                v+=">";
                tj++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(tj>vj)
            {
                v+="<";
                tj--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
             while(ti<vi)
            {
                v+="v";
                ti++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(ti>vi)
            {
                v+="^";
                ti--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            m[{a,b}].insert(v+"A");
        }
    }
}

int main(){
    fstream file("input.txt", ios::in);
    string line;
    set<pair<int,int>>s1,s2;
    map<char,pair<int,int>>m1,m2;
    string b1="7894561230A";
    int ii=0;
    for(int i =0;i<4;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(i==3&&j==0)continue;
            s1.insert({i,j});
            m1[b1[ii++]]={i,j};
        }
    }
    ii=0;
    string b2="^A<v>";
    for(int i =0;i<2;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(i==0&&j==0)continue;
            s2.insert({i,j});
            m2[b2[ii++]]={i,j};
        }
    }
    map<pair<i2,i2>,set<string>>mm1,mm2;
    map<int,pair<i2,i2>>mmm;
    map<pair<i2,i2>,int>rmmm;
    auto it1 =s1.begin();
    while(it1!=s1.end())
    {
        auto jit1 = s1.begin();
        while(jit1!=s1.end())
        {
            qry(*it1,*jit1,mm1,s1);
            jit1++;
        }
        it1++;
    }
    int x=0;
    auto it2 =s2.begin();
    while(it2!=s2.end())
    {
        auto jit2 = s2.begin();
        while(jit2!=s2.end())
        {
            qry(*it2,*jit2,mm2,s2);
            mmm[x]={*it2,*jit2};
            rmmm[{*it2,*jit2}]=x;
            x++;
            jit2++;

        }
        it2++;
    }

    ll ans=0;
    while(getline(file,line))
    {
        vector<string>sv={""};
        char ch='A';
        for(char ci:line)
        {
            vector<string>inter;
            auto u = m1[ch],v=m1[ci];
            for(auto ss:mm1[{u,v}])
            {
                for(auto S:sv)
                {
                    inter.push_back(S+ss);
                }
            }
            ch=ci;
            sv=inter;
        }
        ll mn=LLONG_MAX;
        for(auto &S:sv)
        {
            map<string,map<int,ll>>bdp;
            mn=min(mn,dfs(25,S,bdp,m2,mm2));
        }
        ans+=mn*stoll(line.substr(0,3));
    }
    cout<<ans<<endl;
}