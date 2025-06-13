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
void o0(int op)
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
void o1(int op)
{
    b^=op;
}
void o2(int op)
{
    if(op==4)op=a;
    else if (op==5)op=b;
    else if(op==6)op=c;
    op=op%8;
    b=op;
}
void o3(int op,int &ptr,vector<pair<int,int>>&instr)
{
    if(a==0)return;
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
void o5(string &out,int op)
{
    if(op==4)op=a;
    else if (op==5)op=b;
    else if(op==6)op=c;
    op=op%8;
    out+='0'+op;
    out+=',';
}
void o6(int op)
{
    if(op<4)
    {
        b=a/pow(2,op);
    }
    else if(op==4)
    {
        b=a/pow(2,a);
    }
    else if(op==5)
    {
        b=a/pow(2,b);
    }
    else{
        b=a/pow(2,c);
    }
}
void o7(int op)
{
    if(op<4)
    {
        c=a/pow(2,op);
    }
    else if(op==4)
    {
        c=a/pow(2,a);
    }
    else if(op==5)
    {
        c=a/pow(2,b);
    }
    else{
        c=a/pow(2,c);
    }
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
    a = stoll(vals[0]),b=stoll(vals[1]),c=stoll(vals[2]);
    vector<pair<int,int>>instr;
    for(int i =0;i<vals[3].length()-1;i+=2)
    {
        instr.push_back({vals[3][i]-'0',vals[3][i+1]-'0'});
    }
    int ptr=0;
    string out="";
    while(ptr<instr.size())
    {
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
    cout<<out<<endl;
}
