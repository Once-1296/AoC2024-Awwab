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
bool isnum(char c)
{
    return c>='0'&&c<='9';
}
typedef unsigned long long ull;
int main(){
    fstream file("input.txt", ios::in);
    string line;
    ll ans=0;
    vector<vector<char>>grid;
    while (!file.eof())
    {
        ll vals[6];
        int ii=0;
        for(int i =0;i<3;i++)
        {
            getline(file,line);
            int j =0;
                while(j<line.length()&&!isnum(line[j]))j++;
                string n1="";
                while(j<line.length()&&isnum(line[j]))n1+=line[j++];
                string n2="";
                while(j<line.length()&&!isnum(line[j]))j++;
                while(j<line.length()&&isnum(line[j]))n2+=line[j++];
                vals[ii++]=stoll(n1);
                vals[ii++]=stoll(n2);
        }  
        getline(file,line);
        ll a = vals[0],b=vals[1],c=vals[2],d=vals[3],e=vals[4],f=vals[5];
        ll r = (a*f - e*b)/(a*d - b*c);
        ll l = (c*f - e*d)/(b*c - a*d);
        if(l < 0 || l>100||r>100||r < 0)
        {
            continue;
        }
        if(l*a + r *c !=e || l*b + r*d != f)continue;
        ans+=3*l + r;
    }
    
    cout<<ans<<endl;
}