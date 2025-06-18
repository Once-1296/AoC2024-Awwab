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
typedef pair<int,int> i2;
class matrix
{
    public:
    std::vector<std::vector<ll>>mat;
    ll n,m;
    matrix(ll nn, ll mm, std::vector<std::vector<ll>>in)
    {
        n=nn;
        m=mm;
        mat.resize(n,std::vector<ll>(m));
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                mat[i][j]=in[i][j];
            }
        }
    }
    friend matrix operator*(matrix &a,matrix&b)
    {
        ll na=a.n,ma=a.m;
        ll nb=b.n,mb=b.m;
        std::vector<std::vector<ll>>cm(na,std::vector<ll>(mb,0));
        matrix c(na,mb,cm);
        if(ma!=nb)
        {
            std::cout<<"Error in matmul\n";
            return c;
        }
        for(int i =0;i<na;i++)
        {
            for(int j = 0;j<mb;j++)
            {
                ll res=0;
                for(int k =0;k<nb;k++)
                {
                    res+=(a.mat[i][k]*b.mat[k][j]);
                }
                c.mat[i][j]=res;
            }
        }
        return c;
    }
};
string dtob(int n,int l)
{
    string a="";
    while(n>0)
    {
        if(n&1)a+="1";
        else a+="0";
        n>>=1;
    }
    while(a.length()<l)a+="0";
    reverse(a.begin(),a.end());
    return a;
}
void qry(i2 a, i2 b, map<pair<i2,i2>,set<string>>&m,set<i2>&s)
{
    int ui = a.first,uj=a.second,vi=b.first,vj=b.second;
    for(int i=0;i<2;i++)
    {
        string v="";
        int ti=ui,tj=uj;
        if(i==1)
        {
            bool ok = 1;
            while(ti<vi)
            {
                v+="v";
                ti++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(ti>vi)
            {
                v+="^";
                ti--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(tj<vj)
            {
                v+=">";
                tj++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(tj>vj)
            {
                v+="<";
                tj--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            m[{a,b}].insert(v+"A");
        }
        else
        {
            bool ok = 1;
            while(tj<vj)
            {
                v+=">";
                tj++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(tj>vj)
            {
                v+="<";
                tj--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
             while(ti<vi)
            {
                v+="v";
                ti++;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            while(ti>vi)
            {
                v+="^";
                ti--;
                if(!s.count({ti,tj}))
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)continue;
            m[{a,b}].insert(v+"A");
        }
    }
}

int main(){
    fstream file("input.txt", ios::in);
    string line;
    set<pair<int,int>>s1,s2;
    map<char,pair<int,int>>m1,m2;
    string b1="7894561230A";
    int ii=0;
    for(int i =0;i<4;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(i==3&&j==0)continue;
            s1.insert({i,j});
            m1[b1[ii++]]={i,j};
        }
    }
    ii=0;
    string b2="^A<v>";
    for(int i =0;i<2;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(i==0&&j==0)continue;
            s2.insert({i,j});
            m2[b2[ii++]]={i,j};
        }
    }
    map<pair<i2,i2>,set<string>>mm1,mm2;
    map<int,pair<i2,i2>>mmm;
    map<pair<i2,i2>,int>rmmm;
    auto it1 =s1.begin();
    while(it1!=s1.end())
    {
        auto jit1 = s1.begin();
        while(jit1!=s1.end())
        {
            qry(*it1,*jit1,mm1,s1);
            jit1++;
        }
        it1++;
    }
    int x=0;
    auto it2 =s2.begin();
    while(it2!=s2.end())
    {
        auto jit2 = s2.begin();
        while(jit2!=s2.end())
        {
            qry(*it2,*jit2,mm2,s2);
            mmm[x]={*it2,*jit2};
            rmmm[{*it2,*jit2}]=x;
            x++;
            jit2++;

        }
        it2++;
    }
    vector<vector<ll>>TM(25,vector<ll>(25,0));
    auto I = TM;
    int tc=0;
    for(auto e:mm2)
    {
        if(e.second.size()>1)tc++;
        for(auto&ee:e.second)
        {
            cout<<ee<<" ";
        }
        cout<<endl;
    }
    cout<<mm2.size()<<endl;
    cout<<tc<<endl;
    vector<vector<ll>>T[16];
    for(int i =0;i<16;i++)
    {
        T[i]=TM;
    }
    for(int i=0;i<25;i++)
    {
        I[i][i]=1;
    }
    for(int k =0;k<16;k++)
    {
        string code=dtob(k,4);
        int kkk=0;
    for(int i =0;i<25;i++)
    {
        for(int j =0;j<25;j++)
        {
            pair<i2,i2> v = mmm[i];
            auto u = mmm[j];
            string sss;
            sss= *mm2[u].begin();
            if(mm2[u].size()>1)
            {
                if(code[kkk]=='1')
                {
                    sss=*mm2[u].rbegin();
                }
                kkk++;
            }
            char cc = 'A';
            bool bb=0;
            for(char ci:sss)
            {
                i2 uu=m2[cc];
                i2 vv=m2[ci];
                if(v.first==uu&&v.second==vv)
                {
                    // T[k][i][j]++;
                    bb=1;
                    break;
                }
                cc=ci;
            }
            if(bb)T[k][i][j]=1;
        }
    }
    }
    ll ans=0;
    while(getline(file,line))
    {
        vector<string>sv={""};
        char ch='A';
        for(char ci:line)
        {
            vector<string>inter;
            auto u = m1[ch],v=m1[ci];
            for(auto ss:mm1[{u,v}])
            {
                for(auto S:sv)
                {
                    inter.push_back(S+ss);
                }
            }
            ch=ci;
            sv=inter;
        }
        ll mn=LLONG_MAX;
        for(auto &S:sv)
        {
            char ch='A';
            vector<vector<ll>>start(25,vector<ll>(1,0));
            for(char ci:S)
            {
                auto u=m2[ch],v=m2[ci];
                int iii=rmmm[{u,v}];
                start[iii][0]++;
                ch=ci;
            }
            matrix mS(25,1,start),mI(25,25,I);
            for(int i =0;i<25;i++)
            {
                matrix mT0(25,25,T[0]);
                matrix mSN=mT0*mS;
            for(int j =1;j<16;j++)
            {
                matrix mC=mS;
                matrix mT(25,25,T[j]);
                mC=mT*mC;
                ll sm=0;
                for(int k=0;k<25;k++)
                {
                    sm+=mC.mat[i][0];
                    sm-=mSN.mat[i][0];
                }
                if(sm<0ll)
                {
                    mSN=mC;
                }
            }
            mS=mSN;
            }
            ll tms=0ll;
            for(int i =0;i<25;i++)tms+=mS.mat[i][0];
            mn=min(mn,tms);
        }
        ans+=mn*stoll(line.substr(0,3));
    }
    cout<<ans<<endl;
}