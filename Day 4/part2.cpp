#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include<set>
using namespace std;
int main()
{
    set<string>st={"SSMM","SMMS","MMSS","MSSM"};
    fstream file("input.txt", ios::in);
    string line;
    vector<vector<char>>sv;
    int ans = 0;
    while (getline(file, line))
    {
        vector<char>t(line.begin(),line.end());
        sv.push_back(t);
        //for(auto&c:sv[sv.size()-1])cout<<c<<" ";
        //cout<<endl;
    }
    int n =sv[0].size(),m=sv.size();
    for(int i =1;i<m-1;i++)
    {
        for(int j =1;j<n-1;j++)
        {
            if(sv[i][j]=='A')
            {
                string word={sv[i-1][j-1],sv[i+1][j-1],sv[i+1][j+1],sv[i-1][j+1]};
                if(st.find(word)!=st.end())ans++;
            }
        }
    }
    cout << ans << endl;
}