#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    fstream file("input.txt",ios::in);
    string line;
    vector<int>v[2];
    while(getline(file,line))
    {
        string n1=line.substr(0,5),n2=line.substr(8,5);
        int an=stoi(n1),bn=stoi(n2);
        //cout<<an<<" "<<bn<<endl;
        v[0].push_back(an),v[1].push_back(bn);
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    int sum=0;
    for(int i =0;i<v[0].size();i++)
    {
        sum+=abs(v[0][i]-v[1][i]);
    }
    cout<<sum<<endl;
}