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
ull dfs(int ops,string num,vector<map<ull,ull>>&dp)
{
    ull n = stoull(num);
    //cout<<n<<" "<<num<<endl;
    if(dp[ops].count(n))
    {
        return dp[ops][n];
    }
    if(ops==0)
    {
        return dp[ops][n]=1;
    }
    if(n==0ull)
    {
        return dp[ops][n]=dfs(ops-1,"1",dp);
    }
    if(num.length()%2==0)
    {
        int sz = num.length();
        string lh = num.substr(0,sz/2),rh = num.substr(sz/2,sz/2);
        while(rh.size()>1&&*rh.begin()=='0')rh.erase(rh.begin());
        //cout<<rh<<endl;
        return dp[ops][n]= dfs(ops-1,lh,dp)+dfs(ops-1,rh,dp);
    }
    n*=2024ull;
    //cout<<n<<endl;
    return dp[ops][n/2024]=dfs(ops-1,to_string(n),dp);
}
int main(){
    fstream file("input.txt", ios::in);
    string line;
    ll ans=0;
    vector<vector<char>>grid;
    while (getline(file, line))
    {
        string word;
        stringstream obj(line);
        while(getline(obj,word,' '))
        {
            vector<map<ull,ull>>dp(76);
            dfs(75,word,dp);
            ans+=dp[75][stoull(word)];
            //cout<<dp[1][stoull(word)]<<endl;
        }
    }

    cout<<ans<<endl;
}