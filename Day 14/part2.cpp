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
    vector<pair<int,int>>pos,vel;
    vector<vector<char>>gd(103,vector<char>(101,'.'));
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
        pos.push_back({xo,yo});
        vel.push_back({xv,yv});
    }
    ll mnd=INT_MAX;
    int cm =0,iter=0;
    while(cm<10000&&iter<100000)
    {
        ll dist=0;
        for(int i =0;i<pos.size();i++)
        {
            gd[pos[i].second][pos[i].first]='.';
            pos[i].first = (((pos[i].first + vel[i].first)%101)+101)%101;
            pos[i].second = (((pos[i].second + vel[i].second)%103)+103)%103;
            gd[pos[i].second][pos[i].first]='*';
            dist+= (pos[i].first - 51)*(pos[i].first - 51)+(pos[i].second - 50)*(pos[i].second - 50);
        }
        iter++;
        if(dist<mnd)
        {
            mnd = dist;
            cm++;
            for(int i =0;i<103;i++)
            {
                for(int j =0;j<101;j++)
                {
                    cout<<gd[i][j];
                }
                cout<<endl;
            }
            cout<<iter<<endl;
        }
    }

}