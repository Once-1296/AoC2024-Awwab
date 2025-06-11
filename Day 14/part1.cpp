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
const pair<int,int>dirs[4]={{1,0},{0,1},{-1,0},{0,-1}};
int main(){
    fstream file("input.txt", ios::in);
    string line;
    ll ans=0;
    ll a=0,b=a,c=a,d=a;
    while (getline(file, line))
    {
        stringstream o1(line);
        string p[2];
        int i1=0;
        string w0;
        while(getline(o1,w0,' '))
        {
            p[i1++]=w0;
        }
        ll pts[4];
        int j1=0;
        for(int i =0;i<2;i++)
        {
            stringstream o2(p[i]);
            while(getline(o2,w0,'='))
            {
                if(w0=="p"||w0=="v")continue;
                stringstream o3(w0);
                string w1;
                while(getline(o3,w1,','))
                {
                    pts[j1++]=stoll(w1);
                }
            }
        }
        ll xo=pts[0],yo=pts[1],xv = pts[2],yv=pts[3];
        ll xe =(((xo+100*xv)%101)+101)%101,ye=(((yo+100*yv)%103)+103)%103;
        if(xe!=50&&ye!=51)
        {
            if(xe>50&&ye<51)a++;
            else if(xe<50&&ye<51)b++;
            else if(xe>50&&ye>51)c++;
            else d++;
        }
    }
    cout<<a*b*c*d<<endl;
}