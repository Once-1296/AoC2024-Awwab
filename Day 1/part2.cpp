#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    fstream file("input.txt",ios::in);
    string line;
    map<long long,long long>m1,m2;
    while(getline(file,line))
    {
        string n1=line.substr(0,5),n2=line.substr(8,5);
        long long an=stoi(n1),bn=stoi(n2);
        m1[an]++,m2[bn]++;
        //cout<<an<<" "<<bn<<endl;
    }
    long long sum=0;
    for(auto&e:m1)
    {
        long long prod = m2.count(e.first)?m2[e.first]:0;
        sum+=e.first*e.second*prod;
    }
    cout<<sum<<endl;
}