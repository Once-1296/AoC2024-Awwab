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
ll backtrack(string s,map<string,ll>&mp,map<string,ll>&mo)
{
 if(mp.count(s))return mp[s];
 int n = s.length();
 ll sum =0;
 string t="";
 for(int i =0;i<n;i++)
 {
    t+=s[i];
    if(mo.count(t))
    {
        sum+=backtrack(s.substr(i+1,n-i),mp,mo);
    }
 }   
 return mp[s]=sum;
}
int main(){
  vector<string>sv;
  map<string,ll>words,w2;
  map<int,set<string>>mm;
  fstream file("input.txt",ios::in);
  string line;
  getline(file,line);
  stringstream o1(line);
  string word;
  while(getline(o1,word,','))
  {
    string tmp="";
    for(char c:word)if(c!=' ')tmp+=c;
    int len = tmp.length();
    mm[len].insert(tmp);
    if(len ==1)
    {
        words[tmp]=1;
        w2[tmp]=1;
    }
  }
  for(int i =2;;i++)
  {
    if(!mm.count(i))break;
    for(auto&e:mm[i])
    {
        ll tmp= backtrack(e,words,w2);
        w2[e]=tmp+1;
        words[e]=tmp+1;
    }
  }
  getline(file,line);
  while (getline(file,line))
  {
    sv.push_back(line);
  }
  ll ans=0;
  for(auto&e:sv)
  {
    ll a=backtrack(e,words,w2);
    ans+=a;
   // cout<<a<<" "<<e<<endl;
  }
  cout<<ans<<endl;  
}