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
            v2.push_back(pos[j]+v[i]);
            v2.push_back(pos[j]*v[i]);
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
    while (getline(file, line))
    {
        stringstream obj(line);
        string words[2];
        int x=0;
        string word;
        while(getline(obj,word,':'))
        {
            words[x++]=word;
        }
        words[1].erase(words[1].begin());
        stringstream obj2(words[1]);
        vector<ll>v;
        while(getline(obj2,word,' '))
        {
            cout<<word<<" ";
            v.push_back(stoll(word));
        }
        cout<<endl;
        ll res =stoll(words[0]);
        if(chk(res,v))ans+=res;
    }
   cout<< ans<<endl;
    
}