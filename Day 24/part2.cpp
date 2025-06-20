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
string f(int n)
{
    string s = to_string(n);
    if(n<10)s="0"+s;
    return s;
}
int safe_stoi(string s)
{
    int n=0;
    int prod=1,sz=s.length()-1;
    while(sz>=0)
    {
        if(s[sz]>='0'&&s[sz]<='9')
        {
            n+=prod*int(s[sz]-'0');
            prod*=10;
        }
        sz--;
    }
    return n;
}
bool comp(vector<string>&a,vector<string>&b)
{
    int n1 =safe_stoi(a[3]),n2=safe_stoi(b[3]);
    if(n1<n2)return true;
    else if(n1>n2)return false;
    else
    {
        if(a[3][0]=='c')return true;
        else if(b[3][0]=='c')return false;
        else
        {
            return a[3][0]<b[3][0]?true:false;
        }
    }
}
void save(map<string,string>&mpp,map<string,string>&rmpp,vector<vector<string>>&store,vector<string>in,bool &boo)
{
    string a = in[0],b=in[1],c=in[2],op=in[3];
    for(auto&e:in)
    {
        if(e.size()<3&&e!="OR")
        {
            boo=0;
            break;
        }
    }
    if(a[0]=='x'||a[0]=='y')
    {
        int num = stoi(a.substr(1,2));
        if(num==0)
        {
            if(op=="AND")
            {
                mpp[c]="c"+f(num+1);
                rmpp["c"+f(num+1)]=c;
            }
            if(c[0]=='z')
            {
                mpp[c]=c;
                rmpp[c]=c;
            }
            store.push_back({a,op,b,mpp[c]});
        }
        else
        {
            if(op=="AND")
            {
                mpp[c]="b"+f(num);
                rmpp["b"+f(num)]=c;
            }
            else if(op=="XOR")
            {
                mpp[c]="a"+f(num);
                rmpp["a"+f(num)]=c;
            }
            else
            {
                boo=0;
                return;
            }
            store.push_back({a,op,b,mpp[c]});
        }
    }
    else
    {
        string ma = mpp[a],mb=mpp[b];
        if(mb[0]=='a')swap(ma,mb);
        if(ma[0]=='a')
        {
            if(mb[0]=='c')
            {
                int n1 =stoi(ma.substr(1,2)),n2=stoi(mb.substr(1,2));
                if(n1==n2)
                {
                    if(op=="XOR")
                    {
                        if(c[0]=='z')
                        {
                        mpp[c]=c;
                        rmpp[c]=c;
                        }

                    }
                    else if(op=="AND")
                    {
                        mpp[c]="d"+f(n1);
                        rmpp["d"+f(n1)]=c;
                    }
                    else
                    {
                        boo = 0;
                        return;
                    }
                    store.push_back({ma,op,mb,mpp[c]});
                }
                else
                {
                    boo=0;
                    return;
                }
            }
            else
            {
                boo=0;
                return;
            }
        }
        else
        {
            if(mb[0]=='b')
            {
                swap(ma,mb);
            }
            if(ma[0]=='b'&&mb[0]=='d')
            {
                if(stoi(ma.substr(1,2))==stoi(mb.substr(1,2)))
                {
                    int nn = stoi(ma.substr(1,2));
                    mpp[c]="c"+f(nn+1);
                    rmpp["c"+f(nn+1)]=c;
                    store.push_back({ma,op,mb,mpp[c]});
                }
            }
            else
            {
                boo=0;
                return;
            }
        }
    }
}
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
    map<string,string>mpp,rmpp;
    vector<vector<string>>store;
    bool boo=1;
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
        save(mpp,rmpp,store,e,boo);
        if(!boo)
        {
            cout<<"Error in: "<<a<<" "<<op<<" "<<b<<" "<<c<<"\n";
            break;
        }
        for(auto&e:ops)
        {
        if(indegs[e[0]]==0&&indegs[e[1]]==0&&!vis.count(e))
        {
            que.push(e);
            vis.insert(e);
        }
        }
    }
    fstream fout("out.txt",ios::out);
    sort(store.begin(),store.end(),comp);
    for(auto&e:store)
    {
        for(auto&ee:e)
        {
            fout<<ee<<" ";
        }
        fout<<endl;
    }
    fout.close();
    file.close();
    fstream f3("map.txt",ios::out);
    for(auto&e:rmpp)
    {
        f3<<e.first<<" "<<e.second<<"\n";
    }
    f3.close();
    // for(auto&e:vals)
    // {
    //     if(e.first[0]=='z')
    //     {
    //        string ss = e.first.substr(1,2);
    //         int nn = stoi(ss);
    //         if(e.second==1ll)ans+=(1ll<<nn);
    //     }
    // }
    // cout<<ans<<endl;
}