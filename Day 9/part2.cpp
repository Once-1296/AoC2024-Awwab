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
bool chk(ll res, vector<ll>v)
{
    int n =v.size();
    vector<ll>pos={v[0]};
    for(int i =1;i<n;i++)
    {
        int sz = pos.size();
        vector<ll>v2;
        for(int j =0;j<sz;j++)
        {
            if(pos[j]+v[i]<=res)v2.push_back(pos[j]+v[i]);
            if(pos[j]*v[i]<=res)v2.push_back(pos[j]*v[i]);
            ll op3= stoll(to_string(pos[j])+to_string(v[i]));
            if(op3<=res)v2.push_back(op3);
        }
        pos=v2;
    }
    for(auto&e:pos)if (e==res)return true;
    return false;
}
int main()
{

    fstream file("input.txt", ios::in);
    string line;
    ll ans=0;
    int x =0;
    bool b=1;
    vector<string>disk;
    vector<int>locs,szs;
    while (getline(file, line))
    {
        for(char c:line)
        {
            if(b)
            {
                locs.push_back(disk.size());
                szs.push_back(c-'0');
                vector<string> tmp(c-'0',to_string(x++));
                for(auto&e:tmp)disk.push_back(e);
            }
            else
            {
                vector<string> tmp(c-'0',".");
                for(auto&e:tmp)disk.push_back(e);
            }
            b=!b;
        }
    }
    int n = disk.size();
    int sz= locs.size();
    for(int i =sz-1;i>=0;i--)
    {
        int j =0;
        if(szs[i]==0)continue;
        while(j<locs[i])
        {
            if(disk[j]!=".")
            {
                j++;
                continue;
            }
            else{
                int tj=j;
                int bsz=0;
                while(j<locs[i]&&disk[j]==".")
                {
                    j++,bsz++;
                }
                if(bsz>=szs[i])
                {
                    int ti = locs[i];
                    for(int k =0;k<szs[i];k++)
                    {
                        swap(disk[tj++],disk[ti++]);
                    }
                    break;
                }
            }
        }
    }
    ll x2=0;
    for(auto&e:disk)
    {
        if(e==".")
        {
            x2++;
            continue;
        }
        //cout<<e;
        ans+=(x2++)*stoll(e);
    }
    cout<<ans<<endl;
}