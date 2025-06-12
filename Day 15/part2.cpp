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
map<char,int> oper={{'^',0},{'>',1},{'v',2},{'<',3}};
bool help(vector<vector<char>>&gd,int si,int sj,int &dptr)
{
    int qi=si,qj=sj+1;
    int t1i = si+dirs[dptr].first,t1j=sj+dirs[dptr].second;
    int t2i = qi+dirs[dptr].first,t2j=qj+dirs[dptr].second;
    char o=gd[t1i][t1j],t=gd[t2i][t2j];
    if(o=='.'&&t=='.')
    {
        return true;
    }
    if(o=='#'||t=='#')return false;
    if(o==']'&&t=='.')
    {
        return help(gd,t1i,t1j-1,dptr);
    }
    if(o=='.'&&t=='[')
    {
        return help(gd,t2i,t2j,dptr);
    }
    if(o=='['&&t==']')
    {
        if(help(gd,t1i,t1j,dptr))
        {
        return true;
        }
        else return false;
    }
    return help(gd,t1i,t1j-1,dptr)&&help(gd,t2i,t2j,dptr);
}
void move(vector<vector<char>>&gd,int si,int sj,int &dptr,set<pair<int,int>>&st)
{
    //if(st.count({si,sj}))return;
    //if(gd[si][sj]=='.')return;
    int qi=si,qj=sj+1;
    int t1i = si+dirs[dptr].first,t1j=sj+dirs[dptr].second;
    int t2i = qi+dirs[dptr].first,t2j=qj+dirs[dptr].second;
    char o=gd[t1i][t1j],t=gd[t2i][t2j];
    if(o=='.'&&t=='.')
    {
        swap(gd[si][sj],gd[t1i][t1j]);
        swap(gd[qi][qj],gd[t2i][t2j]);
          st.insert({si,sj});
        return;
    }
    if(o==']'&&t=='.')
    {
        move(gd,t1i,t1j-1,dptr,st);
    }
    else if(o=='.'&&t=='[')
    {
        move(gd,t2i,t2j,dptr,st);
    }
    else if(o=='['&&t==']')
    {
        move(gd,t1i,t1j,dptr,st);
    }
    //else return;
    else{
        move(gd,t1i,t1j-1,dptr,st);
        move(gd,t2i,t2j,dptr,st);
    }
    swap(gd[si][sj],gd[t1i][t1j]);
    swap(gd[qi][qj],gd[t2i][t2j]);
    st.insert({si,sj});
}
void update(char c,vector<vector<char>>&gd,int &ri, int &rj)
{
    if(!oper.count(c))return;
    int dptr=oper[c];
    int ti = ri+dirs[dptr].first,tj=rj+dirs[dptr].second;
    int oi=-1,oj=-1;
    if(gd[ti][tj]=='#')return;
    if(gd[ti][tj]=='.')
    {
        swap(gd[ti][tj],gd[ri][rj]);
        ri=ti;
        rj=tj;
        return;
    }
    if(c=='>'||c=='<')
    {
        int swaps=1;
        while(gd[ti][tj]!='.')
    {
        if(gd[ti][tj]=='#')return;
        swaps++;
        ti+=dirs[dptr].first,tj+=dirs[dptr].second;
    }
    //cout<<swaps<<endl;
    while(swaps--)
    {
        int pi=ti-dirs[dptr].first,pj=tj-dirs[dptr].second;
        swap(gd[ti][tj],gd[pi][pj]);
        ti=pi,tj=pj;
    }
    ri+=dirs[dptr].first;
    rj+=dirs[dptr].second;
    return;
    }
    set<pair<int,int>>st;
    if(gd[ti][tj]=='[')
    {
        if(help(gd,ti,tj,dptr))
        {
            //return;
            move(gd,ti,tj,dptr,st);
             swap(gd[ti][tj],gd[ri][rj]);
        ri=ti;
        rj=tj;
        return;
        }
    }
    else{
        if(help(gd,ti,tj-1,dptr))
        {
           // return;
        move(gd,ti,tj-1,dptr,st);
        swap(gd[ti][tj],gd[ri][rj]);
        ri=ti;
        rj=tj;
        return;
        }
    }
}
int main(){
    fstream file("input.txt", ios::in);
    string line;
    string ops="";
    ll ans=0;
    vector<vector<char>>grid;
    while (getline(file, line))
    {
        if(line[0]=='#')
        {
        vector<char>t;
        for(char c:line)
        {
            if(c=='.')
            {
                t.push_back('.');
                t.push_back('.');
            }
            else if(c=='#')
            {
                t.push_back('#');
                t.push_back('#');
            }
            else if(c=='O')
            {
                t.push_back('[');
                t.push_back(']');
            }
            else{
                t.push_back('@');
                t.push_back('.');
            }
        }
        grid.push_back(t);
        }
        else ops+=line;
    }
    int n= grid.size(),m= grid[0].size();
    int ri=-1,rj;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            //cout<<grid[i][j];
            if(grid[i][j]=='@')
            {
                ri=i;
                rj=j;
                //break;
            }
        }
        //cout<<endl;
        //if(ri!=-1)break;
    }
    for(auto&c:ops)
    {
        update(c,grid,ri,rj);
        //cout<<c<<endl;
    // for(int i =0;i<n;i++)
    // {
    //     for(int j =0;j<m;j++)
    //     {
    //         //cout<<grid[i][j];
    //     }
    //     //cout<<endl;
    // }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            //cout<<grid[i][j];
            if(grid[i][j]=='[')
            {
                ans+=(100ll*i) + j;
            }
        }
       //cout<<endl;
    }
    cout<<ans<<endl;
}