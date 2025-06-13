#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include<set>
#include<map>
#include<queue>
#include <string>
#include<cmath>
typedef long long ll;
using namespace std;
typedef unsigned long long ull;
bool isnum(char c)
{
    return c>='0'&&c<='9';
}
ll a,b,c;
void o0(ll op)
{
    if(op<4)
    {
        a/=pow(2,op);
    }
    else if(op==4)
    {
        a/=pow(2,a);
    }
    else if(op==5)
    {
        a/=pow(2,b);
    }
    else{
        a/=pow(2,c);
    }
}
void o1(ll op)
{
    b^=op;
}
void o2(ll op)
{
    if(op==4ll)op=a;
    else if (op==5ll)op=b;
    else if(op==6ll)op=c;
    op=op%8;
    b=op;
}
void o3(ll op,int &ptr,vector<pair<int,int>>&instr)
{
    if(a==0ll)return;
    ptr=op -1;
    return;
    for(int i =0;i<instr.size();i++)
    {
        if(instr[i].first==op)
        {
            ptr=i-1;
            return;
        }
    }
}
void o4()
{
    b=b^c;
}
void o5(string &out,ll op)
{
    if(op==4ll)op=a;
    else if (op==5ll)op=b;
    else if(op==6ll)op=c;
    op=op%8;
    out+='0'+op;
}
void o6(ll op)
{
    if(op<4ll)
    {
        b=a/pow(2,op);
    }
    else if(op==4ll)
    {
        b=a/pow(2,a);
    }
    else if(op==5ll)
    {
        b=a/pow(2,b);
    }
    else{
        b=a/pow(2,c);
    }
}
void o7(ll op)
{
    if(op<4ll)
    {
        c=a/pow(2,op);
    }
    else if(op==4ll)
    {
        c=a/pow(2,a);
    }
    else if(op==5ll)
    {
        c=a/pow(2,b);
    }
    else{
        c=a/pow(2,c);
    }
}
pair<ll,bool> backtrack(vector<pair<int,int>>&instr,string &inst,int pos,ll d)
{
    if(pos<0)return {d,true};
   int ptr=0;
   int loop=0;
    string out="";
    a=d;
    b=0,c=0;
    while(loop<instr.size())
    {
        loop++;
        switch(instr[ptr].first)
        {
            case 0:
            o0(instr[ptr].second);
            break;
            case 1:
            o1(instr[ptr].second);
            break;
            case 2:
            o2(instr[ptr].second);
            break;
            case 3:
            o3(instr[ptr].second,ptr,instr);
            break;
            case 4:
            o4();
            break;
            case 5:
            o5(out,instr[ptr].second);
            break;
            case 6:
            o6(instr[ptr].second);
            break;
            case 7:
            o7(instr[ptr].second);
            break;
        }
        ptr++;
    }
    if(out[0]==inst[pos])
    {
        if(pos==0)
        {
            return {d,true};
        }
        d*=8ll;
        for(int j =0;j<8;j++)
        {
            d+=j;
            auto e = backtrack(instr,inst,pos-1,d);
            if(e.second)
            {
                return e;
            }
            d-=j;
        }
        d/=8ll;
    }
    return {-1,false};
}
ll main_call(vector<pair<int,int>>&instr,string &inst)
{
    for(ll i =0;i<8;i++)
    {
            auto e = backtrack(instr,inst,inst.length()-1,i);
            if(e.second)
            {
                return e.first;
            }
    }
    return -1;
}
int main(){
    fstream file("input.txt", ios::in);
    string line;
    string vals[4];
    int ii=0;
    while(getline(file,line))
    {
        for(char c:line)
        {
            if(isnum(c))vals[ii]+=c;
        }
        //cout<<vals[ii]<<endl;
        ii++;
    }
     vector<pair<int,int>>instr;
    for(int i =0;i<vals[3].length()-1;i+=2)
    {
        instr.push_back({vals[3][i]-'0',vals[3][i+1]-'0'});
    }
    cout<<main_call(instr,vals[3]);
}
