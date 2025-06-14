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
bool backtrack(int start,string &s,set<string>&words)
{
 int n = s.length();
 if(start==n)return true;
 string t="";
 for(int i =start;i<n;i++)
 {
    t+=s[i];
    if(words.count(t))
    {
        if(backtrack(i+1,s,words))return true;
    }
 }   
 return false;
}
int main(){
  vector<string>sv;
  set<string>words;
  fstream file("input.txt",ios::in);
  string line;
  getline(file,line);
  stringstream o1(line);
  string word;
  while(getline(o1,word,','))
  {
    string tmp="";
    for(char c:word)if(c!=' ')tmp+=c;
    words.insert(tmp);
  }
  getline(file,line);
  while (getline(file,line))
  {
    sv.push_back(line);
  }
  ll ans=0;
  for(auto&e:sv)
  {
    if(backtrack(0,e,words))
    {
        ans++;
    }
  }
  cout<<ans<<endl;  
}