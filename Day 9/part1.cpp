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
    while (getline(file, line))
    {
        for(char c:line)
        {
            if(b)
            {
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
    int r = n-1;
    int l =0;
    while(r>=0&&disk[r]==".")
    {
        r--;
    }
    while(l<n&&disk[l]!=".")l++;
    while(l<r)
    {
        if(disk[l]=="."&&disk[r]!=".")
        {
            swap(disk[l],disk[r]);
            l++,r--;
        }
        while(r>=0&&disk[r]==".")
    {
        r--;
    }
    while(l<n&&disk[l]!=".")l++;
    }
    ll x2=0;
    for(auto&e:disk)
    {
        if(e==".")break;
        //cout<<e;
        ans+=(x2++)*stoll(e);
    }
    cout<<ans<<endl;
}