#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool isnum(char c)
{
    return c>='0'&&c<='9';
}
int main()
{
    fstream file("input.txt", ios::in);
    string line;
    long long ans = 0;
    string full="";
    while (getline(file, line))
    {
        full+=line;
    }
    int sz=full.size();
    int i =0;
    while(i<sz-3)
    {
        string s ={full[i],full[i+1],full[i+2],full[i+3]};
        //cout<<s<<endl;
        if(s=="mul(")
        {
            string t="";
            i+=4;
            bool b=0;
            while(i<sz&&full[i]!=')')
            {
                if(full[i]!=','&&!isnum(full[i]))
                {
                    b=0;
                    break;
                }
                if(full[i]==',')
                {
                    if(b)
                    {
                        b=0;
                        break;
                    }
                    else b=1;
                }
                t+=full[i++];
            }
            //cout<<t<<endl;
            if(!b)continue;
            if(i==sz)break;
            bool oc=0;
            for(auto&c:t)
            {
                if(c==',')
                {
                    if(oc)
                    {
                        oc=0;
                        break;
                    }
                    else oc=1;
                }
                else if(!isnum(c))
                {
                    oc=0;
                    break;
                }
            }
            if(oc)
            {
                stringstream obj(t);
                long long nms[2];
                string num;
                int ii =0;
                while(getline(obj,num,','))
                {
                    //cout<<num<<endl;
                    nms[ii++]=stoll(num);
                }
                ans+=nms[0]*nms[1];
            }
        }
        else i++;
    }
    cout << ans << endl;
}