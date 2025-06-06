#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
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
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m-3;j++)
        {
            string word="";
            word+= {sv[j][i],sv[j+1][i],sv[j+2][i],sv[j+3][i]};
            //cout<<word<<"\n";
            if(word=="XMAS")ans++;
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j=3;j<m;j++)
        {
            string word="";
            word+= {sv[j][i],sv[j-1][i],sv[j-2][i],sv[j-3][i]};
            //cout<<word<<"\n";
            if(word=="XMAS")ans++;
        }
    }
    for(int i =0;i<m;i++)
    {
        for(int j=0;j<n-3;j++)
        {
            string word="";
            word+= {sv[i][j],sv[i][j+1],sv[i][j+2],sv[i][j+3]};
            if(word=="XMAS")ans++;
        }
    }  
    for(int i =0;i<m;i++)
    {
        for(int j=3;j<n;j++)
        {
            string word="";
            word+= {sv[i][j],sv[i][j-1],sv[i][j-2],sv[i][j-3]};
            if(word=="XMAS")ans++;
        }
    }  
    for(int i =0;i<m-3;i++)
    {
        for(int j=0;j<n-3;j++)
        {
            string word="";
            word+= {sv[i][j],sv[i+1][j+1],sv[i+2][j+2],sv[i+3][j+3]};
            if(word=="XMAS")ans++;
        }
    }
    for(int i =3;i<m;i++)
    {
        for(int j=3;j<n;j++)
        {
            string word="";
            word+= {sv[i][j],sv[i-1][j-1],sv[i-2][j-2],sv[i-3][j-3]};
            if(word=="XMAS")ans++;
        }
    }
    for(int i =0;i<m-3;i++)
    {
        for(int j=3;j<n;j++)
        {
            string word="";
            word+= {sv[i][j],sv[i+1][j-1],sv[i+2][j-2],sv[i+3][j-3]};
            if(word=="XMAS")ans++;
        }
    }
    for(int i =3;i<m;i++)
    {
        for(int j=0;j<n-3;j++)
        {
            string word="";
            word+= {sv[i][j],sv[i-1][j+1],sv[i-2][j+2],sv[i-3][j+3]};
            if(word=="XMAS")ans++;
        }
    }
    cout << ans << endl;
}