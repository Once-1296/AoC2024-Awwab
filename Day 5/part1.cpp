#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include<set>
#include<map>
#include<queue>
#include <string>
using namespace std;
map<int,set<int>>aft;
bool chk(vector<int>v,map<int,set<int>>&mp)
{
   int n =v.size();
   for(int i =1;i<n;i++)
   {
    if(mp[v[i-1]].count(v[i])==0)return false;
   }
   return true;
}
bool comp(int a,int b)
{
    if(aft[a].count(b)!=0)return true;
    return false;
}
int main()
{
    fstream file("input.txt", ios::in);
    string line;
    long long ans = 0;
    for(int i =0;i<1176;i++)
    {
        getline(file,line);
        string word;
        stringstream obj(line);
        int nms[2];
        //cout<<line<<endl;
        int ii =0;
        while(getline(obj,word,'|'))
        {
            nms[ii++]=stoi(word);
        }
        aft[nms[0]].insert(nms[1]);
    }
   long long a2=0;
    while(getline(file,line))
    {
        string word;
        stringstream obj(line);
        vector<int>v;
        while(getline(obj,word,','))
        {
            v.push_back(stoi(word));
        }
        if(chk(v,aft))ans+=v[(v.size()-1)/2];
        else{
            sort(v.begin(),v.end(),comp);
            a2+=v[(v.size()-1)/2];
        }
    }
    cout << ans << endl;
    //cout << a2 << endl;
}