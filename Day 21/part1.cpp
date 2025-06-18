#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;
typedef unsigned long long ull;
const pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
typedef pair<int, int> i2;
map<char, int> ord = {{'<', 1}, {'v', 2}, {'^', 3}, {'>', 4}};
bool comp(char c, char d)
{
    return ord[c] < ord[d];
}
void qry(i2 a, i2 b, map<pair<i2, i2>, string> &m)
{
    int ui = a.first, uj = a.second, vi = b.first, vj = b.second;
    string ans = "";
    if (vj > uj)
    {
        for (int i = uj; i < vj; i++)
            ans += ">";
        if (ui > vi)
        {
            for (int i = vi; i < ui; i++)
                ans += "^";
        }
        else
        {
            for (int i = ui; i < vi; i++)
                ans += "v";
            if (!((vi == 3 && (vj == 1 || vj == 2)) && uj == 0))
            {
                reverse(ans.begin(), ans.end());
            }
        }
    }
    else
    {
        for (int i = vj; i < uj; i++)
            ans += "<";
        if (ui > vi)
        {
            for (int i = vi; i < ui; i++)
                ans += "^";
        }
        else
        {
            for (int i = ui; i < vi; i++)
                ans += "v";
        }
        if ((ui == 0 && (uj == 1 || uj == 2)) && (vi == 1 && vj == 0))
        {
            reverse(ans.begin(), ans.end());
        }
        if ((ui == 3 && (uj == 1 || uj == 2)) && vj == 0)
        {
            reverse(ans.begin(), ans.end());
        }
    }
    m[{a, b}] = ans;
}
string h1(string in, map<char, i2> &m, map<pair<i2, i2>, string> &mm)
{
    char p = 'A';
    string ans = "";
    for (int i = 0; i < in.length(); i++)
    {
        char c = in[i];
        i2 a = m[p], b = m[c];
        ans += mm[{a, b}];
        ans += 'A';
        p = c;
    }
    return ans;
}
int main()
{
    fstream file("input.txt", ios::in);
    string line;
    set<pair<int, int>> s1, s2;
    map<char, pair<int, int>> m1, m2;
    string b1 = "7894561230A";
    int ii = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 3 && j == 0)
                continue;
            s1.insert({i, j});
            m1[b1[ii++]] = {i, j};
        }
    }
    ii = 0;
    string b2 = "^A<v>";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
                continue;
            s2.insert({i, j});
            m2[b2[ii++]] = {i, j};
        }
    }
    map<pair<i2, i2>, string> mm1, mm2;
    auto it1 = s1.begin();
    while (it1 != s1.end())
    {
        auto jit1 = s1.begin();
        while (jit1 != s1.end())
        {
            qry(*it1, *jit1, mm1);
            jit1++;
        }
        it1++;
    }
    auto it2 = s2.begin();
    while (it2 != s2.end())
    {
        auto jit2 = s2.begin();
        while (jit2 != s2.end())
        {
            qry(*it2, *jit2, mm2);
            jit2++;
        }
        it2++;
    }
    ll ans = 0;
    while (getline(file, line))
    {
        ll mul = stoll(line.substr(0, 3));
        string str2 = h1(line, m1, mm1);
        string str3 = h1(str2, m2, mm2);
        string str4 = h1(str3, m2, mm2);
        ans += str4.length() * mul;
        cout<<str2.length()<<endl;
        cout<<str3.length()<<endl;
        cout<<str4.length()<<endl;
    }
    // cout<<mm1[{{2,2},{0,0}}]<<endl;
    cout << ans << endl;
}